/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
using System;
using System.Text;
using System.Runtime.InteropServices;
 
namespace DevTools {
   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetMode(IntPtr a0,int a1,int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetConvention(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunOpen(IntPtr a0,int a1,StringBuilder a2,int a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunClose(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunDefDataset(IntPtr a0,StringBuilder a1,long a2,int a3,int a4,int a5,ref int a6);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetNumEntities(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetLibrary(IntPtr a0,out IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunWriteDataset(IntPtr a0,int a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunReadDataset(IntPtr a0,int a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunUpdate(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetStatus(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunIncDataset(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunAppend(IntPtr a0,StringBuilder a1,int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate int VDataFunError(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunWriteModel(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunWriteState(IntPtr a0,IntPtr a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetIds(IntPtr a0,int a1,int a2,int a3,int a4);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetConnect(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetConnect(IntPtr a0,out IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunLibDataset(IntPtr a0,int a1,int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunDefAttribute(IntPtr a0,int a1,StringBuilder a2,int a3,int a4,ref int a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetAttVal(IntPtr a0,int a1,int a2,IntPtr a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetAttVal(IntPtr a0,int a1,int a2,IntPtr a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunNumDatasets(IntPtr a0,ref int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunNumAttributes(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunInqDataset(IntPtr a0,int a1,StringBuilder a2,ref long a3,ref int a4,ref int a5,ref int a6);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunInqAttribute(IntPtr a0,int a1,int a2,StringBuilder a3,ref int a4,ref int a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetInteger(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetString(IntPtr a0,int a1,StringBuilder a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunNumDomains(IntPtr a0,StringBuilder a1,int a2,ref int a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunPushContainer(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunPopContainer(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunReadDatasetCols(IntPtr a0,int a1,int a2,ref int a3,IntPtr a4,ref long a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetThreadsCount(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunSetString(IntPtr a0,int a1,StringBuilder a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunGetUnrecognizedData(IntPtr a0,out IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataFunApplySettings(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataIPCMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataIPCWriteFunc(IntPtr a0,int a1,StringBuilder a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataIPCReadFunc(IntPtr a0,int a1,StringBuilder a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataIPCUserFunc(IntPtr a0,IntPtr a1,int a2,StringBuilder a3,int a4,int [] a5,int a6,float [] a7,int a8,double [] a9);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VABAFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VABALibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VAdamsLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VAFLRFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VH3DLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VANSFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VANSLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VAUTODYNLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VCFXLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VCGNSVLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VCOMSOLLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDPFLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VEnSightLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFEMAPLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFLUENTLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGMVLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VHMAFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VD3DFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VD3DLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VMarcFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VMarcLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VRASFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VRASLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VMemLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VNASFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VNASLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VNatLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VOBJFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VOpenFOAMLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPAMFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPAMLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPatLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPERMASLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPLOT3DLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPOLYFLOWLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VSAMCEFLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VSDRCLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VSTARCCMLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VSTLFilMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTecplotLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VVTKLibMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VPluginLibMonitorFunc(IntPtr a0,IntPtr a1);

   public class vdm {

      public const int ATTRIBUTE_MAXNAME = 256;
      public const int ATTRIBUTE_MAXVALUE = 256;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_AttributeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_AttributeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeDef(IntPtr p,StringBuilder n_ame,int l_ength,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeInq(IntPtr p,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeSet(IntPtr p,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeSetValueiv(IntPtr p,int [] i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeSetValuefv(IntPtr p,float [] f_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeSetValuedv(IntPtr p,double [] d_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeSetValuec(IntPtr p,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeGet(IntPtr p,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeValueInteger(IntPtr p,int [] i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeValueFloat(IntPtr p,float [] f_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeValueDouble(IntPtr p,double [] d_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeValueString(IntPtr p,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeStreamNum(IntPtr p,ref int n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeStreamSave(IntPtr p,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeStreamLoad(IntPtr p,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributeCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AttributePrint(IntPtr p);

      public static IntPtr AttributeBegin() {
         return vdm_AttributeBegin();
      }

      public static void AttributeEnd(IntPtr p) {
         vdm_AttributeEnd(p);
      }

      public static int AttributeError(IntPtr p) {
         return vdm_AttributeError(p);
      }

      public static void AttributeDef(IntPtr p,StringBuilder n_ame,int l_ength,int t_ype) {
         vdm_AttributeDef(p, n_ame, l_ength, t_ype);
      }

      public static void AttributeInq(IntPtr p,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_AttributeInq(p, n_ame,ref l_ength,ref t_ype);
      }

      public static void AttributeSet(IntPtr p,ref IntPtr v_alue) {
         vdm_AttributeSet(p,ref v_alue);
      }

      public static void AttributeSetValueiv(IntPtr p,int [] i_value) {
         vdm_AttributeSetValueiv(p, i_value);
      }

      public static void AttributeSetValuefv(IntPtr p,float [] f_value) {
         vdm_AttributeSetValuefv(p, f_value);
      }

      public static void AttributeSetValuedv(IntPtr p,double [] d_value) {
         vdm_AttributeSetValuedv(p, d_value);
      }

      public static void AttributeSetValuec(IntPtr p,StringBuilder c_value) {
         vdm_AttributeSetValuec(p, c_value);
      }

      public static void AttributeGet(IntPtr p,ref IntPtr v_alue) {
         vdm_AttributeGet(p,ref v_alue);
      }

      public static void AttributeValueInteger(IntPtr p,int [] i_value) {
         vdm_AttributeValueInteger(p, i_value);
      }

      public static void AttributeValueFloat(IntPtr p,float [] f_value) {
         vdm_AttributeValueFloat(p, f_value);
      }

      public static void AttributeValueDouble(IntPtr p,double [] d_value) {
         vdm_AttributeValueDouble(p, d_value);
      }

      public static void AttributeValueString(IntPtr p,StringBuilder c_value) {
         vdm_AttributeValueString(p, c_value);
      }

      public static void AttributeStreamNum(IntPtr p,ref int n_bytes) {
         vdm_AttributeStreamNum(p,ref n_bytes);
      }

      public static void AttributeStreamSave(IntPtr p,ref IntPtr d_ata) {
         vdm_AttributeStreamSave(p,ref d_ata);
      }

      public static void AttributeStreamLoad(IntPtr p,ref IntPtr d_ata) {
         vdm_AttributeStreamLoad(p,ref d_ata);
      }

      public static void AttributeCopy(IntPtr p,IntPtr f_romp) {
         vdm_AttributeCopy(p, f_romp);
      }

      public static void AttributePrint(IntPtr p) {
         vdm_AttributePrint(p);
      }

      public const int DATAFUN_SETMODE = 1;
      public const int DATAFUN_SETCONVENTION = 2;
      public const int DATAFUN_OPEN = 3;
      public const int DATAFUN_CLOSE = 4;
      public const int DATAFUN_DEFDATASET = 5;
      public const int DATAFUN_GETNUMENTITIES = 6;
      public const int DATAFUN_GETLIBRARY = 7;
      public const int DATAFUN_WRITEDATASET = 8;
      public const int DATAFUN_READDATASET = 9;
      public const int DATAFUN_UPDATE = 10;
      public const int DATAFUN_SETSTATUS = 11;
      public const int DATAFUN_INCDATASET = 12;
      public const int DATAFUN_APPEND = 13;
      public const int DATAFUN_ERROR = 14;
      public const int DATAFUN_WRITEMODEL = 15;
      public const int DATAFUN_WRITESTATE = 16;
      public const int DATAFUN_SETIDS = 17;
      public const int DATAFUN_SETCONNECT = 18;
      public const int DATAFUN_GETCONNECT = 19;
      public const int DATAFUN_LIBDATASET = 20;
      public const int DATAFUN_DEFATTRIBUTE = 21;
      public const int DATAFUN_SETATTVAL = 22;
      public const int DATAFUN_GETATTVAL = 23;
      public const int DATAFUN_NUMDATASETS = 24;
      public const int DATAFUN_NUMATTRIBUTES = 25;
      public const int DATAFUN_INQDATASET = 26;
      public const int DATAFUN_INQATTRIBUTE = 27;
      public const int DATAFUN_GETINTEGER = 28;
      public const int DATAFUN_GETSTRING = 29;
      public const int DATAFUN_NUMDOMAINS = 30;
      public const int DATAFUN_PUSHCONTAINER = 31;
      public const int DATAFUN_POPCONTAINER = 32;
      public const int DATAFUN_READDATASETCOLS = 33;
      public const int DATAFUN_SETTHREADSCOUNT = 34;
      public const int DATAFUN_SETSTRING = 35;
      public const int DATAFUN_GETUNRECOGNIZEDDATA = 36;
      public const int DATAFUN_MAX = 38;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_DataFunBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_DataFunError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetErrorFunction(IntPtr p,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetObj(IntPtr p,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetObj(IntPtr p,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetMode(IntPtr p,int m_ode,int p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunOpenFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentities);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunUpdate(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunAppend(IntPtr p,StringBuilder p_ath,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunAppendFile(IntPtr p,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunLibDataset(IntPtr p,int i_op,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunNumDatasets(IntPtr p,ref int n_umdats);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunNumAttributes(IntPtr p,int i_dst,ref int n_umatts);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetInteger(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunNumDomains(IntPtr p,StringBuilder p_ath,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunPushContainer(IntPtr p,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunPopContainer(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uff,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetModeFun(IntPtr p,VDataFunSetMode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetConventionFun(IntPtr p,VDataFunSetConvention f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetOpenFun(IntPtr p,VDataFunOpen f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetCloseFun(IntPtr p,VDataFunClose f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetDefDatasetFun(IntPtr p,VDataFunDefDataset f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetNumEntitiesFun(IntPtr p,VDataFunGetNumEntities f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetLibraryFun(IntPtr p,VDataFunGetLibrary f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetWriteDatasetFun(IntPtr p,VDataFunWriteDataset f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetReadDatasetFun(IntPtr p,VDataFunReadDataset f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetUpdateFun(IntPtr p,VDataFunUpdate f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetStatusFun(IntPtr p,VDataFunSetStatus f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetIncDatasetFun(IntPtr p,VDataFunIncDataset f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetAppendFun(IntPtr p,VDataFunAppend f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetErrorFun(IntPtr p,VDataFunError f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetWriteModelFun(IntPtr p,VDataFunWriteModel f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetWriteStateFun(IntPtr p,VDataFunWriteState f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetIdsFun(IntPtr p,VDataFunSetIds f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetConnectFun(IntPtr p,VDataFunSetConnect f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetConnectFun(IntPtr p,VDataFunGetConnect f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetLibDatasetFun(IntPtr p,VDataFunLibDataset f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetDefAttribute(IntPtr p,VDataFunDefAttribute f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetIntegerFun(IntPtr p,VDataFunGetInteger f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetStringFun(IntPtr p,VDataFunGetString f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetNumDomainsFun(IntPtr p,VDataFunNumDomains f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetPushContainerFun(IntPtr p,VDataFunPushContainer f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetPopContainerFun(IntPtr p,VDataFunPopContainer f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetReadDatasetColrFun(IntPtr p,VDataFunReadDatasetCols f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetThreadsCount(IntPtr p,VDataFunSetThreadsCount f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetSetStringFun(IntPtr p,VDataFunSetString f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSetGetUnrecognizedDataFun(IntPtr p,VDataFunGetUnrecognizedData f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunApplySettingsFun(IntPtr p,VDataFunApplySettings f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetNumDatasets(IntPtr p,ref int n_umdataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunGetDataset(IntPtr p,int i_dst,out IntPtr d_ataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataFunSearchDataset(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um);

      public static IntPtr DataFunBegin() {
         return vdm_DataFunBegin();
      }

      public static void DataFunEnd(IntPtr p) {
         vdm_DataFunEnd(p);
      }

      public static int DataFunError(IntPtr p) {
         return vdm_DataFunError(p);
      }

      public static void DataFunInit(IntPtr p) {
         vdm_DataFunInit(p);
      }

      public static void DataFunSet(IntPtr p,int t_ype,Vfunc f_unction) {
         vdm_DataFunSet(p, t_ype, f_unction);
      }

      public static void DataFunSetErrorFunction(IntPtr p,Vfunc f_unction) {
         vdm_DataFunSetErrorFunction(p, f_unction);
      }

      public static void DataFunGet(IntPtr p,int t_ype,Vfunc f_unction) {
         vdm_DataFunGet(p, t_ype, f_unction);
      }

      public static void DataFunSetObj(IntPtr p,IntPtr o_bj) {
         vdm_DataFunSetObj(p, o_bj);
      }

      public static void DataFunGetObj(IntPtr p,out IntPtr o_bj) {
         vdm_DataFunGetObj(p,out o_bj);
      }

      public static void DataFunCopy(IntPtr p,IntPtr f_romp) {
         vdm_DataFunCopy(p, f_romp);
      }

      public static void DataFunSetMode(IntPtr p,int m_ode,int p_aram) {
         vdm_DataFunSetMode(p, m_ode, p_aram);
      }

      public static void DataFunSetConvention(IntPtr p,long c_onvention) {
         vdm_DataFunSetConvention(p, c_onvention);
      }

      public static void DataFunSetStatus(IntPtr p,int s_tatus) {
         vdm_DataFunSetStatus(p, s_tatus);
      }

      public static void DataFunOpenFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions) {
         vdm_DataFunOpenFile(p, f_ile, o_ptions);
      }

      public static void DataFunOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype) {
         vdm_DataFunOpen(p, m_ode, p_ath, t_ype);
      }

      public static void DataFunClose(IntPtr p) {
         vdm_DataFunClose(p);
      }

      public static void DataFunCloseFile(IntPtr p) {
         vdm_DataFunCloseFile(p);
      }

      public static void DataFunGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentities) {
         vdm_DataFunGetNumEntities(p, e_ntitytype,ref n_umentities);
      }

      public static void DataFunGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_DataFunGetLibrary(p,out l_ibrary);
      }

      public static void DataFunDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_DataFunDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void DataFunReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_DataFunReadDataset(p, i_dst,ref b_uff);
      }

      public static void DataFunWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_DataFunWriteDataset(p, i_dst,ref b_uff);
      }

      public static void DataFunUpdate(IntPtr p) {
         vdm_DataFunUpdate(p);
      }

      public static void DataFunAppend(IntPtr p,StringBuilder p_ath,int t_ype) {
         vdm_DataFunAppend(p, p_ath, t_ype);
      }

      public static void DataFunAppendFile(IntPtr p,StringBuilder p_ath) {
         vdm_DataFunAppendFile(p, p_ath);
      }

      public static void DataFunWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_DataFunWriteModel(p, m_odel);
      }

      public static void DataFunWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_DataFunWriteState(p, r_prop, s_tate);
      }

      public static void DataFunSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3) {
         vdm_DataFunSetIds(p, i_dtype, i_d1, i_d2, i_d3);
      }

      public static void DataFunSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_DataFunSetConnect(p, c_onnect);
      }

      public static void DataFunGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_DataFunGetConnect(p,out c_onnect);
      }

      public static void DataFunLibDataset(IntPtr p,int i_op,int i_dst) {
         vdm_DataFunLibDataset(p, i_op, i_dst);
      }

      public static void DataFunDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att) {
         vdm_DataFunDefAttribute(p, i_dst, n_ame, l_ength, t_ype,ref i_att);
      }

      public static void DataFunSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_DataFunSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void DataFunGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_DataFunGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void DataFunNumDatasets(IntPtr p,ref int n_umdats) {
         vdm_DataFunNumDatasets(p,ref n_umdats);
      }

      public static void DataFunNumAttributes(IntPtr p,int i_dst,ref int n_umatts) {
         vdm_DataFunNumAttributes(p, i_dst,ref n_umatts);
      }

      public static void DataFunInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_DataFunInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void DataFunInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_DataFunInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void DataFunGetInteger(IntPtr p,int t_ype,ref int i_param) {
         vdm_DataFunGetInteger(p, t_ype,ref i_param);
      }

      public static void DataFunGetString(IntPtr p,int t_ype,StringBuilder c_param) {
         vdm_DataFunGetString(p, t_ype, c_param);
      }

      public static void DataFunNumDomains(IntPtr p,StringBuilder p_ath,int t_ype,ref int n_umdomains) {
         vdm_DataFunNumDomains(p, p_ath, t_ype,ref n_umdomains);
      }

      public static void DataFunPushContainer(IntPtr p,StringBuilder p_ath) {
         vdm_DataFunPushContainer(p, p_ath);
      }

      public static void DataFunPopContainer(IntPtr p) {
         vdm_DataFunPopContainer(p);
      }

      public static void DataFunReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uff,ref long l_ptr) {
         vdm_DataFunReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uff,ref l_ptr);
      }

      public static void DataFunSetString(IntPtr p,int t_ype,StringBuilder c_param) {
         vdm_DataFunSetString(p, t_ype, c_param);
      }

      public static void DataFunSetSetModeFun(IntPtr p,VDataFunSetMode f_unc) {
         vdm_DataFunSetSetModeFun(p, f_unc);
      }

      public static void DataFunSetSetConventionFun(IntPtr p,VDataFunSetConvention f_unc) {
         vdm_DataFunSetSetConventionFun(p, f_unc);
      }

      public static void DataFunSetOpenFun(IntPtr p,VDataFunOpen f_unc) {
         vdm_DataFunSetOpenFun(p, f_unc);
      }

      public static void DataFunSetCloseFun(IntPtr p,VDataFunClose f_unc) {
         vdm_DataFunSetCloseFun(p, f_unc);
      }

      public static void DataFunSetDefDatasetFun(IntPtr p,VDataFunDefDataset f_unc) {
         vdm_DataFunSetDefDatasetFun(p, f_unc);
      }

      public static void DataFunSetGetNumEntitiesFun(IntPtr p,VDataFunGetNumEntities f_unc) {
         vdm_DataFunSetGetNumEntitiesFun(p, f_unc);
      }

      public static void DataFunSetGetLibraryFun(IntPtr p,VDataFunGetLibrary f_unc) {
         vdm_DataFunSetGetLibraryFun(p, f_unc);
      }

      public static void DataFunSetWriteDatasetFun(IntPtr p,VDataFunWriteDataset f_unc) {
         vdm_DataFunSetWriteDatasetFun(p, f_unc);
      }

      public static void DataFunSetReadDatasetFun(IntPtr p,VDataFunReadDataset f_unc) {
         vdm_DataFunSetReadDatasetFun(p, f_unc);
      }

      public static void DataFunSetUpdateFun(IntPtr p,VDataFunUpdate f_unc) {
         vdm_DataFunSetUpdateFun(p, f_unc);
      }

      public static void DataFunSetSetStatusFun(IntPtr p,VDataFunSetStatus f_unc) {
         vdm_DataFunSetSetStatusFun(p, f_unc);
      }

      public static void DataFunSetIncDatasetFun(IntPtr p,VDataFunIncDataset f_unc) {
         vdm_DataFunSetIncDatasetFun(p, f_unc);
      }

      public static void DataFunSetAppendFun(IntPtr p,VDataFunAppend f_unc) {
         vdm_DataFunSetAppendFun(p, f_unc);
      }

      public static void DataFunSetErrorFun(IntPtr p,VDataFunError f_unc) {
         vdm_DataFunSetErrorFun(p, f_unc);
      }

      public static void DataFunSetWriteModelFun(IntPtr p,VDataFunWriteModel f_unc) {
         vdm_DataFunSetWriteModelFun(p, f_unc);
      }

      public static void DataFunSetWriteStateFun(IntPtr p,VDataFunWriteState f_unc) {
         vdm_DataFunSetWriteStateFun(p, f_unc);
      }

      public static void DataFunSetSetIdsFun(IntPtr p,VDataFunSetIds f_unc) {
         vdm_DataFunSetSetIdsFun(p, f_unc);
      }

      public static void DataFunSetSetConnectFun(IntPtr p,VDataFunSetConnect f_unc) {
         vdm_DataFunSetSetConnectFun(p, f_unc);
      }

      public static void DataFunSetGetConnectFun(IntPtr p,VDataFunGetConnect f_unc) {
         vdm_DataFunSetGetConnectFun(p, f_unc);
      }

      public static void DataFunSetLibDatasetFun(IntPtr p,VDataFunLibDataset f_unc) {
         vdm_DataFunSetLibDatasetFun(p, f_unc);
      }

      public static void DataFunSetDefAttribute(IntPtr p,VDataFunDefAttribute f_unc) {
         vdm_DataFunSetDefAttribute(p, f_unc);
      }

      public static void DataFunSetGetIntegerFun(IntPtr p,VDataFunGetInteger f_unc) {
         vdm_DataFunSetGetIntegerFun(p, f_unc);
      }

      public static void DataFunSetGetStringFun(IntPtr p,VDataFunGetString f_unc) {
         vdm_DataFunSetGetStringFun(p, f_unc);
      }

      public static void DataFunSetNumDomainsFun(IntPtr p,VDataFunNumDomains f_unc) {
         vdm_DataFunSetNumDomainsFun(p, f_unc);
      }

      public static void DataFunSetPushContainerFun(IntPtr p,VDataFunPushContainer f_unc) {
         vdm_DataFunSetPushContainerFun(p, f_unc);
      }

      public static void DataFunSetPopContainerFun(IntPtr p,VDataFunPopContainer f_unc) {
         vdm_DataFunSetPopContainerFun(p, f_unc);
      }

      public static void DataFunSetReadDatasetColrFun(IntPtr p,VDataFunReadDatasetCols f_unc) {
         vdm_DataFunSetReadDatasetColrFun(p, f_unc);
      }

      public static void DataFunSetSetThreadsCount(IntPtr p,VDataFunSetThreadsCount f_unc) {
         vdm_DataFunSetSetThreadsCount(p, f_unc);
      }

      public static void DataFunSetSetStringFun(IntPtr p,VDataFunSetString f_unc) {
         vdm_DataFunSetSetStringFun(p, f_unc);
      }

      public static void DataFunSetGetUnrecognizedDataFun(IntPtr p,VDataFunGetUnrecognizedData f_unc) {
         vdm_DataFunSetGetUnrecognizedDataFun(p, f_unc);
      }

      public static void DataFunApplySettingsFun(IntPtr p,VDataFunApplySettings f_unc) {
         vdm_DataFunApplySettingsFun(p, f_unc);
      }

      public static void DataFunGetNumDatasets(IntPtr p,ref int n_umdataset) {
         vdm_DataFunGetNumDatasets(p,ref n_umdataset);
      }

      public static void DataFunGetDataset(IntPtr p,int i_dst,out IntPtr d_ataset) {
         vdm_DataFunGetDataset(p, i_dst,out d_ataset);
      }

      public static void DataFunSearchDataset(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um) {
         vdm_DataFunSearchDataset(p, n_ame, m_ax, i_dsts,ref n_um);
      }

      public const int DATAIPC_CLIENT = 1;
      public const int DATAIPC_SERVER = 2;
      public const int DATAIPC_NET = 1;
      public const int DATAIPC_LOCAL = 2;
      public const int DATAIPC_USER = 3;
      public const int DATAIPC_FUN_MONITOR = 1;
      public const int DATAIPC_FUN_WRITE = 2;
      public const int DATAIPC_FUN_READ = 3;
      public const int DATAIPC_FUN_USER = 4;
      public const int DATAIPC_BEFORE = 0;
      public const int DATAIPC_AFTER = 1;
      public const int DATAIPC_DATAFUN = -1;
      public const int DATAIPC_STATE = -2;
      public const int DATAIPC_FILETYPE = -3;
      public const int DATAIPC_FILENAME = -4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_DataIPCBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_DataIPCError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCInq(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetSwap(IntPtr p,int s_wap);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetObject(IntPtr p,int t_ype,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetObject(IntPtr p,int t_ype,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentities);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetInteger(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCPushContainer(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCPopContainer(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCStartServer(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCStopServer(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uff,long [] l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetMonitorFunction(IntPtr p,VDataIPCMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetReadFunction(IntPtr p,VDataIPCReadFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetWriteFunction(IntPtr p,VDataIPCWriteFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCUpdate(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCNumAttributes(IntPtr p,int i_dst,ref int n_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DataIPCUser(IntPtr p,int n_chars,StringBuilder c_hars,int n_ints,int [] i_nts,int n_floats,float [] f_loats,int n_doubles,double [] d_oubles);

      public static IntPtr DataIPCBegin() {
         return vdm_DataIPCBegin();
      }

      public static void DataIPCEnd(IntPtr p) {
         vdm_DataIPCEnd(p);
      }

      public static int DataIPCError(IntPtr p) {
         return vdm_DataIPCError(p);
      }

      public static void DataIPCDef(IntPtr p,int t_ype) {
         vdm_DataIPCDef(p, t_ype);
      }

      public static void DataIPCInq(IntPtr p,ref int t_ype) {
         vdm_DataIPCInq(p,ref t_ype);
      }

      public static void DataIPCSetSwap(IntPtr p,int s_wap) {
         vdm_DataIPCSetSwap(p, s_wap);
      }

      public static void DataIPCSetObject(IntPtr p,int t_ype,IntPtr o_bj) {
         vdm_DataIPCSetObject(p, t_ype, o_bj);
      }

      public static void DataIPCGetObject(IntPtr p,int t_ype,out IntPtr o_bj) {
         vdm_DataIPCGetObject(p, t_ype,out o_bj);
      }

      public static void DataIPCSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_DataIPCSetMode(p, m_ode, f_lag);
      }

      public static void DataIPCSetConvention(IntPtr p,long c_onvention) {
         vdm_DataIPCSetConvention(p, c_onvention);
      }

      public static void DataIPCSetStatus(IntPtr p,int s_tatus) {
         vdm_DataIPCSetStatus(p, s_tatus);
      }

      public static void DataIPCSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_DataIPCSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void DataIPCGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_DataIPCGetConnect(p,out c_onnect);
      }

      public static void DataIPCGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentities) {
         vdm_DataIPCGetNumEntities(p, e_ntitytype,ref n_umentities);
      }

      public static void DataIPCGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_DataIPCGetLibrary(p,out l_ibrary);
      }

      public static void DataIPCGetInteger(IntPtr p,int t_ype,ref int i_param) {
         vdm_DataIPCGetInteger(p, t_ype,ref i_param);
      }

      public static void DataIPCGetString(IntPtr p,int t_ype,StringBuilder c_param) {
         vdm_DataIPCGetString(p, t_ype, c_param);
      }

      public static void DataIPCNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_DataIPCNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void DataIPCPushContainer(IntPtr p,StringBuilder n_ame) {
         vdm_DataIPCPushContainer(p, n_ame);
      }

      public static void DataIPCPopContainer(IntPtr p) {
         vdm_DataIPCPopContainer(p);
      }

      public static void DataIPCStartServer(IntPtr p) {
         vdm_DataIPCStartServer(p);
      }

      public static void DataIPCStopServer(IntPtr p) {
         vdm_DataIPCStopServer(p);
      }

      public static void DataIPCOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_DataIPCOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void DataIPCReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_DataIPCReadDataset(p, i_dst,ref b_uff);
      }

      public static void DataIPCReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uff,long [] l_ptr) {
         vdm_DataIPCReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uff, l_ptr);
      }

      public static void DataIPCClose(IntPtr p) {
         vdm_DataIPCClose(p);
      }

      public static void DataIPCAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_DataIPCAppend(p, f_ilename, t_ype);
      }

      public static void DataIPCSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_DataIPCSetString(p, t_ype, c_value);
      }

      public static void DataIPCDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_DataIPCDataFun(p, d_atafun);
      }

      public static void DataIPCSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject) {
         vdm_DataIPCSetFunction(p, f_unctype, f_unction, o_bject);
      }

      public static void DataIPCSetMonitorFunction(IntPtr p,VDataIPCMonitorFunc f_unction,IntPtr o_bject) {
         vdm_DataIPCSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void DataIPCSetReadFunction(IntPtr p,VDataIPCReadFunc f_unction,IntPtr o_bject) {
         vdm_DataIPCSetReadFunction(p, f_unction, o_bject);
      }

      public static void DataIPCSetWriteFunction(IntPtr p,VDataIPCWriteFunc f_unction,IntPtr o_bject) {
         vdm_DataIPCSetWriteFunction(p, f_unction, o_bject);
      }

      public static void DataIPCAbort(IntPtr p) {
         vdm_DataIPCAbort(p);
      }

      public static void DataIPCLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_DataIPCLibDataset(p, o_per, i_dst);
      }

      public static void DataIPCUpdate(IntPtr p) {
         vdm_DataIPCUpdate(p);
      }

      public static void DataIPCDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_DataIPCDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void DataIPCInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_DataIPCInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void DataIPCNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_DataIPCNumDatasets(p,ref n_umdatasets);
      }

      public static void DataIPCWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_DataIPCWriteDataset(p, i_dst,ref b_uff);
      }

      public static void DataIPCDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att) {
         vdm_DataIPCDefAttribute(p, i_dst, n_ame, l_ength, t_ype,ref i_att);
      }

      public static void DataIPCInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_DataIPCInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void DataIPCSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_DataIPCSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void DataIPCGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_DataIPCGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void DataIPCNumAttributes(IntPtr p,int i_dst,ref int n_att) {
         vdm_DataIPCNumAttributes(p, i_dst,ref n_att);
      }

      public static void DataIPCUser(IntPtr p,int n_chars,StringBuilder c_hars,int n_ints,int [] i_nts,int n_floats,float [] f_loats,int n_doubles,double [] d_oubles) {
         vdm_DataIPCUser(p, n_chars, c_hars, n_ints, i_nts, n_floats, f_loats, n_doubles, d_oubles);
      }

      public const int DATASET_MAXNAME = 256;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_DatasetBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_DatasetError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetDef(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetInq(IntPtr p,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetInqi(IntPtr p,StringBuilder n_ame,ref int l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetNRow(IntPtr p,ref int n_row);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetNCol(IntPtr p,ref int n_col);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetNCol(IntPtr p,int n_col);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetLRec(IntPtr p,long l_rec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetLRec(IntPtr p,ref long l_rec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetLReci(IntPtr p,ref int l_rec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetDTyp(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetDTyp(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetType(IntPtr p,int d_stype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetType(IntPtr p,ref int d_stype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetAddAttribute(IntPtr p,IntPtr a_ttribute);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetNumAttributes(IntPtr p,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetAttribute(IntPtr p,int i_att,out IntPtr a_ttribute);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetRedef(IntPtr p,long l_rec,int n_row,int n_col);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetRename(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSearchAttribute(IntPtr p,StringBuilder n_ame,int m_ax,ref int i_atts,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetDecode(IntPtr p,StringBuilder n_ame,ref int i_d1,ref int i_d2,ref int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetEntType(IntPtr p,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetResType(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSect(IntPtr p,ref int s_ect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetHist(IntPtr p,ref int h_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetCplx(IntPtr p,ref int c_plx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetQual(IntPtr p,ref int n_qua,int [] i_qua,StringBuilder c_qua);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetQualVal(IntPtr p,ref int n_qua,int [] i_qua,int [] d_typ,int [] i_val,float [] f_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetQualStrings(IntPtr p,int i_qlr,StringBuilder n_ame,StringBuilder c_ontents);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetCAux(IntPtr p,StringBuilder c_aux);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetResult(IntPtr p,StringBuilder r_oot,ref int t_ype,ref int h_ist,ref int n_qua,int [] i_qua,StringBuilder c_qua,ref int c_plx,StringBuilder c_aux,ref int s_ect,ref int e_nttype,ref int s_ubtype,ref int i_d1,ref int i_d2,ref int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetDataType(IntPtr p,StringBuilder a_ndata,ref int d_atatypeFIX);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetContents(IntPtr p,StringBuilder a_ncont);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetModel(IntPtr p,StringBuilder m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetDescription(IntPtr p,StringBuilder d_escription);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetComplx(IntPtr p,ref int c_plx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetDimensions(IntPtr p,StringBuilder d_imensions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetInt(IntPtr p,int n_int,int i_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetInt(IntPtr p,int n_int,ref int i_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetObj(IntPtr p,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetObj(IntPtr p,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetEndObj(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetSetLib(IntPtr p,IntPtr l_ib);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetLib(IntPtr p,out IntPtr l_ib);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetEndLib(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetStreamNum(IntPtr p,ref int n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetStreamSave(IntPtr p,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetStreamLoad(IntPtr p,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DatasetGetMetadata(IntPtr p,IntPtr m_etadata);

      public static IntPtr DatasetBegin() {
         return vdm_DatasetBegin();
      }

      public static void DatasetEnd(IntPtr p) {
         vdm_DatasetEnd(p);
      }

      public static int DatasetError(IntPtr p) {
         return vdm_DatasetError(p);
      }

      public static void DatasetDef(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype) {
         vdm_DatasetDef(p, n_ame, l_rec, n_row, n_col, t_ype);
      }

      public static void DatasetInq(IntPtr p,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_DatasetInq(p, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void DatasetInqi(IntPtr p,StringBuilder n_ame,ref int l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_DatasetInqi(p, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void DatasetGetNRow(IntPtr p,ref int n_row) {
         vdm_DatasetGetNRow(p,ref n_row);
      }

      public static void DatasetGetNCol(IntPtr p,ref int n_col) {
         vdm_DatasetGetNCol(p,ref n_col);
      }

      public static void DatasetSetNCol(IntPtr p,int n_col) {
         vdm_DatasetSetNCol(p, n_col);
      }

      public static void DatasetSetLRec(IntPtr p,long l_rec) {
         vdm_DatasetSetLRec(p, l_rec);
      }

      public static void DatasetGetLRec(IntPtr p,ref long l_rec) {
         vdm_DatasetGetLRec(p,ref l_rec);
      }

      public static void DatasetGetLReci(IntPtr p,ref int l_rec) {
         vdm_DatasetGetLReci(p,ref l_rec);
      }

      public static void DatasetSetDTyp(IntPtr p,int t_ype) {
         vdm_DatasetSetDTyp(p, t_ype);
      }

      public static void DatasetGetDTyp(IntPtr p,ref int t_ype) {
         vdm_DatasetGetDTyp(p,ref t_ype);
      }

      public static void DatasetSetType(IntPtr p,int d_stype) {
         vdm_DatasetSetType(p, d_stype);
      }

      public static void DatasetGetType(IntPtr p,ref int d_stype) {
         vdm_DatasetGetType(p,ref d_stype);
      }

      public static void DatasetAddAttribute(IntPtr p,IntPtr a_ttribute) {
         vdm_DatasetAddAttribute(p, a_ttribute);
      }

      public static void DatasetGetNumAttributes(IntPtr p,ref int n_umattributes) {
         vdm_DatasetGetNumAttributes(p,ref n_umattributes);
      }

      public static void DatasetGetAttribute(IntPtr p,int i_att,out IntPtr a_ttribute) {
         vdm_DatasetGetAttribute(p, i_att,out a_ttribute);
      }

      public static void DatasetRedef(IntPtr p,long l_rec,int n_row,int n_col) {
         vdm_DatasetRedef(p, l_rec, n_row, n_col);
      }

      public static void DatasetRename(IntPtr p,StringBuilder n_ame) {
         vdm_DatasetRename(p, n_ame);
      }

      public static void DatasetGetName(IntPtr p,StringBuilder n_ame) {
         vdm_DatasetGetName(p, n_ame);
      }

      public static void DatasetSearchAttribute(IntPtr p,StringBuilder n_ame,int m_ax,ref int i_atts,ref int n_um) {
         vdm_DatasetSearchAttribute(p, n_ame, m_ax,ref i_atts,ref n_um);
      }

      public static void DatasetDecode(IntPtr p,StringBuilder n_ame,ref int i_d1,ref int i_d2,ref int i_d3) {
         vdm_DatasetDecode(p, n_ame,ref i_d1,ref i_d2,ref i_d3);
      }

      public static void DatasetIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3) {
         vdm_DatasetIds(p,ref i_d1,ref i_d2,ref i_d3);
      }

      public static void DatasetEntType(IntPtr p,ref int e_nttype,ref int s_ubtype) {
         vdm_DatasetEntType(p,ref e_nttype,ref s_ubtype);
      }

      public static void DatasetResType(IntPtr p,ref int t_ype) {
         vdm_DatasetResType(p,ref t_ype);
      }

      public static void DatasetSect(IntPtr p,ref int s_ect) {
         vdm_DatasetSect(p,ref s_ect);
      }

      public static void DatasetHist(IntPtr p,ref int h_ist) {
         vdm_DatasetHist(p,ref h_ist);
      }

      public static void DatasetCplx(IntPtr p,ref int c_plx) {
         vdm_DatasetCplx(p,ref c_plx);
      }

      public static void DatasetQual(IntPtr p,ref int n_qua,int [] i_qua,StringBuilder c_qua) {
         vdm_DatasetQual(p,ref n_qua, i_qua, c_qua);
      }

      public static void DatasetQualVal(IntPtr p,ref int n_qua,int [] i_qua,int [] d_typ,int [] i_val,float [] f_val) {
         vdm_DatasetQualVal(p,ref n_qua, i_qua, d_typ, i_val, f_val);
      }

      public static void DatasetQualStrings(IntPtr p,int i_qlr,StringBuilder n_ame,StringBuilder c_ontents) {
         vdm_DatasetQualStrings(p, i_qlr, n_ame, c_ontents);
      }

      public static void DatasetCAux(IntPtr p,StringBuilder c_aux) {
         vdm_DatasetCAux(p, c_aux);
      }

      public static void DatasetResult(IntPtr p,StringBuilder r_oot,ref int t_ype,ref int h_ist,ref int n_qua,int [] i_qua,StringBuilder c_qua,ref int c_plx,StringBuilder c_aux,ref int s_ect,ref int e_nttype,ref int s_ubtype,ref int i_d1,ref int i_d2,ref int i_d3) {
         vdm_DatasetResult(p, r_oot,ref t_ype,ref h_ist,ref n_qua, i_qua, c_qua,ref c_plx, c_aux,ref s_ect,ref e_nttype,ref s_ubtype,ref i_d1,ref i_d2,ref i_d3);
      }

      public static void DatasetDataType(IntPtr p,StringBuilder a_ndata,ref int d_atatypeFIX) {
         vdm_DatasetDataType(p, a_ndata,ref d_atatypeFIX);
      }

      public static void DatasetContents(IntPtr p,StringBuilder a_ncont) {
         vdm_DatasetContents(p, a_ncont);
      }

      public static void DatasetModel(IntPtr p,StringBuilder m_odel) {
         vdm_DatasetModel(p, m_odel);
      }

      public static void DatasetDescription(IntPtr p,StringBuilder d_escription) {
         vdm_DatasetDescription(p, d_escription);
      }

      public static void DatasetComplx(IntPtr p,ref int c_plx) {
         vdm_DatasetComplx(p,ref c_plx);
      }

      public static void DatasetDimensions(IntPtr p,StringBuilder d_imensions) {
         vdm_DatasetDimensions(p, d_imensions);
      }

      public static void DatasetSetInt(IntPtr p,int n_int,int i_val) {
         vdm_DatasetSetInt(p, n_int, i_val);
      }

      public static void DatasetGetInt(IntPtr p,int n_int,ref int i_val) {
         vdm_DatasetGetInt(p, n_int,ref i_val);
      }

      public static void DatasetSetObj(IntPtr p,IntPtr o_bj) {
         vdm_DatasetSetObj(p, o_bj);
      }

      public static void DatasetGetObj(IntPtr p,out IntPtr o_bj) {
         vdm_DatasetGetObj(p,out o_bj);
      }

      public static void DatasetEndObj(IntPtr p,Vfunc1 f_unction) {
         vdm_DatasetEndObj(p, f_unction);
      }

      public static void DatasetSetLib(IntPtr p,IntPtr l_ib) {
         vdm_DatasetSetLib(p, l_ib);
      }

      public static void DatasetGetLib(IntPtr p,out IntPtr l_ib) {
         vdm_DatasetGetLib(p,out l_ib);
      }

      public static void DatasetEndLib(IntPtr p,Vfunc1 f_unction) {
         vdm_DatasetEndLib(p, f_unction);
      }

      public static void DatasetStreamNum(IntPtr p,ref int n_bytes) {
         vdm_DatasetStreamNum(p,ref n_bytes);
      }

      public static void DatasetStreamSave(IntPtr p,ref IntPtr d_ata) {
         vdm_DatasetStreamSave(p,ref d_ata);
      }

      public static void DatasetStreamLoad(IntPtr p,ref IntPtr d_ata) {
         vdm_DatasetStreamLoad(p,ref d_ata);
      }

      public static void DatasetCopy(IntPtr p,IntPtr f_romp) {
         vdm_DatasetCopy(p, f_romp);
      }

      public static void DatasetPrint(IntPtr p) {
         vdm_DatasetPrint(p);
      }

      public static void DatasetGetMetadata(IntPtr p,IntPtr m_etadata) {
         vdm_DatasetGetMetadata(p, m_etadata);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_ElemSectBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ElemSectError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectDef(IntPtr p,int n_umel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectInq(IntPtr p,ref int n_umel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectSetPtr(IntPtr p,ref int s_ect,ref int l_ayp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectNumSection(IntPtr p,int i_n,ref int n_umsec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ElemSectLayPos(IntPtr p,int i_n,int i_sec,ref int i_pos,ref int i_lay);

      public static IntPtr ElemSectBegin() {
         return vdm_ElemSectBegin();
      }

      public static void ElemSectEnd(IntPtr p) {
         vdm_ElemSectEnd(p);
      }

      public static int ElemSectError(IntPtr p) {
         return vdm_ElemSectError(p);
      }

      public static void ElemSectDef(IntPtr p,int n_umel) {
         vdm_ElemSectDef(p, n_umel);
      }

      public static void ElemSectInq(IntPtr p,ref int n_umel) {
         vdm_ElemSectInq(p,ref n_umel);
      }

      public static void ElemSectSetPtr(IntPtr p,ref int s_ect,ref int l_ayp) {
         vdm_ElemSectSetPtr(p,ref s_ect,ref l_ayp);
      }

      public static void ElemSectNumSection(IntPtr p,int i_n,ref int n_umsec) {
         vdm_ElemSectNumSection(p, i_n,ref n_umsec);
      }

      public static void ElemSectLayPos(IntPtr p,int i_n,int i_sec,ref int i_pos,ref int i_lay) {
         vdm_ElemSectLayPos(p, i_n, i_sec,ref i_pos,ref i_lay);
      }

      public const int LIB_NATIVE = 1;
      public const int LIB_GENERIC = 5;
      public const int LIB_PDA = 6;
      public const int LIB_D3DLSTC = 7;
      public const int LIB_ABAODB = 8;
      public const int LIB_ABAFILBIN = 9;
      public const int LIB_NASOUTPUT2 = 10;
      public const int LIB_ABAINPUT = 13;
      public const int LIB_SDRC = 14;
      public const int LIB_PAMDAISY = 15;
      public const int LIB_ANSYSRESULT = 16;
      public const int LIB_MECHANICASTUDY = 17;
      public const int LIB_NASBULKDATA = 18;
      public const int LIB_PATNEUTRAL = 20;
      public const int LIB_FLUENT = 21;
      public const int LIB_ANSYSINPUT = 22;
      public const int LIB_MOLDFLOW = 23;
      public const int LIB_MAXLIBTYPE = 28;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_LibraryBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_LibraryError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryDef(IntPtr p,StringBuilder p_ath,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryInq(IntPtr p,StringBuilder p_ath,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryTOC(IntPtr p,StringBuilder n_ame,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryInsertDataset(IntPtr p,int i_dx,IntPtr d_ataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryAddDataset(IntPtr p,IntPtr d_ataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryGetNumDatasets(IntPtr p,ref int n_umdataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryGetDataset(IntPtr p,int i_dst,out IntPtr d_ataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibrarySearchDataset(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryProcessLinkIndex(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryMaxIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryDatasetEndObj(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryDatasetEndLib(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LibraryDatasetGetObj(IntPtr p,int i_dst,out IntPtr o_bj);

      public static IntPtr LibraryBegin() {
         return vdm_LibraryBegin();
      }

      public static void LibraryEnd(IntPtr p) {
         vdm_LibraryEnd(p);
      }

      public static int LibraryError(IntPtr p) {
         return vdm_LibraryError(p);
      }

      public static void LibraryDef(IntPtr p,StringBuilder p_ath,int t_ype) {
         vdm_LibraryDef(p, p_ath, t_ype);
      }

      public static void LibraryInq(IntPtr p,StringBuilder p_ath,ref int t_ype) {
         vdm_LibraryInq(p, p_ath,ref t_ype);
      }

      public static void LibraryPrint(IntPtr p) {
         vdm_LibraryPrint(p);
      }

      public static void LibraryTOC(IntPtr p,StringBuilder n_ame,int f_lag) {
         vdm_LibraryTOC(p, n_ame, f_lag);
      }

      public static void LibraryInsertDataset(IntPtr p,int i_dx,IntPtr d_ataset) {
         vdm_LibraryInsertDataset(p, i_dx, d_ataset);
      }

      public static void LibraryAddDataset(IntPtr p,IntPtr d_ataset) {
         vdm_LibraryAddDataset(p, d_ataset);
      }

      public static void LibraryGetNumDatasets(IntPtr p,ref int n_umdataset) {
         vdm_LibraryGetNumDatasets(p,ref n_umdataset);
      }

      public static void LibraryGetDataset(IntPtr p,int i_dst,out IntPtr d_ataset) {
         vdm_LibraryGetDataset(p, i_dst,out d_ataset);
      }

      public static void LibrarySearchDataset(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um) {
         vdm_LibrarySearchDataset(p, n_ame, m_ax, i_dsts,ref n_um);
      }

      public static void LibraryProcessLinkIndex(IntPtr p) {
         vdm_LibraryProcessLinkIndex(p);
      }

      public static void LibraryMaxIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3) {
         vdm_LibraryMaxIds(p,ref i_d1,ref i_d2,ref i_d3);
      }

      public static void LibraryDatasetEndObj(IntPtr p,Vfunc1 f_unction) {
         vdm_LibraryDatasetEndObj(p, f_unction);
      }

      public static void LibraryDatasetEndLib(IntPtr p,Vfunc1 f_unction) {
         vdm_LibraryDatasetEndLib(p, f_unction);
      }

      public static void LibraryDatasetGetObj(IntPtr p,int i_dst,out IntPtr o_bj) {
         vdm_LibraryDatasetGetObj(p, i_dst,out o_bj);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_LManBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManOpenFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManCreateFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManAppend(IntPtr p,StringBuilder f_ile);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_LManGetNumStates(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSearchState(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_LManError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManExport(IntPtr p,StringBuilder n_ame,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManImport(IntPtr p,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManTOC(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManList(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManMakeLibDataset(IntPtr p,StringBuilder d_sname,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSaveModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadState(IntPtr p,IntPtr s_tate,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadStateFromName(IntPtr p,StringBuilder d_atasetname,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManGetStateNames(IntPtr p,out IntPtr s_tateNames);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadIdTranState(IntPtr p,IntPtr i_dtran,IntPtr s_tate,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadIdTranStateFromName(IntPtr p,IntPtr i_dtran,StringBuilder d_atasetname,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSaveState(IntPtr p,IntPtr s_tate,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadHistoryFromName(IntPtr p,StringBuilder d_atasetname,IntPtr h_istory);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSaveHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManLoadRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSaveRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManGetMetadata(IntPtr p,int s_tateId,IntPtr m_etadata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManGetMetadataFromName(IntPtr p,StringBuilder s_tateName,IntPtr m_etadata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSaveFile(IntPtr p,StringBuilder f_ilename,IntPtr o_ptions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSearchLibraryMesh(IntPtr p,int m_ax,int [] i_dsts,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManSetLibraryMesh(IntPtr p,int o_peration,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_LManInquire(IntPtr p,StringBuilder p_ath,ref int t_ype);

      public static IntPtr LManBegin() {
         return vdm_LManBegin();
      }

      public static void LManOpenFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions) {
         vdm_LManOpenFile(p, f_ile, o_ptions);
      }

      public static void LManCreateFile(IntPtr p,StringBuilder f_ile,IntPtr o_ptions) {
         vdm_LManCreateFile(p, f_ile, o_ptions);
      }

      public static void LManAppend(IntPtr p,StringBuilder f_ile) {
         vdm_LManAppend(p, f_ile);
      }

      public static int LManGetNumStates(IntPtr p) {
         return vdm_LManGetNumStates(p);
      }

      public static void LManSearchState(IntPtr p,StringBuilder n_ame,int m_ax,int [] i_dsts,ref int n_um) {
         vdm_LManSearchState(p, n_ame, m_ax, i_dsts,ref n_um);
      }

      public static void LManEnd(IntPtr p) {
         vdm_LManEnd(p);
      }

      public static void LManCloseFile(IntPtr p) {
         vdm_LManCloseFile(p);
      }

      public static int LManError(IntPtr p) {
         return vdm_LManError(p);
      }

      public static void LManSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vdm_LManSetObject(p, o_bjecttype, o_bject);
      }

      public static void LManGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vdm_LManGetObject(p, o_bjecttype,out o_bject);
      }

      public static void LManSetParami(IntPtr p,int t_ype,int i_param) {
         vdm_LManSetParami(p, t_ype, i_param);
      }

      public static void LManExport(IntPtr p,StringBuilder n_ame,StringBuilder p_ath) {
         vdm_LManExport(p, n_ame, p_ath);
      }

      public static void LManImport(IntPtr p,StringBuilder p_ath) {
         vdm_LManImport(p, p_ath);
      }

      public static void LManTOC(IntPtr p,StringBuilder n_ame) {
         vdm_LManTOC(p, n_ame);
      }

      public static void LManList(IntPtr p,StringBuilder n_ame) {
         vdm_LManList(p, n_ame);
      }

      public static void LManLoadModel(IntPtr p,IntPtr m_odel) {
         vdm_LManLoadModel(p, m_odel);
      }

      public static void LManMakeLibDataset(IntPtr p,StringBuilder d_sname,ref int i_dst) {
         vdm_LManMakeLibDataset(p, d_sname,ref i_dst);
      }

      public static void LManSaveModel(IntPtr p,IntPtr m_odel) {
         vdm_LManSaveModel(p, m_odel);
      }

      public static void LManLoadState(IntPtr p,IntPtr s_tate,IntPtr r_prop) {
         vdm_LManLoadState(p, s_tate, r_prop);
      }

      public static void LManLoadStateFromName(IntPtr p,StringBuilder d_atasetname,IntPtr s_tate) {
         vdm_LManLoadStateFromName(p, d_atasetname, s_tate);
      }

      public static void LManGetStateNames(IntPtr p,out IntPtr s_tateNames) {
         vdm_LManGetStateNames(p,out s_tateNames);
      }

      public static void LManLoadIdTranState(IntPtr p,IntPtr i_dtran,IntPtr s_tate,IntPtr r_prop) {
         vdm_LManLoadIdTranState(p, i_dtran, s_tate, r_prop);
      }

      public static void LManLoadIdTranStateFromName(IntPtr p,IntPtr i_dtran,StringBuilder d_atasetname,IntPtr s_tate) {
         vdm_LManLoadIdTranStateFromName(p, i_dtran, d_atasetname, s_tate);
      }

      public static void LManSaveState(IntPtr p,IntPtr s_tate,IntPtr r_prop) {
         vdm_LManSaveState(p, s_tate, r_prop);
      }

      public static void LManLoadHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop) {
         vdm_LManLoadHistory(p, h_istory, r_prop);
      }

      public static void LManLoadHistoryFromName(IntPtr p,StringBuilder d_atasetname,IntPtr h_istory) {
         vdm_LManLoadHistoryFromName(p, d_atasetname, h_istory);
      }

      public static void LManSaveHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop) {
         vdm_LManSaveHistory(p, h_istory, r_prop);
      }

      public static void LManLoadRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop) {
         vdm_LManLoadRedMat(p, r_edmat, r_prop);
      }

      public static void LManSaveRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop) {
         vdm_LManSaveRedMat(p, r_edmat, r_prop);
      }

      public static void LManGetMetadata(IntPtr p,int s_tateId,IntPtr m_etadata) {
         vdm_LManGetMetadata(p, s_tateId, m_etadata);
      }

      public static void LManGetMetadataFromName(IntPtr p,StringBuilder s_tateName,IntPtr m_etadata) {
         vdm_LManGetMetadataFromName(p, s_tateName, m_etadata);
      }

      public static void LManSaveFile(IntPtr p,StringBuilder f_ilename,IntPtr o_ptions) {
         vdm_LManSaveFile(p, f_ilename, o_ptions);
      }

      public static void LManGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_LManGetConnect(p,out c_onnect);
      }

      public static void LManSearchLibraryMesh(IntPtr p,int m_ax,int [] i_dsts,ref int n_um) {
         vdm_LManSearchLibraryMesh(p, m_ax, i_dsts,ref n_um);
      }

      public static void LManSetLibraryMesh(IntPtr p,int o_peration,int i_ndex) {
         vdm_LManSetLibraryMesh(p, o_peration, i_ndex);
      }

      public static void LManInquire(IntPtr p,StringBuilder p_ath,ref int t_ype) {
         vdm_LManInquire(p, p_ath,ref t_ype);
      }

      public const int LMAN_NONZERO = 0;
      public const int LMAN_INDEXSTART = 1;
      public const int LMAN_INDEXSTOP = 2;
      public const int LMAN_VERBOSE = 3;
      public const int LMAN_SAVEMODEL_PRE = 5;
      public const int LMAN_FOCUSCONN = 6;
      public const int LMAN_NODATAVAL = 7;
      public const int LMAN_RETAINCONNECT = 8;
      public const int LMAN_LOADRESULT_PRE = 9;
      public const int LMAN_LOADMODEL_LOAD = 11;
      public const int LMAN_LOADMODEL_REST = 12;
      public const int LMAN_LOADMODEL_ELEMGEOM = 13;
      public const int LMAN_LOADMODEL_SET = 14;
      public const int LMAN_SAVEMODEL_CASE = 15;
      public const int LMAN_SAVERESULT_CASE = 16;
      public const int LMAN_SAVERESULT_PRE = 17;
      public const int LMAN_LOADMODEL_PRE = 18;
      public const int LMAN_CHECK = 19;
      public const int LMAN_LOADMODEL_STORE = 20;
      public const int LMAN_MESH_LIB_PUSH = 1;
      public const int LMAN_MESH_LIB_POP = 2;
      public const int LMAN_MESH_LIB_TOP = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_OptionsBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_OptionsError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsAddConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsSetMode(IntPtr p,int m_ode,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsSetFileFormat(IntPtr p,int f_ileFormat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsGetModes(IntPtr p,out IntPtr m_odes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsGetConventions(IntPtr p,ref long c_onventions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsGetFileFormat(IntPtr p,ref int f_ileFormat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OptionsEnd(IntPtr p);

      public static IntPtr OptionsBegin() {
         return vdm_OptionsBegin();
      }

      public static int OptionsError(IntPtr p) {
         return vdm_OptionsError(p);
      }

      public static void OptionsAddConvention(IntPtr p,long c_onvention) {
         vdm_OptionsAddConvention(p, c_onvention);
      }

      public static void OptionsSetMode(IntPtr p,int m_ode,int v_alue) {
         vdm_OptionsSetMode(p, m_ode, v_alue);
      }

      public static void OptionsSetFileFormat(IntPtr p,int f_ileFormat) {
         vdm_OptionsSetFileFormat(p, f_ileFormat);
      }

      public static void OptionsGetModes(IntPtr p,out IntPtr m_odes) {
         vdm_OptionsGetModes(p,out m_odes);
      }

      public static void OptionsGetConventions(IntPtr p,ref long c_onventions) {
         vdm_OptionsGetConventions(p,ref c_onventions);
      }

      public static void OptionsGetFileFormat(IntPtr p,ref int f_ileFormat) {
         vdm_OptionsGetFileFormat(p,ref f_ileFormat);
      }

      public static void OptionsEnd(IntPtr p) {
         vdm_OptionsEnd(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_SettingsBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SettingsEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SettingsRegisterPluginSettings(IntPtr p,StringBuilder p_luginNameId,IntPtr p_luginSettings);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SettingsGetPluginSettings(IntPtr p,StringBuilder p_luginNameId,out IntPtr p_luginSettings);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SettingsGetAllPluginIdentifiers(IntPtr p,IntPtr p_luginNameIds);

      public static IntPtr SettingsBegin() {
         return vdm_SettingsBegin();
      }

      public static void SettingsEnd(IntPtr p) {
         vdm_SettingsEnd(p);
      }

      public static void SettingsRegisterPluginSettings(IntPtr p,StringBuilder p_luginNameId,IntPtr p_luginSettings) {
         vdm_SettingsRegisterPluginSettings(p, p_luginNameId, p_luginSettings);
      }

      public static void SettingsGetPluginSettings(IntPtr p,StringBuilder p_luginNameId,out IntPtr p_luginSettings) {
         vdm_SettingsGetPluginSettings(p, p_luginNameId,out p_luginSettings);
      }

      public static void SettingsGetAllPluginIdentifiers(IntPtr p,IntPtr p_luginNameIds) {
         vdm_SettingsGetAllPluginIdentifiers(p, p_luginNameIds);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_UnrecognizedDataBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_UnrecognizedDataAddLine(IntPtr p,int l_ineNumber,StringBuilder l_ine);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_UnrecognizedDataInq(IntPtr p,ref int c_ount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_UnrecognizedDataGetLineNumbers(IntPtr p,out IntPtr l_ineNumbers);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_UnrecognizedDataGetLines(IntPtr p,out IntPtr l_ines);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_UnrecognizedDataEnd(IntPtr p);

      public static IntPtr UnrecognizedDataBegin() {
         return vdm_UnrecognizedDataBegin();
      }

      public static void UnrecognizedDataAddLine(IntPtr p,int l_ineNumber,StringBuilder l_ine) {
         vdm_UnrecognizedDataAddLine(p, l_ineNumber, l_ine);
      }

      public static void UnrecognizedDataInq(IntPtr p,ref int c_ount) {
         vdm_UnrecognizedDataInq(p,ref c_ount);
      }

      public static void UnrecognizedDataGetLineNumbers(IntPtr p,out IntPtr l_ineNumbers) {
         vdm_UnrecognizedDataGetLineNumbers(p,out l_ineNumbers);
      }

      public static void UnrecognizedDataGetLines(IntPtr p,out IntPtr l_ines) {
         vdm_UnrecognizedDataGetLines(p,out l_ines);
      }

      public static void UnrecognizedDataEnd(IntPtr p) {
         vdm_UnrecognizedDataEnd(p);
      }

      public const int VDM_NATIVE = 1;
      public const int VDM_PLOT3D_GRID = 2;
      public const int VDM_PLOT3D_SOLUTION = 3;
      public const int VDM_PATRAN_RESULT = 4;
      public const int VDM_GENERIC = 5;
      public const int VDM_PDA = 6;
      public const int VDM_LSTC_STATE = 7;
      public const int VDM_ABAQUS_ODB = 8;
      public const int VDM_ABAQUS_FILBIN = 9;
      public const int VDM_ABAQUS_FIL = 9;
      public const int VDM_NASTRAN_OUTPUT2 = 10;
      public const int VDM_STL = 11;
      public const int VDM_STLBIN = 12;
      public const int VDM_ABAQUS_INPUT = 13;
      public const int VDM_SDRC_UNIVERSAL = 14;
      public const int VDM_PAM_DAISY = 15;
      public const int VDM_ANSYS_RESULT = 16;
      public const int VDM_MECHANICA_STUDY = 17;
      public const int VDM_NASTRAN_BULKDATA = 18;
      public const int VDM_FDI_NEUTRAL = 19;
      public const int VDM_PAT_NEUTRAL = 20;
      public const int VDM_PATRAN_NEUTRAL = 20;
      public const int VDM_FLUENT_MESH = 21;
      public const int VDM_ANSYS_INPUT = 22;
      public const int VDM_TECPLOT = 23;
      public const int VDM_HYPERMESH_ASCII = 24;
      public const int VDM_LSTC_INPUT = 25;
      public const int VDM_CGNS = 26;
      public const int VDM_MARC_POST = 27;
      public const int VDM_ENSIGHT = 28;
      public const int VDM_STARCCM = 29;
      public const int VDM_MECHANICA_FNF = 30;
      public const int VDM_LSTC_HISTORY = 32;
      public const int VDM_NASTRAN_XDB = 33;
      public const int VDM_NASTRAN_H5 = 34;
      public const int VDM_POLYFLOW = 36;
      public const int VDM_FEMAP_NEUTRAL = 37;
      public const int VDM_AUTODYN_RES = 38;
      public const int VDM_PAM_ERF = 39;
      public const int VDM_OPENFOAM = 40;
      public const int VDM_OBJ = 41;
      public const int VDM_COMSOL_SECTION = 43;
      public const int VDM_H3D = 44;
      public const int VDM_LSTC_STATEFEMZIP = 45;
      public const int VDM_PAM_INPUT = 46;
      public const int VDM_CFX_RESULT = 47;
      public const int VDM_GMV = 48;
      public const int VDM_PERMAS_POST = 49;
      public const int VDM_VTK_LEGACY = 50;
      public const int VDM_SAMCEF = 51;
      public const int VDM_AFLR = 52;
      public const int VDM_ADAMS = 53;
      public const int VDM_NATIVE_HDF5 = 54;
      public const int VDM_MEMORY = 55;
      public const int VDM_COMSOL_MPH = 56;
      public const int VDM_COMSOL_MPHBIN = 57;
      public const int VDM_MARC_INPUT = 58;
      public const int VDM_ANSYS_DPF = 59;
      public const int VDM_PLUGIN = 60;
      public const int VDM_VTK_VTU = 61;
      public const int VDM_MAXTYPE = 62;
      public const int VDM_STATUS_OLD = 1;
      public const int VDM_STATUS_NEW = 2;
      public const int VDM_STATUS_ADD = 3;
      public const int VDM_ONFILE = 1000;
      public const int VDM_VIRTUAL = 1001;
      public const int VDM_ELEMNODEPNTR = 1002;
      public const int VDM_ELEMNODESIZE = 1003;
      public const int VDM_ELEMNODE = 1004;
      public const int VDM_ELEMTYPE = 1005;
      public const int VDM_ELEMTYPEINT = 1007;
      public const int VDM_ELEMTYPEHOL = 1008;
      public const int VDM_EID = 1009;
      public const int VDM_MID = 1010;
      public const int VDM_PID = 1011;
      public const int VDM_PARAMINT = 1012;
      public const int VDM_PARAMHOL = 1013;
      public const int VDM_ERSCID = 1014;
      public const int VDM_COLORELEM = 1015;
      public const int VDM_PARTIDELEM = 1016;
      public const int VDM_ORIENTELEM = 1017;
      public const int VDM_ERSVEC = 1018;
      public const int VDM_SETELEM = 1019;
      public const int VDM_X = 1020;
      public const int VDM_SETNODE = 1021;
      public const int VDM_NID = 1022;
      public const int VDM_NODETYPE = 1023;
      public const int VDM_SETELEMENT = 1024;
      public const int VDM_DOFCID = 1025;
      public const int VDM_DOF = 1026;
      public const int VDM_COLORNODE = 1027;
      public const int VDM_PARTIDNODE = 1028;
      public const int VDM_COLORMAP = 1029;
      public const int VDM_ELEMTOPO = 1030;
      public const int VDM_ELEMSPEC = 1031;
      public const int VDM_ELEMTWOD = 1032;
      public const int VDM_PARAMIJK = 1033;
      public const int VDM_IBLANKNODE = 1034;
      public const int VDM_ELEMTYPEEXT = 1035;
      public const int VDM_ELEMSIZE = 1036;
      public const int VDM_ELEMSHAP = 1037;
      public const int VDM_ELEMMIJK = 1038;
      public const int VDM_ELEMTECH = 1039;
      public const int VDM_DIRCOS = 1040;
      public const int VDM_ELEMEIPS = 1041;
      public const int VDM_CREFID = 1042;
      public const int VDM_ELEMSEID = 1043;
      public const int VDM_ELEMSYMMID = 1044;
      public const int VDM_THICKNESS = 1050;
      public const int VDM_NORMAL = 1051;
      public const int VDM_OFFSETVEC = 1052;
      public const int VDM_FIBERBOT = 1053;
      public const int VDM_FIBERTOP = 1054;
      public const int VDM_OFFSET = 1055;
      public const int VDM_DOMAINNODE = 1058;
      public const int VDM_DOMAINELEM = 1059;
      public const int VDM_EMTCID = 1060;
      public const int VDM_EMTVEC = 1061;
      public const int VDM_EMTFLAG = 1062;
      public const int VDM_ENDATOPO = 1063;
      public const int VDM_ENDBTOPO = 1064;
      public const int VDM_ENDACON = 1065;
      public const int VDM_ENDBCON = 1066;
      public const int VDM_ENDAVEC = 1067;
      public const int VDM_ENDBVEC = 1068;
      public const int VDM_NODEGEOVERT = 1069;
      public const int VDM_NODEGEOEDGE = 1070;
      public const int VDM_NODEGEOFACE = 1071;
      public const int VDM_NODEGEOBODY = 1072;
      public const int VDM_ELEMGEOEDGE = 1073;
      public const int VDM_ELEMGEOFACE = 1074;
      public const int VDM_ELEMGEOBODY = 1075;
      public const int VDM_ELEMEDGEGEOEDGE = 1076;
      public const int VDM_ELEMFACEGEOFACE = 1077;
      public const int VDM_PINFLAGSELEM = 1078;
      public const int VDM_MISCID = 101079;
      public const int VDM_MISCID0 = 101079;
      public const int VDM_MISCID1 = 101080;
      public const int VDM_MISCID2 = 101081;
      public const int VDM_MISCID3 = 101082;
      public const int VDM_MISCID4 = 101083;
      public const int VDM_MISCID5 = 101084;
      public const int VDM_MISCID6 = 101085;
      public const int VDM_MISCID7 = 101086;
      public const int VDM_MISCID8 = 101087;
      public const int VDM_MISCIDELEMFACE = 101088;
      public const int VDM_MISCID0ELEMFACE = 101088;
      public const int VDM_MISCID1ELEMFACE = 101089;
      public const int VDM_MISCID2ELEMFACE = 101090;
      public const int VDM_MISCID3ELEMFACE = 101091;
      public const int VDM_MISCID4ELEMFACE = 101092;
      public const int VDM_MISCID5ELEMFACE = 101093;
      public const int VDM_MISCID6ELEMFACE = 101094;
      public const int VDM_MISCID7ELEMFACE = 101095;
      public const int VDM_MISCID8ELEMFACE = 101096;
      public const int VDM_MISCIDELEMEDGE = 101097;
      public const int VDM_MISCID0ELEMEDGE = 101097;
      public const int VDM_MISCID1ELEMEDGE = 101098;
      public const int VDM_MISCID2ELEMEDGE = 101099;
      public const int VDM_MISCID3ELEMEDGE = 101100;
      public const int VDM_MISCID4ELEMEDGE = 101101;
      public const int VDM_MISCID5ELEMEDGE = 101092;
      public const int VDM_MISCID6ELEMEDGE = 101103;
      public const int VDM_MISCID7ELEMEDGE = 101104;
      public const int VDM_MISCID8ELEMEDGE = 101105;
      public const int VDM_PARTNAMEID = 1080;
      public const int VDM_PARTNAME = 1081;
      public const int VDM_ELEMTANGEDGE = 1082;
      public const int VDM_ELEMTANGEDGEINDX = 1083;
      public const int VDM_ELEMNORMFACE = 1085;
      public const int VDM_ELEMNORMFACEINDX = 1086;
      public const int VDM_PARTIJKID = 1088;
      public const int VDM_PARTIJK = 1089;
      public const int VDM_IDE = 1090;
      public const int VDM_IDN = 1091;
      public const int VDM_CSYS = 1100;
      public const int VDM_CSYSID = 1101;
      public const int VDM_CSYSTYPE = 1102;
      public const int VDM_UNITSTYPE = 1103;
      public const int VDM_UNITS = 1104;
      public const int VDM_REST = 1110;
      public const int VDM_RESTDISP = 1111;
      public const int VDM_RESTINDX = 1112;
      public const int VDM_RESTTAG = 1113;
      public const int VDM_RESTMAST = 1114;
      public const int VDM_RESTNAME = 1115;
      public const int VDM_RESTELEM = 1116;
      public const int VDM_RESTELEMDISP = 1117;
      public const int VDM_RESTELEMINDX = 1118;
      public const int VDM_RESTELEMTAG = 1119;
      public const int VDM_RESTTID = 1120;
      public const int VDM_RESTDOT = 1121;
      public const int VDM_LOADACCL = 1123;
      public const int VDM_LOADNAME = 1124;
      public const int VDM_LOADTEMPNODETID = 1125;
      public const int VDM_LOADHEATNODETID = 1126;
      public const int VDM_LOADCSCANODETID = 1127;
      public const int VDM_LOADCVECNODETID = 1128;
      public const int VDM_LOADTID = 1129;
      public const int VDM_MATL = 1130;
      public const int VDM_MATLID = 1131;
      public const int VDM_MATLTYPE = 1132;
      public const int VDM_MATLINT = 1133;
      public const int VDM_MATLFLAG = 1135;
      public const int VDM_MATLNAME = 1136;
      public const int VDM_LOADTEMPNODE = 1140;
      public const int VDM_LOADHEATNODE = 1141;
      public const int VDM_LOADCSCANODE = 1142;
      public const int VDM_LOADCVECNODE = 1143;
      public const int VDM_LOAD = 1144;
      public const int VDM_LOADTEMPNODEINDX = 1145;
      public const int VDM_LOADHEATNODEINDX = 1146;
      public const int VDM_LOADCSCANODEINDX = 1147;
      public const int VDM_LOADCVECNODEINDX = 1148;
      public const int VDM_LOADINDX = 1149;
      public const int VDM_PROP = 1150;
      public const int VDM_PROPID = 1151;
      public const int VDM_PROPTYPE = 1152;
      public const int VDM_PROPINT = 1153;
      public const int VDM_PROPHOL = 1154;
      public const int VDM_PROPFLAG = 1155;
      public const int VDM_PROPNAME = 1156;
      public const int VDM_SOLN = 1160;
      public const int VDM_SOLNID = 1161;
      public const int VDM_SOLNTYPE = 1162;
      public const int VDM_SOLNINT = 1163;
      public const int VDM_SOLNHOL = 1164;
      public const int VDM_SOLNFLAG = 1165;
      public const int VDM_MPCNODE = 1170;
      public const int VDM_MPCCOMP = 1171;
      public const int VDM_MPCCOEF = 1172;
      public const int VDM_MPCSIZE = 1173;
      public const int VDM_MPCRHS = 1174;
      public const int VDM_MPCELEM = 1175;
      public const int VDM_MPCTYPE = 1176;
      public const int VDM_FUNC = 1180;
      public const int VDM_FUNCID = 1181;
      public const int VDM_FUNCTYPE = 1182;
      public const int VDM_FUNCINT = 1183;
      public const int VDM_INITDOF = 1190;
      public const int VDM_INITDOFINDX = 1191;
      public const int VDM_INITDOFTAG = 1192;
      public const int VDM_INITDOFDOT = 1193;
      public const int VDM_INITDOFDOTINDX = 1194;
      public const int VDM_INITDOFDOTTAG = 1195;
      public const int VDM_LOADPRESEDGE = 1200;
      public const int VDM_LOADPRESEDGEINDX = 1201;
      public const int VDM_LOADPRESEDGETID = 1202;
      public const int VDM_LOADPRESFACE = 1205;
      public const int VDM_LOADPRESFACEINDX = 1206;
      public const int VDM_LOADPRESFACETID = 1207;
      public const int VDM_LOADFLUXEDGE = 1210;
      public const int VDM_LOADFLUXEDGEINDX = 1211;
      public const int VDM_LOADFLUXEDGETID = 1212;
      public const int VDM_LOADFLUXFACE = 1215;
      public const int VDM_LOADFLUXFACEINDX = 1216;
      public const int VDM_LOADFLUXFACETID = 1217;
      public const int VDM_LOADTRACEDGE = 1220;
      public const int VDM_LOADTRACEDGEINDX = 1221;
      public const int VDM_LOADTRACEDGETID = 1222;
      public const int VDM_LOADTRACFACE = 1225;
      public const int VDM_LOADTRACFACEINDX = 1226;
      public const int VDM_LOADTRACFACETID = 1227;
      public const int VDM_LOADHEATELEM = 1230;
      public const int VDM_LOADHEATELEMINDX = 1231;
      public const int VDM_LOADHEATELEMTID = 1232;
      public const int VDM_LOADACCLELEM = 1234;
      public const int VDM_LOADACCLELEMINDX = 1235;
      public const int VDM_LOADACCLELEMTID = 1236;
      public const int VDM_LOADCONVEDGE = 1240;
      public const int VDM_LOADCONVEDGEINDX = 1241;
      public const int VDM_LOADCONVEDGETID = 1242;
      public const int VDM_LOADCONVFACE = 1245;
      public const int VDM_LOADCONVFACEINDX = 1246;
      public const int VDM_LOADCONVFACETID = 1247;
      public const int VDM_LOADDMOMEDGE = 1250;
      public const int VDM_LOADDMOMEDGEINDX = 1251;
      public const int VDM_LOADDMOMEDGETID = 1252;
      public const int VDM_LOADDMOMFACE = 1255;
      public const int VDM_LOADDMOMFACEINDX = 1256;
      public const int VDM_LOADDMOMFACETID = 1257;
      public const int VDM_LOADDSCAEDGE = 1260;
      public const int VDM_LOADDSCAEDGEINDX = 1261;
      public const int VDM_LOADDSCAEDGETID = 1262;
      public const int VDM_LOADDSCAFACE = 1265;
      public const int VDM_LOADDSCAFACEINDX = 1266;
      public const int VDM_LOADDSCAFACETID = 1267;
      public const int VDM_LOADDVECEDGE = 1270;
      public const int VDM_LOADDVECEDGEINDX = 1271;
      public const int VDM_LOADDVECEDGETID = 1272;
      public const int VDM_LOADDVECFACE = 1275;
      public const int VDM_LOADDVECFACEINDX = 1276;
      public const int VDM_LOADDVECFACETID = 1277;
      public const int VDM_LOADHRADEDGE = 1290;
      public const int VDM_LOADHRADEDGEINDX = 1291;
      public const int VDM_LOADHRADEDGETID = 1292;
      public const int VDM_LOADHRADFACE = 1295;
      public const int VDM_LOADHRADFACEINDX = 1296;
      public const int VDM_LOADHRADFACETID = 1297;
      public const int VDM_GLOB = 1280;
      public const int VDM_GLOBINT = 1283;
      public const int VDM_GLOBHOL = 1284;
      public const int VDM_GLOBFLAG = 1285;
      public const int VDM_CONT = 1300;
      public const int VDM_CONTFLAG = 1301;
      public const int VDM_CONTINT = 1302;
      public const int VDM_CONTTYPE = 1310;
      public const int VDM_CONTMASTASURF = 1323;
      public const int VDM_CONTMASTELEMFACE = 1324;
      public const int VDM_CONTMASTELEMEDGE = 1325;
      public const int VDM_CONTSLAVAREA = 1333;
      public const int VDM_CONTSLAVNODE = 1334;
      public const int VDM_CONTSLAVELEMFACE = 1335;
      public const int VDM_CONTSLAVELEMEDGE = 1336;
      public const int VDM_CONVERSIONTIME = 1337;
      public const int VDM_CONVERSIONSTATUS = 1338;
      public const int VDM_EFFECTIVEMASSSUMMARY = 1339;
      public const int VDM_EFFECTIVEMASS = 1340;
      public const int VDM_PARTICIPATIONFACTOR = 1341;
      public const int VDM_MASSFRACTION = 1342;
      public const int VDM_POLYUNIQUEFACE = 1343;
      public const int VDM_LOADHRADABSORPEDGE = 1350;
      public const int VDM_LOADHRADABSORPEDGEINDX = 1351;
      public const int VDM_LOADHRADABSORPEDGETID = 1352;
      public const int VDM_LOADHRADABSORPFACE = 1355;
      public const int VDM_LOADHRADABSORPFACEINDX = 1356;
      public const int VDM_LOADHRADABSORPFACETID = 1357;
      public const int VDM_OUTELEM = 2000;
      public const int VDM_OUTELEMNODEAVGD = 2001;
      public const int VDM_OUTELEMNODEFREE = 2002;
      public const int VDM_OUTHISTELEM = 2100;
      public const int VDM_OUTELEMINDEX = 2101;
      public const int VDM_OUTNODE = 3000;
      public const int VDM_OUTHISTNODE = 3100;
      public const int VDM_OUTNODEINDEX = 3101;
      public const int VDM_OUTELEMNODE = 4000;
      public const int VDM_OUTHISTELEMNODE = 4003;
      public const int VDM_OUTHISTMODEL = 5100;
      public const int VDM_OUTHISTTIME = 5101;
      public const int VDM_OUTHISTSTEP = 5102;
      public const int VDM_OUTNODECOMP = 5103;
      public const int VDM_OUTELEMCOMP = 5104;
      public const int VDM_OUTELEMSECT = 5105;
      public const int VDM_OUTELEMLAYS = 5106;
      public const int VDM_OUTENTDOF = 5107;
      public const int VDM_OUTMODE = 5108;
      public const int VDM_OUTMODEINDEX = 5109;
      public const int VDM_OUTHISTMODE = 5110;
      public const int VDM_OUTPANEL = 5111;
      public const int VDM_OUTPANELINDEX = 5112;
      public const int VDM_OUTHISTPANEL = 5113;
      public const int VDM_OUTEDGEINDEX = 5114;
      public const int VDM_OUTFACEINDEX = 5115;
      public const int VDM_OUTELEMEIP = 5116;
      public const int VDM_OUTMATSIZE = 5117;
      public const int VDM_OUTMATEQUN = 5118;
      public const int VDM_ASURFTYPE = 6000;
      public const int VDM_ASURFSEGS = 6001;
      public const int VDM_ASURFSEGTYPE = 6002;
      public const int VDM_ASURFPNTS = 6003;
      public const int VDM_ASURFDBL = 6004;
      public const int VDM_ASURFNAME = 6005;
      public const int VDM_ASURFFACET = 6006;
      public const int VDM_ASURFFACETTYPE = 6007;
      public const int VDM_ASURFTRIM = 6008;
      public const int VDM_ASURFTRIMNUM = 6009;
      public const int VDM_ASURFNURBS = 6010;
      public const int VDM_ASURFNURBSNUM = 6011;
      public const int VDM_ASURFNURBSTRIM = 6012;
      public const int VDM_RBODY = 6100;
      public const int VDM_RBODYFLAG = 6101;
      public const int VDM_RBODYINT = 6102;
      public const int VDM_RBODYTYPE = 6103;
      public const int VDM_RBODYASURF = 6104;
      public const int VDM_RBODYELEMFACE = 6105;
      public const int VDM_RBODYELEMEDGE = 6106;
      public const int VDM_RBODYELEM = 6107;
      public const int VDM_RBODYNODE = 6108;
      public const int VDM_RBODYNODETYPE = 6109;
      public const int VDM_DATASETCOLS_UNDEF = -1;
      public const int VDM_DATASETCOLS_UNSUP = -2;
      public const int VDM_NODATAVALMODE = 1;
      public const int VDM_RETAINCONNECTMODE = 2;
      public const int VDM_ABAODBNOCLOSEMODE = 3;
      public const int VDM_INCLUDEERRORMODE = 4;
      public const int VDM_ZLIBCOMPRESSMODE = 5;
      public const int VDM_ANSYS_PARTIDNUMBERINGMODE = 6;
      public const int VDM_CGNS_FAMILYSPECIFIED = 7;
      public const int VDM_CGNS_MULTIZONESEXPORT = 8;
      public const int VDM_CGNS_ZONEFACECENTER = 9;
      public const int VDM_DPFLIB_ROTATETOGLOBALFRAME = 10;
      public const int VDM_DPFLIB_CHECKVERSION = 11;
      public const int VDM_WRITEFORMAT = 12;
      public const int VDM_HEADERPRECISION = 13;
      public const int VDM_DPFLIB_ASSUMELICENSING = 14;
      public const int VDM_DEFERREDREADMODE = 15;
      public const int VDM_CGNS_POLYASELEMENTASSOC = 16;
      public const int VDM_ABAODBAUTOUPDATE = 17;
      public const uint VDM_NODATAVAL = 4294967295;
      public const int EXPORT_ASCII = 0;
      public const int EXPORT_BINARY = 1;
      public const int HEADERUINT32 = 0;
      public const int HEADERUINT64 = 1;
      public const int VDM_PHASE = 1;
      public const int VDM_SOURCE = 2;
      public const int VDM_SOURCE_SIZE = 256;
      public const int VDM_PHASE_UNDEFINED = 0;
      public const int VDM_PHASE_OPENMODEL = 1;
      public const int VDM_PHASE_OPENMODELCOMPLETE = 2;
      public const int VDM_PHASE_OPENRESULT = 3;
      public const int VDM_OPENPLEX = -1;
      public const int VDM_IDS_OFFSET = 0;
      public const int VDM_IDS_BASE = 1;
      public const int VDM_IDS_ABSOLUTE = 2;
      public const long VDM_CONVENTION_DEF = 0;
      public const long VDM_CONVENTION_NOINTERLAMINAR = 1;
      public const long VDM_CONVENTION_DOUBLERESULT = 2;
      public const long VDM_CONVENTION_SPARSE = 4;
      public const long VDM_CONVENTION_ALTPART = 8;
      public const long VDM_CONVENTION_DOUBLE = 16;
      public const long VDM_CONVENTION_STRESSINVARIANT = 32;
      public const long VDM_CONVENTION_PSHELLTHICK = 64;
      public const long VDM_CONVENTION_DATASET32 = 128;
      public const long VDM_CONVENTION_NOINTPT = 256;
      public const long VDM_CONVENTION_NOSETS = 512;
      public const long VDM_CONVENTION_STARCD = 1024;
      public const long VDM_CONVENTION_EIP = 2048;
      public const long VDM_CONVENTION_ELEMCENT = 4096;
      public const long VDM_CONVENTION_FRAMEZERO = 8192;
      public const long VDM_CONVENTION_NOINTERNALSETS = 16384;
      public const long VDM_CONVENTION_NODEBC = 32768;
      public const long VDM_CONVENTION_WALLINTER = 65536;
      public const long VDM_CONVENTION_CONVERTPOLY = 131072;
      public const long VDM_CONVENTION_NOEQUIV = 262144;
      public const long VDM_CONVENTION_UNIRESULTTYPE = 524288;
      public const long VDM_CONVENTION_COMPLEX = 1048576;
      public const long VDM_CONVENTION_LINEAREXTRAP = 2097152;
      public const long VDM_CONVENTION_SECTNUM = 4194304;
      public const long VDM_CONVENTION_NOPARINTER = 8388608;
      public const long VDM_CONVENTION_NOCOMMENT = 16777216;
      public const long VDM_CONVENTION_CGNSLEGACYEXPORT = 33554432;
      public const long VDM_CONVENTION_NOHISTORYOUTPUT = 67108864;
      public const long VDM_CONVENTION_MAPCYLINDRICALALTTOVECTOR = 134217728;
      public const long VDM_CONVENTION_CGNSALWAYSMIXED = 268435456;
      public const long VDM_CONVENTION_ONLYSCALARSHEARPANELSTRESS = 536870912;
      public const long VDM_CONVENTION_CGNSLEGACYCELLZONENUMBER = 1073741824;
      public const long VDM_CONVENTION_CGNSSINGLENGONSECTION2D = 2147483648;
      public const long VDM_CONVENTION_NOFIELDOUTPUT = 4294967296;
      public const long VDM_CONVENTION_ORIGINAL_GASKET_STATUS = 8589934592;
      public const int VDM_LIBDATASET_PUSH = 1;
      public const int VDM_LIBDATASET_POP = 2;
      public const int VDM_LIBDATASET_TOP = 3;
      public const int VDM_ATTRIBUTE = 6000;
      public const int VDM_DATASET = 6001;
      public const int VDM_LIBRARY = 6002;
      public const int VDM_DATAFUN = 6003;
      public const int VDM_LMAN = 6004;
      public const int VDM_DATAIPC = 6005;
      public const int VDM_ELEMSECT = 6006;
      public const int VDM_UNRECOGNIZEDDATA = 6007;
      public const int VDM_OPENFOAM_ETC_PATH = 1;
      public const int VDM_LIBRARY_PATH = 2;
      public const int VDM_ABALIB_UPGRADEODBNAME = 3;
      public const int ANSLIB_PARTIDUSINGLEGACYMETHOD = 0;
      public const int ANSLIB_PARTIDUSINGSECNUM = 1;
      public const int ANSLIB_PARTIDUSINGREALCONSTREF_NUMBER = 2;
      public const int ANSLIB_PARTIDUSINGELEM_TYPE = 3;

      public const int WRITER_RESTYPE = 1;
      public const int WRITER_RESFILE = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_WriterBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_WriterError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterDef(IntPtr p,StringBuilder f_ilePath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterGetParami(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterSetParamc(IntPtr p,int p_type,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterGetParamc(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterWriteRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterWriteHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterOpen(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_WriterClose(IntPtr p);

      public static IntPtr WriterBegin() {
         return vdm_WriterBegin();
      }

      public static void WriterEnd(IntPtr p) {
         vdm_WriterEnd(p);
      }

      public static int WriterError(IntPtr p) {
         return vdm_WriterError(p);
      }

      public static void WriterDef(IntPtr p,StringBuilder f_ilePath) {
         vdm_WriterDef(p, f_ilePath);
      }

      public static void WriterSetParami(IntPtr p,int p_type,int i_param) {
         vdm_WriterSetParami(p, p_type, i_param);
      }

      public static void WriterGetParami(IntPtr p,int t_ype,ref int i_param) {
         vdm_WriterGetParami(p, t_ype,ref i_param);
      }

      public static void WriterSetParamc(IntPtr p,int p_type,StringBuilder c_param) {
         vdm_WriterSetParamc(p, p_type, c_param);
      }

      public static void WriterGetParamc(IntPtr p,int t_ype,StringBuilder c_param) {
         vdm_WriterGetParamc(p, t_ype, c_param);
      }

      public static void WriterWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop) {
         vdm_WriterWriteState(p, s_tate, r_prop);
      }

      public static void WriterWriteRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop) {
         vdm_WriterWriteRedMat(p, r_edmat, r_prop);
      }

      public static void WriterWriteHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop) {
         vdm_WriterWriteHistory(p, h_istory, r_prop);
      }

      public static void WriterWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_WriterWriteModel(p, m_odel);
      }

      public static void WriterOpen(IntPtr p) {
         vdm_WriterOpen(p);
      }

      public static void WriterClose(IntPtr p) {
         vdm_WriterClose(p);
      }

      public const int ABAFIL_NUMRESTYPES = 32;
      public const int ABAFIL_NUMUNREC = -1;
      public const int ABAFIL_LINENUM = -2;
      public const int ABAFIL_UNRECTYPE = -3;
      public const int ABAFIL_UNRECCARD = -4;
      public const int ABAFIL_UNRECKEYWORD = -5;
      public const int ABAFIL_UNRECPARAM = -6;
      public const int ABAFIL_UNRECPARAMVAL = -7;
      public const int ABAFIL_UNRECDATALINE = -8;
      public const int ABAFIL_UNRECFILE = -9;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_ABAFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ABAFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetMonitorFunction(IntPtr p,VABAFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABAFilPrintUnrecognizedData(IntPtr p);

      public static IntPtr ABAFilBegin() {
         return vdm_ABAFilBegin();
      }

      public static void ABAFilEnd(IntPtr p) {
         vdm_ABAFilEnd(p);
      }

      public static int ABAFilError(IntPtr p) {
         return vdm_ABAFilError(p);
      }

      public static void ABAFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_ABAFilSetMode(p, m_ode, f_lag);
      }

      public static void ABAFilSetConvention(IntPtr p,long c_onvention) {
         vdm_ABAFilSetConvention(p, c_onvention);
      }

      public static void ABAFilSetStatus(IntPtr p,int s_tatus) {
         vdm_ABAFilSetStatus(p, s_tatus);
      }

      public static void ABAFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_ABAFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void ABAFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_ABAFilGetConnect(p,out c_onnect);
      }

      public static void ABAFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_ABAFilSetConnect(p, c_onnect);
      }

      public static void ABAFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_ABAFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void ABAFilSetMonitorFunction(IntPtr p,VABAFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_ABAFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void ABAFilAbort(IntPtr p) {
         vdm_ABAFilAbort(p);
      }

      public static void ABAFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_ABAFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void ABAFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_ABAFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void ABAFilClose(IntPtr p) {
         vdm_ABAFilClose(p);
      }

      public static void ABAFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_ABAFilAppend(p, f_ilename, t_ype);
      }

      public static void ABAFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_ABAFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void ABAFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_ABAFilGetLibrary(p,out l_ibrary);
      }

      public static void ABAFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_ABAFilNumDatasets(p,ref n_umdatasets);
      }

      public static void ABAFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_ABAFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void ABAFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_ABAFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void ABAFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_ABAFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void ABAFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_ABAFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void ABAFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_ABAFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void ABAFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_ABAFilGetInteger(p, t_ype,ref i_value);
      }

      public static void ABAFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ABAFilGetString(p, t_ype, c_value);
      }

      public static void ABAFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_ABAFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void ABAFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_ABAFilWriteModel(p, m_odel);
      }

      public static void ABAFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_ABAFilLibDataset(p, o_per, i_dst);
      }

      public static void ABAFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ABAFilSetString(p, t_ype, c_value);
      }

      public static void ABAFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_ABAFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void ABAFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_ABAFilDataFun(p, d_atafun);
      }

      public static void ABAFilPrintUnrecognizedData(IntPtr p) {
         vdm_ABAFilPrintUnrecognizedData(p);
      }

      public const int ABALIB_UPGRADEODB = 1;
      public const int ABALIB_UPGRADEODBAUTO = 2;
      public const int ABA_OUTELEM_WHOLE = -2;
      public const int ABA_OUTELEMNODE_WHOLE = -3;
      public const int ABA_ROTANGELEM = -4;
      public const int ABA_ROTANGELEMNODE = -5;
      public const int ABA_ROTANGELEMEIP = -6;
      public const int ABA_OUTELEM_FACE = -7;
      public const int ABA_OUTELEM_EDGE = -8;
      public const double ABA_SML = 1.0e-20;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_ABALibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ABALibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetInteger(IntPtr p,int t_ype,ref int p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetMonitorFunction(IntPtr p,VABALibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ABALibMonitor(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibUpgradeOdb(IntPtr p,StringBuilder o_dbpath,StringBuilder n_ewodbpath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibSect(IntPtr p,IntPtr d_ataset,int e_nfl);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ABALibTerm(IntPtr p);

      public static IntPtr ABALibBegin() {
         return vdm_ABALibBegin();
      }

      public static void ABALibEnd(IntPtr p) {
         vdm_ABALibEnd(p);
      }

      public static int ABALibError(IntPtr p) {
         return vdm_ABALibError(p);
      }

      public static void ABALibGetInteger(IntPtr p,int t_ype,ref int p_aram) {
         vdm_ABALibGetInteger(p, t_ype,ref p_aram);
      }

      public static void ABALibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ABALibGetString(p, t_ype, c_value);
      }

      public static void ABALibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_ABALibSetMode(p, m_ode, f_lag);
      }

      public static void ABALibSetConvention(IntPtr p,long c_onvention) {
         vdm_ABALibSetConvention(p, c_onvention);
      }

      public static void ABALibSetStatus(IntPtr p,int s_tatus) {
         vdm_ABALibSetStatus(p, s_tatus);
      }

      public static void ABALibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_ABALibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void ABALibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_ABALibGetConnect(p,out c_onnect);
      }

      public static void ABALibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_ABALibSetConnect(p, c_onnect);
      }

      public static void ABALibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_ABALibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void ABALibSetMonitorFunction(IntPtr p,VABALibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_ABALibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void ABALibAbort(IntPtr p) {
         vdm_ABALibAbort(p);
      }

      public static int ABALibMonitor(IntPtr p) {
         return vdm_ABALibMonitor(p);
      }

      public static void ABALibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_ABALibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void ABALibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_ABALibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void ABALibClose(IntPtr p) {
         vdm_ABALibClose(p);
      }

      public static void ABALibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_ABALibAppend(p, f_ilename, t_ype);
      }

      public static void ABALibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_ABALibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void ABALibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_ABALibGetLibrary(p,out l_ibrary);
      }

      public static void ABALibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_ABALibNumDatasets(p,ref n_umdatasets);
      }

      public static void ABALibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_ABALibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void ABALibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_ABALibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void ABALibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_ABALibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void ABALibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_ABALibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void ABALibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_ABALibReadDataset(p, i_dst,ref b_uf);
      }

      public static void ABALibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_ABALibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void ABALibUpgradeOdb(IntPtr p,StringBuilder o_dbpath,StringBuilder n_ewodbpath) {
         vdm_ABALibUpgradeOdb(p, o_dbpath, n_ewodbpath);
      }

      public static void ABALibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_ABALibLibDataset(p, o_per, i_dst);
      }

      public static void ABALibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ABALibSetString(p, t_ype, c_value);
      }

      public static void ABALibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_ABALibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void ABALibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_ABALibDataFun(p, d_atafun);
      }

      public static void ABALibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_ABALibWriteModel(p, m_odel);
      }

      public static void ABALibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_ABALibWriteState(p, r_prop, s_tate);
      }

      public static void ABALibSect(IntPtr p,IntPtr d_ataset,int e_nfl) {
         vdm_ABALibSect(p, d_ataset, e_nfl);
      }

      public static void ABALibTerm(IntPtr p) {
         vdm_ABALibTerm(p);
      }

      public const int ABA_NUMELEMTYPES = 226;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_AdamsLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_AdamsLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetMonitorFunction(IntPtr p,VAdamsLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AdamsLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr AdamsLibBegin() {
         return vdm_AdamsLibBegin();
      }

      public static void AdamsLibEnd(IntPtr p) {
         vdm_AdamsLibEnd(p);
      }

      public static int AdamsLibError(IntPtr p) {
         return vdm_AdamsLibError(p);
      }

      public static void AdamsLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_AdamsLibSetMode(p, m_ode, f_lag);
      }

      public static void AdamsLibSetConvention(IntPtr p,long c_onvention) {
         vdm_AdamsLibSetConvention(p, c_onvention);
      }

      public static void AdamsLibSetStatus(IntPtr p,int s_tatus) {
         vdm_AdamsLibSetStatus(p, s_tatus);
      }

      public static void AdamsLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_AdamsLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void AdamsLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_AdamsLibGetConnect(p,out c_onnect);
      }

      public static void AdamsLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_AdamsLibSetConnect(p, c_onnect);
      }

      public static void AdamsLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_AdamsLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void AdamsLibSetMonitorFunction(IntPtr p,VAdamsLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_AdamsLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void AdamsLibAbort(IntPtr p) {
         vdm_AdamsLibAbort(p);
      }

      public static void AdamsLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_AdamsLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void AdamsLibClose(IntPtr p) {
         vdm_AdamsLibClose(p);
      }

      public static void AdamsLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_AdamsLibAppend(p, f_ilename, t_ype);
      }

      public static void AdamsLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_AdamsLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void AdamsLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_AdamsLibGetLibrary(p,out l_ibrary);
      }

      public static void AdamsLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_AdamsLibNumDatasets(p,ref n_umdatasets);
      }

      public static void AdamsLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_AdamsLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void AdamsLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_AdamsLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void AdamsLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_AdamsLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void AdamsLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_AdamsLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void AdamsLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_AdamsLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void AdamsLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_AdamsLibLibDataset(p, o_per, i_dst);
      }

      public static void AdamsLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AdamsLibSetString(p, t_ype, c_value);
      }

      public static void AdamsLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_AdamsLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void AdamsLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_AdamsLibDataFun(p, d_atafun);
      }

      public static void AdamsLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_AdamsLibGetInteger(p, t_ype,ref i_value);
      }

      public static void AdamsLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AdamsLibGetString(p, t_ype, c_value);
      }

      public static void AdamsLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_AdamsLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_AFLRFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_AFLRFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetMonitorFunction(IntPtr p,VAFLRFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AFLRFilDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr AFLRFilBegin() {
         return vdm_AFLRFilBegin();
      }

      public static void AFLRFilEnd(IntPtr p) {
         vdm_AFLRFilEnd(p);
      }

      public static int AFLRFilError(IntPtr p) {
         return vdm_AFLRFilError(p);
      }

      public static void AFLRFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_AFLRFilGetInteger(p, t_ype,ref i_value);
      }

      public static void AFLRFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AFLRFilGetString(p, t_ype, c_value);
      }

      public static void AFLRFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_AFLRFilSetMode(p, m_ode, f_lag);
      }

      public static void AFLRFilSetConvention(IntPtr p,long c_onvention) {
         vdm_AFLRFilSetConvention(p, c_onvention);
      }

      public static void AFLRFilSetStatus(IntPtr p,int s_tatus) {
         vdm_AFLRFilSetStatus(p, s_tatus);
      }

      public static void AFLRFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_AFLRFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void AFLRFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_AFLRFilGetConnect(p,out c_onnect);
      }

      public static void AFLRFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_AFLRFilSetConnect(p, c_onnect);
      }

      public static void AFLRFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_AFLRFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void AFLRFilSetMonitorFunction(IntPtr p,VAFLRFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_AFLRFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void AFLRFilAbort(IntPtr p) {
         vdm_AFLRFilAbort(p);
      }

      public static void AFLRFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_AFLRFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void AFLRFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_AFLRFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void AFLRFilClose(IntPtr p) {
         vdm_AFLRFilClose(p);
      }

      public static void AFLRFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_AFLRFilAppend(p, f_ilename, t_ype);
      }

      public static void AFLRFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_AFLRFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void AFLRFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_AFLRFilGetLibrary(p,out l_ibrary);
      }

      public static void AFLRFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_AFLRFilNumDatasets(p,ref n_umdatasets);
      }

      public static void AFLRFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_AFLRFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void AFLRFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_AFLRFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void AFLRFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_AFLRFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void AFLRFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_AFLRFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void AFLRFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_AFLRFilReadDataset(p, i_dst,ref b_uff);
      }

      public static void AFLRFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_AFLRFilLibDataset(p, o_per, i_dst);
      }

      public static void AFLRFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_AFLRFilWriteModel(p, m_odel);
      }

      public static void AFLRFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AFLRFilSetString(p, t_ype, c_value);
      }

      public static void AFLRFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_AFLRFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void AFLRFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_AFLRFilDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_H3DLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_H3DLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetMonitorFunction(IntPtr p,VH3DLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_H3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr H3DLibBegin() {
         return vdm_H3DLibBegin();
      }

      public static void H3DLibEnd(IntPtr p) {
         vdm_H3DLibEnd(p);
      }

      public static int H3DLibError(IntPtr p) {
         return vdm_H3DLibError(p);
      }

      public static void H3DLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_H3DLibSetMode(p, m_ode, f_lag);
      }

      public static void H3DLibSetConvention(IntPtr p,long c_onvention) {
         vdm_H3DLibSetConvention(p, c_onvention);
      }

      public static void H3DLibSetStatus(IntPtr p,int s_tatus) {
         vdm_H3DLibSetStatus(p, s_tatus);
      }

      public static void H3DLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_H3DLibSetConnect(p, c_onnect);
      }

      public static void H3DLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_H3DLibGetConnect(p,out c_onnect);
      }

      public static void H3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_H3DLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void H3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_H3DLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void H3DLibSetMonitorFunction(IntPtr p,VH3DLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_H3DLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void H3DLibAbort(IntPtr p) {
         vdm_H3DLibAbort(p);
      }

      public static void H3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_H3DLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void H3DLibClose(IntPtr p) {
         vdm_H3DLibClose(p);
      }

      public static void H3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_H3DLibAppend(p, f_ilename, t_ype);
      }

      public static void H3DLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_H3DLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void H3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_H3DLibGetLibrary(p,out l_ibrary);
      }

      public static void H3DLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_H3DLibNumDatasets(p,ref n_umdatasets);
      }

      public static void H3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_H3DLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void H3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_H3DLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void H3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_H3DLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void H3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_H3DLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void H3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_H3DLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void H3DLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_H3DLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void H3DLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_H3DLibLibDataset(p, o_per, i_dst);
      }

      public static void H3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_H3DLibSetString(p, t_ype, c_value);
      }

      public static void H3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_H3DLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void H3DLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_H3DLibDataFun(p, d_atafun);
      }

      public static void H3DLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_H3DLibGetInteger(p, t_ype,ref i_value);
      }

      public static void H3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_H3DLibGetString(p, t_ype, c_value);
      }

      public static void H3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_H3DLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int ANSFIL_NUMRESTYPES = 12;
      public const int ANSFIL_CONTROLCARDS = 1;
      public const int ANSFIL_NUMUNREC = -1;
      public const int ANSFIL_LINENUM = -2;
      public const int ANSFIL_UNRECTYPE = -3;
      public const int ANSFIL_UNRECCARD = -4;
      public const int ANSFIL_UNRECKEYWORD = -5;
      public const int ANSFIL_UNRECFORMAT = -6;
      public const int ANSFIL_UNRECDATALINE = -7;
      public const int ANSFIL_UNRECPARAM = -8;
      public const int ANSFIL_UNRECREFER = -9;
      public const int ANSFIL_MAXSIZE = 257;
      public const int ANSFIL_MAXELEMENTNODE = 81;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_ANSFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ANSFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetMonitorFunction(IntPtr p,VANSFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSFilPrintUnrecognizedData(IntPtr p);

      public static IntPtr ANSFilBegin() {
         return vdm_ANSFilBegin();
      }

      public static void ANSFilEnd(IntPtr p) {
         vdm_ANSFilEnd(p);
      }

      public static int ANSFilError(IntPtr p) {
         return vdm_ANSFilError(p);
      }

      public static void ANSFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ANSFilGetString(p, t_ype, c_value);
      }

      public static void ANSFilSetParami(IntPtr p,int p_type,int i_param) {
         vdm_ANSFilSetParami(p, p_type, i_param);
      }

      public static void ANSFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_ANSFilSetMode(p, m_ode, f_lag);
      }

      public static void ANSFilSetConvention(IntPtr p,long c_onvention) {
         vdm_ANSFilSetConvention(p, c_onvention);
      }

      public static void ANSFilSetStatus(IntPtr p,int s_tatus) {
         vdm_ANSFilSetStatus(p, s_tatus);
      }

      public static void ANSFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_ANSFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void ANSFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_ANSFilGetConnect(p,out c_onnect);
      }

      public static void ANSFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_ANSFilSetConnect(p, c_onnect);
      }

      public static void ANSFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_ANSFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void ANSFilSetMonitorFunction(IntPtr p,VANSFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_ANSFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void ANSFilAbort(IntPtr p) {
         vdm_ANSFilAbort(p);
      }

      public static void ANSFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_ANSFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void ANSFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_ANSFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void ANSFilClose(IntPtr p) {
         vdm_ANSFilClose(p);
      }

      public static void ANSFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_ANSFilAppend(p, f_ilename, t_ype);
      }

      public static void ANSFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_ANSFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void ANSFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_ANSFilGetLibrary(p,out l_ibrary);
      }

      public static void ANSFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_ANSFilNumDatasets(p,ref n_umdatasets);
      }

      public static void ANSFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_ANSFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void ANSFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_ANSFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void ANSFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_ANSFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void ANSFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_ANSFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void ANSFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_ANSFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void ANSFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_ANSFilGetInteger(p, t_ype,ref i_value);
      }

      public static void ANSFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_ANSFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void ANSFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_ANSFilWriteModel(p, m_odel);
      }

      public static void ANSFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_ANSFilLibDataset(p, o_per, i_dst);
      }

      public static void ANSFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ANSFilSetString(p, t_ype, c_value);
      }

      public static void ANSFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_ANSFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void ANSFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_ANSFilDataFun(p, d_atafun);
      }

      public static void ANSFilPrintUnrecognizedData(IntPtr p) {
         vdm_ANSFilPrintUnrecognizedData(p);
      }

      public const int ANSLIB_SEARCH_OFF = 0;
      public const int ANSLIB_SEARCH_CDB = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_ANSLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_ANSLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetMonitorFunction(IntPtr p,VANSLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetSearch(IntPtr p,int s_earch);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetSearchPath(IntPtr p,int s_earch,StringBuilder p_athname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_ANSLibDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr ANSLibBegin() {
         return vdm_ANSLibBegin();
      }

      public static void ANSLibEnd(IntPtr p) {
         vdm_ANSLibEnd(p);
      }

      public static int ANSLibError(IntPtr p) {
         return vdm_ANSLibError(p);
      }

      public static void ANSLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_ANSLibGetInteger(p, t_ype,ref i_value);
      }

      public static void ANSLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ANSLibGetString(p, t_ype, c_value);
      }

      public static void ANSLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_ANSLibSetMode(p, m_ode, f_lag);
      }

      public static void ANSLibSetConvention(IntPtr p,long c_onvention) {
         vdm_ANSLibSetConvention(p, c_onvention);
      }

      public static void ANSLibSetStatus(IntPtr p,int s_tatus) {
         vdm_ANSLibSetStatus(p, s_tatus);
      }

      public static void ANSLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_ANSLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void ANSLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_ANSLibGetConnect(p,out c_onnect);
      }

      public static void ANSLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_ANSLibSetConnect(p, c_onnect);
      }

      public static void ANSLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_ANSLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void ANSLibSetMonitorFunction(IntPtr p,VANSLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_ANSLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void ANSLibAbort(IntPtr p) {
         vdm_ANSLibAbort(p);
      }

      public static void ANSLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_ANSLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void ANSLibSetSearch(IntPtr p,int s_earch) {
         vdm_ANSLibSetSearch(p, s_earch);
      }

      public static void ANSLibSetSearchPath(IntPtr p,int s_earch,StringBuilder p_athname) {
         vdm_ANSLibSetSearchPath(p, s_earch, p_athname);
      }

      public static void ANSLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_ANSLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void ANSLibClose(IntPtr p) {
         vdm_ANSLibClose(p);
      }

      public static void ANSLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_ANSLibAppend(p, f_ilename, t_ype);
      }

      public static void ANSLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_ANSLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void ANSLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_ANSLibGetLibrary(p,out l_ibrary);
      }

      public static void ANSLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_ANSLibNumDatasets(p,ref n_umdatasets);
      }

      public static void ANSLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_ANSLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void ANSLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_ANSLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void ANSLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_ANSLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void ANSLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_ANSLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void ANSLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_ANSLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void ANSLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_ANSLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void ANSLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_ANSLibLibDataset(p, o_per, i_dst);
      }

      public static void ANSLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_ANSLibSetString(p, t_ype, c_value);
      }

      public static void ANSLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_ANSLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void ANSLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_ANSLibDataFun(p, d_atafun);
      }

      public const int AUTODYNLIB_LIBVERSION = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_AUTODYNLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_AUTODYNLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetMonitorFunction(IntPtr p,VAUTODYNLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetVersion(IntPtr p,int i_version);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_AUTODYNLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr AUTODYNLibBegin() {
         return vdm_AUTODYNLibBegin();
      }

      public static void AUTODYNLibEnd(IntPtr p) {
         vdm_AUTODYNLibEnd(p);
      }

      public static int AUTODYNLibError(IntPtr p) {
         return vdm_AUTODYNLibError(p);
      }

      public static void AUTODYNLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_AUTODYNLibSetMode(p, m_ode, f_lag);
      }

      public static void AUTODYNLibSetConvention(IntPtr p,long c_onvention) {
         vdm_AUTODYNLibSetConvention(p, c_onvention);
      }

      public static void AUTODYNLibSetStatus(IntPtr p,int s_tatus) {
         vdm_AUTODYNLibSetStatus(p, s_tatus);
      }

      public static void AUTODYNLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_AUTODYNLibSetConnect(p, c_onnect);
      }

      public static void AUTODYNLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_AUTODYNLibGetConnect(p,out c_onnect);
      }

      public static void AUTODYNLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_AUTODYNLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void AUTODYNLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_AUTODYNLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void AUTODYNLibSetMonitorFunction(IntPtr p,VAUTODYNLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_AUTODYNLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void AUTODYNLibAbort(IntPtr p) {
         vdm_AUTODYNLibAbort(p);
      }

      public static void AUTODYNLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_AUTODYNLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void AUTODYNLibClose(IntPtr p) {
         vdm_AUTODYNLibClose(p);
      }

      public static void AUTODYNLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_AUTODYNLibAppend(p, f_ilename, t_ype);
      }

      public static void AUTODYNLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_AUTODYNLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void AUTODYNLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_AUTODYNLibGetLibrary(p,out l_ibrary);
      }

      public static void AUTODYNLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_AUTODYNLibNumDatasets(p,ref n_umdatasets);
      }

      public static void AUTODYNLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_AUTODYNLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void AUTODYNLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_AUTODYNLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void AUTODYNLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_AUTODYNLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void AUTODYNLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_AUTODYNLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void AUTODYNLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_AUTODYNLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void AUTODYNLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_AUTODYNLibLibDataset(p, o_per, i_dst);
      }

      public static void AUTODYNLibSetVersion(IntPtr p,int i_version) {
         vdm_AUTODYNLibSetVersion(p, i_version);
      }

      public static void AUTODYNLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AUTODYNLibSetString(p, t_ype, c_value);
      }

      public static void AUTODYNLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_AUTODYNLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void AUTODYNLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_AUTODYNLibDataFun(p, d_atafun);
      }

      public static void AUTODYNLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_AUTODYNLibGetInteger(p, t_ype,ref i_value);
      }

      public static void AUTODYNLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_AUTODYNLibGetString(p, t_ype, c_value);
      }

      public static void AUTODYNLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_AUTODYNLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_CFXLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_CFXLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetMonitorFunction(IntPtr p,VCFXLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CFXLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr CFXLibBegin() {
         return vdm_CFXLibBegin();
      }

      public static void CFXLibEnd(IntPtr p) {
         vdm_CFXLibEnd(p);
      }

      public static int CFXLibError(IntPtr p) {
         return vdm_CFXLibError(p);
      }

      public static void CFXLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_CFXLibSetMode(p, m_ode, f_lag);
      }

      public static void CFXLibSetConvention(IntPtr p,long c_onvention) {
         vdm_CFXLibSetConvention(p, c_onvention);
      }

      public static void CFXLibSetStatus(IntPtr p,int s_tatus) {
         vdm_CFXLibSetStatus(p, s_tatus);
      }

      public static void CFXLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_CFXLibSetConnect(p, c_onnect);
      }

      public static void CFXLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_CFXLibGetConnect(p,out c_onnect);
      }

      public static void CFXLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_CFXLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void CFXLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_CFXLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void CFXLibSetMonitorFunction(IntPtr p,VCFXLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_CFXLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void CFXLibAbort(IntPtr p) {
         vdm_CFXLibAbort(p);
      }

      public static void CFXLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_CFXLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void CFXLibClose(IntPtr p) {
         vdm_CFXLibClose(p);
      }

      public static void CFXLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_CFXLibAppend(p, f_ilename, t_ype);
      }

      public static void CFXLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_CFXLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void CFXLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_CFXLibGetLibrary(p,out l_ibrary);
      }

      public static void CFXLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_CFXLibNumDatasets(p,ref n_umdatasets);
      }

      public static void CFXLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_CFXLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void CFXLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_CFXLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void CFXLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_CFXLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void CFXLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_CFXLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void CFXLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_CFXLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void CFXLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_CFXLibLibDataset(p, o_per, i_dst);
      }

      public static void CFXLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_CFXLibSetString(p, t_ype, c_value);
      }

      public static void CFXLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_CFXLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void CFXLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_CFXLibDataFun(p, d_atafun);
      }

      public static void CFXLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_CFXLibGetInteger(p, t_ype,ref i_value);
      }

      public static void CFXLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_CFXLibGetString(p, t_ype, c_value);
      }

      public static void CFXLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_CFXLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int CGNSVLIB_SEARCH_OFF = 0;
      public const int CGNSVLIB_SEARCH_DIRNUM = 1;
      public const int CGNSVLIB_SEARCH_DIRNUMFILENUM = 2;
      public const int CGNSVLIB_SEARCH_FILENUM = 3;
      public const int CGNSVLIB_HDF5 = 1;
      public const int CGNSVLIB_ADF = 2;
      public const int MAXELEMOFFSETSIZE = 10000000;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_CGNSVLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_CGNSVLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetThreadsCount(IntPtr p,int t_hreadsCount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetMonitorFunction(IntPtr p,VCGNSVLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetSearch(IntPtr p,int s_earch);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_CGNSVLibSetWriteFileType(IntPtr p,int f_iletype);

      public static IntPtr CGNSVLibBegin() {
         return vdm_CGNSVLibBegin();
      }

      public static void CGNSVLibEnd(IntPtr p) {
         vdm_CGNSVLibEnd(p);
      }

      public static int CGNSVLibError(IntPtr p) {
         return vdm_CGNSVLibError(p);
      }

      public static void CGNSVLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_CGNSVLibSetMode(p, m_ode, f_lag);
      }

      public static void CGNSVLibSetConvention(IntPtr p,long c_onvention) {
         vdm_CGNSVLibSetConvention(p, c_onvention);
      }

      public static void CGNSVLibSetThreadsCount(IntPtr p,int t_hreadsCount) {
         vdm_CGNSVLibSetThreadsCount(p, t_hreadsCount);
      }

      public static void CGNSVLibSetStatus(IntPtr p,int s_tatus) {
         vdm_CGNSVLibSetStatus(p, s_tatus);
      }

      public static void CGNSVLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_CGNSVLibSetConnect(p, c_onnect);
      }

      public static void CGNSVLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_CGNSVLibGetConnect(p,out c_onnect);
      }

      public static void CGNSVLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_CGNSVLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void CGNSVLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_CGNSVLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void CGNSVLibSetMonitorFunction(IntPtr p,VCGNSVLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_CGNSVLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void CGNSVLibAbort(IntPtr p) {
         vdm_CGNSVLibAbort(p);
      }

      public static void CGNSVLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_CGNSVLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void CGNSVLibClose(IntPtr p) {
         vdm_CGNSVLibClose(p);
      }

      public static void CGNSVLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_CGNSVLibAppend(p, f_ilename, t_ype);
      }

      public static void CGNSVLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_CGNSVLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void CGNSVLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_CGNSVLibGetLibrary(p,out l_ibrary);
      }

      public static void CGNSVLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_CGNSVLibNumDatasets(p,ref n_umdatasets);
      }

      public static void CGNSVLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_CGNSVLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void CGNSVLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_CGNSVLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void CGNSVLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_CGNSVLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void CGNSVLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_CGNSVLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void CGNSVLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_CGNSVLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void CGNSVLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_CGNSVLibLibDataset(p, o_per, i_dst);
      }

      public static void CGNSVLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_CGNSVLibSetString(p, t_ype, c_value);
      }

      public static void CGNSVLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_CGNSVLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void CGNSVLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_CGNSVLibDataFun(p, d_atafun);
      }

      public static void CGNSVLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_CGNSVLibWriteModel(p, m_odel);
      }

      public static void CGNSVLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_CGNSVLibWriteState(p, r_prop, s_tate);
      }

      public static void CGNSVLibSetSearch(IntPtr p,int s_earch) {
         vdm_CGNSVLibSetSearch(p, s_earch);
      }

      public static void CGNSVLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_CGNSVLibGetInteger(p, t_ype,ref i_value);
      }

      public static void CGNSVLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_CGNSVLibGetString(p, t_ype, c_value);
      }

      public static void CGNSVLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_CGNSVLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void CGNSVLibSetWriteFileType(IntPtr p,int f_iletype) {
         vdm_CGNSVLibSetWriteFileType(p, f_iletype);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_COMSOLLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_COMSOLLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetMonitorFunction(IntPtr p,VCOMSOLLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_COMSOLLibWriteModel(IntPtr p,IntPtr m_odel);

      public static IntPtr COMSOLLibBegin() {
         return vdm_COMSOLLibBegin();
      }

      public static void COMSOLLibEnd(IntPtr p) {
         vdm_COMSOLLibEnd(p);
      }

      public static int COMSOLLibError(IntPtr p) {
         return vdm_COMSOLLibError(p);
      }

      public static void COMSOLLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_COMSOLLibSetMode(p, m_ode, f_lag);
      }

      public static void COMSOLLibSetConvention(IntPtr p,long c_onvention) {
         vdm_COMSOLLibSetConvention(p, c_onvention);
      }

      public static void COMSOLLibSetStatus(IntPtr p,int s_tatus) {
         vdm_COMSOLLibSetStatus(p, s_tatus);
      }

      public static void COMSOLLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_COMSOLLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void COMSOLLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_COMSOLLibGetConnect(p,out c_onnect);
      }

      public static void COMSOLLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_COMSOLLibSetConnect(p, c_onnect);
      }

      public static void COMSOLLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_COMSOLLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void COMSOLLibSetMonitorFunction(IntPtr p,VCOMSOLLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_COMSOLLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void COMSOLLibAbort(IntPtr p) {
         vdm_COMSOLLibAbort(p);
      }

      public static void COMSOLLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_COMSOLLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void COMSOLLibClose(IntPtr p) {
         vdm_COMSOLLibClose(p);
      }

      public static void COMSOLLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_COMSOLLibAppend(p, f_ilename, t_ype);
      }

      public static void COMSOLLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_COMSOLLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void COMSOLLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_COMSOLLibGetLibrary(p,out l_ibrary);
      }

      public static void COMSOLLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_COMSOLLibNumDatasets(p,ref n_umdatasets);
      }

      public static void COMSOLLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_COMSOLLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void COMSOLLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_COMSOLLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void COMSOLLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_COMSOLLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void COMSOLLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_COMSOLLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void COMSOLLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_COMSOLLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void COMSOLLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_COMSOLLibLibDataset(p, o_per, i_dst);
      }

      public static void COMSOLLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_COMSOLLibSetString(p, t_ype, c_value);
      }

      public static void COMSOLLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_COMSOLLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void COMSOLLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_COMSOLLibDataFun(p, d_atafun);
      }

      public static void COMSOLLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_COMSOLLibGetInteger(p, t_ype,ref i_value);
      }

      public static void COMSOLLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_COMSOLLibGetString(p, t_ype, c_value);
      }

      public static void COMSOLLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_COMSOLLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void COMSOLLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_COMSOLLibWriteModel(p, m_odel);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_DPFLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibReadDataset(IntPtr p,int d_atasetIndex,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_DPFLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibNumAttributes(IntPtr p,int d_atasetIndex,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetAttVal(IntPtr p,int d_atasetIndex,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibInqDataset(IntPtr p,int d_atasetIndex,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetMonitorFunction(IntPtr p,VDPFLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_DPFLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      public static IntPtr DPFLibBegin() {
         return vdm_DPFLibBegin();
      }

      public static void DPFLibEnd(IntPtr p) {
         vdm_DPFLibEnd(p);
      }

      public static void DPFLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_DPFLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void DPFLibReadDataset(IntPtr p,int d_atasetIndex,ref IntPtr d_ata) {
         vdm_DPFLibReadDataset(p, d_atasetIndex,ref d_ata);
      }

      public static void DPFLibClose(IntPtr p) {
         vdm_DPFLibClose(p);
      }

      public static void DPFLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_DPFLibGetConnect(p,out c_onnect);
      }

      public static void DPFLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_DPFLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static int DPFLibError(IntPtr p) {
         return vdm_DPFLibError(p);
      }

      public static void DPFLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_DPFLibGetLibrary(p,out l_ibrary);
      }

      public static void DPFLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_DPFLibNumDatasets(p,ref n_umdatasets);
      }

      public static void DPFLibNumAttributes(IntPtr p,int d_atasetIndex,ref int n_umattributes) {
         vdm_DPFLibNumAttributes(p, d_atasetIndex,ref n_umattributes);
      }

      public static void DPFLibGetAttVal(IntPtr p,int d_atasetIndex,int i_att,ref IntPtr v_alue) {
         vdm_DPFLibGetAttVal(p, d_atasetIndex, i_att,ref v_alue);
      }

      public static void DPFLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_DPFLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void DPFLibInqDataset(IntPtr p,int d_atasetIndex,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_DPFLibInqDataset(p, d_atasetIndex, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void DPFLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_DPFLibSetMode(p, m_ode, f_lag);
      }

      public static void DPFLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_DPFLibSetString(p, t_ype, c_value);
      }

      public static void DPFLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_DPFLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void DPFLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_DPFLibDataFun(p, d_atafun);
      }

      public static void DPFLibAbort(IntPtr p) {
         vdm_DPFLibAbort(p);
      }

      public static void DPFLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_DPFLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void DPFLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_DPFLibAppend(p, f_ilename, t_ype);
      }

      public static void DPFLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_DPFLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void DPFLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_DPFLibLibDataset(p, o_per, i_dst);
      }

      public static void DPFLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_DPFLibGetInteger(p, t_ype,ref i_value);
      }

      public static void DPFLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_DPFLibGetString(p, t_ype, c_value);
      }

      public static void DPFLibSetConvention(IntPtr p,long c_onvention) {
         vdm_DPFLibSetConvention(p, c_onvention);
      }

      public static void DPFLibSetStatus(IntPtr p,int s_tatus) {
         vdm_DPFLibSetStatus(p, s_tatus);
      }

      public static void DPFLibSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3) {
         vdm_DPFLibSetIds(p, i_dtype, i_d1, i_d2, i_d3);
      }

      public static void DPFLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_DPFLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void DPFLibSetMonitorFunction(IntPtr p,VDPFLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_DPFLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void DPFLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_DPFLibSetConnect(p, c_onnect);
      }

      public static void DPFLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_DPFLibDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void DPFLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_DPFLibWriteDataset(p, i_dst,ref b_uff);
      }

      public static void DPFLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att) {
         vdm_DPFLibDefAttribute(p, i_dst, n_ame, l_ength, t_ype,ref i_att);
      }

      public static void DPFLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_DPFLibSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_EnSightLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_EnSightLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetMonitorFunction(IntPtr p,VEnSightLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibWriteState(IntPtr p,IntPtr u_rprop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_EnSightLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr EnSightLibBegin() {
         return vdm_EnSightLibBegin();
      }

      public static void EnSightLibEnd(IntPtr p) {
         vdm_EnSightLibEnd(p);
      }

      public static int EnSightLibError(IntPtr p) {
         return vdm_EnSightLibError(p);
      }

      public static void EnSightLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_EnSightLibSetMode(p, m_ode, f_lag);
      }

      public static void EnSightLibSetConvention(IntPtr p,long c_onvention) {
         vdm_EnSightLibSetConvention(p, c_onvention);
      }

      public static void EnSightLibSetStatus(IntPtr p,int s_tatus) {
         vdm_EnSightLibSetStatus(p, s_tatus);
      }

      public static void EnSightLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_EnSightLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void EnSightLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_EnSightLibGetConnect(p,out c_onnect);
      }

      public static void EnSightLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_EnSightLibSetConnect(p, c_onnect);
      }

      public static void EnSightLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_EnSightLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void EnSightLibSetMonitorFunction(IntPtr p,VEnSightLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_EnSightLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void EnSightLibAbort(IntPtr p) {
         vdm_EnSightLibAbort(p);
      }

      public static void EnSightLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_EnSightLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void EnSightLibClose(IntPtr p) {
         vdm_EnSightLibClose(p);
      }

      public static void EnSightLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_EnSightLibAppend(p, f_ilename, t_ype);
      }

      public static void EnSightLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_EnSightLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void EnSightLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_EnSightLibGetLibrary(p,out l_ibrary);
      }

      public static void EnSightLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_EnSightLibNumDatasets(p,ref n_umdatasets);
      }

      public static void EnSightLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_EnSightLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void EnSightLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_EnSightLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void EnSightLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_EnSightLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void EnSightLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_EnSightLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void EnSightLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_EnSightLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void EnSightLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_EnSightLibLibDataset(p, o_per, i_dst);
      }

      public static void EnSightLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_EnSightLibSetString(p, t_ype, c_value);
      }

      public static void EnSightLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_EnSightLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void EnSightLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_EnSightLibDataFun(p, d_atafun);
      }

      public static void EnSightLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_EnSightLibWriteModel(p, m_odel);
      }

      public static void EnSightLibWriteState(IntPtr p,IntPtr u_rprop,IntPtr s_tate) {
         vdm_EnSightLibWriteState(p, u_rprop, s_tate);
      }

      public static void EnSightLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_EnSightLibGetInteger(p, t_ype,ref i_value);
      }

      public static void EnSightLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_EnSightLibGetString(p, t_ype, c_value);
      }

      public static void EnSightLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_EnSightLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_FEMAPLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_FEMAPLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetFunction(IntPtr p,int f_untype,Vfunc1 f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetMonitorFunction(IntPtr p,VFEMAPLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FEMAPLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr FEMAPLibBegin() {
         return vdm_FEMAPLibBegin();
      }

      public static void FEMAPLibEnd(IntPtr p) {
         vdm_FEMAPLibEnd(p);
      }

      public static int FEMAPLibError(IntPtr p) {
         return vdm_FEMAPLibError(p);
      }

      public static void FEMAPLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_FEMAPLibSetMode(p, m_ode, f_lag);
      }

      public static void FEMAPLibSetConvention(IntPtr p,long c_onvention) {
         vdm_FEMAPLibSetConvention(p, c_onvention);
      }

      public static void FEMAPLibSetStatus(IntPtr p,int s_tatus) {
         vdm_FEMAPLibSetStatus(p, s_tatus);
      }

      public static void FEMAPLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_FEMAPLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void FEMAPLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_FEMAPLibGetConnect(p,out c_onnect);
      }

      public static void FEMAPLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_FEMAPLibSetConnect(p, c_onnect);
      }

      public static void FEMAPLibSetFunction(IntPtr p,int f_untype,Vfunc1 f_unction,IntPtr o_bject) {
         vdm_FEMAPLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void FEMAPLibSetMonitorFunction(IntPtr p,VFEMAPLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_FEMAPLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void FEMAPLibAbort(IntPtr p) {
         vdm_FEMAPLibAbort(p);
      }

      public static void FEMAPLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_FEMAPLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void FEMAPLibClose(IntPtr p) {
         vdm_FEMAPLibClose(p);
      }

      public static void FEMAPLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_FEMAPLibAppend(p, f_ilename, t_ype);
      }

      public static void FEMAPLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_FEMAPLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void FEMAPLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_FEMAPLibGetLibrary(p,out l_ibrary);
      }

      public static void FEMAPLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_FEMAPLibNumDatasets(p,ref n_umdatasets);
      }

      public static void FEMAPLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_FEMAPLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void FEMAPLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_FEMAPLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void FEMAPLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_FEMAPLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void FEMAPLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_FEMAPLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void FEMAPLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_FEMAPLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void FEMAPLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_FEMAPLibLibDataset(p, o_per, i_dst);
      }

      public static void FEMAPLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_FEMAPLibSetString(p, t_ype, c_value);
      }

      public static void FEMAPLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_FEMAPLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void FEMAPLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_FEMAPLibDataFun(p, d_atafun);
      }

      public static void FEMAPLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_FEMAPLibGetInteger(p, t_ype,ref i_value);
      }

      public static void FEMAPLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_FEMAPLibGetString(p, t_ype, c_value);
      }

      public static void FEMAPLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_FEMAPLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_FDILibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_FDILibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FDILibDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr FDILibBegin() {
         return vdm_FDILibBegin();
      }

      public static void FDILibEnd(IntPtr p) {
         vdm_FDILibEnd(p);
      }

      public static int FDILibError(IntPtr p) {
         return vdm_FDILibError(p);
      }

      public static void FDILibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_FDILibSetMode(p, m_ode, f_lag);
      }

      public static void FDILibSetConvention(IntPtr p,long c_onvention) {
         vdm_FDILibSetConvention(p, c_onvention);
      }

      public static void FDILibSetStatus(IntPtr p,int s_tatus) {
         vdm_FDILibSetStatus(p, s_tatus);
      }

      public static void FDILibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_FDILibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void FDILibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_FDILibGetConnect(p,out c_onnect);
      }

      public static void FDILibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_FDILibSetConnect(p, c_onnect);
      }

      public static void FDILibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_FDILibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void FDILibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_FDILibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void FDILibClose(IntPtr p) {
         vdm_FDILibClose(p);
      }

      public static void FDILibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_FDILibAppend(p, f_ilename, t_ype);
      }

      public static void FDILibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_FDILibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void FDILibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_FDILibGetLibrary(p,out l_ibrary);
      }

      public static void FDILibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_FDILibNumDatasets(p,ref n_umdatasets);
      }

      public static void FDILibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_FDILibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void FDILibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_FDILibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void FDILibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_FDILibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void FDILibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_FDILibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void FDILibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_FDILibReadDataset(p, i_dst,ref b_uff);
      }

      public static void FDILibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_FDILibLibDataset(p, o_per, i_dst);
      }

      public static void FDILibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_FDILibDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_FLUENTLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_FLUENTLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetOpenLib(IntPtr p,IntPtr o_penlib);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetMonitorFunction(IntPtr p,VFLUENTLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibOpenFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibInit(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibTerm(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibDimension(IntPtr p,ref int n_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumEntities(IntPtr p,ref int n_umcell,ref int n_umface,ref int n_umnode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumCellZone(IntPtr p,ref int n_umcellzone);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibCellZoneParam(IntPtr p,int i_thcellzone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibCellZoneType(IntPtr p,int i_thcellzone,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibCellZoneName(IntPtr p,int i_thcellzone,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibCellZoneId(IntPtr p,int i_thcellzone,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNumFaceZone(IntPtr p,ref int n_umfacezone);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibFaceZoneParam(IntPtr p,int i_thfacezone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibFaceZoneType(IntPtr p,int i_thfacezone,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibFaceZoneName(IntPtr p,int i_thfacezone,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibFaceZoneId(IntPtr p,int i_thfacezone,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibFaceZone(IntPtr p,int i_thfacezone,int [] i_xf,int [] c_l,int [] c_r);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_FLUENTLibNode(IntPtr p,double [] x_);

      public static IntPtr FLUENTLibBegin() {
         return vdm_FLUENTLibBegin();
      }

      public static void FLUENTLibEnd(IntPtr p) {
         vdm_FLUENTLibEnd(p);
      }

      public static int FLUENTLibError(IntPtr p) {
         return vdm_FLUENTLibError(p);
      }

      public static void FLUENTLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_FLUENTLibGetInteger(p, t_ype,ref i_value);
      }

      public static void FLUENTLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_FLUENTLibGetString(p, t_ype, c_value);
      }

      public static void FLUENTLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_FLUENTLibSetMode(p, m_ode, f_lag);
      }

      public static void FLUENTLibSetConvention(IntPtr p,long c_onvention) {
         vdm_FLUENTLibSetConvention(p, c_onvention);
      }

      public static void FLUENTLibSetStatus(IntPtr p,int s_tatus) {
         vdm_FLUENTLibSetStatus(p, s_tatus);
      }

      public static void FLUENTLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_FLUENTLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void FLUENTLibSetOpenLib(IntPtr p,IntPtr o_penlib) {
         vdm_FLUENTLibSetOpenLib(p, o_penlib);
      }

      public static void FLUENTLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_FLUENTLibSetConnect(p, c_onnect);
      }

      public static void FLUENTLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_FLUENTLibGetConnect(p,out c_onnect);
      }

      public static void FLUENTLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_FLUENTLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void FLUENTLibSetMonitorFunction(IntPtr p,VFLUENTLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_FLUENTLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void FLUENTLibAbort(IntPtr p) {
         vdm_FLUENTLibAbort(p);
      }

      public static void FLUENTLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_FLUENTLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void FLUENTLibOpenFile(IntPtr p) {
         vdm_FLUENTLibOpenFile(p);
      }

      public static void FLUENTLibCloseFile(IntPtr p) {
         vdm_FLUENTLibCloseFile(p);
      }

      public static void FLUENTLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_FLUENTLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void FLUENTLibClose(IntPtr p) {
         vdm_FLUENTLibClose(p);
      }

      public static void FLUENTLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_FLUENTLibAppend(p, f_ilename, t_ype);
      }

      public static void FLUENTLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_FLUENTLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void FLUENTLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_FLUENTLibGetLibrary(p,out l_ibrary);
      }

      public static void FLUENTLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_FLUENTLibNumDatasets(p,ref n_umdatasets);
      }

      public static void FLUENTLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_FLUENTLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void FLUENTLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_FLUENTLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void FLUENTLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_FLUENTLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void FLUENTLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_FLUENTLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void FLUENTLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_FLUENTLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void FLUENTLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_FLUENTLibWriteModel(p, m_odel);
      }

      public static void FLUENTLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_FLUENTLibWriteState(p, r_prop, s_tate);
      }

      public static void FLUENTLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_FLUENTLibLibDataset(p, o_per, i_dst);
      }

      public static void FLUENTLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_FLUENTLibSetString(p, t_ype, c_value);
      }

      public static void FLUENTLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_FLUENTLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void FLUENTLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_FLUENTLibDataFun(p, d_atafun);
      }

      public static void FLUENTLibInit(IntPtr p,IntPtr m_odel) {
         vdm_FLUENTLibInit(p, m_odel);
      }

      public static void FLUENTLibTerm(IntPtr p) {
         vdm_FLUENTLibTerm(p);
      }

      public static void FLUENTLibDimension(IntPtr p,ref int n_d) {
         vdm_FLUENTLibDimension(p,ref n_d);
      }

      public static void FLUENTLibNumEntities(IntPtr p,ref int n_umcell,ref int n_umface,ref int n_umnode) {
         vdm_FLUENTLibNumEntities(p,ref n_umcell,ref n_umface,ref n_umnode);
      }

      public static void FLUENTLibNumCellZone(IntPtr p,ref int n_umcellzone) {
         vdm_FLUENTLibNumCellZone(p,ref n_umcellzone);
      }

      public static void FLUENTLibCellZoneParam(IntPtr p,int i_thcellzone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type) {
         vdm_FLUENTLibCellZoneParam(p, i_thcellzone,ref i_first,ref i_last,ref t_ype,ref e_type);
      }

      public static void FLUENTLibCellZoneType(IntPtr p,int i_thcellzone,int [] t_ype) {
         vdm_FLUENTLibCellZoneType(p, i_thcellzone, t_ype);
      }

      public static void FLUENTLibCellZoneName(IntPtr p,int i_thcellzone,StringBuilder n_ame) {
         vdm_FLUENTLibCellZoneName(p, i_thcellzone, n_ame);
      }

      public static void FLUENTLibCellZoneId(IntPtr p,int i_thcellzone,ref int i_d) {
         vdm_FLUENTLibCellZoneId(p, i_thcellzone,ref i_d);
      }

      public static void FLUENTLibNumFaceZone(IntPtr p,ref int n_umfacezone) {
         vdm_FLUENTLibNumFaceZone(p,ref n_umfacezone);
      }

      public static void FLUENTLibFaceZoneParam(IntPtr p,int i_thfacezone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type) {
         vdm_FLUENTLibFaceZoneParam(p, i_thfacezone,ref i_first,ref i_last,ref t_ype,ref e_type);
      }

      public static void FLUENTLibFaceZoneType(IntPtr p,int i_thfacezone,int [] t_ype) {
         vdm_FLUENTLibFaceZoneType(p, i_thfacezone, t_ype);
      }

      public static void FLUENTLibFaceZoneName(IntPtr p,int i_thfacezone,StringBuilder n_ame) {
         vdm_FLUENTLibFaceZoneName(p, i_thfacezone, n_ame);
      }

      public static void FLUENTLibFaceZoneId(IntPtr p,int i_thfacezone,ref int i_d) {
         vdm_FLUENTLibFaceZoneId(p, i_thfacezone,ref i_d);
      }

      public static void FLUENTLibFaceZone(IntPtr p,int i_thfacezone,int [] i_xf,int [] c_l,int [] c_r) {
         vdm_FLUENTLibFaceZone(p, i_thfacezone, i_xf, c_l, c_r);
      }

      public static void FLUENTLibNode(IntPtr p,double [] x_) {
         vdm_FLUENTLibNode(p, x_);
      }

      public const int GMVLIB_SEARCH_OFF = 0;
      public const int GMVLIB_SEARCH_FILENUM = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_GMVLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_GMVLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetMonitorFunction(IntPtr p,VGMVLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_GMVLibSetSearch(IntPtr p,int s_earch);

      public static IntPtr GMVLibBegin() {
         return vdm_GMVLibBegin();
      }

      public static void GMVLibEnd(IntPtr p) {
         vdm_GMVLibEnd(p);
      }

      public static int GMVLibError(IntPtr p) {
         return vdm_GMVLibError(p);
      }

      public static void GMVLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_GMVLibSetMode(p, m_ode, f_lag);
      }

      public static void GMVLibSetConvention(IntPtr p,long c_onvention) {
         vdm_GMVLibSetConvention(p, c_onvention);
      }

      public static void GMVLibSetStatus(IntPtr p,int s_tatus) {
         vdm_GMVLibSetStatus(p, s_tatus);
      }

      public static void GMVLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_GMVLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void GMVLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_GMVLibGetConnect(p,out c_onnect);
      }

      public static void GMVLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_GMVLibSetConnect(p, c_onnect);
      }

      public static void GMVLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_GMVLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void GMVLibSetMonitorFunction(IntPtr p,VGMVLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_GMVLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void GMVLibAbort(IntPtr p) {
         vdm_GMVLibAbort(p);
      }

      public static void GMVLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_GMVLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void GMVLibClose(IntPtr p) {
         vdm_GMVLibClose(p);
      }

      public static void GMVLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_GMVLibAppend(p, f_ilename, t_ype);
      }

      public static void GMVLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_GMVLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void GMVLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_GMVLibGetLibrary(p,out l_ibrary);
      }

      public static void GMVLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_GMVLibNumDatasets(p,ref n_umdatasets);
      }

      public static void GMVLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_GMVLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void GMVLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_GMVLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void GMVLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_GMVLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void GMVLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_GMVLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void GMVLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_GMVLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void GMVLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_GMVLibWriteModel(p, m_odel);
      }

      public static void GMVLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_GMVLibLibDataset(p, o_per, i_dst);
      }

      public static void GMVLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_GMVLibSetString(p, t_ype, c_value);
      }

      public static void GMVLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_GMVLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void GMVLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_GMVLibDataFun(p, d_atafun);
      }

      public static void GMVLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_GMVLibGetInteger(p, t_ype,ref i_value);
      }

      public static void GMVLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_GMVLibGetString(p, t_ype, c_value);
      }

      public static void GMVLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_GMVLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void GMVLibSetSearch(IntPtr p,int s_earch) {
         vdm_GMVLibSetSearch(p, s_earch);
      }

      public const int HMAFIL_NUMUNREC = -1;
      public const int HMAFIL_LINENUM = -2;
      public const int HMAFIL_UNRECCARD = -3;
      public const int HMAFIL_UNRECKEYWORD = -4;
      public const int HMAFIL_UNRECTYPE = -5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_HMAFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_HMAFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetMonitorFunction(IntPtr p,VHMAFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_HMAFilPrintUnrecognizedData(IntPtr p);

      public static IntPtr HMAFilBegin() {
         return vdm_HMAFilBegin();
      }

      public static void HMAFilEnd(IntPtr p) {
         vdm_HMAFilEnd(p);
      }

      public static int HMAFilError(IntPtr p) {
         return vdm_HMAFilError(p);
      }

      public static void HMAFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_HMAFilGetString(p, t_ype, c_value);
      }

      public static void HMAFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_HMAFilSetMode(p, m_ode, f_lag);
      }

      public static void HMAFilSetConvention(IntPtr p,long c_onvention) {
         vdm_HMAFilSetConvention(p, c_onvention);
      }

      public static void HMAFilSetStatus(IntPtr p,int s_tatus) {
         vdm_HMAFilSetStatus(p, s_tatus);
      }

      public static void HMAFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_HMAFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void HMAFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_HMAFilGetConnect(p,out c_onnect);
      }

      public static void HMAFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_HMAFilSetConnect(p, c_onnect);
      }

      public static void HMAFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_HMAFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void HMAFilSetMonitorFunction(IntPtr p,VHMAFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_HMAFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void HMAFilAbort(IntPtr p) {
         vdm_HMAFilAbort(p);
      }

      public static void HMAFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_HMAFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void HMAFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_HMAFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void HMAFilClose(IntPtr p) {
         vdm_HMAFilClose(p);
      }

      public static void HMAFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_HMAFilAppend(p, f_ilename, t_ype);
      }

      public static void HMAFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_HMAFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void HMAFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_HMAFilGetLibrary(p,out l_ibrary);
      }

      public static void HMAFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_HMAFilNumDatasets(p,ref n_umdatasets);
      }

      public static void HMAFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_HMAFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void HMAFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_HMAFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void HMAFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_HMAFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void HMAFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_HMAFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void HMAFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_HMAFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void HMAFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_HMAFilGetInteger(p, t_ype,ref i_value);
      }

      public static void HMAFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_HMAFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void HMAFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_HMAFilLibDataset(p, o_per, i_dst);
      }

      public static void HMAFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_HMAFilSetString(p, t_ype, c_value);
      }

      public static void HMAFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_HMAFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void HMAFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_HMAFilDataFun(p, d_atafun);
      }

      public static void HMAFilPrintUnrecognizedData(IntPtr p) {
         vdm_HMAFilPrintUnrecognizedData(p);
      }

      public const int D3DFIL_NUMRESTYPES = 32;
      public const int D3DFIL_PARTHEADER_LENGTH = 133;
      public const int D3DFIL_NUMUNREC = -1;
      public const int D3DFIL_LINENUM = -2;
      public const int D3DFIL_UNRECKEYWORD = -3;
      public const int D3DFIL_UNRECDATALINE = -4;
      public const int D3DFIL_UNRECFILE = -5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_D3DFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_D3DFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetMonitorFunction(IntPtr p,VD3DFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilGetUnrecognizedDataSize(IntPtr p,ref int n_umunrec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DFilPrintUnrecognizedData(IntPtr p);

      public static IntPtr D3DFilBegin() {
         return vdm_D3DFilBegin();
      }

      public static void D3DFilEnd(IntPtr p) {
         vdm_D3DFilEnd(p);
      }

      public static int D3DFilError(IntPtr p) {
         return vdm_D3DFilError(p);
      }

      public static void D3DFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_D3DFilSetMode(p, m_ode, f_lag);
      }

      public static void D3DFilSetConvention(IntPtr p,long c_onvention) {
         vdm_D3DFilSetConvention(p, c_onvention);
      }

      public static void D3DFilSetStatus(IntPtr p,int s_tatus) {
         vdm_D3DFilSetStatus(p, s_tatus);
      }

      public static void D3DFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_D3DFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void D3DFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_D3DFilGetConnect(p,out c_onnect);
      }

      public static void D3DFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_D3DFilSetConnect(p, c_onnect);
      }

      public static void D3DFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_D3DFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void D3DFilSetMonitorFunction(IntPtr p,VD3DFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_D3DFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void D3DFilAbort(IntPtr p) {
         vdm_D3DFilAbort(p);
      }

      public static void D3DFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_D3DFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void D3DFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_D3DFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void D3DFilClose(IntPtr p) {
         vdm_D3DFilClose(p);
      }

      public static void D3DFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_D3DFilAppend(p, f_ilename, t_ype);
      }

      public static void D3DFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_D3DFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void D3DFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_D3DFilGetLibrary(p,out l_ibrary);
      }

      public static void D3DFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_D3DFilNumDatasets(p,ref n_umdatasets);
      }

      public static void D3DFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_D3DFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void D3DFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_D3DFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void D3DFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_D3DFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void D3DFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_D3DFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void D3DFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_D3DFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void D3DFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_D3DFilGetInteger(p, t_ype,ref i_value);
      }

      public static void D3DFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_D3DFilGetString(p, t_ype, c_value);
      }

      public static void D3DFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_D3DFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void D3DFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_D3DFilWriteModel(p, m_odel);
      }

      public static void D3DFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_D3DFilLibDataset(p, o_per, i_dst);
      }

      public static void D3DFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_D3DFilSetString(p, t_ype, c_value);
      }

      public static void D3DFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_D3DFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void D3DFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_D3DFilDataFun(p, d_atafun);
      }

      public static void D3DFilGetUnrecognizedDataSize(IntPtr p,ref int n_umunrec) {
         vdm_D3DFilGetUnrecognizedDataSize(p,ref n_umunrec);
      }

      public static void D3DFilPrintUnrecognizedData(IntPtr p) {
         vdm_D3DFilPrintUnrecognizedData(p);
      }

      public const int D3DLIB_SEARCH_SWFORC = 1;
      public const int D3DLIB_SEARCH_SWFORC_OFF = 2;
      public const int D3DLIB_SEARCH_NCFORC = 3;
      public const int D3DLIB_SEARCH_NCFORC_OFF = 4;
      public const int D3D_ELEMENT_SOLID = 0;
      public const int D3D_ELEMENT_BEAM = 1;
      public const int D3D_ELEMENT_SHELL = 2;
      public const int D3D_ELEMENT_THICK_SHELL = 3;
      public const int D3D_ELEMENT_HEX8 = 4;
      public const int D3D_ELEMENT_HEX20 = 5;
      public const int D3D_ELEMENT_HEX27 = 6;
      public const int D3D_ELEMENT_TET4 = 7;
      public const int D3D_ELEMENT_TET10 = 8;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_D3DLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_D3DLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetMonitorFunction(IntPtr p,VD3DLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetSearch(IntPtr p,int s_earch);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_D3DLibPrintUnrecognizedData(IntPtr p);

      public static IntPtr D3DLibBegin() {
         return vdm_D3DLibBegin();
      }

      public static void D3DLibEnd(IntPtr p) {
         vdm_D3DLibEnd(p);
      }

      public static int D3DLibError(IntPtr p) {
         return vdm_D3DLibError(p);
      }

      public static void D3DLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_D3DLibGetInteger(p, t_ype,ref i_value);
      }

      public static void D3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_D3DLibGetString(p, t_ype, c_value);
      }

      public static void D3DLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_D3DLibSetMode(p, m_ode, f_lag);
      }

      public static void D3DLibSetConvention(IntPtr p,long c_onvention) {
         vdm_D3DLibSetConvention(p, c_onvention);
      }

      public static void D3DLibSetStatus(IntPtr p,int s_tatus) {
         vdm_D3DLibSetStatus(p, s_tatus);
      }

      public static void D3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_D3DLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void D3DLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_D3DLibGetConnect(p,out c_onnect);
      }

      public static void D3DLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_D3DLibSetConnect(p, c_onnect);
      }

      public static void D3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_D3DLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void D3DLibSetMonitorFunction(IntPtr p,VD3DLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_D3DLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void D3DLibAbort(IntPtr p) {
         vdm_D3DLibAbort(p);
      }

      public static void D3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_D3DLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void D3DLibSetSearch(IntPtr p,int s_earch) {
         vdm_D3DLibSetSearch(p, s_earch);
      }

      public static void D3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_D3DLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void D3DLibClose(IntPtr p) {
         vdm_D3DLibClose(p);
      }

      public static void D3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_D3DLibAppend(p, f_ilename, t_ype);
      }

      public static void D3DLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_D3DLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void D3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_D3DLibGetLibrary(p,out l_ibrary);
      }

      public static void D3DLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_D3DLibNumDatasets(p,ref n_umdatasets);
      }

      public static void D3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_D3DLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void D3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_D3DLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void D3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_D3DLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void D3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_D3DLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void D3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_D3DLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void D3DLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_D3DLibLibDataset(p, o_per, i_dst);
      }

      public static void D3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_D3DLibSetString(p, t_ype, c_value);
      }

      public static void D3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_D3DLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void D3DLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_D3DLibDataFun(p, d_atafun);
      }

      public static void D3DLibPrintUnrecognizedData(IntPtr p) {
         vdm_D3DLibPrintUnrecognizedData(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_MarcFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_MarcFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetMonitorFunction(IntPtr p,VMarcFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcFilDataFun(IntPtr p,IntPtr d_f);

      public static IntPtr MarcFilBegin() {
         return vdm_MarcFilBegin();
      }

      public static void MarcFilEnd(IntPtr p) {
         vdm_MarcFilEnd(p);
      }

      public static int MarcFilError(IntPtr p) {
         return vdm_MarcFilError(p);
      }

      public static void MarcFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_MarcFilGetInteger(p, t_ype,ref i_value);
      }

      public static void MarcFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MarcFilGetString(p, t_ype, c_value);
      }

      public static void MarcFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_MarcFilSetMode(p, m_ode, f_lag);
      }

      public static void MarcFilSetConvention(IntPtr p,long c_onvention) {
         vdm_MarcFilSetConvention(p, c_onvention);
      }

      public static void MarcFilSetStatus(IntPtr p,int s_tatus) {
         vdm_MarcFilSetStatus(p, s_tatus);
      }

      public static void MarcFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_MarcFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void MarcFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_MarcFilGetConnect(p,out c_onnect);
      }

      public static void MarcFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_MarcFilSetConnect(p, c_onnect);
      }

      public static void MarcFilSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject) {
         vdm_MarcFilSetFunction(p, f_unctype, f_unction, o_bject);
      }

      public static void MarcFilSetMonitorFunction(IntPtr p,VMarcFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_MarcFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void MarcFilAbort(IntPtr p) {
         vdm_MarcFilAbort(p);
      }

      public static void MarcFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_MarcFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void MarcFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_MarcFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void MarcFilClose(IntPtr p) {
         vdm_MarcFilClose(p);
      }

      public static void MarcFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_MarcFilAppend(p, f_ilename, t_ype);
      }

      public static void MarcFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_MarcFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void MarcFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_MarcFilGetLibrary(p,out l_ibrary);
      }

      public static void MarcFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_MarcFilNumDatasets(p,ref n_umdatasets);
      }

      public static void MarcFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_MarcFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void MarcFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_MarcFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void MarcFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_MarcFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void MarcFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_MarcFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void MarcFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_MarcFilReadDataset(p, i_dst,ref b_uff);
      }

      public static void MarcFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_MarcFilLibDataset(p, o_per, i_dst);
      }

      public static void MarcFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_MarcFilWriteModel(p, m_odel);
      }

      public static void MarcFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MarcFilSetString(p, t_ype, c_value);
      }

      public static void MarcFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_MarcFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void MarcFilDataFun(IntPtr p,IntPtr d_f) {
         vdm_MarcFilDataFun(p, d_f);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_MarcLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_MarcLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetMonitorFunction(IntPtr p,VMarcLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MarcLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr MarcLibBegin() {
         return vdm_MarcLibBegin();
      }

      public static void MarcLibEnd(IntPtr p) {
         vdm_MarcLibEnd(p);
      }

      public static int MarcLibError(IntPtr p) {
         return vdm_MarcLibError(p);
      }

      public static void MarcLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_MarcLibSetMode(p, m_ode, f_lag);
      }

      public static void MarcLibSetConvention(IntPtr p,long c_onvention) {
         vdm_MarcLibSetConvention(p, c_onvention);
      }

      public static void MarcLibSetStatus(IntPtr p,int s_tatus) {
         vdm_MarcLibSetStatus(p, s_tatus);
      }

      public static void MarcLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_MarcLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void MarcLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_MarcLibGetConnect(p,out c_onnect);
      }

      public static void MarcLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_MarcLibSetConnect(p, c_onnect);
      }

      public static void MarcLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_MarcLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void MarcLibSetMonitorFunction(IntPtr p,VMarcLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_MarcLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void MarcLibAbort(IntPtr p) {
         vdm_MarcLibAbort(p);
      }

      public static void MarcLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_MarcLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void MarcLibClose(IntPtr p) {
         vdm_MarcLibClose(p);
      }

      public static void MarcLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_MarcLibAppend(p, f_ilename, t_ype);
      }

      public static void MarcLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_MarcLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void MarcLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_MarcLibGetLibrary(p,out l_ibrary);
      }

      public static void MarcLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_MarcLibNumDatasets(p,ref n_umdatasets);
      }

      public static void MarcLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_MarcLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void MarcLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_MarcLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void MarcLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_MarcLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void MarcLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_MarcLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void MarcLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_MarcLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void MarcLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_MarcLibLibDataset(p, o_per, i_dst);
      }

      public static void MarcLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MarcLibSetString(p, t_ype, c_value);
      }

      public static void MarcLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_MarcLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void MarcLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_MarcLibDataFun(p, d_atafun);
      }

      public static void MarcLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_MarcLibGetInteger(p, t_ype,ref i_value);
      }

      public static void MarcLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MarcLibGetString(p, t_ype, c_value);
      }

      public static void MarcLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_MarcLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int MARCLIB_IPT_NONE = 0;
      public const int MARCLIB_IPT_LINE_LINE2_1PT = 1;
      public const int MARCLIB_IPT_LINE_LINE2_2PT = 2;
      public const int MARCLIB_IPT_LINE_LINE3_2PT = 3;
      public const int MARCLIB_IPT_LINE_LINE2_3PT = 4;
      public const int MARCLIB_IPT_LINE_LINE3_3PT = 5;
      public const int MARCLIB_IPT_LINE_2NODE = 6;
      public const int MARCLIB_IPT_LINE_QUAD4_2PT = 7;
      public const int MARCLIB_IPT_LINE_QUAD8_6PT = 8;
      public const int MARCLIB_IPT_LINE_AVG_2PT = 9;
      public const int MARCLIB_IPT_TRI3_1PT = 10;
      public const int MARCLIB_IPT_TRI6_1PT = 11;
      public const int MARCLIB_IPT_TRI3_3PT = 12;
      public const int MARCLIB_IPT_TRI6_3PT = 13;
      public const int MARCLIB_IPT_TRI_7PT = 14;
      public const int MARCLIB_IPT_QUAD_1PT = 15;
      public const int MARCLIB_IPT_QUAD4_4PT = 16;
      public const int MARCLIB_IPT_QUAD8_4PT = 17;
      public const int MARCLIB_IPT_QUAD_AVG_4PT = 18;
      public const int MARCLIB_IPT_QUAD_9PT = 19;
      public const int MARCLIB_IPT_QUAD_AVG_9PT = 20;
      public const int MARCLIB_IPT_QUAD_INF_9PT = 21;
      public const int MARCLIB_IPT_QUAD_4NODE = 22;
      public const int MARCLIB_IPT_QUAD_6PT = 23;
      public const int MARCLIB_IPT_QUAD_28PT = 24;
      public const int MARCLIB_IPT_QUAD_HEX8_4PT = 25;
      public const int MARCLIB_IPT_QUAD_HEX20_4PT = 26;
      public const int MARCLIB_IPT_TET_1PT = 27;
      public const int MARCLIB_IPT_TET_4PT = 28;
      public const int MARCLIB_IPT_HEX_1PT = 29;
      public const int MARCLIB_IPT_HEX8_8PT = 30;
      public const int MARCLIB_IPT_HEX20_8PT = 31;
      public const int MARCLIB_IPT_HEX_27PT = 32;
      public const int MARCLIB_IPT_HEX_INF_27PT = 33;
      public const int MARCLIB_IPT_HEX_12PT = 34;
      public const int MARCLIB_IPT_WED_21PT = 35;
      public const int MARCLIB_IPT_WED_6PT = 36;
      public const int MARCLIB_IPT_PYR_5PT = 37;
      public const int MARCLIB_IPT_PYR_14PT = 38;
      public const int MARCLIB_RULE_GAUSS = 1;
      public const int MARCLIB_RULE_LOBATTO = 2;
      public const int MARCLIB_RULE_AVERAGE = -3;
      public const int MARCLIB_RULE_QUADINF = -4;
      public const int MARCLIB_RULE_HEXINF = -5;
      public const int MARCLIB_RULE_4TRI7 = -6;
      public const int MARCLIB_RULE_4_8 = -7;
      public const int MARCLIB_RULE_4_20 = -8;
      public const int MARC_NUMELEMTYPES = 243;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_RASFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_RASFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetMonitorFunction(IntPtr p,VRASFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASFilDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr RASFilBegin() {
         return vdm_RASFilBegin();
      }

      public static void RASFilEnd(IntPtr p) {
         vdm_RASFilEnd(p);
      }

      public static int RASFilError(IntPtr p) {
         return vdm_RASFilError(p);
      }

      public static void RASFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_RASFilGetInteger(p, t_ype,ref i_value);
      }

      public static void RASFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_RASFilGetString(p, t_ype, c_value);
      }

      public static void RASFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_RASFilSetMode(p, m_ode, f_lag);
      }

      public static void RASFilSetConvention(IntPtr p,long c_onvention) {
         vdm_RASFilSetConvention(p, c_onvention);
      }

      public static void RASFilSetStatus(IntPtr p,int s_tatus) {
         vdm_RASFilSetStatus(p, s_tatus);
      }

      public static void RASFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_RASFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void RASFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_RASFilGetConnect(p,out c_onnect);
      }

      public static void RASFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_RASFilSetConnect(p, c_onnect);
      }

      public static void RASFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_RASFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void RASFilSetMonitorFunction(IntPtr p,VRASFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_RASFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void RASFilAbort(IntPtr p) {
         vdm_RASFilAbort(p);
      }

      public static void RASFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_RASFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void RASFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_RASFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void RASFilClose(IntPtr p) {
         vdm_RASFilClose(p);
      }

      public static void RASFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_RASFilAppend(p, f_ilename, t_ype);
      }

      public static void RASFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_RASFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void RASFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_RASFilGetLibrary(p,out l_ibrary);
      }

      public static void RASFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_RASFilNumDatasets(p,ref n_umdatasets);
      }

      public static void RASFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_RASFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void RASFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_RASFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void RASFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_RASFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void RASFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_RASFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void RASFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_RASFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void RASFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_RASFilWriteModel(p, m_odel);
      }

      public static void RASFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_RASFilLibDataset(p, o_per, i_dst);
      }

      public static void RASFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_RASFilSetString(p, t_ype, c_value);
      }

      public static void RASFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_RASFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void RASFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_RASFilDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_RASLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_RASLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetMonitorFunction(IntPtr p,VRASLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_RASLibDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr RASLibBegin() {
         return vdm_RASLibBegin();
      }

      public static void RASLibEnd(IntPtr p) {
         vdm_RASLibEnd(p);
      }

      public static int RASLibError(IntPtr p) {
         return vdm_RASLibError(p);
      }

      public static void RASLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_RASLibGetInteger(p, t_ype,ref i_value);
      }

      public static void RASLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_RASLibGetString(p, t_ype, c_value);
      }

      public static void RASLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_RASLibSetMode(p, m_ode, f_lag);
      }

      public static void RASLibSetConvention(IntPtr p,long c_onvention) {
         vdm_RASLibSetConvention(p, c_onvention);
      }

      public static void RASLibSetStatus(IntPtr p,int s_tatus) {
         vdm_RASLibSetStatus(p, s_tatus);
      }

      public static void RASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_RASLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void RASLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_RASLibGetConnect(p,out c_onnect);
      }

      public static void RASLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_RASLibSetConnect(p, c_onnect);
      }

      public static void RASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_RASLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void RASLibSetMonitorFunction(IntPtr p,VRASLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_RASLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void RASLibAbort(IntPtr p) {
         vdm_RASLibAbort(p);
      }

      public static void RASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_RASLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void RASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_RASLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void RASLibClose(IntPtr p) {
         vdm_RASLibClose(p);
      }

      public static void RASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_RASLibAppend(p, f_ilename, t_ype);
      }

      public static void RASLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_RASLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void RASLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_RASLibGetLibrary(p,out l_ibrary);
      }

      public static void RASLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_RASLibNumDatasets(p,ref n_umdatasets);
      }

      public static void RASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_RASLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void RASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_RASLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void RASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_RASLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void RASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_RASLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void RASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_RASLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void RASLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_RASLibLibDataset(p, o_per, i_dst);
      }

      public static void RASLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_RASLibSetString(p, t_ype, c_value);
      }

      public static void RASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_RASLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void RASLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_RASLibDataFun(p, d_atafun);
      }

      public const int MEMLIB_VERSION = -1;
      public const int MEMLIB_CREATEDATE = -2;
      public const int MEMLIB_CREATETIME = -3;
      public const int MEMLIB_UPDATEDATE = -4;
      public const int MEMLIB_UPDATETIME = -5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_MemLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_MemLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetInteger(IntPtr p,int t_ype,ref int p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetMonitorFunction(IntPtr p,VMemLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int a_tttype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibNumDataset(IntPtr p,ref int n_umdataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibUpdate(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibPushContainer(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibPopContainer(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibStreamNum(IntPtr p,ref long n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_MemLibStream(IntPtr p,ref IntPtr b_uff);

      public static IntPtr MemLibBegin() {
         return vdm_MemLibBegin();
      }

      public static void MemLibEnd(IntPtr p) {
         vdm_MemLibEnd(p);
      }

      public static int MemLibError(IntPtr p) {
         return vdm_MemLibError(p);
      }

      public static void MemLibGetInteger(IntPtr p,int t_ype,ref int p_aram) {
         vdm_MemLibGetInteger(p, t_ype,ref p_aram);
      }

      public static void MemLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MemLibGetString(p, t_ype, c_value);
      }

      public static void MemLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_MemLibSetMode(p, m_ode, f_lag);
      }

      public static void MemLibSetConvention(IntPtr p,long c_onvention) {
         vdm_MemLibSetConvention(p, c_onvention);
      }

      public static void MemLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_MemLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void MemLibSetStatus(IntPtr p,int s_tatus) {
         vdm_MemLibSetStatus(p, s_tatus);
      }

      public static void MemLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_MemLibSetConnect(p, c_onnect);
      }

      public static void MemLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_MemLibGetConnect(p,out c_onnect);
      }

      public static void MemLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_MemLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void MemLibSetMonitorFunction(IntPtr p,VMemLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_MemLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void MemLibAbort(IntPtr p) {
         vdm_MemLibAbort(p);
      }

      public static void MemLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_MemLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void MemLibOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype) {
         vdm_MemLibOpen(p, m_ode, p_ath, t_ype);
      }

      public static void MemLibClose(IntPtr p) {
         vdm_MemLibClose(p);
      }

      public static void MemLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_MemLibAppend(p, f_ilename, t_ype);
      }

      public static void MemLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_MemLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void MemLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_MemLibGetLibrary(p,out l_ibrary);
      }

      public static void MemLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_MemLibNumDatasets(p,ref n_umdatasets);
      }

      public static void MemLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_MemLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void MemLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_MemLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void MemLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_MemLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void MemLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_MemLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void MemLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_MemLibDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void MemLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int a_tttype,ref int i_att) {
         vdm_MemLibDefAttribute(p, i_dst, n_ame, l_ength, a_tttype,ref i_att);
      }

      public static void MemLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_MemLibSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void MemLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_MemLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void MemLibNumDataset(IntPtr p,ref int n_umdataset) {
         vdm_MemLibNumDataset(p,ref n_umdataset);
      }

      public static void MemLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_MemLibWriteDataset(p, i_dst,ref b_uff);
      }

      public static void MemLibUpdate(IntPtr p) {
         vdm_MemLibUpdate(p);
      }

      public static void MemLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_MemLibLibDataset(p, o_per, i_dst);
      }

      public static void MemLibPushContainer(IntPtr p,StringBuilder n_ame) {
         vdm_MemLibPushContainer(p, n_ame);
      }

      public static void MemLibPopContainer(IntPtr p) {
         vdm_MemLibPopContainer(p);
      }

      public static void MemLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_MemLibSetString(p, t_ype, c_value);
      }

      public static void MemLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_MemLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void MemLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_MemLibDataFun(p, d_atafun);
      }

      public static void MemLibStreamNum(IntPtr p,ref long n_bytes) {
         vdm_MemLibStreamNum(p,ref n_bytes);
      }

      public static void MemLibStream(IntPtr p,ref IntPtr b_uff) {
         vdm_MemLibStream(p,ref b_uff);
      }

      public const int NAS_NUMRESTYPES = 17;
      public const int NASFIL_NUMUNREC = -1;
      public const int NASFIL_LINENUM = -2;
      public const int NASFIL_UNRECTYPE = -3;
      public const int NASFIL_UNRECCARD = -4;
      public const int NASFIL_UNRECCOMMAND = -5;
      public const int NASFIL_UNRECFIELD = -6;
      public const int NASFIL_UNRECFIELDVAL = -7;
      public const int NASFIL_RELATIVEPATH = 1;
      public const float NASFIL_RIGIDPBUSHVALUE = 1e11F;
      public const int NASFIL_NO_COORDINATE_SYSTEM = 0;
      public const int NASFIL_BASIC_COORDINATE_SYSTEM = 1;
      public const int NASFIL_GLOBAL_COORDINATE_SYSTEM = 2;
      public const int NASFIL_OFFSET_COORDINATE_SYSTEM = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_NASFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_NASFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetMonitorFunction(IntPtr p,VNASFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilPrintUnrecognizedData(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASFilDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr NASFilBegin() {
         return vdm_NASFilBegin();
      }

      public static void NASFilEnd(IntPtr p) {
         vdm_NASFilEnd(p);
      }

      public static int NASFilError(IntPtr p) {
         return vdm_NASFilError(p);
      }

      public static void NASFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NASFilGetString(p, t_ype, c_value);
      }

      public static void NASFilSetParami(IntPtr p,int t_ype,int i_param) {
         vdm_NASFilSetParami(p, t_ype, i_param);
      }

      public static void NASFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_NASFilSetMode(p, m_ode, f_lag);
      }

      public static void NASFilSetConvention(IntPtr p,long c_onvention) {
         vdm_NASFilSetConvention(p, c_onvention);
      }

      public static void NASFilSetStatus(IntPtr p,int s_tatus) {
         vdm_NASFilSetStatus(p, s_tatus);
      }

      public static void NASFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_NASFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void NASFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_NASFilGetConnect(p,out c_onnect);
      }

      public static void NASFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_NASFilSetConnect(p, c_onnect);
      }

      public static void NASFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_NASFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void NASFilSetMonitorFunction(IntPtr p,VNASFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_NASFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void NASFilAbort(IntPtr p) {
         vdm_NASFilAbort(p);
      }

      public static void NASFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_NASFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void NASFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_NASFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void NASFilClose(IntPtr p) {
         vdm_NASFilClose(p);
      }

      public static void NASFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_NASFilAppend(p, f_ilename, t_ype);
      }

      public static void NASFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_NASFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void NASFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_NASFilGetLibrary(p,out l_ibrary);
      }

      public static void NASFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_NASFilNumDatasets(p,ref n_umdatasets);
      }

      public static void NASFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_NASFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void NASFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_NASFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void NASFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_NASFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void NASFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_NASFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void NASFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_NASFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void NASFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_NASFilGetInteger(p, t_ype,ref i_value);
      }

      public static void NASFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_NASFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void NASFilPrintUnrecognizedData(IntPtr p) {
         vdm_NASFilPrintUnrecognizedData(p);
      }

      public static void NASFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_NASFilWriteModel(p, m_odel);
      }

      public static void NASFilWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_NASFilWriteState(p, r_prop, s_tate);
      }

      public static void NASFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_NASFilLibDataset(p, o_per, i_dst);
      }

      public static void NASFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NASFilSetString(p, t_ype, c_value);
      }

      public static void NASFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_NASFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void NASFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_NASFilDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_NASLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_NASLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetMonitorFunction(IntPtr p,VNASLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibOpenFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibAddDataset(IntPtr p,IntPtr n_asdat,IntPtr d_ataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSectInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSectComp(IntPtr p,int n_lent,ref int l_reccent,ref int l_recelno,StringBuilder d_ssect,ref int l_aysflag,StringBuilder d_slays);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSect(IntPtr p,IntPtr d_ataset,int i_nd,int n_step,StringBuilder d_ssect,int l_aysflag,StringBuilder d_slays);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibPlyRotAngComp(IntPtr p,StringBuilder d_nsect,int l_aysflag,StringBuilder d_nlays,StringBuilder d_nrota,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibPlyRotAngRead(IntPtr p,IntPtr d_srota,ref float f_buf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibElemTransform(IntPtr p,int n_,int e_code,int e_lrescs,int c_flag,int c_orde,int c_sopt,int n_cmp,int i_str,int c_plx,float [] f_b);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibOpenInit(IntPtr p,ref int n_umnp,ref int n_umel,ref int m_axnpe,ref long l_ngec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NASLibSetCoordinateSystems(IntPtr p,IntPtr c_oordinatesystems);

      public static IntPtr NASLibBegin() {
         return vdm_NASLibBegin();
      }

      public static void NASLibEnd(IntPtr p) {
         vdm_NASLibEnd(p);
      }

      public static int NASLibError(IntPtr p) {
         return vdm_NASLibError(p);
      }

      public static void NASLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_NASLibGetInteger(p, t_ype,ref i_value);
      }

      public static void NASLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NASLibGetString(p, t_ype, c_value);
      }

      public static void NASLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_NASLibSetMode(p, m_ode, f_lag);
      }

      public static void NASLibSetConvention(IntPtr p,long c_onvention) {
         vdm_NASLibSetConvention(p, c_onvention);
      }

      public static void NASLibSetStatus(IntPtr p,int s_tatus) {
         vdm_NASLibSetStatus(p, s_tatus);
      }

      public static void NASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_NASLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void NASLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_NASLibSetConnect(p, c_onnect);
      }

      public static void NASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_NASLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void NASLibSetMonitorFunction(IntPtr p,VNASLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_NASLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void NASLibAbort(IntPtr p) {
         vdm_NASLibAbort(p);
      }

      public static void NASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_NASLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void NASLibOpenFile(IntPtr p) {
         vdm_NASLibOpenFile(p);
      }

      public static void NASLibCloseFile(IntPtr p) {
         vdm_NASLibCloseFile(p);
      }

      public static void NASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_NASLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void NASLibClose(IntPtr p) {
         vdm_NASLibClose(p);
      }

      public static void NASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_NASLibAppend(p, f_ilename, t_ype);
      }

      public static void NASLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_NASLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void NASLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_NASLibGetLibrary(p,out l_ibrary);
      }

      public static void NASLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_NASLibNumDatasets(p,ref n_umdatasets);
      }

      public static void NASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_NASLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void NASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_NASLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void NASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_NASLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void NASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_NASLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void NASLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_NASLibGetConnect(p,out c_onnect);
      }

      public static void NASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_NASLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void NASLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_NASLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void NASLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_NASLibLibDataset(p, o_per, i_dst);
      }

      public static void NASLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NASLibSetString(p, t_ype, c_value);
      }

      public static void NASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_NASLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void NASLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_NASLibDataFun(p, d_atafun);
      }

      public static void NASLibAddDataset(IntPtr p,IntPtr n_asdat,IntPtr d_ataset) {
         vdm_NASLibAddDataset(p, n_asdat, d_ataset);
      }

      public static void NASLibSectInit(IntPtr p) {
         vdm_NASLibSectInit(p);
      }

      public static void NASLibSectComp(IntPtr p,int n_lent,ref int l_reccent,ref int l_recelno,StringBuilder d_ssect,ref int l_aysflag,StringBuilder d_slays) {
         vdm_NASLibSectComp(p, n_lent,ref l_reccent,ref l_recelno, d_ssect,ref l_aysflag, d_slays);
      }

      public static void NASLibSect(IntPtr p,IntPtr d_ataset,int i_nd,int n_step,StringBuilder d_ssect,int l_aysflag,StringBuilder d_slays) {
         vdm_NASLibSect(p, d_ataset, i_nd, n_step, d_ssect, l_aysflag, d_slays);
      }

      public static void NASLibPlyRotAngComp(IntPtr p,StringBuilder d_nsect,int l_aysflag,StringBuilder d_nlays,StringBuilder d_nrota,ref int f_lag) {
         vdm_NASLibPlyRotAngComp(p, d_nsect, l_aysflag, d_nlays, d_nrota,ref f_lag);
      }

      public static void NASLibPlyRotAngRead(IntPtr p,IntPtr d_srota,ref float f_buf) {
         vdm_NASLibPlyRotAngRead(p, d_srota,ref f_buf);
      }

      public static void NASLibElemTransform(IntPtr p,int n_,int e_code,int e_lrescs,int c_flag,int c_orde,int c_sopt,int n_cmp,int i_str,int c_plx,float [] f_b) {
         vdm_NASLibElemTransform(p, n_, e_code, e_lrescs, c_flag, c_orde, c_sopt, n_cmp, i_str, c_plx, f_b);
      }

      public static void NASLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_NASLibWriteModel(p, m_odel);
      }

      public static void NASLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_NASLibWriteState(p, r_prop, s_tate);
      }

      public static void NASLibOpenInit(IntPtr p,ref int n_umnp,ref int n_umel,ref int m_axnpe,ref long l_ngec) {
         vdm_NASLibOpenInit(p,ref n_umnp,ref n_umel,ref m_axnpe,ref l_ngec);
      }

      public static void NASLibSetCoordinateSystems(IntPtr p,IntPtr c_oordinatesystems) {
         vdm_NASLibSetCoordinateSystems(p, c_oordinatesystems);
      }

      public const int MAXNATDATASET = 4096;
      public const int NATLIB_BASE = 0;
      public const int NATLIB_SWAP = 1;
      public const int NATLIB_VERSION = -1;
      public const int NATLIB_CREATEDATE = -2;
      public const int NATLIB_CREATETIME = -3;
      public const int NATLIB_UPDATEDATE = -4;
      public const int NATLIB_UPDATETIME = -5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_NatLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_NatLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetInteger(IntPtr p,int t_ype,ref int p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetMonitorFunction(IntPtr p,VNatLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibNumDataset(IntPtr p,ref int n_umdataset);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibUpdate(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibPushContainer(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_NatLibSetRaggedPtr(IntPtr p,int n_col,int [] s_ize);

      public static IntPtr NatLibBegin() {
         return vdm_NatLibBegin();
      }

      public static void NatLibEnd(IntPtr p) {
         vdm_NatLibEnd(p);
      }

      public static int NatLibError(IntPtr p) {
         return vdm_NatLibError(p);
      }

      public static void NatLibGetInteger(IntPtr p,int t_ype,ref int p_aram) {
         vdm_NatLibGetInteger(p, t_ype,ref p_aram);
      }

      public static void NatLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NatLibGetString(p, t_ype, c_value);
      }

      public static void NatLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_NatLibSetMode(p, m_ode, f_lag);
      }

      public static void NatLibSetConvention(IntPtr p,long c_onvention) {
         vdm_NatLibSetConvention(p, c_onvention);
      }

      public static void NatLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_NatLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void NatLibSetStatus(IntPtr p,int s_tatus) {
         vdm_NatLibSetStatus(p, s_tatus);
      }

      public static void NatLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_NatLibSetConnect(p, c_onnect);
      }

      public static void NatLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_NatLibGetConnect(p,out c_onnect);
      }

      public static void NatLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_NatLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void NatLibSetMonitorFunction(IntPtr p,VNatLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_NatLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void NatLibAbort(IntPtr p) {
         vdm_NatLibAbort(p);
      }

      public static void NatLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_NatLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void NatLibOpen(IntPtr p,int m_ode,StringBuilder p_ath,int t_ype) {
         vdm_NatLibOpen(p, m_ode, p_ath, t_ype);
      }

      public static void NatLibClose(IntPtr p) {
         vdm_NatLibClose(p);
      }

      public static void NatLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_NatLibAppend(p, f_ilename, t_ype);
      }

      public static void NatLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_NatLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void NatLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_NatLibGetLibrary(p,out l_ibrary);
      }

      public static void NatLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_NatLibNumDatasets(p,ref n_umdatasets);
      }

      public static void NatLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_NatLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void NatLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_NatLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void NatLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_NatLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void NatLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_NatLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void NatLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_NatLibDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void NatLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att) {
         vdm_NatLibDefAttribute(p, i_dst, n_ame, l_ength, t_ype,ref i_att);
      }

      public static void NatLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_NatLibSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void NatLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_NatLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void NatLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_NatLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void NatLibNumDataset(IntPtr p,ref int n_umdataset) {
         vdm_NatLibNumDataset(p,ref n_umdataset);
      }

      public static void NatLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_NatLibWriteDataset(p, i_dst,ref b_uff);
      }

      public static void NatLibUpdate(IntPtr p) {
         vdm_NatLibUpdate(p);
      }

      public static void NatLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_NatLibLibDataset(p, o_per, i_dst);
      }

      public static void NatLibPushContainer(IntPtr p,StringBuilder n_ame) {
         vdm_NatLibPushContainer(p, n_ame);
      }

      public static void NatLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_NatLibSetString(p, t_ype, c_value);
      }

      public static void NatLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_NatLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void NatLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_NatLibDataFun(p, d_atafun);
      }

      public static void NatLibSetRaggedPtr(IntPtr p,int n_col,int [] s_ize) {
         vdm_NatLibSetRaggedPtr(p, n_col, s_ize);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_OBJFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_OBJFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetMonitorFunction(IntPtr p,VOBJFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OBJFilDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr OBJFilBegin() {
         return vdm_OBJFilBegin();
      }

      public static void OBJFilEnd(IntPtr p) {
         vdm_OBJFilEnd(p);
      }

      public static int OBJFilError(IntPtr p) {
         return vdm_OBJFilError(p);
      }

      public static void OBJFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_OBJFilGetInteger(p, t_ype,ref i_value);
      }

      public static void OBJFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_OBJFilGetString(p, t_ype, c_value);
      }

      public static void OBJFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_OBJFilSetMode(p, m_ode, f_lag);
      }

      public static void OBJFilSetConvention(IntPtr p,long c_onvention) {
         vdm_OBJFilSetConvention(p, c_onvention);
      }

      public static void OBJFilSetStatus(IntPtr p,int s_tatus) {
         vdm_OBJFilSetStatus(p, s_tatus);
      }

      public static void OBJFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_OBJFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void OBJFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_OBJFilGetConnect(p,out c_onnect);
      }

      public static void OBJFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_OBJFilSetConnect(p, c_onnect);
      }

      public static void OBJFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_OBJFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void OBJFilSetMonitorFunction(IntPtr p,VOBJFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_OBJFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void OBJFilAbort(IntPtr p) {
         vdm_OBJFilAbort(p);
      }

      public static void OBJFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_OBJFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void OBJFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_OBJFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void OBJFilClose(IntPtr p) {
         vdm_OBJFilClose(p);
      }

      public static void OBJFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_OBJFilAppend(p, f_ilename, t_ype);
      }

      public static void OBJFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_OBJFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void OBJFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_OBJFilGetLibrary(p,out l_ibrary);
      }

      public static void OBJFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_OBJFilNumDatasets(p,ref n_umdatasets);
      }

      public static void OBJFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_OBJFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void OBJFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_OBJFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void OBJFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_OBJFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void OBJFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_OBJFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void OBJFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_OBJFilReadDataset(p, i_dst,ref b_uff);
      }

      public static void OBJFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_OBJFilLibDataset(p, o_per, i_dst);
      }

      public static void OBJFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_OBJFilWriteModel(p, m_odel);
      }

      public static void OBJFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_OBJFilSetString(p, t_ype, c_value);
      }

      public static void OBJFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_OBJFilDataFun(p, d_atafun);
      }

      public const int OPENFOAMLIB_SEARCH_DEFAULT = 0;
      public const int OPENFOAMLIB_SEARCH_RECONSTRUCT = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_OpenFOAMLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_OpenFOAMLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetMonitorFunction(IntPtr p,VOpenFOAMLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_OpenFOAMLibSetSearch(IntPtr p,int s_earch);

      public static IntPtr OpenFOAMLibBegin() {
         return vdm_OpenFOAMLibBegin();
      }

      public static void OpenFOAMLibEnd(IntPtr p) {
         vdm_OpenFOAMLibEnd(p);
      }

      public static int OpenFOAMLibError(IntPtr p) {
         return vdm_OpenFOAMLibError(p);
      }

      public static void OpenFOAMLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_OpenFOAMLibSetMode(p, m_ode, f_lag);
      }

      public static void OpenFOAMLibSetConvention(IntPtr p,long c_onvention) {
         vdm_OpenFOAMLibSetConvention(p, c_onvention);
      }

      public static void OpenFOAMLibSetStatus(IntPtr p,int s_tatus) {
         vdm_OpenFOAMLibSetStatus(p, s_tatus);
      }

      public static void OpenFOAMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_OpenFOAMLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void OpenFOAMLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_OpenFOAMLibGetConnect(p,out c_onnect);
      }

      public static void OpenFOAMLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_OpenFOAMLibSetConnect(p, c_onnect);
      }

      public static void OpenFOAMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_OpenFOAMLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void OpenFOAMLibSetMonitorFunction(IntPtr p,VOpenFOAMLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_OpenFOAMLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void OpenFOAMLibAbort(IntPtr p) {
         vdm_OpenFOAMLibAbort(p);
      }

      public static void OpenFOAMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_OpenFOAMLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void OpenFOAMLibClose(IntPtr p) {
         vdm_OpenFOAMLibClose(p);
      }

      public static void OpenFOAMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_OpenFOAMLibAppend(p, f_ilename, t_ype);
      }

      public static void OpenFOAMLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_OpenFOAMLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void OpenFOAMLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_OpenFOAMLibGetLibrary(p,out l_ibrary);
      }

      public static void OpenFOAMLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_OpenFOAMLibNumDatasets(p,ref n_umdatasets);
      }

      public static void OpenFOAMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_OpenFOAMLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void OpenFOAMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_OpenFOAMLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void OpenFOAMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_OpenFOAMLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void OpenFOAMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_OpenFOAMLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void OpenFOAMLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_OpenFOAMLibWriteModel(p, m_odel);
      }

      public static void OpenFOAMLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_OpenFOAMLibLibDataset(p, o_per, i_dst);
      }

      public static void OpenFOAMLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_OpenFOAMLibDataFun(p, d_atafun);
      }

      public static void OpenFOAMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_OpenFOAMLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void OpenFOAMLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_OpenFOAMLibGetInteger(p, t_ype,ref i_value);
      }

      public static void OpenFOAMLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_OpenFOAMLibGetString(p, t_ype, c_value);
      }

      public static void OpenFOAMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_OpenFOAMLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void OpenFOAMLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_OpenFOAMLibSetString(p, t_ype, c_value);
      }

      public static void OpenFOAMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_OpenFOAMLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void OpenFOAMLibSetSearch(IntPtr p,int s_earch) {
         vdm_OpenFOAMLibSetSearch(p, s_earch);
      }

      public const int PAMFIL_NUMRESTYPES = 32;
      public const int PAMFIL_NUMUNREC = -1;
      public const int PAMFIL_LINENUM = -2;
      public const int PAMFIL_UNRECKEYWORD = -3;
      public const int PAMFIL_UNRECDATALINE = -4;
      public const int PAMFIL_UNRECFILE = -5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PAMFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PAMFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetMonitorFunction(IntPtr p,VPAMFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilDataFun(IntPtr p,IntPtr d_f);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMFilPrintUnrecognizedData(IntPtr p);

      public static IntPtr PAMFilBegin() {
         return vdm_PAMFilBegin();
      }

      public static void PAMFilEnd(IntPtr p) {
         vdm_PAMFilEnd(p);
      }

      public static int PAMFilError(IntPtr p) {
         return vdm_PAMFilError(p);
      }

      public static void PAMFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PAMFilSetMode(p, m_ode, f_lag);
      }

      public static void PAMFilSetConvention(IntPtr p,long c_onvention) {
         vdm_PAMFilSetConvention(p, c_onvention);
      }

      public static void PAMFilSetStatus(IntPtr p,int s_tatus) {
         vdm_PAMFilSetStatus(p, s_tatus);
      }

      public static void PAMFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_PAMFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void PAMFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PAMFilGetConnect(p,out c_onnect);
      }

      public static void PAMFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PAMFilSetConnect(p, c_onnect);
      }

      public static void PAMFilSetFunction(IntPtr p,int f_unctype,Vfunc f_unction,IntPtr o_bject) {
         vdm_PAMFilSetFunction(p, f_unctype, f_unction, o_bject);
      }

      public static void PAMFilSetMonitorFunction(IntPtr p,VPAMFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_PAMFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void PAMFilAbort(IntPtr p) {
         vdm_PAMFilAbort(p);
      }

      public static void PAMFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PAMFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void PAMFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PAMFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PAMFilClose(IntPtr p) {
         vdm_PAMFilClose(p);
      }

      public static void PAMFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PAMFilAppend(p, f_ilename, t_ype);
      }

      public static void PAMFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_PAMFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void PAMFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PAMFilGetLibrary(p,out l_ibrary);
      }

      public static void PAMFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PAMFilNumDatasets(p,ref n_umdatasets);
      }

      public static void PAMFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_PAMFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void PAMFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PAMFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PAMFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PAMFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PAMFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PAMFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PAMFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_PAMFilReadDataset(p, i_dst,ref b_uf);
      }

      public static void PAMFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PAMFilGetInteger(p, t_ype,ref i_value);
      }

      public static void PAMFilGetStringPtr(IntPtr p,int t_ype,out IntPtr s_tring) {
         vdm_PAMFilGetStringPtr(p, t_ype,out s_tring);
      }

      public static void PAMFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PAMFilGetString(p, t_ype, c_value);
      }

      public static void PAMFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_PAMFilWriteModel(p, m_odel);
      }

      public static void PAMFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PAMFilLibDataset(p, o_per, i_dst);
      }

      public static void PAMFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PAMFilSetString(p, t_ype, c_value);
      }

      public static void PAMFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_PAMFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void PAMFilDataFun(IntPtr p,IntPtr d_f) {
         vdm_PAMFilDataFun(p, d_f);
      }

      public static void PAMFilPrintUnrecognizedData(IntPtr p) {
         vdm_PAMFilPrintUnrecognizedData(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PAMLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PAMLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetMonitorFunction(IntPtr p,VPAMLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibWriteState(IntPtr p,IntPtr u_rprop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PAMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr PAMLibBegin() {
         return vdm_PAMLibBegin();
      }

      public static void PAMLibEnd(IntPtr p) {
         vdm_PAMLibEnd(p);
      }

      public static int PAMLibError(IntPtr p) {
         return vdm_PAMLibError(p);
      }

      public static void PAMLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PAMLibSetMode(p, m_ode, f_lag);
      }

      public static void PAMLibSetConvention(IntPtr p,long c_onvention) {
         vdm_PAMLibSetConvention(p, c_onvention);
      }

      public static void PAMLibSetStatus(IntPtr p,int s_tatus) {
         vdm_PAMLibSetStatus(p, s_tatus);
      }

      public static void PAMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_PAMLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void PAMLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PAMLibGetConnect(p,out c_onnect);
      }

      public static void PAMLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PAMLibSetConnect(p, c_onnect);
      }

      public static void PAMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_PAMLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void PAMLibSetMonitorFunction(IntPtr p,VPAMLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_PAMLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void PAMLibAbort(IntPtr p) {
         vdm_PAMLibAbort(p);
      }

      public static void PAMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PAMLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PAMLibClose(IntPtr p) {
         vdm_PAMLibClose(p);
      }

      public static void PAMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PAMLibAppend(p, f_ilename, t_ype);
      }

      public static void PAMLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_PAMLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void PAMLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PAMLibGetLibrary(p,out l_ibrary);
      }

      public static void PAMLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PAMLibNumDatasets(p,ref n_umdatasets);
      }

      public static void PAMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_PAMLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void PAMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PAMLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PAMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PAMLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PAMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PAMLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PAMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_PAMLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void PAMLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_PAMLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void PAMLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PAMLibLibDataset(p, o_per, i_dst);
      }

      public static void PAMLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PAMLibSetString(p, t_ype, c_value);
      }

      public static void PAMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_PAMLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void PAMLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_PAMLibDataFun(p, d_atafun);
      }

      public static void PAMLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_PAMLibWriteModel(p, m_odel);
      }

      public static void PAMLibWriteState(IntPtr p,IntPtr u_rprop,IntPtr s_tate) {
         vdm_PAMLibWriteState(p, u_rprop, s_tate);
      }

      public static void PAMLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PAMLibGetInteger(p, t_ype,ref i_value);
      }

      public static void PAMLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PAMLibGetString(p, t_ype, c_value);
      }

      public static void PAMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PAMLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int PAM_LAYERPOSITION_BEAM1 = 9;
      public const int PAM_LAYERPOSITION_BEAM2 = 10;
      public const int PAM_LAYERPOSITION_BEAM3 = 11;
      public const int PAM_LAYERPOSITION_BEAM4 = 12;
      public const int PAM_LAYERPOSITION_BEAM12 = 13;
      public const int PAM_LAYERPOSITION_BEAM13 = 14;
      public const int PAM_LAYERPOSITION_BEAM14 = 15;
      public const int PAM_LAYERPOSITION_BEAM23 = 16;
      public const int PAM_LAYERPOSITION_BEAM24 = 17;
      public const int PAM_LAYERPOSITION_BEAM34 = 18;
      public const int PAM_LAYERPOSITION_BEAM123 = 19;
      public const int PAM_LAYERPOSITION_BEAM124 = 20;
      public const int PAM_LAYERPOSITION_BEAM234 = 21;
      public const int PAM_LAYERPOSITION_BEAM134 = 22;
      public const int PAM_LAYERPOSITION_BEAM1234 = 23;

      public const int PATLIB_NODAL = 1;
      public const int PATLIB_DISPLACEMENT = 2;
      public const int PATLIB_ELEMENTAL = 3;
      public const int PATLIB_TITLE_MAXNAME = 83;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PatLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PatLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetMonitorFunction(IntPtr p,VPatLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetResultCols(IntPtr p,int n_cols,int [] i_cols);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetResultType(IntPtr p,int r_type,int r_estype,int s_ect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PatLibDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr PatLibBegin() {
         return vdm_PatLibBegin();
      }

      public static void PatLibEnd(IntPtr p) {
         vdm_PatLibEnd(p);
      }

      public static int PatLibError(IntPtr p) {
         return vdm_PatLibError(p);
      }

      public static void PatLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PatLibGetInteger(p, t_ype,ref i_value);
      }

      public static void PatLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PatLibGetString(p, t_ype, c_value);
      }

      public static void PatLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PatLibSetMode(p, m_ode, f_lag);
      }

      public static void PatLibSetConvention(IntPtr p,long c_onvention) {
         vdm_PatLibSetConvention(p, c_onvention);
      }

      public static void PatLibSetStatus(IntPtr p,int s_tatus) {
         vdm_PatLibSetStatus(p, s_tatus);
      }

      public static void PatLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_PatLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void PatLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PatLibSetConnect(p, c_onnect);
      }

      public static void PatLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PatLibGetConnect(p,out c_onnect);
      }

      public static void PatLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_PatLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void PatLibSetMonitorFunction(IntPtr p,VPatLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_PatLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void PatLibAbort(IntPtr p) {
         vdm_PatLibAbort(p);
      }

      public static void PatLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PatLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void PatLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PatLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PatLibClose(IntPtr p) {
         vdm_PatLibClose(p);
      }

      public static void PatLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PatLibAppend(p, f_ilename, t_ype);
      }

      public static void PatLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_PatLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void PatLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PatLibGetLibrary(p,out l_ibrary);
      }

      public static void PatLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PatLibNumDatasets(p,ref n_umdatasets);
      }

      public static void PatLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_PatLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void PatLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PatLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PatLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PatLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PatLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PatLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PatLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_PatLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void PatLibSetResultCols(IntPtr p,int n_cols,int [] i_cols) {
         vdm_PatLibSetResultCols(p, n_cols, i_cols);
      }

      public static void PatLibSetResultType(IntPtr p,int r_type,int r_estype,int s_ect) {
         vdm_PatLibSetResultType(p, r_type, r_estype, s_ect);
      }

      public static void PatLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_PatLibWriteModel(p, m_odel);
      }

      public static void PatLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_PatLibWriteState(p, r_prop, s_tate);
      }

      public static void PatLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PatLibLibDataset(p, o_per, i_dst);
      }

      public static void PatLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PatLibSetString(p, t_ype, c_value);
      }

      public static void PatLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_PatLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void PatLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_PatLibDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PERMASLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PERMASLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetOpenLib(IntPtr p,IntPtr o_penlib);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetMonitorFunction(IntPtr p,VPERMASLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,long [] l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PERMASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr PERMASLibBegin() {
         return vdm_PERMASLibBegin();
      }

      public static void PERMASLibEnd(IntPtr p) {
         vdm_PERMASLibEnd(p);
      }

      public static int PERMASLibError(IntPtr p) {
         return vdm_PERMASLibError(p);
      }

      public static void PERMASLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PERMASLibSetMode(p, m_ode, f_lag);
      }

      public static void PERMASLibSetConvention(IntPtr p,long c_onvention) {
         vdm_PERMASLibSetConvention(p, c_onvention);
      }

      public static void PERMASLibSetStatus(IntPtr p,int s_tatus) {
         vdm_PERMASLibSetStatus(p, s_tatus);
      }

      public static void PERMASLibSetOpenLib(IntPtr p,IntPtr o_penlib) {
         vdm_PERMASLibSetOpenLib(p, o_penlib);
      }

      public static void PERMASLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PERMASLibSetConnect(p, c_onnect);
      }

      public static void PERMASLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PERMASLibGetConnect(p,out c_onnect);
      }

      public static void PERMASLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_PERMASLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void PERMASLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_PERMASLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void PERMASLibSetMonitorFunction(IntPtr p,VPERMASLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_PERMASLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void PERMASLibAbort(IntPtr p) {
         vdm_PERMASLibAbort(p);
      }

      public static void PERMASLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PERMASLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PERMASLibClose(IntPtr p) {
         vdm_PERMASLibClose(p);
      }

      public static void PERMASLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PERMASLibAppend(p, f_ilename, t_ype);
      }

      public static void PERMASLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_PERMASLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void PERMASLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PERMASLibGetLibrary(p,out l_ibrary);
      }

      public static void PERMASLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PERMASLibNumDatasets(p,ref n_umdatasets);
      }

      public static void PERMASLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_PERMASLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void PERMASLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PERMASLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PERMASLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PERMASLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PERMASLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PERMASLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PERMASLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_PERMASLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void PERMASLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,long [] l_ptr) {
         vdm_PERMASLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf, l_ptr);
      }

      public static void PERMASLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PERMASLibLibDataset(p, o_per, i_dst);
      }

      public static void PERMASLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PERMASLibSetString(p, t_ype, c_value);
      }

      public static void PERMASLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_PERMASLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void PERMASLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_PERMASLibDataFun(p, d_atafun);
      }

      public static void PERMASLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PERMASLibGetInteger(p, t_ype,ref i_value);
      }

      public static void PERMASLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PERMASLibGetString(p, t_ype, c_value);
      }

      public static void PERMASLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PERMASLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int PERMASLIB_NONE = 0;
      public const int PERMASLIB_CORNER = 1;
      public const int PERMASLIB_SECTION = 2;

      public const int PLOT3DLIB_AUTO = 0;
      public const int PLOT3DLIB_SINGLE = 1;
      public const int PLOT3DLIB_MULTIPLE = 2;
      public const int PLOT3DLIB_1D = 1;
      public const int PLOT3DLIB_2D = 2;
      public const int PLOT3DLIB_3DWHOLE = 3;
      public const int PLOT3DLIB_3DPLANES = 4;
      public const int PLOT3DLIB_UNSTRUCTURED = 5;
      public const int PLOT3DLIB_Q = 1;
      public const int PLOT3DLIB_FUNCTION = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PLOT3DLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PLOT3DLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetMonitorFunction(IntPtr p,VPLOT3DLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetGridType(IntPtr p,int g_type,int d_ime,int i_blank);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetResultType(IntPtr p,int r_type,int r_estype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PLOT3DLibDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr PLOT3DLibBegin() {
         return vdm_PLOT3DLibBegin();
      }

      public static void PLOT3DLibEnd(IntPtr p) {
         vdm_PLOT3DLibEnd(p);
      }

      public static int PLOT3DLibError(IntPtr p) {
         return vdm_PLOT3DLibError(p);
      }

      public static void PLOT3DLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PLOT3DLibGetInteger(p, t_ype,ref i_value);
      }

      public static void PLOT3DLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PLOT3DLibGetString(p, t_ype, c_value);
      }

      public static void PLOT3DLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PLOT3DLibSetMode(p, m_ode, f_lag);
      }

      public static void PLOT3DLibSetConvention(IntPtr p,long c_onvention) {
         vdm_PLOT3DLibSetConvention(p, c_onvention);
      }

      public static void PLOT3DLibSetStatus(IntPtr p,int s_tatus) {
         vdm_PLOT3DLibSetStatus(p, s_tatus);
      }

      public static void PLOT3DLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_PLOT3DLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void PLOT3DLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PLOT3DLibSetConnect(p, c_onnect);
      }

      public static void PLOT3DLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PLOT3DLibGetConnect(p,out c_onnect);
      }

      public static void PLOT3DLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_PLOT3DLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void PLOT3DLibSetMonitorFunction(IntPtr p,VPLOT3DLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_PLOT3DLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void PLOT3DLibAbort(IntPtr p) {
         vdm_PLOT3DLibAbort(p);
      }

      public static void PLOT3DLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PLOT3DLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void PLOT3DLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PLOT3DLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PLOT3DLibClose(IntPtr p) {
         vdm_PLOT3DLibClose(p);
      }

      public static void PLOT3DLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PLOT3DLibAppend(p, f_ilename, t_ype);
      }

      public static void PLOT3DLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_PLOT3DLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void PLOT3DLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PLOT3DLibGetLibrary(p,out l_ibrary);
      }

      public static void PLOT3DLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PLOT3DLibNumDatasets(p,ref n_umdatasets);
      }

      public static void PLOT3DLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_PLOT3DLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void PLOT3DLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PLOT3DLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PLOT3DLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PLOT3DLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PLOT3DLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PLOT3DLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PLOT3DLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_PLOT3DLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void PLOT3DLibSetGridType(IntPtr p,int g_type,int d_ime,int i_blank) {
         vdm_PLOT3DLibSetGridType(p, g_type, d_ime, i_blank);
      }

      public static void PLOT3DLibSetResultType(IntPtr p,int r_type,int r_estype) {
         vdm_PLOT3DLibSetResultType(p, r_type, r_estype);
      }

      public static void PLOT3DLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PLOT3DLibLibDataset(p, o_per, i_dst);
      }

      public static void PLOT3DLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PLOT3DLibSetString(p, t_ype, c_value);
      }

      public static void PLOT3DLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_PLOT3DLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void PLOT3DLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_PLOT3DLibDataFun(p, d_atafun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_POLYFLOWLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_POLYFLOWLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetMonitorFunction(IntPtr p,VPOLYFLOWLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_POLYFLOWLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr POLYFLOWLibBegin() {
         return vdm_POLYFLOWLibBegin();
      }

      public static void POLYFLOWLibEnd(IntPtr p) {
         vdm_POLYFLOWLibEnd(p);
      }

      public static int POLYFLOWLibError(IntPtr p) {
         return vdm_POLYFLOWLibError(p);
      }

      public static void POLYFLOWLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_POLYFLOWLibSetMode(p, m_ode, f_lag);
      }

      public static void POLYFLOWLibSetConvention(IntPtr p,long c_onvention) {
         vdm_POLYFLOWLibSetConvention(p, c_onvention);
      }

      public static void POLYFLOWLibSetStatus(IntPtr p,int s_tatus) {
         vdm_POLYFLOWLibSetStatus(p, s_tatus);
      }

      public static void POLYFLOWLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_POLYFLOWLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void POLYFLOWLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_POLYFLOWLibGetConnect(p,out c_onnect);
      }

      public static void POLYFLOWLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_POLYFLOWLibSetConnect(p, c_onnect);
      }

      public static void POLYFLOWLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_POLYFLOWLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void POLYFLOWLibSetMonitorFunction(IntPtr p,VPOLYFLOWLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_POLYFLOWLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void POLYFLOWLibAbort(IntPtr p) {
         vdm_POLYFLOWLibAbort(p);
      }

      public static void POLYFLOWLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_POLYFLOWLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void POLYFLOWLibClose(IntPtr p) {
         vdm_POLYFLOWLibClose(p);
      }

      public static void POLYFLOWLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_POLYFLOWLibAppend(p, f_ilename, t_ype);
      }

      public static void POLYFLOWLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_POLYFLOWLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void POLYFLOWLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_POLYFLOWLibGetLibrary(p,out l_ibrary);
      }

      public static void POLYFLOWLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_POLYFLOWLibNumDatasets(p,ref n_umdatasets);
      }

      public static void POLYFLOWLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_POLYFLOWLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void POLYFLOWLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_POLYFLOWLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void POLYFLOWLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_POLYFLOWLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void POLYFLOWLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_POLYFLOWLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void POLYFLOWLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_POLYFLOWLibReadDataset(p, i_dst,ref b_uff);
      }

      public static void POLYFLOWLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_POLYFLOWLibLibDataset(p, o_per, i_dst);
      }

      public static void POLYFLOWLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_POLYFLOWLibSetString(p, t_ype, c_value);
      }

      public static void POLYFLOWLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_POLYFLOWLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void POLYFLOWLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_POLYFLOWLibDataFun(p, d_atafun);
      }

      public static void POLYFLOWLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_POLYFLOWLibGetInteger(p, t_ype,ref i_value);
      }

      public static void POLYFLOWLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_POLYFLOWLibGetString(p, t_ype, c_value);
      }

      public static void POLYFLOWLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_POLYFLOWLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_SAMCEFLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_SAMCEFLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetMonitorFunction(IntPtr p,VSAMCEFLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,long [] l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SAMCEFLibSetTempDir(IntPtr p,StringBuilder n_ame);

      public static IntPtr SAMCEFLibBegin() {
         return vdm_SAMCEFLibBegin();
      }

      public static void SAMCEFLibEnd(IntPtr p) {
         vdm_SAMCEFLibEnd(p);
      }

      public static int SAMCEFLibError(IntPtr p) {
         return vdm_SAMCEFLibError(p);
      }

      public static void SAMCEFLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_SAMCEFLibSetMode(p, m_ode, f_lag);
      }

      public static void SAMCEFLibSetConvention(IntPtr p,long c_onvention) {
         vdm_SAMCEFLibSetConvention(p, c_onvention);
      }

      public static void SAMCEFLibSetStatus(IntPtr p,int s_tatus) {
         vdm_SAMCEFLibSetStatus(p, s_tatus);
      }

      public static void SAMCEFLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_SAMCEFLibSetConnect(p, c_onnect);
      }

      public static void SAMCEFLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_SAMCEFLibGetConnect(p,out c_onnect);
      }

      public static void SAMCEFLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_SAMCEFLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void SAMCEFLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_SAMCEFLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void SAMCEFLibSetMonitorFunction(IntPtr p,VSAMCEFLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_SAMCEFLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void SAMCEFLibAbort(IntPtr p) {
         vdm_SAMCEFLibAbort(p);
      }

      public static void SAMCEFLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_SAMCEFLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void SAMCEFLibClose(IntPtr p) {
         vdm_SAMCEFLibClose(p);
      }

      public static void SAMCEFLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_SAMCEFLibAppend(p, f_ilename, t_ype);
      }

      public static void SAMCEFLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_SAMCEFLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void SAMCEFLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_SAMCEFLibGetLibrary(p,out l_ibrary);
      }

      public static void SAMCEFLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_SAMCEFLibNumDatasets(p,ref n_umdatasets);
      }

      public static void SAMCEFLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_SAMCEFLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void SAMCEFLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_SAMCEFLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void SAMCEFLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_SAMCEFLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void SAMCEFLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_SAMCEFLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void SAMCEFLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_SAMCEFLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void SAMCEFLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,long [] l_ptr) {
         vdm_SAMCEFLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf, l_ptr);
      }

      public static void SAMCEFLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_SAMCEFLibLibDataset(p, o_per, i_dst);
      }

      public static void SAMCEFLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_SAMCEFLibSetString(p, t_ype, c_value);
      }

      public static void SAMCEFLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_SAMCEFLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void SAMCEFLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_SAMCEFLibDataFun(p, d_atafun);
      }

      public static void SAMCEFLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_SAMCEFLibGetInteger(p, t_ype,ref i_value);
      }

      public static void SAMCEFLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_SAMCEFLibGetString(p, t_ype, c_value);
      }

      public static void SAMCEFLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_SAMCEFLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void SAMCEFLibSetTempDir(IntPtr p,StringBuilder n_ame) {
         vdm_SAMCEFLibSetTempDir(p, n_ame);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_SDRCLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_SDRCLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetOpenLib(IntPtr p,IntPtr o_penlib);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetMonitorFunction(IntPtr p,VSDRCLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_SDRCLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      public static IntPtr SDRCLibBegin() {
         return vdm_SDRCLibBegin();
      }

      public static void SDRCLibEnd(IntPtr p) {
         vdm_SDRCLibEnd(p);
      }

      public static int SDRCLibError(IntPtr p) {
         return vdm_SDRCLibError(p);
      }

      public static void SDRCLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_SDRCLibGetInteger(p, t_ype,ref i_value);
      }

      public static void SDRCLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_SDRCLibGetString(p, t_ype, c_value);
      }

      public static void SDRCLibSetConvention(IntPtr p,long c_onvention) {
         vdm_SDRCLibSetConvention(p, c_onvention);
      }

      public static void SDRCLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_SDRCLibSetMode(p, m_ode, f_lag);
      }

      public static void SDRCLibSetStatus(IntPtr p,int s_tatus) {
         vdm_SDRCLibSetStatus(p, s_tatus);
      }

      public static void SDRCLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_SDRCLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void SDRCLibSetOpenLib(IntPtr p,IntPtr o_penlib) {
         vdm_SDRCLibSetOpenLib(p, o_penlib);
      }

      public static void SDRCLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_SDRCLibSetConnect(p, c_onnect);
      }

      public static void SDRCLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_SDRCLibGetConnect(p,out c_onnect);
      }

      public static void SDRCLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_SDRCLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void SDRCLibSetMonitorFunction(IntPtr p,VSDRCLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_SDRCLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void SDRCLibAbort(IntPtr p) {
         vdm_SDRCLibAbort(p);
      }

      public static void SDRCLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_SDRCLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void SDRCLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_SDRCLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void SDRCLibClose(IntPtr p) {
         vdm_SDRCLibClose(p);
      }

      public static void SDRCLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_SDRCLibAppend(p, f_ilename, t_ype);
      }

      public static void SDRCLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_SDRCLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void SDRCLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_SDRCLibGetLibrary(p,out l_ibrary);
      }

      public static void SDRCLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_SDRCLibNumDatasets(p,ref n_umdatasets);
      }

      public static void SDRCLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_SDRCLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void SDRCLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_SDRCLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void SDRCLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_SDRCLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void SDRCLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_SDRCLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void SDRCLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_SDRCLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void SDRCLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_SDRCLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void SDRCLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_SDRCLibLibDataset(p, o_per, i_dst);
      }

      public static void SDRCLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_SDRCLibSetString(p, t_ype, c_value);
      }

      public static void SDRCLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_SDRCLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void SDRCLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_SDRCLibDataFun(p, d_atafun);
      }

      public static void SDRCLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_SDRCLibWriteModel(p, m_odel);
      }

      public static void SDRCLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_SDRCLibWriteState(p, r_prop, s_tate);
      }

      public const int SDRC_NUMELEMTYPES = 196;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_STARCCMLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_STARCCMLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetMonitorFunction(IntPtr p,VSTARCCMLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibOpenFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STARCCMLibCloseFile(IntPtr p);

      public static IntPtr STARCCMLibBegin() {
         return vdm_STARCCMLibBegin();
      }

      public static void STARCCMLibEnd(IntPtr p) {
         vdm_STARCCMLibEnd(p);
      }

      public static int STARCCMLibError(IntPtr p) {
         return vdm_STARCCMLibError(p);
      }

      public static void STARCCMLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_STARCCMLibSetMode(p, m_ode, f_lag);
      }

      public static void STARCCMLibSetConvention(IntPtr p,long c_onvention) {
         vdm_STARCCMLibSetConvention(p, c_onvention);
      }

      public static void STARCCMLibSetStatus(IntPtr p,int s_tatus) {
         vdm_STARCCMLibSetStatus(p, s_tatus);
      }

      public static void STARCCMLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_STARCCMLibSetConnect(p, c_onnect);
      }

      public static void STARCCMLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_STARCCMLibGetConnect(p,out c_onnect);
      }

      public static void STARCCMLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_STARCCMLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void STARCCMLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_STARCCMLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void STARCCMLibSetMonitorFunction(IntPtr p,VSTARCCMLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_STARCCMLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void STARCCMLibAbort(IntPtr p) {
         vdm_STARCCMLibAbort(p);
      }

      public static void STARCCMLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_STARCCMLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void STARCCMLibClose(IntPtr p) {
         vdm_STARCCMLibClose(p);
      }

      public static void STARCCMLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_STARCCMLibAppend(p, f_ilename, t_ype);
      }

      public static void STARCCMLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_STARCCMLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void STARCCMLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_STARCCMLibGetLibrary(p,out l_ibrary);
      }

      public static void STARCCMLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_STARCCMLibNumDatasets(p,ref n_umdatasets);
      }

      public static void STARCCMLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_STARCCMLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void STARCCMLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_STARCCMLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void STARCCMLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_STARCCMLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void STARCCMLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_STARCCMLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void STARCCMLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_STARCCMLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void STARCCMLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_STARCCMLibLibDataset(p, o_per, i_dst);
      }

      public static void STARCCMLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_STARCCMLibSetString(p, t_ype, c_value);
      }

      public static void STARCCMLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_STARCCMLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void STARCCMLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_STARCCMLibDataFun(p, d_atafun);
      }

      public static void STARCCMLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_STARCCMLibGetInteger(p, t_ype,ref i_value);
      }

      public static void STARCCMLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_STARCCMLibGetString(p, t_ype, c_value);
      }

      public static void STARCCMLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_STARCCMLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void STARCCMLibOpenFile(IntPtr p) {
         vdm_STARCCMLibOpenFile(p);
      }

      public static void STARCCMLibCloseFile(IntPtr p) {
         vdm_STARCCMLibCloseFile(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_STLFilBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_STLFilError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetMonitorFunction(IntPtr p,VSTLFilMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_STLFilDataFun(IntPtr p,IntPtr d_atafun);

      public static IntPtr STLFilBegin() {
         return vdm_STLFilBegin();
      }

      public static void STLFilEnd(IntPtr p) {
         vdm_STLFilEnd(p);
      }

      public static int STLFilError(IntPtr p) {
         return vdm_STLFilError(p);
      }

      public static void STLFilGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_STLFilGetInteger(p, t_ype,ref i_value);
      }

      public static void STLFilGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_STLFilGetString(p, t_ype, c_value);
      }

      public static void STLFilSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_STLFilSetMode(p, m_ode, f_lag);
      }

      public static void STLFilSetConvention(IntPtr p,long c_onvention) {
         vdm_STLFilSetConvention(p, c_onvention);
      }

      public static void STLFilSetStatus(IntPtr p,int s_tatus) {
         vdm_STLFilSetStatus(p, s_tatus);
      }

      public static void STLFilSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_STLFilSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void STLFilGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_STLFilGetConnect(p,out c_onnect);
      }

      public static void STLFilSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_STLFilSetConnect(p, c_onnect);
      }

      public static void STLFilSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_STLFilSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void STLFilSetMonitorFunction(IntPtr p,VSTLFilMonitorFunc f_unction,IntPtr o_bject) {
         vdm_STLFilSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void STLFilAbort(IntPtr p) {
         vdm_STLFilAbort(p);
      }

      public static void STLFilNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_STLFilNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void STLFilOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_STLFilOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void STLFilClose(IntPtr p) {
         vdm_STLFilClose(p);
      }

      public static void STLFilAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_STLFilAppend(p, f_ilename, t_ype);
      }

      public static void STLFilGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_STLFilGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void STLFilGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_STLFilGetLibrary(p,out l_ibrary);
      }

      public static void STLFilNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_STLFilNumDatasets(p,ref n_umdatasets);
      }

      public static void STLFilNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_STLFilNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void STLFilGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_STLFilGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void STLFilInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_STLFilInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void STLFilInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_STLFilInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void STLFilReadDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_STLFilReadDataset(p, i_dst,ref b_uff);
      }

      public static void STLFilLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_STLFilLibDataset(p, o_per, i_dst);
      }

      public static void STLFilWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_STLFilWriteModel(p, m_odel);
      }

      public static void STLFilSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_STLFilSetString(p, t_ype, c_value);
      }

      public static void STLFilGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_STLFilGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void STLFilDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_STLFilDataFun(p, d_atafun);
      }

      public const int TECPLOTLIB_MERGESHAPE = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_TecplotLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_TecplotLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetMonitorFunction(IntPtr p,VTecplotLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetCoordsNames(IntPtr p,StringBuilder x_name,StringBuilder y_name,StringBuilder z_name);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_TecplotLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      public static IntPtr TecplotLibBegin() {
         return vdm_TecplotLibBegin();
      }

      public static void TecplotLibEnd(IntPtr p) {
         vdm_TecplotLibEnd(p);
      }

      public static int TecplotLibError(IntPtr p) {
         return vdm_TecplotLibError(p);
      }

      public static void TecplotLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_TecplotLibSetMode(p, m_ode, f_lag);
      }

      public static void TecplotLibSetConvention(IntPtr p,long c_onvention) {
         vdm_TecplotLibSetConvention(p, c_onvention);
      }

      public static void TecplotLibSetStatus(IntPtr p,int s_tatus) {
         vdm_TecplotLibSetStatus(p, s_tatus);
      }

      public static void TecplotLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_TecplotLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void TecplotLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_TecplotLibSetConnect(p, c_onnect);
      }

      public static void TecplotLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_TecplotLibGetConnect(p,out c_onnect);
      }

      public static void TecplotLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_TecplotLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void TecplotLibSetMonitorFunction(IntPtr p,VTecplotLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_TecplotLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void TecplotLibAbort(IntPtr p) {
         vdm_TecplotLibAbort(p);
      }

      public static void TecplotLibSetCoordsNames(IntPtr p,StringBuilder x_name,StringBuilder y_name,StringBuilder z_name) {
         vdm_TecplotLibSetCoordsNames(p, x_name, y_name, z_name);
      }

      public static void TecplotLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_TecplotLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void TecplotLibClose(IntPtr p) {
         vdm_TecplotLibClose(p);
      }

      public static void TecplotLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_TecplotLibAppend(p, f_ilename, t_ype);
      }

      public static void TecplotLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_TecplotLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void TecplotLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_TecplotLibGetLibrary(p,out l_ibrary);
      }

      public static void TecplotLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_TecplotLibNumDatasets(p,ref n_umdatasets);
      }

      public static void TecplotLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_TecplotLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void TecplotLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_TecplotLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void TecplotLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_TecplotLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void TecplotLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_TecplotLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void TecplotLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_TecplotLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void TecplotLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_TecplotLibLibDataset(p, o_per, i_dst);
      }

      public static void TecplotLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_TecplotLibSetString(p, t_ype, c_value);
      }

      public static void TecplotLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_TecplotLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void TecplotLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_TecplotLibDataFun(p, d_atafun);
      }

      public static void TecplotLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_TecplotLibWriteModel(p, m_odel);
      }

      public static void TecplotLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_TecplotLibWriteState(p, r_prop, s_tate);
      }

      public static void TecplotLibSetParami(IntPtr p,int t_ype,int i_param) {
         vdm_TecplotLibSetParami(p, t_ype, i_param);
      }

      public static void TecplotLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_TecplotLibGetInteger(p, t_ype,ref i_value);
      }

      public static void TecplotLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_TecplotLibGetString(p, t_ype, c_value);
      }

      public static void TecplotLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_TecplotLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public const int VTK_DS_NONE = 0;
      public const int VTK_DS_STRUCTURED_POINTS = 1;
      public const int VTK_DS_STRUCTURED_GRID = 2;
      public const int VTK_DS_UNSTRUCTURED_GRID = 3;
      public const int VTK_DS_POLYDATA = 4;
      public const int VTK_DS_RECTILINEAR_GRID = 5;
      public const int VTKLIB_SHAPETRISTRIP = -1;
      public const int VTK_EMPTY_CELL = 0;
      public const int VTK_VERTEX = 1;
      public const int VTK_POLY_VERTEX = 2;
      public const int VTK_LINE = 3;
      public const int VTK_POLY_LINE = 4;
      public const int VTK_TRIANGLE = 5;
      public const int VTK_TRIANGLE_STRIP = 6;
      public const int VTK_POLYGON = 7;
      public const int VTK_PIXEL = 8;
      public const int VTK_QUAD = 9;
      public const int VTK_TETRA = 10;
      public const int VTK_VOXEL = 11;
      public const int VTK_HEXAHEDRON = 12;
      public const int VTK_WEDGE = 13;
      public const int VTK_PYRAMID = 14;
      public const int VTK_PENTAGONAL_PRISM = 15;
      public const int VTK_HEXAGONAL_PRISM = 16;
      public const int VTK_QUADRATIC_EDGE = 21;
      public const int VTK_QUADRATIC_TRIANGLE = 22;
      public const int VTK_QUADRATIC_QUAD = 23;
      public const int VTK_QUADRATIC_TETRA = 24;
      public const int VTK_QUADRATIC_HEXAHEDRON = 25;
      public const int VTK_QUADRATIC_WEDGE = 26;
      public const int VTK_QUADRATIC_PYRAMID = 27;
      public const int VTK_BIQUADRATIC_QUAD = 28;
      public const int VTK_TRIQUADRATIC_HEXAHEDRON = 29;
      public const int VTK_QUADRATIC_LINEAR_QUAD = 30;
      public const int VTK_QUADRATIC_LINEAR_WEDGE = 31;
      public const int VTK_BIQUADRATIC_QUADRATIC_WEDGE = 32;
      public const int VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON = 33;
      public const int VTK_BIQUADRATIC_TRIANGLE = 34;
      public const int VTK_CUBIC_LINE = 35;
      public const int VTK_CONVEX_POINT_SET = 41;
      public const int VTK_POLYHEDRON = 42;
      public const int VTK_PARAMETRIC_CURVE = 51;
      public const int VTK_PARAMETRIC_SURFACE = 52;
      public const int VTK_PARAMETRIC_TRI_SURFACE = 53;
      public const int VTK_PARAMETRIC_QUAD_SURFACE = 54;
      public const int VTK_PARAMETRIC_TETRA_REGION = 55;
      public const int VTK_PARAMETRIC_HEX_REGION = 56;
      public const int VTK_HIGHER_ORDER_EDGE = 60;
      public const int VTK_HIGHER_ORDER_TRIANGLE = 61;
      public const int VTK_HIGHER_ORDER_QUAD = 62;
      public const int VTK_HIGHER_ORDER_POLYGON = 63;
      public const int VTK_HIGHER_ORDER_TETRAHEDRON = 64;
      public const int VTK_HIGHER_ORDER_WEDGE = 65;
      public const int VTK_HIGHER_ORDER_PYRAMID = 66;
      public const int VTK_HIGHER_ORDER_HEXAHEDRON = 67;

      public const int VTKLIB_SEARCH_OFF = 0;
      public const int VTKLIB_SEARCH_OPENFOAM = 1;
      public const int VTKLIB_SEARCH_MULTIDIR = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_VTKLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_VTKLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetMonitorFunction(IntPtr p,VVTKLibMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibSetSearch(IntPtr p,int s_earch);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_VTKLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate);

      public static IntPtr VTKLibBegin() {
         return vdm_VTKLibBegin();
      }

      public static void VTKLibEnd(IntPtr p) {
         vdm_VTKLibEnd(p);
      }

      public static int VTKLibError(IntPtr p) {
         return vdm_VTKLibError(p);
      }

      public static void VTKLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_VTKLibSetMode(p, m_ode, f_lag);
      }

      public static void VTKLibSetConvention(IntPtr p,long c_onvention) {
         vdm_VTKLibSetConvention(p, c_onvention);
      }

      public static void VTKLibSetStatus(IntPtr p,int s_tatus) {
         vdm_VTKLibSetStatus(p, s_tatus);
      }

      public static void VTKLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_VTKLibSetConnect(p, c_onnect);
      }

      public static void VTKLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_VTKLibGetConnect(p,out c_onnect);
      }

      public static void VTKLibSetIds(IntPtr p,int i_dtype,int i_d1off,int i_d2off,int i_d3off) {
         vdm_VTKLibSetIds(p, i_dtype, i_d1off, i_d2off, i_d3off);
      }

      public static void VTKLibSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vdm_VTKLibSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void VTKLibSetMonitorFunction(IntPtr p,VVTKLibMonitorFunc f_unction,IntPtr o_bject) {
         vdm_VTKLibSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void VTKLibAbort(IntPtr p) {
         vdm_VTKLibAbort(p);
      }

      public static void VTKLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_VTKLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void VTKLibClose(IntPtr p) {
         vdm_VTKLibClose(p);
      }

      public static void VTKLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_VTKLibAppend(p, f_ilename, t_ype);
      }

      public static void VTKLibGetNumEntities(IntPtr p,int e_nttype,ref int n_ument) {
         vdm_VTKLibGetNumEntities(p, e_nttype,ref n_ument);
      }

      public static void VTKLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_VTKLibGetLibrary(p,out l_ibrary);
      }

      public static void VTKLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_VTKLibNumDatasets(p,ref n_umdatasets);
      }

      public static void VTKLibNumAttributes(IntPtr p,int i_dst,ref int n_umattributes) {
         vdm_VTKLibNumAttributes(p, i_dst,ref n_umattributes);
      }

      public static void VTKLibGetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_VTKLibGetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void VTKLibInqDataset(IntPtr p,int i_dst,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_VTKLibInqDataset(p, i_dst, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void VTKLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_VTKLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void VTKLibReadDataset(IntPtr p,int i_dst,ref IntPtr b_uf) {
         vdm_VTKLibReadDataset(p, i_dst,ref b_uf);
      }

      public static void VTKLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_VTKLibLibDataset(p, o_per, i_dst);
      }

      public static void VTKLibSetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_VTKLibSetString(p, t_ype, c_value);
      }

      public static void VTKLibGetUnrecognizedData(IntPtr p,out IntPtr u_nrecognizedData) {
         vdm_VTKLibGetUnrecognizedData(p,out u_nrecognizedData);
      }

      public static void VTKLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_VTKLibDataFun(p, d_atafun);
      }

      public static void VTKLibSetSearch(IntPtr p,int s_earch) {
         vdm_VTKLibSetSearch(p, s_earch);
      }

      public static void VTKLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_VTKLibGetInteger(p, t_ype,ref i_value);
      }

      public static void VTKLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_VTKLibGetString(p, t_ype, c_value);
      }

      public static void VTKLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_VTKLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void VTKLibWriteModel(IntPtr p,IntPtr m_odel) {
         vdm_VTKLibWriteModel(p, m_odel);
      }

      public static void VTKLibWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate) {
         vdm_VTKLibWriteState(p, r_prop, s_tate);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PluginLibBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibDef(IntPtr p,StringBuilder p_athToPluginLibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PluginLibError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibApplySettings(IntPtr p,IntPtr g_lobalSettings);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibDataFun(IntPtr p,IntPtr d_atafun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetLibrary(IntPtr p,out IntPtr l_ibrary);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetStatus(IntPtr p,int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetAttVal(IntPtr p,int d_atasetIndex,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibNumDatasets(IntPtr p,ref int n_umdatasets);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibNumAttributes(IntPtr p,int d_atasetIndex,ref int n_umattributes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibInqDataset(IntPtr p,int d_atasetIndex,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibReadDataset(IntPtr p,int d_atasetIndex,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetConvention(IntPtr p,long c_onvention);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibLibDataset(IntPtr p,int o_per,int i_dst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetInteger(IntPtr p,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibGetString(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginLibSetErrorLevel(IntPtr p,int e_rrorLevel);

      public static IntPtr PluginLibBegin() {
         return vdm_PluginLibBegin();
      }

      public static void PluginLibDef(IntPtr p,StringBuilder p_athToPluginLibrary) {
         vdm_PluginLibDef(p, p_athToPluginLibrary);
      }

      public static void PluginLibEnd(IntPtr p) {
         vdm_PluginLibEnd(p);
      }

      public static int PluginLibError(IntPtr p) {
         return vdm_PluginLibError(p);
      }

      public static void PluginLibClose(IntPtr p) {
         vdm_PluginLibClose(p);
      }

      public static void PluginLibApplySettings(IntPtr p,IntPtr g_lobalSettings) {
         vdm_PluginLibApplySettings(p, g_lobalSettings);
      }

      public static void PluginLibOpen(IntPtr p,int m_ode,StringBuilder f_ilename,int t_ype) {
         vdm_PluginLibOpen(p, m_ode, f_ilename, t_ype);
      }

      public static void PluginLibDataFun(IntPtr p,IntPtr d_atafun) {
         vdm_PluginLibDataFun(p, d_atafun);
      }

      public static void PluginLibGetConnect(IntPtr p,out IntPtr c_onnect) {
         vdm_PluginLibGetConnect(p,out c_onnect);
      }

      public static void PluginLibGetNumEntities(IntPtr p,int e_ntitytype,ref int n_umentity) {
         vdm_PluginLibGetNumEntities(p, e_ntitytype,ref n_umentity);
      }

      public static void PluginLibGetLibrary(IntPtr p,out IntPtr l_ibrary) {
         vdm_PluginLibGetLibrary(p,out l_ibrary);
      }

      public static void PluginLibSetStatus(IntPtr p,int s_tatus) {
         vdm_PluginLibSetStatus(p, s_tatus);
      }

      public static void PluginLibGetAttVal(IntPtr p,int d_atasetIndex,int i_att,ref IntPtr v_alue) {
         vdm_PluginLibGetAttVal(p, d_atasetIndex, i_att,ref v_alue);
      }

      public static void PluginLibNumDatasets(IntPtr p,ref int n_umdatasets) {
         vdm_PluginLibNumDatasets(p,ref n_umdatasets);
      }

      public static void PluginLibNumAttributes(IntPtr p,int d_atasetIndex,ref int n_umattributes) {
         vdm_PluginLibNumAttributes(p, d_atasetIndex,ref n_umattributes);
      }

      public static void PluginLibInqDataset(IntPtr p,int d_atasetIndex,StringBuilder n_ame,ref long l_rec,ref int n_row,ref int n_col,ref int t_ype) {
         vdm_PluginLibInqDataset(p, d_atasetIndex, n_ame,ref l_rec,ref n_row,ref n_col,ref t_ype);
      }

      public static void PluginLibInqAttribute(IntPtr p,int i_dst,int i_att,StringBuilder n_ame,ref int l_ength,ref int t_ype) {
         vdm_PluginLibInqAttribute(p, i_dst, i_att, n_ame,ref l_ength,ref t_ype);
      }

      public static void PluginLibReadDataset(IntPtr p,int d_atasetIndex,ref IntPtr d_ata) {
         vdm_PluginLibReadDataset(p, d_atasetIndex,ref d_ata);
      }

      public static void PluginLibSetMode(IntPtr p,int m_ode,int f_lag) {
         vdm_PluginLibSetMode(p, m_ode, f_lag);
      }

      public static void PluginLibSetConvention(IntPtr p,long c_onvention) {
         vdm_PluginLibSetConvention(p, c_onvention);
      }

      public static void PluginLibDefDataset(IntPtr p,StringBuilder n_ame,long l_rec,int n_row,int n_col,int t_ype,ref int i_dst) {
         vdm_PluginLibDefDataset(p, n_ame, l_rec, n_row, n_col, t_ype,ref i_dst);
      }

      public static void PluginLibWriteDataset(IntPtr p,int i_dst,ref IntPtr b_uff) {
         vdm_PluginLibWriteDataset(p, i_dst,ref b_uff);
      }

      public static void PluginLibAppend(IntPtr p,StringBuilder f_ilename,int t_ype) {
         vdm_PluginLibAppend(p, f_ilename, t_ype);
      }

      public static void PluginLibSetIds(IntPtr p,int i_dtype,int i_d1,int i_d2,int i_d3) {
         vdm_PluginLibSetIds(p, i_dtype, i_d1, i_d2, i_d3);
      }

      public static void PluginLibSetConnect(IntPtr p,IntPtr c_onnect) {
         vdm_PluginLibSetConnect(p, c_onnect);
      }

      public static void PluginLibLibDataset(IntPtr p,int o_per,int i_dst) {
         vdm_PluginLibLibDataset(p, o_per, i_dst);
      }

      public static void PluginLibDefAttribute(IntPtr p,int i_dst,StringBuilder n_ame,int l_ength,int t_ype,ref int i_att) {
         vdm_PluginLibDefAttribute(p, i_dst, n_ame, l_ength, t_ype,ref i_att);
      }

      public static void PluginLibSetAttVal(IntPtr p,int i_dst,int i_att,ref IntPtr v_alue) {
         vdm_PluginLibSetAttVal(p, i_dst, i_att,ref v_alue);
      }

      public static void PluginLibGetInteger(IntPtr p,int t_ype,ref int i_value) {
         vdm_PluginLibGetInteger(p, t_ype,ref i_value);
      }

      public static void PluginLibGetString(IntPtr p,int t_ype,StringBuilder c_value) {
         vdm_PluginLibGetString(p, t_ype, c_value);
      }

      public static void PluginLibNumDomains(IntPtr p,StringBuilder f_ilename,int t_ype,ref int n_umdomains) {
         vdm_PluginLibNumDomains(p, f_ilename, t_ype,ref n_umdomains);
      }

      public static void PluginLibReadDatasetCols(IntPtr p,int i_dst,int n_cols,int [] c_ols,ref IntPtr b_uf,ref long l_ptr) {
         vdm_PluginLibReadDatasetCols(p, i_dst, n_cols, c_ols,ref b_uf,ref l_ptr);
      }

      public static void PluginLibSetErrorLevel(IntPtr p,int e_rrorLevel) {
         vdm_PluginLibSetErrorLevel(p, e_rrorLevel);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PluginManagerBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginManagerEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginManagerShutdown(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginManagerLoadPlugin(IntPtr p,StringBuilder p_athToPluginLibraryWithoutExtension);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginManagerLoadPluginSettings(IntPtr p,StringBuilder f_ileMask,IntPtr p_luginSettings);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PluginManagerError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginManagerSetErrorLevel(IntPtr p,int e_rrorLevel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PluginManagerGetErrorLevel(IntPtr p);

      public static IntPtr PluginManagerBegin() {
         return vdm_PluginManagerBegin();
      }

      public static void PluginManagerEnd(IntPtr p) {
         vdm_PluginManagerEnd(p);
      }

      public static void PluginManagerShutdown(IntPtr p) {
         vdm_PluginManagerShutdown(p);
      }

      public static void PluginManagerLoadPlugin(IntPtr p,StringBuilder p_athToPluginLibraryWithoutExtension) {
         vdm_PluginManagerLoadPlugin(p, p_athToPluginLibraryWithoutExtension);
      }

      public static void PluginManagerLoadPluginSettings(IntPtr p,StringBuilder f_ileMask,IntPtr p_luginSettings) {
         vdm_PluginManagerLoadPluginSettings(p, f_ileMask, p_luginSettings);
      }

      public static int PluginManagerError(IntPtr p) {
         return vdm_PluginManagerError(p);
      }

      public static void PluginManagerSetErrorLevel(IntPtr p,int e_rrorLevel) {
         vdm_PluginManagerSetErrorLevel(p, e_rrorLevel);
      }

      public static int PluginManagerGetErrorLevel(IntPtr p) {
         return vdm_PluginManagerGetErrorLevel(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vdm_PluginSettingsBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PluginSettingsError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsDef(IntPtr p,StringBuilder i_dstring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsInq(IntPtr p,StringBuilder i_dstring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vdm_PluginSettingsCount(IntPtr p,ref int i_ntegerkeyCount,ref int d_oublekeyCount,ref int s_tringkeyCount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsGetInteger(IntPtr p,int i_ntegerIndex,StringBuilder k_ey,StringBuilder d_escription,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsPushInteger(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsGetDouble(IntPtr p,int d_oubleIndex,StringBuilder k_ey,StringBuilder d_escription,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsPushDouble(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsGetString(IntPtr p,int s_tringIndex,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsPushString(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vdm_PluginSettingsPrint(IntPtr p);

      public static IntPtr PluginSettingsBegin() {
         return vdm_PluginSettingsBegin();
      }

      public static void PluginSettingsEnd(IntPtr p) {
         vdm_PluginSettingsEnd(p);
      }

      public static int PluginSettingsError(IntPtr p) {
         return vdm_PluginSettingsError(p);
      }

      public static void PluginSettingsDef(IntPtr p,StringBuilder i_dstring) {
         vdm_PluginSettingsDef(p, i_dstring);
      }

      public static void PluginSettingsInq(IntPtr p,StringBuilder i_dstring) {
         vdm_PluginSettingsInq(p, i_dstring);
      }

      public static int PluginSettingsCount(IntPtr p,ref int i_ntegerkeyCount,ref int d_oublekeyCount,ref int s_tringkeyCount) {
         return vdm_PluginSettingsCount(p,ref i_ntegerkeyCount,ref d_oublekeyCount,ref s_tringkeyCount);
      }

      public static void PluginSettingsGetInteger(IntPtr p,int i_ntegerIndex,StringBuilder k_ey,StringBuilder d_escription,ref int v_alue) {
         vdm_PluginSettingsGetInteger(p, i_ntegerIndex, k_ey, d_escription,ref v_alue);
      }

      public static void PluginSettingsPushInteger(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,int v_alue) {
         vdm_PluginSettingsPushInteger(p, k_ey, d_escription, v_alue);
      }

      public static void PluginSettingsGetDouble(IntPtr p,int d_oubleIndex,StringBuilder k_ey,StringBuilder d_escription,ref double v_alue) {
         vdm_PluginSettingsGetDouble(p, d_oubleIndex, k_ey, d_escription,ref v_alue);
      }

      public static void PluginSettingsPushDouble(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue) {
         vdm_PluginSettingsPushDouble(p, k_ey, d_escription, v_alue);
      }

      public static void PluginSettingsGetString(IntPtr p,int s_tringIndex,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue) {
         vdm_PluginSettingsGetString(p, s_tringIndex, k_ey, d_escription, v_alue);
      }

      public static void PluginSettingsPushString(IntPtr p,StringBuilder k_ey,StringBuilder d_escription,StringBuilder v_alue) {
         vdm_PluginSettingsPushString(p, k_ey, d_escription, v_alue);
      }

      public static void PluginSettingsPrint(IntPtr p) {
         vdm_PluginSettingsPrint(p);
      }

   }
}
