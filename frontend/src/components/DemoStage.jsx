import { useState, useMemo } from "react";
import { formats } from '../data';
import FormatSelector from './FormatSelector';
import UploadButton from './UploadButton';
import DependencyFilesInput from './DependencyFilesInput';
import StepRawFile from './StepRawFile';
import StepStructured from './StepStructured';
import StepResult from './StepResult3D';
import StepIndicator from './StepIndicator';

function onNext(currentStep, setStep) {
    if (currentStep === '3D')
       return setStep('raw');
    const steps = ['raw', 'structured', '3D'];
    steps.forEach((stepItem, i) => {
        if (currentStep === stepItem && i < steps.length - 1)
           return setStep(steps[i + 1]);
    });
}

export default function DemoStage() {

    const [activeId, setActiveId] = useState('Nastran');
    const [step, setStep] = useState('raw');
    const [collapsed, setCollapsed] = useState(false);
    const [geometryData, setGeometryData] = useState(null);
    const [isExtracting, setIsExtracting] = useState(false);
    const [extractError, setExtractError] = useState(null);
    const [uploadedFile, setUploadedFile] = useState(null);
    const [dependencyFiles, setDependencyFiles] = useState([]);

    const format = useMemo(
        () => (uploadedFile ? { label: 'Uploaded file', filename: uploadedFile.name } : formats[activeId]),
        [uploadedFile, activeId]
    );

    function handleFormatChange(id) {
        setUploadedFile(null);
        setDependencyFiles([]);
        setActiveId(id);
    }

    function handleUpload(file) {
        setUploadedFile(file);
        setDependencyFiles([]);
        setGeometryData(null);
        setExtractError(null);
        setCollapsed(false);
        setStep('raw');
    }

    async function handleExtract() {
        setIsExtracting(true);
        setExtractError(null);

        try {
            let blob;
            if (uploadedFile) {
                blob = uploadedFile;
            } else {
                const response = await fetch(format.samplePath);
                blob = await response.blob();
            }

            const formData = new FormData();
            formData.append('file', blob, format.filename);
            dependencyFiles.forEach((depFile) => formData.append('dependencies', depFile, depFile.name));

            const backendResponse = await fetch('http://localhost:3000/translate', {
                method: 'POST',
                body: formData,
            });

            const data = await backendResponse.json();

            if (!backendResponse.ok) {
                throw new Error(data.error || 'Access failed to process the file.');
            }

            setGeometryData(data);
            onNext(step, setStep);
            setCollapsed(true);
        } catch (err) {
            setExtractError(err.message || 'Something went wrong while contacting the backend.');
        } finally {
            setIsExtracting(false);
        }
    }

    return (

        <div className="min-h-screen flex items-start justify-center bg-slate-50 p-4 pt-8 sm:pt-16">
            <div className="w-full max-w-5xl h-160 sm:h-220 md:h-300 bg-white rounded-2xl shadow-lg p-4 sm:p-6 flex flex-col">
                <StepIndicator step={step} format={format}/>
                <div className="flex-1 min-h-0 flex flex-col overflow-y-auto">
                    {step === 'raw' && (
                        <>
                            <FormatSelector
                                activeId={activeId}
                                onChange={handleFormatChange}
                                isUploadActive={Boolean(uploadedFile)}
                            />
                            <div className="flex justify-center mb-5 -mt-1">
                                <UploadButton
                                    onUpload={handleUpload}
                                    isActive={Boolean(uploadedFile)}
                                    fileName={uploadedFile?.name}
                                />
                            </div>
                            {uploadedFile && (
                                <DependencyFilesInput
                                    files={dependencyFiles}
                                    onChange={setDependencyFiles}
                                />
                            )}
                        </>
                    )}
                    <StepRawFile
                        format={format}
                        uploadedFile={uploadedFile}
                        onNext={handleExtract}
                        collapsed={collapsed}
                        onExpand={() => { setCollapsed(!collapsed); setStep('raw'); }}
                        isExtracting={isExtracting}
                        extractError={extractError}
                    />
                    {step === 'structured' && <StepStructured format={format} geometryData={geometryData} onNext={() => onNext(step, setStep)} />}
                    {step === '3D' && <StepResult geometryData={geometryData} onNext={() => { onNext(step, setStep); setCollapsed(false); }} />}
                </div>
            </div>
        </div>
    );
}