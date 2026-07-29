import { useState } from "react";
import { formats } from '../data';
import FormatSelector from './FormatSelector';
import StepRawFile from './StepRawFile';
import StepStructured from './StepStructured';
import StepResult from './StepResult3D';

function onNext(currentStep, setStep) {
    if (currentStep === '3D')
       return setStep('raw');
    const steps = ['raw', 'structured', '3D'];
    steps.forEach((stepItem, i) => {
        if (currentStep === stepItem && i < steps.length - 1)
           return setStep(steps[i + 1]);
    });
}

function onExpand(collapsed, setCollapsed) {
    setCollapsed(!collapsed); 
}

export default function DemoStage() {

    const [activeId, setActiveId] = useState('nastran');
    const [step, setStep] = useState('raw');
    const [collapsed, setCollapsed] = useState(false);

    const format = formats[activeId];
    return (

        <div>
            {step === 'raw' && <FormatSelector activeId={activeId} onChange={setActiveId} />}
            {step === 'raw' && <StepRawFile format={format} onNext={() => onNext(step, setStep)} collapsed={collapsed} onExpand={() => onExpand(collapsed, setCollapsed)} />}
            {step === 'structured' && <StepStructured format={format} onNext={() => onNext(step, setStep)} />}
            {step === '3D' && <StepResult format={format} onNext={() => onNext(step, setStep)} />}
        </div>
    );
}