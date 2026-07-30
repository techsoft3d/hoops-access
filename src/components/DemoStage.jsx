import { useState } from "react";
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

    const [activeId, setActiveId] = useState('nastran');
    const [step, setStep] = useState('raw');
    const [collapsed, setCollapsed] = useState(false);

    const format = formats[activeId];
    return (

        <div className="min-h-screen flex items-start justify-center bg-slate-50 p-4 pt-16">
            <div className="w-full max-w-4xl bg-white rounded-2xl shadow-lg p-6">
                <StepIndicator step={step} format={format}/>
                {step === 'raw' && <FormatSelector activeId={activeId} onChange={setActiveId} />}
                <StepRawFile format={format} onNext={() => { onNext(step, setStep); setCollapsed(true); }} collapsed={collapsed} onExpand={() => { setCollapsed(!collapsed); setStep('raw'); }} />
                {step === 'structured' && <StepStructured format={format} onNext={() => onNext(step, setStep)} />}
                {step === '3D' && <StepResult format={format} onNext={() => { onNext(step, setStep); setCollapsed(false); }} />}
            </div>
        </div>
    );
}