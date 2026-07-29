import { nastran } from './nastran';
import { abaqus } from './abaqus';
import { ansys } from './ansys';
import { fluent } from './fluent';

export const formats = { nastran, abaqus, ansys, fluent };
export const formatList = Object.values(formats);