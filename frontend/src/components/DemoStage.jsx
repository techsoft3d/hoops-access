import { useState, useMemo } from "react";
import { formats } from '../data';
import FormatSelector from './FormatSelector';
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

    const format = useMemo(
        () => (uploadedFile ? { label: 'Uploaded file', filename: uploadedFile.name } : formats[activeId]),
        [uploadedFile, activeId]
    );

    function handleFormatChange(id) {
        setUploadedFile(null);
        setActiveId(id);
    }

    function handleUpload(file) {
        setUploadedFile(file);
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

        <div className="min-h-screen flex items-start justify-center bg-slate-50 p-4 pt-16">
            <div className="w-full max-w-4xl bg-white rounded-2xl shadow-lg p-6">
                <StepIndicator step={step} format={format}/>
                {step === 'raw' && (
                    <FormatSelector
                        activeId={activeId}
                        onChange={handleFormatChange}
                        onUpload={handleUpload}
                        isUploadActive={Boolean(uploadedFile)}
                        uploadedFileName={uploadedFile?.name}
                    />
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
    );
}