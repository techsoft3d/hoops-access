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
   public delegate void Vfunc();

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate int VfuncInt(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void Vfunc1(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void Vfunc2(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunOpenFile(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunCloseFile(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunConnectFile(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunDisconnectFile(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunQueryFile(IntPtr a0,out IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunListType(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunHeadingLevel(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunRuleWidth(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunSetMode(IntPtr a0,int a1,int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunFormInit(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunFormTerm(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunFormAction(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunHorizontalRule(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunImageFile(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunString(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunSpace(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunTextColor(IntPtr a0,float [] a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunTableColor(IntPtr a0,float [] a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunBackColor(IntPtr a0,float [] a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunBorderWidth(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunTableWidth(IntPtr a0,int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTextFunColumnAlign(IntPtr a0,int a1);

   public class vsy {

      public const int ADTREE_POINT = 1;
      public const int ADTREE_EXTENT = 2;
      public const int ADTREE_TOLERANCE = 1;
      public const int ADTREE_NUMHITS = 1;
      public const int ADTREE_NUMVISITS = 2;
      public const int ADTREE_MAXLEVEL = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_ADTreeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_ADTreeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeDef(IntPtr p,int t_ype,double [] x_min,double [] x_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeInq(IntPtr p,ref int t_ype,ref int l_en,double [] x_min,double [] x_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeSetParamd(IntPtr p,int p_type,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeCheck(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeInsertPoint(IntPtr p,int k_ey,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeInsertExtent(IntPtr p,int k_ey,double [] x_min,double [] x_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeInsertLine(IntPtr p,int i_ndex,double [] x_1,double [] x_2);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeInsertElem(IntPtr p,int i_ndex,int n_n,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefPointInit(IntPtr p,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefPointNext(IntPtr p,ref int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefExtentInit(IntPtr p,double [] x_min,double [] x_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefExtentNext(IntPtr p,ref int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRemove(IntPtr p,int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeGetInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreePrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefPointInitIter(IntPtr p,int i_ter,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefPointNextIter(IntPtr p,int i_ter,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefExtentInitIter(IntPtr p,int i_ter,double [] x_min,double [] x_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeRefExtentNextIter(IntPtr p,int i_ter,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ADTreeGetIntegerIter(IntPtr p,int i_ter,int t_ype,int [] i_params);

      public static IntPtr ADTreeBegin() {
         return vsy_ADTreeBegin();
      }

      public static void ADTreeEnd(IntPtr p) {
         vsy_ADTreeEnd(p);
      }

      public static int ADTreeError(IntPtr p) {
         return vsy_ADTreeError(p);
      }

      public static void ADTreeDef(IntPtr p,int t_ype,double [] x_min,double [] x_max) {
         vsy_ADTreeDef(p, t_ype, x_min, x_max);
      }

      public static void ADTreeInq(IntPtr p,ref int t_ype,ref int l_en,double [] x_min,double [] x_max) {
         vsy_ADTreeInq(p,ref t_ype,ref l_en, x_min, x_max);
      }

      public static void ADTreeSetParamd(IntPtr p,int p_type,double d_param) {
         vsy_ADTreeSetParamd(p, p_type, d_param);
      }

      public static void ADTreeCheck(IntPtr p) {
         vsy_ADTreeCheck(p);
      }

      public static void ADTreeInsertPoint(IntPtr p,int k_ey,double [] x_) {
         vsy_ADTreeInsertPoint(p, k_ey, x_);
      }

      public static void ADTreeInsertExtent(IntPtr p,int k_ey,double [] x_min,double [] x_max) {
         vsy_ADTreeInsertExtent(p, k_ey, x_min, x_max);
      }

      public static void ADTreeInsertLine(IntPtr p,int i_ndex,double [] x_1,double [] x_2) {
         vsy_ADTreeInsertLine(p, i_ndex, x_1, x_2);
      }

      public static void ADTreeInsertElem(IntPtr p,int i_ndex,int n_n,double [] x_) {
         vsy_ADTreeInsertElem(p, i_ndex, n_n, x_);
      }

      public static void ADTreeRefPointInit(IntPtr p,double [] x_) {
         vsy_ADTreeRefPointInit(p, x_);
      }

      public static void ADTreeRefPointNext(IntPtr p,ref int k_ey) {
         vsy_ADTreeRefPointNext(p,ref k_ey);
      }

      public static void ADTreeRefExtentInit(IntPtr p,double [] x_min,double [] x_max) {
         vsy_ADTreeRefExtentInit(p, x_min, x_max);
      }

      public static void ADTreeRefExtentNext(IntPtr p,ref int k_ey) {
         vsy_ADTreeRefExtentNext(p,ref k_ey);
      }

      public static void ADTreeRemove(IntPtr p,int k_ey) {
         vsy_ADTreeRemove(p, k_ey);
      }

      public static void ADTreeGetInteger(IntPtr p,int t_ype,int [] i_param) {
         vsy_ADTreeGetInteger(p, t_ype, i_param);
      }

      public static void ADTreePrint(IntPtr p) {
         vsy_ADTreePrint(p);
      }

      public static void ADTreeRefPointInitIter(IntPtr p,int i_ter,double [] x_) {
         vsy_ADTreeRefPointInitIter(p, i_ter, x_);
      }

      public static void ADTreeRefPointNextIter(IntPtr p,int i_ter,ref int i_ndex) {
         vsy_ADTreeRefPointNextIter(p, i_ter,ref i_ndex);
      }

      public static void ADTreeRefExtentInitIter(IntPtr p,int i_ter,double [] x_min,double [] x_max) {
         vsy_ADTreeRefExtentInitIter(p, i_ter, x_min, x_max);
      }

      public static void ADTreeRefExtentNextIter(IntPtr p,int i_ter,ref int i_ndex) {
         vsy_ADTreeRefExtentNextIter(p, i_ter,ref i_ndex);
      }

      public static void ADTreeGetIntegerIter(IntPtr p,int i_ter,int t_ype,int [] i_params) {
         vsy_ADTreeGetIntegerIter(p, i_ter, t_ype, i_params);
      }

      public const int VKI_OS_UNIX = 1;
      public const int VKI_OS_WIN32 = 1;
      public const int VKI_OS_LINUX = 1;
      public const int SYS_NONE = 0;
      public const int SYS_NODE = 1;
      public const int SYS_EDGE = 2;
      public const int SYS_FACE = 3;
      public const int SYS_ELEM = 4;
      public const int SYS_DOF = 10;
      public const int SYS_INTPNT = 12;
      public const int SYS_PARTICLE = 13;
      public const int SYS_MODE = 14;
      public const int SYS_ASURF = 2660;
      public const int SYS_COORDSYS = 2100;
      public const int SYS_EQN = 11;
      public const int SYS_PANEL = 15;
      public const int SYS_CPAIR = 2600;
      public const int SYS_LIBRARY = 6002;
      public const int SYS_NODATATYPE = 0;
      public const int SYS_INTEGER = 1;
      public const int SYS_REAL = 2;
      public const int SYS_FLOAT = 2;
      public const int SYS_HOLLERITH = 3;
      public const int SYS_CHAR = 3;
      public const int SYS_DOUBLE = 4;
      public const int SYS_STRING = 5;
      public const int SYS_COMPLEX = 6;
      public const int SYS_DOUBLECOMPLEX = 7;
      public const int SYS_OBJECT = 8;
      public const int SYS_SHORT = 9;
      public const int SYS_LONG = 10;
      public const int SYS_HALF = 11;
      public const int SYS_QUARTER = 12;
      public const int SYS_WCHAR = 13;
      public const int SYS_24BIT = 14;
      public const int SYS_DATATYPE_NONE = -1;
      public const int SYS_SCALAR = 0;
      public const int SYS_VECTOR = 1;
      public const int SYS_TENSOR = 2;
      public const int SYS_GENERALTENSOR = 3;
      public const int SYS_SIXDOF = 9;
      public const int SYS_MATRIX_DIAG = 6;
      public const int SYS_MATRIX_SYMM = 7;
      public const int SYS_MATRIX_USYMM = 8;
      public const int SYS_ELEMRES = 5;
      public const int SYS_SCALARS = 10;
      public const int SYS_SCALARS1 = 11;
      public const int SYS_SCALARS2 = 12;
      public const int SYS_SCALARS3 = 13;
      public const int SYS_SCALARS4 = 14;
      public const int SYS_SCALARS5 = 15;
      public const int SYS_SCALARS6 = 16;
      public const int SYS_SCALARS7 = 17;
      public const int SYS_SCALARS8 = 18;
      public const int SYS_SCALARS9 = 19;
      public const int SYS_SCALARS10 = 20;
      public const int SYS_SCALARS11 = 21;
      public const int SYS_SCALARS12 = 22;
      public const int SYS_SCALARS13 = 23;
      public const int SYS_SCALARS14 = 24;
      public const int SYS_SCALARS15 = 25;
      public const int SYS_SCALARS16 = 26;
      public const int SYS_SCALARS17 = 27;
      public const int SYS_SCALARS18 = 28;
      public const int SYS_SCALARS19 = 29;
      public const int SYS_SCALARS20 = 30;
      public const int SYS_SCALARS21 = 31;
      public const int SYS_SCALARS22 = 32;
      public const int SYS_SCALARS23 = 33;
      public const int SYS_SCALARS24 = 34;
      public const int SYS_SCALARS25 = 35;
      public const int SYS_SCALARS26 = 36;
      public const int SYS_SCALARS27 = 37;
      public const int SYS_SCALARS28 = 38;
      public const int SYS_SCALARS29 = 39;
      public const int SYS_SCALARS30 = 40;
      public const int SYS_SCALARS31 = 41;
      public const int SYS_SCALARS32 = 42;
      public const int SYS_SCALARS33 = 43;
      public const int SYS_SCALARS34 = 44;
      public const int SYS_SCALARS35 = 45;
      public const int SYS_SCALARS36 = 46;
      public const int SYS_SCALARS37 = 47;
      public const int SYS_SCALARS38 = 48;
      public const int SYS_SCALARS39 = 49;
      public const int SYS_SCALARS40 = 50;
      public const int SYS_SCALARS41 = 51;
      public const int SYS_SCALARS42 = 52;
      public const int SYS_SCALARS43 = 53;
      public const int SYS_SCALARS44 = 54;
      public const int SYS_SCALARS45 = 55;
      public const int SYS_SCALARS46 = 56;
      public const int SYS_SCALARS47 = 57;
      public const int SYS_SCALARS48 = 58;
      public const int SYS_SCALARS49 = 59;
      public const int SYS_SCALARS50 = 60;
      public const int SYS_SCALARS51 = 61;
      public const int SYS_SCALARS52 = 62;
      public const int SYS_SCALARS53 = 63;
      public const int SYS_SCALARS54 = 64;
      public const int SYS_SCALARS55 = 65;
      public const int SYS_SCALARS56 = 66;
      public const int SYS_SCALARS57 = 67;
      public const int SYS_SCALARS58 = 68;
      public const int SYS_SCALARS59 = 69;
      public const int SYS_SCALARS60 = 70;
      public const int SYS_SCALARS61 = 71;
      public const int SYS_SCALARS62 = 72;
      public const int SYS_SCALARS63 = 73;
      public const int SYS_SCALARS64 = 74;
      public const int SYS_SCALARS65 = 75;
      public const int SYS_SCALARS66 = 76;
      public const int SYS_SCALARS67 = 77;
      public const int SYS_SCALARS68 = 78;
      public const int SYS_SCALARS69 = 79;
      public const int SYS_SCALARS70 = 80;
      public const int SYS_SCALARS71 = 81;
      public const int SYS_SCALARS72 = 82;
      public const int SYS_SCALARS73 = 83;
      public const int SYS_SCALARS74 = 84;
      public const int SYS_SCALARS75 = 85;
      public const int SYS_SCALARS76 = 86;
      public const int SYS_SCALARS77 = 87;
      public const int SYS_SCALARS78 = 88;
      public const int SYS_SCALARS79 = 89;
      public const int SYS_SCALARS80 = 90;
      public const int SYS_SCALARS81 = 91;
      public const int SYS_SCALARS82 = 92;
      public const int SYS_SCALARS83 = 93;
      public const int SYS_SCALARS84 = 94;
      public const int SYS_SCALARS85 = 95;
      public const int SYS_SCALARS86 = 96;
      public const int SYS_SCALARS87 = 97;
      public const int SYS_SCALARS88 = 98;
      public const int SYS_SCALARS89 = 99;
      public const int SYS_SCALARS90 = 100;
      public const int SYS_SCALARS91 = 101;
      public const int SYS_SCALARS92 = 102;
      public const int SYS_SCALARS93 = 103;
      public const int SYS_SCALARS94 = 104;
      public const int SYS_SCALARS95 = 105;
      public const int SYS_SCALARS96 = 106;
      public const int SYS_SCALARS97 = 107;
      public const int SYS_SCALARS98 = 108;
      public const int SYS_SCALARS99 = 109;
      public const int SYS_SCALARS100 = 110;
      public const int SYS_SCALARS101 = 111;
      public const int SYS_SCALARS102 = 112;
      public const int SYS_SCALARS103 = 113;
      public const int SYS_SCALARS104 = 114;
      public const int SYS_SCALARS105 = 115;
      public const int SYS_SCALARS106 = 116;
      public const int SYS_SCALARS107 = 117;
      public const int SYS_SCALARS108 = 118;
      public const int SYS_SCALARS109 = 119;
      public const int SYS_SCALARS110 = 120;
      public const int SYS_SCALARS111 = 121;
      public const int SYS_SCALARS112 = 122;
      public const int SYS_SCALARS113 = 123;
      public const int SYS_SCALARS114 = 124;
      public const int SYS_SCALARS115 = 125;
      public const int SYS_SCALARS116 = 126;
      public const int SYS_SCALARS117 = 127;
      public const int SYS_SCALARS118 = 128;
      public const int SYS_SCALARS119 = 129;
      public const int SYS_SCALARS120 = 130;
      public const int SYS_SCALARS121 = 131;
      public const int SYS_SCALARS122 = 132;
      public const int SYS_SCALARS123 = 133;
      public const int SYS_SCALARS124 = 134;
      public const int SYS_SCALARS125 = 135;
      public const int SYS_SCALARS126 = 136;
      public const int SYS_SCALARS127 = 137;
      public const int SYS_SCALARS128 = 138;
      public const int SYS_SCALARS129 = 139;
      public const int SYS_SCALARS130 = 140;
      public const int SYS_SCALARS131 = 141;
      public const int SYS_SCALARS132 = 142;
      public const int SYS_SCALARS133 = 143;
      public const int SYS_SCALARS134 = 144;
      public const int SYS_SCALARS135 = 145;
      public const int SYS_SCALARS136 = 146;
      public const int SYS_SCALARS137 = 147;
      public const int SYS_SCALARS138 = 148;
      public const int SYS_SCALARS139 = 149;
      public const int SYS_SCALARS140 = 150;
      public const int SYS_SCALARS141 = 151;
      public const int SYS_SCALARS142 = 152;
      public const int SYS_SCALARS143 = 153;
      public const int SYS_SCALARS144 = 154;
      public const int SYS_SCALARS145 = 155;
      public const int SYS_SCALARS146 = 156;
      public const int SYS_SCALARS147 = 157;
      public const int SYS_SCALARS148 = 158;
      public const int SYS_SCALARS149 = 159;
      public const int SYS_SCALARS150 = 160;
      public const int SYS_SCALARS151 = 161;
      public const int SYS_SCALARS152 = 162;
      public const int SYS_SCALARS153 = 163;
      public const int SYS_SCALARS154 = 164;
      public const int SYS_SCALARS155 = 165;
      public const int SYS_SCALARS156 = 166;
      public const int SYS_SCALARS157 = 167;
      public const int SYS_SCALARS158 = 168;
      public const int SYS_SCALARS159 = 169;
      public const int SYS_SCALARS160 = 170;
      public const int SYS_SCALARS161 = 171;
      public const int SYS_SCALARS162 = 172;
      public const int SYS_SCALARS163 = 173;
      public const int SYS_SCALARS164 = 174;
      public const int SYS_SCALARS165 = 175;
      public const int SYS_SCALARS166 = 176;
      public const int SYS_SCALARS167 = 177;
      public const int SYS_SCALARS168 = 178;
      public const int SYS_SCALARS169 = 179;
      public const int SYS_SCALARS170 = 180;
      public const int SYS_SCALARS171 = 181;
      public const int SYS_SCALARS172 = 182;
      public const int SYS_SCALARS173 = 183;
      public const int SYS_SCALARS174 = 184;
      public const int SYS_SCALARS175 = 185;
      public const int SYS_SCALARS176 = 186;
      public const int SYS_SCALARS177 = 187;
      public const int SYS_SCALARS178 = 188;
      public const int SYS_SCALARS179 = 189;
      public const int SYS_SCALARS180 = 190;
      public const int SYS_SCALARS181 = 191;
      public const int SYS_SCALARS182 = 192;
      public const int SYS_SCALARS183 = 193;
      public const int SYS_SCALARS184 = 194;
      public const int SYS_SCALARS185 = 195;
      public const int SYS_SCALARS186 = 196;
      public const int SYS_SCALARS187 = 197;
      public const int SYS_SCALARS188 = 198;
      public const int SYS_SCALARS189 = 199;
      public const int SYS_SCALARS190 = 200;
      public const int SYS_SCALARS191 = 201;
      public const int SYS_SCALARS192 = 202;
      public const int SYS_SCALARS193 = 203;
      public const int SYS_SCALARS194 = 204;
      public const int SYS_SCALARS195 = 205;
      public const int SYS_SCALARS196 = 206;
      public const int SYS_SCALARS197 = 207;
      public const int SYS_SCALARS198 = 208;
      public const int SYS_SCALARS199 = 209;
      public const int SYS_SCALARS200 = 210;
      public const int SYS_SCALARS201 = 211;
      public const int SYS_SCALARS202 = 212;
      public const int SYS_SCALARS203 = 213;
      public const int SYS_SCALARS204 = 214;
      public const int SYS_SCALARS205 = 215;
      public const int SYS_SCALARS206 = 216;
      public const int SYS_SCALARS207 = 217;
      public const int SYS_SCALARS208 = 218;
      public const int SYS_SCALARS209 = 219;
      public const int SYS_SCALARS210 = 220;
      public const int SYS_SCALARS211 = 221;
      public const int SYS_SCALARS212 = 222;
      public const int SYS_SCALARS213 = 223;
      public const int SYS_SCALARS214 = 224;
      public const int SYS_SCALARS215 = 225;
      public const int SYS_SCALARS216 = 226;
      public const int SYS_SCALARS217 = 227;
      public const int SYS_SCALARS218 = 228;
      public const int SYS_SCALARS219 = 229;
      public const int SYS_SCALARS220 = 230;
      public const int SYS_SCALARS221 = 231;
      public const int SYS_SCALARS222 = 232;
      public const int SYS_SCALARS223 = 233;
      public const int SYS_SCALARS224 = 234;
      public const int SYS_SCALARS225 = 235;
      public const int SYS_SCALARS226 = 236;
      public const int SYS_SCALARS227 = 237;
      public const int SYS_SCALARS228 = 238;
      public const int SYS_SCALARS229 = 239;
      public const int SYS_SCALARS230 = 240;
      public const int SYS_SCALARS231 = 241;
      public const int SYS_SCALARS232 = 242;
      public const int SYS_SCALARS233 = 243;
      public const int SYS_SCALARS234 = 244;
      public const int SYS_SCALARS235 = 245;
      public const int SYS_SCALARS236 = 246;
      public const int SYS_SCALARS237 = 247;
      public const int SYS_SCALARS238 = 248;
      public const int SYS_SCALARS239 = 249;
      public const int SYS_SCALARS240 = 250;
      public const int SYS_SCALARS241 = 251;
      public const int SYS_SCALARS242 = 252;
      public const int SYS_SCALARS243 = 253;
      public const int SYS_SCALARS244 = 254;
      public const int SYS_SCALARS245 = 255;
      public const int SYS_SCALARS246 = 256;
      public const int SYS_SCALARS247 = 257;
      public const int SYS_SCALARS248 = 258;
      public const int SYS_SCALARS249 = 259;
      public const int SYS_SCALARS250 = 260;
      public const int SYS_SCALARS251 = 261;
      public const int SYS_SCALARS252 = 262;
      public const int SYS_SCALARS253 = 263;
      public const int SYS_SCALARS254 = 264;
      public const int SYS_SCALARS255 = 265;
      public const int SYS_SCALARS256 = 266;
      public const int SYS_DATATYPE_MAX = 266;
      public const int SYS_COMPLEX_NONE = 0;
      public const int SYS_COMPLEX_REAL = 1;
      public const int SYS_COMPLEX_MAGNITUDE = 2;
      public const int SYS_COMPLEX_IMAGINARY = 3;
      public const int SYS_COMPLEX_PHASE = 4;
      public const int SYS_COMPLEX_REALIMAGINARY = 5;
      public const int SYS_COMPLEX_MAGNITUDEPHASE = 6;
      public const uint SYS_NODATAVAL = 0xffffffff;
      public const uint SYS_GRAD_NODATAVAL = 0xfffffffe;
      public const int SYS_CARTESIAN = 1;
      public const int SYS_CYLINDRICAL = 2;
      public const int SYS_SPHERICAL = 3;
      public const int SYS_SPHERICAL_ALT = 4;
      public const int SYS_TOROIDAL = 5;
      public const int SYS_CYLINDRICAL_ALT = 6;
      public const int SYS_XAXIS = 1;
      public const int SYS_YAXIS = 2;
      public const int SYS_ZAXIS = 3;
      public const int SYS_XYPLANE = 12;
      public const int SYS_XZPLANE = 13;
      public const int SYS_YZPLANE = 23;
      public const int SYS_OFF = 0;
      public const int SYS_ON = 1;
      public const int SYS_NEW = 2;
      public const int SYS_CHARBITS = 8;
      public const int SYS_INVALIDINT = 900000000;
      public const int SYS_THREADS_MAX = 64;
      public const int SYS_KEEP = 0;
      public const int SYS_DELETE = 1;
      public const int SYS_UNKNOWN = 0;
      public const int SYS_OLD = 1;
      public const int SYS_SHAPEUNDEFINED = -1;
      public const int SYS_SHAPEPOINT = 0;
      public const int SYS_SHAPELINE = 1;
      public const int SYS_SHAPETRI = 2;
      public const int SYS_SHAPEQUAD = 3;
      public const int SYS_SHAPETET = 4;
      public const int SYS_SHAPEPYR = 5;
      public const int SYS_SHAPEWED = 6;
      public const int SYS_SHAPEHEX = 7;
      public const int SYS_SHAPEPOLYGON = 8;
      public const int SYS_SHAPEPOLYHED = 9;
      public const int SYS_SHAPE_MAX = 10;
      public const int SYS_NODE_UNDEFINED = 0;
      public const int SYS_NODE_GRID = 1;
      public const int SYS_NODE_SCALAR = 2;
      public const int SYS_ELEM_UNDEFINED = 0;
      public const int SYS_ELEM_SOLID = 1;
      public const int SYS_ELEM_SHELL = 2;
      public const int SYS_ELEM_MEMBRANE = 3;
      public const int SYS_ELEM_BEAM = 4;
      public const int SYS_ELEM_TRUSS = 5;
      public const int SYS_ELEM_INFINITE = 6;
      public const int SYS_ELEM_GAP = 7;
      public const int SYS_ELEM_JOINT = 8;
      public const int SYS_ELEM_SPRINGDASHPOT = 9;
      public const int SYS_ELEM_RIGID = 10;
      public const int SYS_ELEM_CONSTRAINT = 11;
      public const int SYS_ELEM_PLOT = 12;
      public const int SYS_ELEM_MASS = 13;
      public const int SYS_ELEM_INTER = 14;
      public const int SYS_ELEM_SUPER = 15;
      public const int SYS_ELEM_REINFORCEMENT = 16;
      public const int SYS_ELEM_MAX = 17;
      public const int SYS_SOLID_SOLID = 0;
      public const int SYS_SOLID_FLUID = 1;
      public const int SYS_SOLID_SHELL = 2;
      public const int SYS_MEMBRANE_STAN = 0;
      public const int SYS_MEMBRANE_SHEAR = 1;
      public const int SYS_MEMBRANE_FACE = 2;
      public const int SYS_BEAM_STAN = 0;
      public const int SYS_BEAM_ROD = 1;
      public const int SYS_BEAM_WELD = 2;
      public const int SYS_BEAM_CBEND = 3;
      public const int SYS_TRUSS_STAN = 0;
      public const int SYS_TRUSS_EDGE = 1;
      public const int SYS_SPRINGDASHPOT_SCALAR = 0;
      public const int SYS_SPRINGDASHPOT_LINK = 1;
      public const int SYS_SPRINGDASHPOT_WELD = 2;
      public const int SYS_SPRINGDASHPOT_BUSH = 3;
      public const int SYS_SPRINGDASHPOT_SCALARDAMP = 4;
      public const int SYS_SPRINGDASHPOT_LINKDAMP = 5;
      public const int SYS_SPRINGDASHPOT_VECTOR = 6;
      public const int SYS_SPRINGDASHPOT_SEATBELT = 7;
      public const int SYS_SPRINGDASHPOT_TORSION = 8;
      public const int SYS_MASS_SCALAR = 0;
      public const int SYS_MASS_LUMP = 1;
      public const int SYS_MASS_MATRIX = 2;
      public const int SYS_MASS_VECTOR = 3;
      public const int SYS_MASS_VERTEX = 4;
      public const int SYS_RIGID_KINE = 0;
      public const int SYS_RIGID_DIST = 1;
      public const int SYS_RIGID_LINK = 2;
      public const int SYS_RIGID_MPC = 3;
      public const int SYS_RIGID_RBE3 = 4;
      public const int SYS_RIGID_SPLINE = 5;
      public const int SYS_RIGID_JOINT = 6;
      public const int SYS_CONSTRAINT_NONE = 0;
      public const int SYS_CONSTRAINT_MEAN = 1;
      public const int SYS_PLOT_LOD0 = 0;
      public const int SYS_PLOT_LOD1 = 1;
      public const int SYS_PLOT_LOD2 = 2;
      public const int SYS_PLOT_LOD3 = 3;
      public const int SYS_PLOT_AERO = 4;
      public const int SYS_INTER_NONE = 0;
      public const int SYS_INTER_CONTACT = 1;
      public const int SYS_INTER_INTERIOR = 2;
      public const int SYS_INTER_WALL = 3;
      public const int SYS_INTER_INLET_PRESSURE = 4;
      public const int SYS_INTER_OUTLET_PRESSURE = 5;
      public const int SYS_INTER_SURF = 6;
      public const int SYS_INTER_SYMMETRY = 7;
      public const int SYS_INTER_PERIODIC_SHADOW = 8;
      public const int SYS_INTER_PRESSURE_FARFIELD = 9;
      public const int SYS_INTER_INLET_VELOCITY = 10;
      public const int SYS_INTER_PERIODIC = 11;
      public const int SYS_INTER_FAN = 12;
      public const int SYS_INTER_INLET_MASSFLOW = 13;
      public const int SYS_INTER_INTERFACE = 14;
      public const int SYS_INTER_PARENT = 15;
      public const int SYS_INTER_OUTFLOW = 16;
      public const int SYS_INTER_AXIS = 17;
      public const int SYS_INTER_USER_DEFINED = 18;
      public const int SYS_INTER_DEGENERATE_LINE = 19;
      public const int SYS_INTER_DIRICHLET = 20;
      public const int SYS_INTER_FARFIELD = 21;
      public const int SYS_INTER_NEUMANN = 22;
      public const int SYS_INTER_GENERAL = 23;
      public const int SYS_INTER_INFLOW_SUBSONIC = 24;
      public const int SYS_INTER_OUTFLOW_SUBSONIC = 25;
      public const int SYS_INTER_INFLOW_SUPERSONIC = 26;
      public const int SYS_INTER_OUTFLOW_SUPERSONIC = 27;
      public const int SYS_INTER_TUNNEL_INFLOW = 28;
      public const int SYS_INTER_SYMMETRY_POLAR = 29;
      public const int SYS_INTER_TUNNEL_OUTFLOW = 30;
      public const int SYS_INTER_WALL_VISCOUS = 31;
      public const int SYS_INTER_WALL_VISCOUS_HEAT_FLUX = 32;
      public const int SYS_INTER_WALL_VISCOUS_ISOTHERMAL = 33;
      public const int SYS_INTER_WALL_INVISCID = 34;
      public const int SYS_INTER_DEGENERATE_POINT = 35;
      public const int SYS_INTER_EXTRAPOLATE = 36;
      public const int SYS_INTER_SURF_ENVIRONMENT = 37;
      public const int SYS_INTER_STAGNATION = 38;
      public const int SYS_INTER_PRESSURE = 39;
      public const int SYS_INTER_BAFFLE = 40;
      public const int SYS_INTER_FREESTREAM = 41;
      public const int SYS_INTER_GASKET = 42;
      public const int SYS_INTER_COHESIVE = 43;
      public const int SYS_INTER_PATCH = 44;
      public const int SYS_INTER_OPENING = 45;
      public const int SYS_INTER_INLET = 46;
      public const int SYS_INTER_OUTLET = 47;
      public const int SYS_SOLID_STAN = 0;
      public const int SYS_SPRINGDASHPOT_INTRINSIC = 9;
      public const int SYS_INTER_MAX = 47;
      public const int SYS_ELEMSYS_GLOBAL = 0;
      public const int SYS_ELEMSYS_STANDARD = -1;
      public const int SYS_ELEMSYS_POSITION = -2;
      public const int SYS_ELEMSYS_GLOBALPROJECT = -3;
      public const int SYS_ELEMSYS_VECTOR = -4;
      public const int SYS_ELEMSYS_BISECTOR = -5;
      public const int SYS_ELEMSYS_NASTRANSHELL = -6;
      public const int SYS_ELEMSYS_VECTORELEMNODE = -8;
      public const int SYS_ELEMSYS_FIRSTEDGE = -9;
      public const int SYS_ELEMSYS_FIRSTEDGEANGLE = -11;
      public const int SYS_ELEMSYS_SPHERICAL_ALT = -13;
      public const int SYS_ELEMSYS_GLOBALCLOSEST = -14;
      public const int SYS_ELEMSYS_CYLINDRICAL = -15;
      public const int SYS_ELEMSYS_SPHERICAL = -16;
      public const int SYS_ELEMSYS_CENTROID = -17;
      public const int SYS_ELEMSYS_ROTANG = -18;
      public const int SYS_ELEMSYS_ROTANGELEMNODE = -19;
      public const int SYS_ELEMSYS_UNKNOWN = -20;
      public const int SYS_ELEMSYS_MIDEDGE = -25;
      public const int SYS_ELEMSYS_BIDIAGONAL = -27;
      public const int SYS_ELEMSYS_MIDPOINT = -28;
      public const int SYS_ELEMSYS_CYLINDRICAL_ALT = -29;
      public const int SYS_ELEMSYS_NASTRANSOLID = -10;
      public const int SYS_ELEMSYS_GLOBALPROJECTR = -21;
      public const int SYS_ELEMSYS_GLOBALPROJECTS = -22;
      public const int SYS_ELEMSYS_GLOBALPROJECTT = -23;
      public const int SYS_ELEMSYS_MARCSHELL = -24;
      public const int SYS_ELEMSYS_MAX = 30;
      public const int SYS_ELEMEND_NONE = 0;
      public const int SYS_ELEMEND_POSITION = -1;
      public const int SYS_ELEMEND_OFFSET = -2;
      public const int SYS_ELEMSEC_NONE = 0;
      public const int SYS_ELEMSEC_BOT = -1;
      public const int SYS_ELEMSEC_TOP = -2;
      public const int SYS_ELEMSEC_MID = -3;
      public const int SYS_ELEMSEC_ALL = -4;
      public const int SYS_LAYERPOSITION_NONE = 0;
      public const int SYS_LAYERPOSITION_MID = 1;
      public const int SYS_LAYERPOSITION_BOTTOP = 2;
      public const int SYS_LAYERPOSITION_BOTMIDTOP = 3;
      public const int SYS_LAYERPOSITION_INTPNT = 4;
      public const int SYS_LAYERPOSITION_BOTMID = 5;
      public const int SYS_LAYERPOSITION_MIDTOP = 6;
      public const int SYS_LAYERPOSITION_BOT = 7;
      public const int SYS_LAYERPOSITION_TOP = 8;
      public const int SYS_LAYERPOSITION_B1M = 9;
      public const int SYS_LAYERPOSITION_M1T = 10;
      public const int SYS_LAYERPOSITION_B5T = 11;
      public const int SYS_STRAINTYPE_TENSOR = 0;
      public const int SYS_STRAINTYPE_ENGINEERING = 1;
      public const int SYS_BEAMSECT_PROPS = 0;
      public const int SYS_BEAMSECT_GEOMETRY = 1;
      public const int SYS_BEAMSECT_BOX = 2;
      public const int SYS_BEAMSECT_ANGLE = 3;
      public const int SYS_BEAMSECT_IBEAM = 4;
      public const int SYS_BEAMSECT_CIRCLE = 5;
      public const int SYS_BEAMSECT_TUBE = 6;
      public const int SYS_BEAMSECT_PANEL = 7;
      public const int SYS_BEAMSECT_RECTANGLE = 8;
      public const int SYS_BEAMSECT_TRAPEZOID = 9;
      public const int SYS_BEAMSECT_HEXAGON = 10;
      public const int SYS_BEAMSECT_TEE = 11;
      public const int SYS_BEAMSECT_ZEE = 12;
      public const int SYS_BEAMSECT_CHANNEL = 13;
      public const int SYS_BEAMSECT_SECTOR = 14;
      public const int SYS_BEAMSECT_ELLIPSE = 15;
      public const int SYS_BEAMSECT_HAT = 16;
      public const int SYS_BEAMSECT_CROSS = 17;
      public const int SYS_BEAMSECT_DBOX = 18;
      public const int SYS_BEAMSECT_HAT1 = 19;
      public const int SYS_BEAMSECT_QUAD = 20;
      public const int SYS_BEAMSECT_HATG = 21;
      public const int SYS_BEAMSECT_SOLIDHEXA = 22;
      public const int SYS_BEAMSECT_SEGMENTS = 23;
      public const int SYS_BEAMSECT_MAXSECTIONS = 24;
      public const int SYS_SHELLWALL_MONOCOQUE = 0;
      public const int SYS_SHELLWALL_PROPS = 1;
      public const int SYS_SHELLWALL_LAMINATE = 2;
      public const int SYS_SHELLWALL_CORRUGATED = 3;
      public const int SYS_SHELLWALL_PSHELL = 4;
      public const int SYS_SHELLWALL_MATRIX = 5;
      public const int SYS_SHELLWALL_GEOMETRY = 6;
      public const int SYS_SOLIDMIX_SINGLE = 0;
      public const int SYS_SOLIDMIX_MULTI = 1;
      public const int SYS_TECH_UNDEFINNED = 0;
      public const int SYS_TECH_ISOP = 1;
      public const int SYS_TECH_URED = 2;
      public const int SYS_TECH_KIRCHHOFF = 3;
      public const int SYS_TECH_MIXED = 4;
      public const int SYS_TECH_ENHANCED = 5;
      public const int SYS_TECH_ANS = 6;
      public const int SYS_PROP_THICKNESS = 2;
      public const int SYS_PROP_OFFSET = 4;
      public const int SYS_PROP_NORMAL = 5;
      public const int SYS_PROP_FIBERBOT = 6;
      public const int SYS_PROP_FIBERTOP = 7;
      public const int SYS_PROP_ELEMVEC = 28;
      public const int SYS_PROP_MATLVEC = 29;
      public const int SYS_PROP_ENDAX = 35;
      public const int SYS_PROP_ENDBX = 36;
      public const int SYS_PROP_OFFSETVEC = 37;
      public const int SYS_PROP_VOLFACT = 3;
      public const int SYS_PROP_AREA = 10;
      public const int SYS_PROP_VOLFACT_MASS = 40;
      public const int SYS_PROP_VOLFACT_STIFF = 41;
      public const int SYS_PROP_VOLFACT_LOAD = 42;
      public const int SYS_REINFSECT_SMEAR = 0;
      public const int SYS_REINFSECT_LOCATION_NOTYPE = 0;
      public const int SYS_REINFSECT_LOCATION_TYPE_MESH = 1;
      public const int SYS_BASIS_SERENDIPITY = 0;
      public const int SYS_BASIS_LAGRANGE = 1;
      public const int SYS_BASIS_BEZIER = 2;
      public const int SYS_BASIS_SPLINE = 3;
      public const int SYS_BASIS_NURBS = 4;
      public const int SYS_BASIS_HERMITE = 5;
      public const int SYS_RULE_UNKKNOWN = 0;
      public const int SYS_RULE_GAUSS = 1;
      public const int SYS_RULE_LOBATTO = 2;
      public const int SYS_RULE_SIMPSON = 3;
      public const int SYS_ERROR_NONE = 0;
      public const int SYS_ERROR_VALUE = 1;
      public const int SYS_ERROR_ENUM = 2;
      public const int SYS_ERROR_OBJECTTYPE = 3;
      public const int SYS_ERROR_MEMORY = 4;
      public const int SYS_ERROR_NULLOBJECT = 5;
      public const int SYS_ERROR_FILE = 6;
      public const int SYS_ERROR_COMPUTE = 7;
      public const int SYS_ERROR_OPERATION = 8;
      public const int SYS_ERROR_OVERFLOW = 9;
      public const int SYS_ERROR_UNDERFLOW = 10;
      public const int SYS_ERROR_UNKNOWN = 11;
      public const int SYS_ERROR_FORMAT = 12;
      public const int SYS_ERROR_LOAD = 13;
      public const int SYS_ERROR_SEVERE = 14;
      public const int SYS_ERROR_LICENSE = 15;
      public const int SYS_ERROR_MAX = 15;
      public const int SYS_MAXPATHCHAR = 1024;
      public const int SYS_MAXNAMECHAR = 81;
      public const int SYS_MAXNAME = 256;
      public const int SYS_MAXDATENAME = 11;
      public const int SYS_MAXTIMENAME = 9;
      public const int SYS_FUNCTION_DEBUG = 1;
      public const int SYS_FUNCTION_MONITOR = 2;
      public const int SYS_FUNCTION_SIZING = 3;
      public const int SYS_FUNCTION_ASIZING = 4;
      public const int SYS_FUNCTION_GEOPROJ = 5;
      public const int SYS_ORDER_AUTO = 0;
      public const int SYS_ORDER_MMD1 = 1;
      public const int SYS_ORDER_MMD2 = 2;
      public const int SYS_ORDER_MDF1 = 3;
      public const int SYS_ORDER_ORIG = 4;
      public const int SYS_ORDER_METIS = 5;
      public const int SYS_ORDER_BCS_MMD = 7;
      public const int SYS_ORDER_RANDOM = 14;
      public const int SYS_ORDER_SWEEP = 15;
      public const int SYS_ORDER_BAND = 16;
      public const int SYS_ORDER_EXTMETIS = 17;
      public const int SYS_TEXT_UNORDERED = 0;
      public const int SYS_TEXT_ORDERED = 1;
      public const int SYS_TEXT_MENU = 2;
      public const int SYS_TEXT_PREFORMATTED = 0;
      public const int SYS_TEXT_BOLD = 1;
      public const int SYS_TEXT_ITALICS = 2;
      public const int SYS_TEXT_TYPEWRITER = 3;
      public const int SYS_TEXT_CENTER = 4;
      public const int SYS_TEXT_HANDLEERR = 5;
      public const int SYS_TEXT_BORDEREQUALS = 6;
      public const int SYS_TEXT_TABLETITLES = 7;
      public const int SYS_TEXT_HEADING = 1;
      public const int SYS_TEXT_ANCHOR = 2;
      public const int SYS_TEXT_TITLE = 3;
      public const int SYS_TEXT_LIST = 4;
      public const int SYS_TEXT_ITEM = 5;
      public const int SYS_TEXT_PARAGRAPH = 6;
      public const int SYS_TEXT_LINEBREAK = 7;
      public const int SYS_TEXT_TABLE = 8;
      public const int SYS_TEXT_ROW = 9;
      public const int SYS_TEXT_COLUMN = 10;
      public const int SYS_TEXT_INTERRUPT = 11;
      public const int SYS_TEXT_LEFT = 1;
      public const int SYS_TEXT_MIDDLE = 2;
      public const int SYS_TEXT_RIGHT = 3;
      public const int SYS_ANALYSIS_NONE = 0;
      public const int SYS_ANALYSIS_STRUCTURAL = 1;
      public const int SYS_ANALYSIS_THERMAL = 2;
      public const int SYS_ANALYSIS_ELECTRIC = 3;
      public const int SYS_ANALYSIS_MAGNETIC = 4;
      public const int SYS_ANALYSIS_FLUID = 5;
      public const int SYS_ANALYSIS_ACOUSTIC = 6;
      public const int SYS_ANALYSIS_DIFFUSION = 7;
      public const int SYS_ANALYSIS_ELECTROCHEMICAL = 8;
      public const int SYS_PLANESTRAIN = 1;
      public const int SYS_PLANESTRESS = 2;
      public const int SYS_AXISYMMETRIC = 3;
      public const int SYS_AXISYMFOURIER = 4;
      public const int SYS_EIGEN_NONE = 0;
      public const int SYS_EIGEN_ALL = 1;
      public const int SYS_EIGEN_LOWEST = 2;
      public const int SYS_EIGEN_NEAREST = 3;
      public const int SYS_EIGEN_SUBSPACE = 5;
      public const int SYS_EIGEN_LANCZOS = 6;
      public const int SYS_EIGEN_AMLS = 9;
      public const int SYS_EIGEN_NORMMASS = 7;
      public const int SYS_EIGEN_NORMMAX = 8;
      public const int SYS_SOLVERTYPE_PARDISO = 1;
      public const int SYS_SOLVERTYPE_MUMPS = 2;
      public const int SYS_SOLVERTYPE_MUMPSPIVOT = 3;
      public const int SYS_SOLVERTYPE_LL = 4;
      public const int SYS_SOLVERTYPE_MF = 5;
      public const int SYS_SOLVERTYPE_MFP = 6;
      public const int SYS_DOF_NONE = 0;
      public const int SYS_DOF_TX = 1;
      public const int SYS_DOF_TY = 2;
      public const int SYS_DOF_TZ = 3;
      public const int SYS_DOF_RX = 4;
      public const int SYS_DOF_RY = 5;
      public const int SYS_DOF_RZ = 6;
      public const int SYS_DOF_TEMP = 7;
      public const int SYS_DOF_VOLT = 8;
      public const int SYS_DOF_WARP = 9;
      public const int SYS_DOF_PRES = 10;
      public const int SYS_DOF_VX = 11;
      public const int SYS_DOF_VY = 12;
      public const int SYS_DOF_VZ = 13;
      public const int SYS_DOF_ELEM = 14;
      public const int SYS_DOF_LAGM = 15;
      public const int SYS_DOF_S0 = 16;
      public const int SYS_DOF_S1 = 17;
      public const int SYS_DOF_S2 = 18;
      public const int SYS_DOF_S3 = 19;
      public const int SYS_DOF_S4 = 20;
      public const int SYS_DOF_S5 = 21;
      public const int SYS_DOF_S6 = 22;
      public const int SYS_DOF_S7 = 23;
      public const int SYS_DOF_S8 = 24;
      public const int SYS_DOF_S9 = 25;
      public const int SYS_DOF_S10 = 26;
      public const int SYS_DOF_S11 = 27;
      public const int SYS_DOF_S12 = 28;
      public const int SYS_DOF_S13 = 29;
      public const int SYS_DOF_S14 = 30;
      public const int SYS_DOF_S15 = 31;
      public const int SYS_DOF_S = 16;
      public const int SYS_DOF_MAX = 31;
      public const int SYS_MAT_ISOTROPIC = 0;
      public const int SYS_MAT_LAMINA = 1;
      public const int SYS_MAT_ORTHOTROPIC = 2;
      public const int SYS_MAT_ANISOTROPIC = 3;
      public const int SYS_MAT_HYPERELASTIC = 4;
      public const int SYS_MAT_GENERIC = 5;
      public const int SYS_MAT_MAX = 6;
      public const int SYS_MAT_HARDENING_ISOTROPIC = -1;
      public const int SYS_MAT_HARDENING_KINEMATIC = -2;
      public const int SYS_HEATEXCH_LINEAR = 1;
      public const int SYS_HEATEXCH_EXP = 2;
      public const int SYS_HEATEXCH_POW = 3;
      public const int SYS_HEATEXCH_RAD = 4;
      public const int SYS_ASCII = -1;
      public const int SYS_BINARY = -2;
      public const int SYS_FILE_STL = -4;
      public const int SYS_FILE_STLBIN = -5;
      public const int SYS_FILE_OBJ = -6;
      public const int SYS_MAGIC = 7946;
      public const int SYS_NATIVE = 1;
      public const int SYS_PLOT3D_GRID = 2;
      public const int SYS_PLOT3D_SOLUTION = 3;
      public const int SYS_PATRAN_RESULT = 4;
      public const int SYS_GENERIC = 5;
      public const int SYS_PDA = 6;
      public const int SYS_LSTC_STATE = 7;
      public const int SYS_ABAQUS_ODB = 8;
      public const int SYS_ABAQUS_FIL = 9;
      public const int SYS_NASTRAN_OUTPUT2 = 10;
      public const int SYS_STL = 11;
      public const int SYS_STLBIN = 12;
      public const int SYS_ABAQUS_INPUT = 13;
      public const int SYS_SDRC_UNIVERSAL = 14;
      public const int SYS_PAM_DAISY = 15;
      public const int SYS_ANSYS_RESULT = 16;
      public const int SYS_MECHANICA_STUDY = 17;
      public const int SYS_NASTRAN_BULKDATA = 18;
      public const int SYS_FDI_NEUTRAL = 19;
      public const int SYS_PATRAN_NEUTRAL = 20;
      public const int SYS_FLUENT_MESH = 21;
      public const int SYS_ANSYS_INPUT = 22;
      public const int SYS_TECPLOT = 23;
      public const int SYS_HYPERMESH_ASCII = 24;
      public const int SYS_LSTC_INPUT = 25;
      public const int SYS_CGNS = 26;
      public const int SYS_MARC_POST = 27;
      public const int SYS_ENSIGHT = 28;
      public const int SYS_STARCCM = 29;
      public const int SYS_MECHANICA_FNF = 30;
      public const int SYS_LSTC_HISTORY = 32;
      public const int SYS_NASTRAN_XDB = 33;
      public const int SYS_NASTRAN_H5 = 34;
      public const int SYS_POLYFLOW = 36;
      public const int SYS_FEMAP_NEUTRAL = 37;
      public const int SYS_AUTODYN_RES = 38;
      public const int SYS_PAM_ERF = 39;
      public const int SYS_OPENFOAM = 40;
      public const int SYS_OBJ = 41;
      public const int SYS_COMSOL_SECTION = 43;
      public const int SYS_H3D = 44;
      public const int SYS_LSTC_STATEFEMZIP = 45;
      public const int SYS_PAM_INPUT = 46;
      public const int SYS_CFX_RESULT = 47;
      public const int SYS_GMV = 48;
      public const int SYS_PERMAS_POST = 49;
      public const int SYS_VTK_LEGACY = 50;
      public const int SYS_SAMCEF = 51;
      public const int SYS_AFLR = 52;
      public const int SYS_ADAMS = 53;
      public const int SYS_NATIVE_HDF5 = 54;
      public const int SYS_MEMORY = 55;
      public const int SYS_COMSOL_MPH = 56;
      public const int SYS_COMSOL_MPHBIN = 57;
      public const int SYS_MARC_INPUT = 58;
      public const int SYS_ANSYS_DPF = 59;
      public const int SYS_PLUGIN = 60;
      public const int SYS_VTK_VTU = 61;
      public const int SYS_MAXTYPE = 62;
      public const int SYS_CATEGORY_NONE = 0;
      public const int SYS_CATEGORY_BUCK = 1;
      public const int SYS_CATEGORY_VIBE = 2;
      public const int SYS_CATEGORY_STAT = 3;
      public const int SYS_CATEGORY_TRAN = 4;
      public const int SYS_CATEGORY_CONS = 5;
      public const int SYS_CATEGORY_CONC = 6;
      public const int SYS_CATEGORY_DIST = 7;
      public const int SYS_CATEGORY_INERTIA = 8;
      public const int SYS_CATEGORY_EFFINERTIA = 9;
      public const int SYS_CATEGORY_RIGID = 10;
      public const int SYS_CATEGORY_LOAD = 11;
      public const int SYS_CATEGORY_FREQUENCYRESPONSE = 12;
      public const int SYS_CATEGORY_MAX = 13;
      public const int SYS_VENDOR_UNKNOWN = 0;
      public const int SYS_VENDOR_VKI = 1;
      public const int SYS_VENDOR_MSC_NASTRAN = 2;
      public const int SYS_VENDOR_ANSYS = 3;
      public const int SYS_VENDOR_ABAQUS = 4;
      public const int SYS_VENDOR_LS_DYNA3D = 5;
      public const int SYS_VENDOR_ALTAIR_OPTISTRUCT = 6;
      public const int SYS_VENDOR_NX_NASTRAN = 7;
      public const int SYS_VENDOR_ADINA_NASTRAN = 7;
      public const int SYS_VENDOR_MAX = 8;
      public const int SYS_RES_NONE = -1;
      public const int SYS_RES_X = 0;
      public const int SYS_RES_D = 1;
      public const int SYS_RES_XF = 2;
      public const int SYS_RES_R = 3;
      public const int SYS_RES_V = 4;
      public const int SYS_RES_A = 5;
      public const int SYS_RES_HEAT_FLUX = 6;
      public const int SYS_RES_VOLT = 7;
      public const int SYS_RES_DENS = 8;
      public const int SYS_RES_VISC = 9;
      public const int SYS_RES_COND = 10;
      public const int SYS_RES_MACH = 11;
      public const int SYS_RES_STREAM = 12;
      public const int SYS_RES_ENTROPY = 13;
      public const int SYS_RES_MASS_FLUX = 14;
      public const int SYS_RES_TEMP = 15;
      public const int SYS_RES_FILM_COEF = 16;
      public const int SYS_RES_J = 17;
      public const int SYS_RES_TF = 18;
      public const int SYS_RES_PRES = 19;
      public const int SYS_RES_D_MAT = 20;
      public const int SYS_RES_ELEC_POT = 21;
      public const int SYS_RES_Q = 22;
      public const int SYS_RES_MAG_POT = 23;
      public const int SYS_RES_R_J = 24;
      public const int SYS_RES_MASS_FLOW = 25;
      public const int SYS_RES_VOLUME = 26;
      public const int SYS_RES_VOLUME_FLUX = 27;
      public const int SYS_RES_UNKNOWN = 28;
      public const int SYS_RES_V_DIV = 29;
      public const int SYS_RES_E = 30;
      public const int SYS_RES_INERTIA = 31;
      public const int SYS_RES_DENS_GRAD = 32;
      public const int SYS_RES_P = 33;
      public const int SYS_RES_TIME = 34;
      public const int SYS_RES_S = 35;
      public const int SYS_RES_ID = 36;
      public const int SYS_RES_V_GRAD = 37;
      public const int SYS_RES_USER = 38;
      public const int SYS_RES_THICKNESS = 39;
      public const int SYS_RES_STIFF = 40;
      public const int SYS_RES_R_Q = 41;
      public const int SYS_RES_SCALARS = 42;
      public const int SYS_RES_HEAT_GRAD = 43;
      public const int SYS_RES_TE_ERROR = 44;
      public const int SYS_RES_XF_Q = 45;
      public const int SYS_RES_ENERGY_DENSITY = 46;
      public const int SYS_RES_SDV = 47;
      public const int SYS_RES_VIEW_FACT = 48;
      public const int SYS_RES_DAMP = 49;
      public const int SYS_RES_FREQ = 50;
      public const int SYS_RES_SE_DENSITY = 51;
      public const int SYS_RES_K_MAT = 52;
      public const int SYS_RES_M_MAT = 53;
      public const int SYS_RES_L_VEC = 54;
      public const int SYS_RES_ORDER = 55;
      public const int SYS_RES_AREA = 56;
      public const int SYS_RES_LENGTH = 57;
      public const int SYS_RES_RADIUS = 58;
      public const int SYS_RES_NUMBER = 59;
      public const int SYS_RES_KE_DENSITY = 60;
      public const int SYS_RES_DAMAGE = 61;
      public const int SYS_RES_DIST = 62;
      public const int SYS_RES_TEMP_DOT = 63;
      public const int SYS_RES_TE = 64;
      public const int SYS_RES_COND_MAT = 65;
      public const int SYS_RES_CAP_MAT = 66;
      public const int SYS_RES_FAIL_INDEX = 67;
      public const int SYS_RES_VOID_RATIO = 69;
      public const int SYS_RES_TEMP_GRAD = 70;
      public const int SYS_RES_PRES_COEF = 71;
      public const int SYS_RES_LOAD_FACT = 72;
      public const int SYS_RES_PRES_GRAD = 73;
      public const int SYS_RES_PRES_DOT = 74;
      public const int SYS_RES_PRES_DOTDOT = 75;
      public const int SYS_RES_MASS = 76;
      public const int SYS_RES_HEAT = 77;
      public const int SYS_RES_CRACK_DENSITY = 78;
      public const int SYS_RES_ELEC_FIELD = 79;
      public const int SYS_RES_ELEC_FLUX = 80;
      public const int SYS_RES_R_HEAT_FLOW = 81;
      public const int SYS_RES_MAG_FLUX = 82;
      public const int SYS_RES_MAG_FIELD = 83;
      public const int SYS_RES_J_DENSITY = 84;
      public const int SYS_RES_TURB_KE = 85;
      public const int SYS_RES_TURB_ED = 86;
      public const int SYS_RES_CONC = 87;
      public const int SYS_RES_H = 88;
      public const int SYS_RES_CP = 89;
      public const int SYS_RES_POROSITY = 90;
      public const int SYS_RES_H_DOT = 91;
      public const int SYS_RES_FACTOR = 92;
      public const int SYS_RES_HEAT_FLOW = 93;
      public const int SYS_RES_SFM = 94;
      public const int SYS_RES_SEK = 95;
      public const int SYS_RES_WEIGHT = 96;
      public const int SYS_RES_KE = 97;
      public const int SYS_RES_SE = 98;
      public const int SYS_RES_DIR = 99;
      public const int SYS_RES_ENERGY = 100;
      public const int SYS_RES_SEP = 102;
      public const int SYS_RES_CLOSURE = 105;
      public const int SYS_RES_STATE = 107;
      public const int SYS_RES_STAT = 108;
      public const int SYS_RES_R_MASS_FLOW = 109;
      public const int SYS_RES_XF_MASS_FLOW = 110;
      public const int SYS_RES_E_RATE = 113;
      public const int SYS_RES_SE_ERROR = 117;
      public const int SYS_RES_XF_HEAT_FLOW = 119;
      public const int SYS_RES_DIR_COS = 120;
      public const int SYS_RES_SF = 121;
      public const int SYS_RES_SD = 122;
      public const int SYS_RES_YPLUS = 123;
      public const int SYS_RES_UTAU = 124;
      public const int SYS_RES_SE_PERCENT = 125;
      public const int SYS_RES_KE_PERCENT = 126;
      public const int SYS_RES_DOM_FLUID_PHASE = 127;
      public const int SYS_RES_SOUND_MODEL = 128;
      public const int SYS_RES_PENE_CONTACT = 129;
      public const int SYS_RES_SAFE_FACT = 139;
      public const int SYS_RES_FAT_DAMAGE = 140;
      public const int SYS_RES_FAT_DAMAGE_DIR = 141;
      public const int SYS_RES_FAT_LIFE = 142;
      public const int SYS_RES_GAP = 144;
      public const int SYS_RES_EN_FORC = 145;
      public const int SYS_RES_EN_FLUX = 146;
      public const int SYS_RES_STRENGTH_SAFE_FACT = 147;
      public const int SYS_RES_FAT_SAFE_FACT = 148;
      public const int SYS_RES_PHASE_DIAMETER = 149;
      public const int SYS_RES_MU_LAMB = 150;
      public const int SYS_RES_MU_TURB = 151;
      public const int SYS_RES_BODY_FORCE = 152;
      public const int SYS_RES_WALL_SHEAR = 153;
      public const int SYS_RES_VORTICITY = 154;
      public const int SYS_RES_REACTION_PROGRESS = 155;
      public const int SYS_RES_SOUND_LEVEL = 156;
      public const int SYS_RES_ROT_ANG = 157;
      public const int SYS_RES_VOF = 158;
      public const int SYS_RES_VISC_EDDY = 159;
      public const int SYS_RES_ROUGHNESS = 160;
      public const int SYS_RES_FRACTION = 161;
      public const int SYS_RES_CONV_COEF = 162;
      public const int SYS_RES_POWER = 163;
      public const int SYS_RES_INTENSITY = 164;
      public const int SYS_RES_TRAC = 165;
      public const int SYS_RES_XF_J = 166;
      public const int SYS_RES_PRANDTL = 167;
      public const int SYS_RES_TURB_DIST = 168;
      public const int SYS_RES_REYNOLDS = 169;
      public const int SYS_RES_RADIANCE = 170;
      public const int SYS_RES_FLUENCE = 171;
      public const int SYS_RES_RC_PROD = 172;
      public const int SYS_RES_POWER_DENSITY = 173;
      public const int SYS_RES_WATER_ACCUM = 174;
      public const int SYS_RES_TURB_SD = 175;
      public const int SYS_RES_TE_DENSITY = 176;
      public const int SYS_RES_STRENGTH_RATIO = 177;
      public const int SYS_RES_DELETED = 178;
      public const int SYS_RES_MARG_SAFE = 179;
      public const int SYS_RES_MOMENT = 180;
      public const int SYS_RES_ROTATION = 181;
      public const int SYS_RES_TRANSLATION = 182;
      public const int SYS_RES_FORCE = 183;
      public const int SYS_RES_DECIBEL = 184;
      public const int SYS_RES_PROBABILITY = 185;
      public const int SYS_RES_FORCE_MOMENT = 186;
      public const int SYS_RES_YOUNGS_MODULUS = 187;
      public const int SYS_RES_POISSONS_RATIO = 188;
      public const int SYS_RES_SHEAR_MODULUS = 189;
      public const int SYS_RES_TEXP_COEF = 190;
      public const int SYS_RES_CHEM_SHRINKAGE = 191;
      public const int SYS_RES_CONVERSIONTIME = 192;
      public const int SYS_RES_CONVERSIONSTATUS = 193;
      public const int SYS_RES_EFFECTIVEMASSSUMMARY = 194;
      public const int SYS_RES_EFFECTIVEMASS = 195;
      public const int SYS_RES_PARTICIPATIONFACTOR = 196;
      public const int SYS_RES_MASSFRACTION = 197;
      public const int SYS_RES_TM = 198;
      public const int SYS_RES_HOURGLASS_ENERGY = 199;
      public const int SYS_RES_MAX = 200;
      public const int SYS_QUA_NONE = -1;
      public const int SYS_QUA_X = 0;
      public const int SYS_QUA_Y = 1;
      public const int SYS_QUA_Z = 2;
      public const int SYS_QUA_MAG = 3;
      public const int SYS_QUA_XX = 4;
      public const int SYS_QUA_YY = 5;
      public const int SYS_QUA_ZZ = 6;
      public const int SYS_QUA_XY = 7;
      public const int SYS_QUA_YZ = 8;
      public const int SYS_QUA_ZX = 9;
      public const int SYS_QUA_VONMISES = 10;
      public const int SYS_QUA_NXX = 11;
      public const int SYS_QUA_NYY = 12;
      public const int SYS_QUA_NXY = 13;
      public const int SYS_QUA_MXX = 14;
      public const int SYS_QUA_MYY = 15;
      public const int SYS_QUA_MXY = 16;
      public const int SYS_QUA_QXY = 17;
      public const int SYS_QUA_QZX = 18;
      public const int SYS_QUA_TX = 19;
      public const int SYS_QUA_TY = 20;
      public const int SYS_QUA_TZ = 21;
      public const int SYS_QUA_RX = 22;
      public const int SYS_QUA_RY = 23;
      public const int SYS_QUA_RZ = 24;
      public const int SYS_QUA_MINIMUM = 25;
      public const int SYS_QUA_MAXIMUM = 26;
      public const int SYS_QUA_INTERMEDIATE = 27;
      public const int SYS_QUA_EFF = 28;
      public const int SYS_QUA_TOT = 29;
      public const int SYS_QUA_INC = 30;
      public const int SYS_QUA_REL = 31;
      public const int SYS_QUA_ABS = 32;
      public const int SYS_QUA_EQUIV = 33;
      public const int SYS_QUA_PLAST = 34;
      public const int SYS_QUA_CREEP = 35;
      public const int SYS_QUA_THERMAL = 36;
      public const int SYS_QUA_ELAST = 37;
      public const int SYS_QUA_INELAST = 38;
      public const int SYS_QUA_REYNOLDS = 39;
      public const int SYS_QUA_STAG = 40;
      public const int SYS_QUA_CAUCHY = 41;
      public const int SYS_QUA_PK = 42;
      public const int SYS_QUA_LOG = 43;
      public const int SYS_QUA_TRESCA = 44;
      public const int SYS_QUA_YIELD = 45;
      public const int SYS_QUA_MEAN = 46;
      public const int SYS_QUA_NONLIN = 47;
      public const int SYS_QUA_TORSION = 48;
      public const int SYS_QUA_SWELLING = 49;
      public const int SYS_QUA_CRACKING = 50;
      public const int SYS_QUA_NORMAL = 51;
      public const int SYS_QUA_SHEAR = 52;
      public const int SYS_QUA_PSD = 53;
      public const int SYS_QUA_RMS = 54;
      public const int SYS_QUA_NOM = 55;
      public const int SYS_QUA_COMPONENT = 56;
      public const int SYS_QUA_INTERLAMINAR = 57;
      public const int SYS_QUA_PLY = 58;
      public const int SYS_QUA_BOND = 59;
      public const int SYS_QUA_CONSTRAINT = 60;
      public const int SYS_QUA_PORE = 61;
      public const int SYS_QUA_GASKET = 62;
      public const int SYS_QUA_CONTACT = 63;
      public const int SYS_QUA_INITIAL = 64;
      public const int SYS_QUA_FINAL = 65;
      public const int SYS_QUA_TENS = 66;
      public const int SYS_QUA_COMP = 67;
      public const int SYS_QUA_INFRARED = 68;
      public const int SYS_QUA_DIFFUSE = 69;
      public const int SYS_QUA_COLLIMATED = 70;
      public const int SYS_QUA_SOLAR = 71;
      public const int SYS_QUA_SOUND = 72;
      public const int SYS_QUA_RADIATIVE = 73;
      public const int SYS_QUA_CONDUCTIVE = 74;
      public const int SYS_QUA_CONVECTIVE = 75;
      public const int SYS_QUA_RESIDUAL = 76;
      public const int SYS_QUA_ADJUSTED = 77;
      public const int SYS_QUA_PSIDE = 78;
      public const int SYS_QUA_MSIDE = 79;
      public const int SYS_QUA_LOCAL = 80;
      public const int SYS_QUA_INTERNAL = 81;
      public const int SYS_QUA_BULK = 82;
      public const int SYS_QUA_STATIC = 83;
      public const int SYS_QUA_DYNAMIC = 84;
      public const int SYS_QUA_SLIP = 85;
      public const int SYS_QUA_FREE = 86;
      public const int SYS_QUA_FORCED = 87;
      public const int SYS_QUA_FLUID = 88;
      public const int SYS_QUA_HARMONIC = 89;
      public const int SYS_QUA_LORENTZ = 90;
      public const int SYS_QUA_BEARING = 91;
      public const int SYS_QUA_RADIAL = 92;
      public const int SYS_QUA_TANG = 93;
      public const int SYS_QUA_AXIAL = 94;
      public const int SYS_QUA_GREEN = 95;
      public const int SYS_QUA_MEANPRES = 96;
      public const int SYS_QUA_DEFORM = 97;
      public const int SYS_QUA_GPF = 98;
      public const int SYS_QUA_VISC = 99;
      public const int SYS_QUA_GLUE = 100;
      public const int SYS_QUA_FRICTION = 101;
      public const int SYS_QUA_SCALAR = 102;
      public const int SYS_QUA_PRINCIPAL = 103;
      public const int SYS_QUA_NOZ = 104;
      public const int SYS_QUA_ATO = 105;
      public const int SYS_QUA_CRM = 106;
      public const int SYS_QUA_SOURCE = 107;
      public const int SYS_QUA_SUM = 108;
      public const int SYS_QUA_NET = 109;
      public const int SYS_QUA_ACOUSTIC = 110;
      public const int SYS_QUA_RADIOSITY = 111;
      public const int SYS_QUA_IRRADIANCE = 112;
      public const int SYS_QUA_TRANSMITTED = 113;
      public const int SYS_QUA_REFLECTED = 114;
      public const int SYS_QUA_INCIDENT = 115;
      public const int SYS_QUA_ABSORBED = 116;
      public const int SYS_QUA_SOLID = 117;
      public const int SYS_QUA_DISSIPATED = 118;
      public const int SYS_QUA_OPT = 119;
      public const int SYS_QUA_CONC = 120;
      public const int SYS_QUA_DIST = 121;
      public const int SYS_QUA_ATTACHMENT = 122;
      public const int SYS_QUA_INERTIA = 123;
      public const int SYS_QUA_REDUCED = 124;
      public const int SYS_QUA_MODAL = 125;
      public const int SYS_QUA_PARTICLE = 126;
      public const int SYS_QUA_NEIGHBORS = 127;
      public const int SYS_QUA_SHELL = 128;
      public const int SYS_QUA_ERROR = 129;
      public const int SYS_QUA_NORM = 130;
      public const int SYS_QUA_EIP = 131;
      public const int SYS_QUA_PANEL = 132;
      public const int SYS_QUA_LCR = 133;
      public const int SYS_QUA_PEAK = 134;
      public const int SYS_QUA_DIFFERENCE = 135;
      public const int SYS_QUA_CYCLIC = 136;
      public const int SYS_QUA_SIN = 137;
      public const int SYS_QUA_COS = 138;
      public const int SYS_QUA_MPC = 139;
      public const int SYS_QUA_TURB = 140;
      public const int SYS_QUA_SYM = 141;
      public const int SYS_QUA_ASYM = 142;
      public const int SYS_QUA_DAMAGE = 143;
      public const int SYS_QUA_COHESIVE = 144;
      public const int SYS_QUA_BOLT = 145;
      public const int SYS_QUA_CHOCKING = 146;
      public const int SYS_QUA_MECH = 147;
      public const int SYS_QUA_ENTHALPY = 148;
      public const int SYS_QUA_FLAME = 149;
      public const int SYS_QUA_GLASSTRANS = 150;
      public const int SYS_QUA_EMITTED = 151;
      public const int SYS_QUA_COUPLED = 152;
      public const int SYS_QUA_UNCOUPLED = 153;
      public const int SYS_QUA_STRUCT = 154;
      public const int SYS_QUA_TRANSPORT = 155;
      public const int SYS_QUA_WELD = 156;
      public const int SYS_QUA_KIRCH = 157;
      public const int SYS_QUA_NORMALIZED = 158;
      public const int SYS_QUA_APPLIED = 159;
      public const int SYS_QUA_GYROSCOPIC = 160;
      public const int SYS_QUA_DAMPING = 161;
      public const int SYS_QUA_CIRCULATORY_FORCES = 162;
      public const int SYS_QUA_TSAI_HILL = 163;
      public const int SYS_QUA_TSAI_WU = 164;
      public const int SYS_QUA_HASHIN = 165;
      public const int SYS_QUA_STRESS = 166;
      public const int SYS_QUA_STRAIN = 167;
      public const int SYS_QUA_RICE_TRACEY = 168;
      public const int SYS_QUA_HOFFMAN = 169;
      public const int SYS_QUA_PUCK = 170;
      public const int SYS_QUA_LARC04 = 171;
      public const int SYS_QUA_TRACTION = 172;
      public const int SYS_QUA_PLANE_STRESS = 173;
      public const int SYS_QUA_FIBER = 174;
      public const int SYS_QUA_MATRIX = 175;
      public const int SYS_QUA_RATIO = 176;
      public const int SYS_QUA_VARIANT = 177;
      public const int SYS_QUA_CRITICAL = 178;
      public const int SYS_QUA_FULL = 179;
      public const int SYS_QUA_MATERIAL = 180;
      public const int SYS_QUA_AWEIGHT = 181;
      public const int SYS_QUA_INACTIVE = 182;
      public const int SYS_QUA_OVERHEATING = 183;
      public const int SYS_QUA_UNCONVERGED = 184;
      public const int SYS_QUA_VOLUME = 185;
      public const int SYS_QUA_VIBE = 186;
      public const int SYS_QUA_PENETRATION = 187;
      public const int SYS_QUA_BIOT = 188;
      public const int SYS_QUA_ENG = 189;
      public const int SYS_QUA_CG = 190;
      public const int SYS_QUA_PARTICIPATION = 191;
      public const int SYS_QUA_AERO = 192;
      public const int SYS_QUA_MASS = 193;
      public const int SYS_QUA_RIGID = 194;
      public const int SYS_QUA_UNIT = 195;
      public const int SYS_QUA_RESTRAINED = 196;
      public const int SYS_QUA_UNRESTRAINED = 197;
      public const int SYS_QUA_HOMOGENIZED = 198;
      public const int SYS_QUA_SHEARPANEL = 199;
      public const int SYS_QUA_BENDING = 200;
      public const int SYS_QUA_BODY = 201;
      public const int SYS_QUA_SPC = 202;
      public const int SYS_QUA_ROTATIONAL = 203;
      public const int SYS_QUA_MAX = 204;
      public const int SYS_QUAVAL_NONE = -1;
      public const int SYS_QUAVAL_PHASE = 0;
      public const int SYS_QUAVAL_HARMONIC = 1;
      public const int SYS_QUAVAL_ROTORSPEED = 2;
      public const int SYS_QUAVAL_NODE = 3;
      public const int SYS_QUAVAL_MATERIAL = 4;
      public const int SYS_QUAVAL_SET = 5;
      public const int SYS_QUAVAL_DESIGNCYCLE = 6;
      public const int SYS_QUAVAL_SECTION = 7;
      public const int SYS_QUAVAL_INTPNT = 8;
      public const int SYS_QUAVAL_CONTACTPAIR = 9;
      public const int SYS_QUAVAL_SPECIES = 10;
      public const int SYS_QUAVAL_BOLTSEQUENCE = 11;
      public const int SYS_QUAVAL_STEP = 12;
      public const int SYS_QUAVAL_COUNT = 13;
      public const int SYS_QUAVAL_MAX = 14;
      public const int SYS_NQUA_MAX = 4;
      public const int SYS_APPROX_NONE = 0;
      public const int SYS_APPROX_LINEAR = 1;
      public const int SYS_APPROX_QUADRATIC = 2;
      public const int SYS_APPROX_CUBIC = 3;
      public const int SYS_PHASE_MASS = 1;
      public const int SYS_PHASE_SYMFACTOR = 2;
      public const int SYS_PHASE_INITCOND = 3;
      public const int SYS_PHASE_PREDICTOR = 4;
      public const int SYS_PHASE_STIFF = 5;
      public const int SYS_PHASE_FACTOR = 6;
      public const int SYS_PHASE_UPDATE = 7;
      public const int SYS_PHASE_REACT = 8;
      public const int SYS_PHASE_REACTSTIFF = 9;
      public const int SYS_PHASE_SOLVE = 10;
      public const int SYS_PHASE_GEOMSTIFF = 11;
      public const int SYS_PHASE_BUCKLING = 12;
      public const int SYS_PHASE_VIBRATION = 13;
      public const int SYS_PHASE_OUTPUT = 14;
      public const int SYS_PHASE_STATICMODES = 15;
      public const int SYS_PHASE_DOFTAB = 16;
      public const int SYS_PHASE_INITIALIZATION = 17;
      public const int SYS_PHASE_BEGINCASE = 18;
      public const int SYS_PHASE_ENDCASE = 19;
      public const int VSY_DICTIONARY = 1010;
      public const int VSY_HASHTABLE = 1020;
      public const int VSY_LIST = 1030;
      public const int VSY_STACK = 1040;
      public const int VSY_BITVEC = 1050;
      public const int VSY_PROPSET = 1060;
      public const int VSY_RANDOM = 1070;
      public const int VSY_TEXTFUN = 1080;
      public const int VSY_TEXTFUN_0 = 1080;
      public const int VSY_TEXTFUN_1 = 1081;
      public const int VSY_TEXTFUN_2 = 1082;
      public const int VSY_TEXTFUN_3 = 1083;
      public const int VSY_TEXTFUN_4 = 1084;
      public const int VSY_TEXTFUN_5 = 1085;
      public const int VSY_TEXTFUN_6 = 1086;
      public const int VSY_TEXTFUN_7 = 1087;
      public const int VSY_TEXTFUN_TEE = 1081;
      public const int VSY_HTMLTEXT = 1100;
      public const int VSY_PLAINTEXT = 1110;
      public const int VSY_CONCAT = 1120;
      public const int VSY_DATATABLE = 1130;
      public const int VSY_PQUEUE = 1140;
      public const int VSY_TRICON = 1150;
      public const int VSY_VERTLOC = 1160;
      public const int VSY_LINECON = 1170;
      public const int VSY_INTVEC = 1180;
      public const int VSY_TIMER = 1190;
      public const int VSY_PTASK = 1200;
      public const int VSY_TEXTTEE = 1210;
      public const int VSY_LATEXTEXT = 1220;
      public const int VSY_FILETEXT = 1230;
      public const int VSY_LINKLIST = 1240;
      public const int VSY_ADTREE = 1250;
      public const int VSY_DBLVEC = 1260;
      public const int VSY_INTHASH = 1270;
      public const int VSY_INTDICT = 1280;
      public const int VSY_CALC = 1290;
      public const int VSY_PROGRESS = 1300;
      public const int VSY_INTSTACK = 1310;
      public const int VSY_REGEXP = 1320;
      public const int VSY_ECHO = 1330;
      public const int VSY_FLTVEC = 1340;
      public const int VSY_INTQUE = 1350;
      public const int VSY_HEAP = 1360;
      public const int VSY_HEAPIND = 1370;
      public const int VSY_REDPRE = 1380;
      public const int VSY_INTVHASH = 1390;
      public const int VSY_TREE = 1400;
      public const int VSY_PRED = 1410;
      public const int VSY_MPC = 1411;
      public const int VSY_ZMEM = 1430;
      public const int VSY_VHASHTABLE = 1440;
      public const int VSY_CVECT = 1490;
      public const int VSY_INCLUDEZERO = 1;
      public const int SYS_CHAR_UNDEFINED = 127;
      public const int SYS_SCHAR_UNDEFINED = 127;
      public const int SYS_UCHAR_UNDEFINED = 255;
      public const int SYS_SHORT_UNDEFINED = 32767;
      public const int SYS_USHORT_UNDEFINED = 65535;
      public const int SYS_INT_UNDEFINED = 2147483647;
      public const long SYS_LONG_UNDEFINED = 9223372036854775807;
      public const ulong SYS_ULONG_UNDEFINED = 18446744073709551615;
      public const ulong SYS_WORD_UNDEFINED = 18446744073709551615;
      public const float SYS_FLOAT_UNDEFINED = 3.402823466e+38F;
      public const double SYS_DOUBLE_UNDEFINED = 1.7976931348623158e+308;
      public const uint SYS_UINT_UNDEFINED = 4294967295;
      public const int SYS_TCHAR_UNDEFINED = 127;
      public const int SYS_WCHAR_T_UNDEFINED = 2147483647;
      public const int SYS_MAX_DEGREES_OF_FREEDOM = 6;

      public const int BITVEC_SET = 1;
      public const int BITVEC_AND = 2;
      public const int BITVEC_OR = 3;
      public const int BITVEC_XOR = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_BitVecBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_BitVecError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecDef(IntPtr p,int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecInq(IntPtr p,ref int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecVector(IntPtr p,int [] v_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecSet(IntPtr p,int i_ndex,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecGet(IntPtr p,int i_dx,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecComplement(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecBoolean(IntPtr p,int o_per,IntPtr b_itvecsrc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecMatch(IntPtr p,IntPtr b_itvecm,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_BitVecPrint(IntPtr p);

      public static IntPtr BitVecBegin() {
         return vsy_BitVecBegin();
      }

      public static void BitVecEnd(IntPtr p) {
         vsy_BitVecEnd(p);
      }

      public static int BitVecError(IntPtr p) {
         return vsy_BitVecError(p);
      }

      public static void BitVecDef(IntPtr p,int m_axindex) {
         vsy_BitVecDef(p, m_axindex);
      }

      public static void BitVecInq(IntPtr p,ref int l_en) {
         vsy_BitVecInq(p,ref l_en);
      }

      public static void BitVecSetParami(IntPtr p,int p_type,int i_param) {
         vsy_BitVecSetParami(p, p_type, i_param);
      }

      public static void BitVecCount(IntPtr p,ref int n_um) {
         vsy_BitVecCount(p,ref n_um);
      }

      public static void BitVecVector(IntPtr p,int [] v_ec) {
         vsy_BitVecVector(p, v_ec);
      }

      public static void BitVecSet(IntPtr p,int i_ndex,int v_alue) {
         vsy_BitVecSet(p, i_ndex, v_alue);
      }

      public static void BitVecGet(IntPtr p,int i_dx,ref int v_alue) {
         vsy_BitVecGet(p, i_dx,ref v_alue);
      }

      public static void BitVecClear(IntPtr p) {
         vsy_BitVecClear(p);
      }

      public static void BitVecComplement(IntPtr p) {
         vsy_BitVecComplement(p);
      }

      public static void BitVecBoolean(IntPtr p,int o_per,IntPtr b_itvecsrc) {
         vsy_BitVecBoolean(p, o_per, b_itvecsrc);
      }

      public static void BitVecInitIter(IntPtr p) {
         vsy_BitVecInitIter(p);
      }

      public static void BitVecNextIter(IntPtr p,ref int i_ndex) {
         vsy_BitVecNextIter(p,ref i_ndex);
      }

      public static void BitVecMatch(IntPtr p,IntPtr b_itvecm,ref int f_lag) {
         vsy_BitVecMatch(p, b_itvecm,ref f_lag);
      }

      public static void BitVecCopy(IntPtr p,IntPtr f_romp) {
         vsy_BitVecCopy(p, f_romp);
      }

      public static void BitVecPrint(IntPtr p) {
         vsy_BitVecPrint(p);
      }

      public const int CALC_INFIX = 1;
      public const int CALC_POSTFIX = 2;
      public const int CALC_LPAREN = 1;
      public const int CALC_RPAREN = 2;
      public const int CALC_PLUS = 3;
      public const int CALC_MINUS = 4;
      public const int CALC_ADD = 5;
      public const int CALC_SUB = 6;
      public const int CALC_DIV = 7;
      public const int CALC_MUL = 8;
      public const int CALC_POWER = 9;
      public const int CALC_INTEGER = 10;
      public const int CALC_REAL = 11;
      public const int CALC_STRING = 12;
      public const int CALC_ABS = 13;
      public const int CALC_ACOS = 14;
      public const int CALC_ASIN = 15;
      public const int CALC_ATAN = 16;
      public const int CALC_COS = 17;
      public const int CALC_LOG = 18;
      public const int CALC_LOG10 = 19;
      public const int CALC_POW = 20;
      public const int CALC_SIN = 21;
      public const int CALC_SQRT = 22;
      public const int CALC_TAN = 23;
      public const int CALC_INT = 24;
      public const int CALC_FLOAT = 25;
      public const int CALC_STR = 26;
      public const int CALC_MAX_TYPE = 27;
      public const int CALC_PARSEERROR = 1;
      public const int CALC_UNMATCHEDPAREN = 1;
      public const int CALC_INSUFFICIENTOPERANDS = 2;
      public const int CALC_ILLEGALOPERAND = 3;
      public const int CALC_MAX_TOKENS = 100;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_CalcBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_CalcError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcInq(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcSetToken(IntPtr p,int t_ype,int v_ali,double v_ald,StringBuilder v_alc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcTerm(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcGetEvalType(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcEval(IntPtr p,int t_ype,ref int v_ali,ref double v_ald,StringBuilder v_alc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CalcGetInteger(IntPtr p,int t_ype,ref int i_param);

      public static IntPtr CalcBegin() {
         return vsy_CalcBegin();
      }

      public static void CalcEnd(IntPtr p) {
         vsy_CalcEnd(p);
      }

      public static int CalcError(IntPtr p) {
         return vsy_CalcError(p);
      }

      public static void CalcDef(IntPtr p,int t_ype) {
         vsy_CalcDef(p, t_ype);
      }

      public static void CalcInq(IntPtr p,ref int t_ype) {
         vsy_CalcInq(p,ref t_ype);
      }

      public static void CalcInit(IntPtr p) {
         vsy_CalcInit(p);
      }

      public static void CalcSetToken(IntPtr p,int t_ype,int v_ali,double v_ald,StringBuilder v_alc) {
         vsy_CalcSetToken(p, t_ype, v_ali, v_ald, v_alc);
      }

      public static void CalcTerm(IntPtr p) {
         vsy_CalcTerm(p);
      }

      public static void CalcGetEvalType(IntPtr p,ref int t_ype) {
         vsy_CalcGetEvalType(p,ref t_ype);
      }

      public static void CalcEval(IntPtr p,int t_ype,ref int v_ali,ref double v_ald,StringBuilder v_alc) {
         vsy_CalcEval(p, t_ype,ref v_ali,ref v_ald, v_alc);
      }

      public static void CalcGetInteger(IntPtr p,int t_ype,ref int i_param) {
         vsy_CalcGetInteger(p, t_ype,ref i_param);
      }

      public const int CONCAT_ITER = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_ConcatBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_ConcatError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatDef(IntPtr p,long m_axbytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatInq(IntPtr p,ref long l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatMem(IntPtr p,int n_bytes,out IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatAdd(IntPtr p,int n_bytes,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatRef(IntPtr p,out IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatSetParami(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ConcatNextIter(IntPtr p,ref int n_bytes,out IntPtr d_ata);

      public static IntPtr ConcatBegin() {
         return vsy_ConcatBegin();
      }

      public static void ConcatEnd(IntPtr p) {
         vsy_ConcatEnd(p);
      }

      public static int ConcatError(IntPtr p) {
         return vsy_ConcatError(p);
      }

      public static void ConcatDef(IntPtr p,long m_axbytes) {
         vsy_ConcatDef(p, m_axbytes);
      }

      public static void ConcatInq(IntPtr p,ref long l_en) {
         vsy_ConcatInq(p,ref l_en);
      }

      public static void ConcatCount(IntPtr p,ref int n_um) {
         vsy_ConcatCount(p,ref n_um);
      }

      public static void ConcatMem(IntPtr p,int n_bytes,out IntPtr d_ata) {
         vsy_ConcatMem(p, n_bytes,out d_ata);
      }

      public static void ConcatAdd(IntPtr p,int n_bytes,ref IntPtr d_ata) {
         vsy_ConcatAdd(p, n_bytes,ref d_ata);
      }

      public static void ConcatRef(IntPtr p,out IntPtr d_ata) {
         vsy_ConcatRef(p,out d_ata);
      }

      public static void ConcatSetParami(IntPtr p,int t_ype,int i_value) {
         vsy_ConcatSetParami(p, t_ype, i_value);
      }

      public static void ConcatClear(IntPtr p) {
         vsy_ConcatClear(p);
      }

      public static void ConcatInitIter(IntPtr p) {
         vsy_ConcatInitIter(p);
      }

      public static void ConcatNextIter(IntPtr p,ref int n_bytes,out IntPtr d_ata) {
         vsy_ConcatNextIter(p,ref n_bytes,out d_ata);
      }

      public const int CVECT_NUM = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_CVectBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_CVectError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectDef(IntPtr p,int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectInq(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectSet(IntPtr p,int i_ndex,int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectSetOne(IntPtr p,int i_ndex,int n_o,int i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectReplace(IntPtr p,int i_ndex,int n_o,int i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGet(IntPtr p,int i_ndex,int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGetNum(IntPtr p,int i_ndex,ref int n_ix);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGetAll(IntPtr p,int i_ndex,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGetInv(IntPtr p,int i_ndex,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGetOne(IntPtr p,int i_ndex,int n_o,ref int i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectAppend(IntPtr p,int i_ndex,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectRemove(IntPtr p,int i_ndex,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectDel(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectGetMax(IntPtr p,ref int m_ax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectCount(IntPtr p,ref int c_ount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectKernel(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectPtrAll(IntPtr p,int i_ndex,ref int n_ix,out int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectPtrInv(IntPtr p,int i_ndex,ref int n_ix,out int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectMatch(IntPtr p,IntPtr q_,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectCopy(IntPtr p,IntPtr q_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_CVectClear(IntPtr p);

      public static IntPtr CVectBegin() {
         return vsy_CVectBegin();
      }

      public static void CVectEnd(IntPtr p) {
         vsy_CVectEnd(p);
      }

      public static int CVectError(IntPtr p) {
         return vsy_CVectError(p);
      }

      public static void CVectDef(IntPtr p,int m_axindex) {
         vsy_CVectDef(p, m_axindex);
      }

      public static void CVectInq(IntPtr p,ref int m_axindex) {
         vsy_CVectInq(p,ref m_axindex);
      }

      public static void CVectSet(IntPtr p,int i_ndex,int n_ix,int [] i_x) {
         vsy_CVectSet(p, i_ndex, n_ix, i_x);
      }

      public static void CVectSetOne(IntPtr p,int i_ndex,int n_o,int i_x) {
         vsy_CVectSetOne(p, i_ndex, n_o, i_x);
      }

      public static void CVectReplace(IntPtr p,int i_ndex,int n_o,int i_x) {
         vsy_CVectReplace(p, i_ndex, n_o, i_x);
      }

      public static void CVectGet(IntPtr p,int i_ndex,int n_ix,int [] i_x) {
         vsy_CVectGet(p, i_ndex, n_ix, i_x);
      }

      public static void CVectGetNum(IntPtr p,int i_ndex,ref int n_ix) {
         vsy_CVectGetNum(p, i_ndex,ref n_ix);
      }

      public static void CVectGetAll(IntPtr p,int i_ndex,ref int n_ix,int [] i_x) {
         vsy_CVectGetAll(p, i_ndex,ref n_ix, i_x);
      }

      public static void CVectGetInv(IntPtr p,int i_ndex,ref int n_ix,int [] i_x) {
         vsy_CVectGetInv(p, i_ndex,ref n_ix, i_x);
      }

      public static void CVectGetOne(IntPtr p,int i_ndex,int n_o,ref int i_x) {
         vsy_CVectGetOne(p, i_ndex, n_o,ref i_x);
      }

      public static void CVectAppend(IntPtr p,int i_ndex,int i_d) {
         vsy_CVectAppend(p, i_ndex, i_d);
      }

      public static void CVectRemove(IntPtr p,int i_ndex,int i_d,ref int f_lag) {
         vsy_CVectRemove(p, i_ndex, i_d,ref f_lag);
      }

      public static void CVectDel(IntPtr p,int i_ndex) {
         vsy_CVectDel(p, i_ndex);
      }

      public static void CVectPrint(IntPtr p) {
         vsy_CVectPrint(p);
      }

      public static void CVectGetMax(IntPtr p,ref int m_ax) {
         vsy_CVectGetMax(p,ref m_ax);
      }

      public static void CVectCount(IntPtr p,ref int c_ount) {
         vsy_CVectCount(p,ref c_ount);
      }

      public static void CVectKernel(IntPtr p,int f_lag) {
         vsy_CVectKernel(p, f_lag);
      }

      public static void CVectPtrAll(IntPtr p,int i_ndex,ref int n_ix,out int [] i_x) {
         vsy_CVectPtrAll(p, i_ndex,ref n_ix,out i_x);
      }

      public static void CVectPtrInv(IntPtr p,int i_ndex,ref int n_ix,out int [] i_x) {
         vsy_CVectPtrInv(p, i_ndex,ref n_ix,out i_x);
      }

      public static void CVectMatch(IntPtr p,IntPtr q_,ref int f_lag) {
         vsy_CVectMatch(p, q_,ref f_lag);
      }

      public static void CVectCopy(IntPtr p,IntPtr q_) {
         vsy_CVectCopy(p, q_);
      }

      public static void CVectClear(IntPtr p) {
         vsy_CVectClear(p);
      }

      public const int DATATABLE_INTERPOLATE = 1;
      public const int DATATABLE_EXTRAPOLATE = 2;
      public const int DATATABLE_CLAMP = 1;
      public const int DATATABLE_LINEAR = 2;
      public const int DATATABLE_PARABOLIC_SLOPE = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_DataTableBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_DataTableError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableDef(IntPtr p,int n_umobj,int l_ength);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableInq(IntPtr p,ref int l_en,ref int s_iz);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableInsert(IntPtr p,double v_alue,double [] v_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableLookup(IntPtr p,double v_alue,ref double v_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableEval(IntPtr p,double v_alue,double [] v_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableEvalGrad(IntPtr p,double v_alue,double [] v_ec,double [] g_rad);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableNextIter(IntPtr p,ref double v_ar,out double [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DataTableForEach(IntPtr p,Vfunc1 f_unc);

      public static IntPtr DataTableBegin() {
         return vsy_DataTableBegin();
      }

      public static void DataTableEnd(IntPtr p) {
         vsy_DataTableEnd(p);
      }

      public static int DataTableError(IntPtr p) {
         return vsy_DataTableError(p);
      }

      public static void DataTableDef(IntPtr p,int n_umobj,int l_ength) {
         vsy_DataTableDef(p, n_umobj, l_ength);
      }

      public static void DataTableInq(IntPtr p,ref int l_en,ref int s_iz) {
         vsy_DataTableInq(p,ref l_en,ref s_iz);
      }

      public static void DataTableSetParami(IntPtr p,int p_type,int i_param) {
         vsy_DataTableSetParami(p, p_type, i_param);
      }

      public static void DataTableCount(IntPtr p,ref int n_um) {
         vsy_DataTableCount(p,ref n_um);
      }

      public static void DataTableInsert(IntPtr p,double v_alue,double [] v_ec) {
         vsy_DataTableInsert(p, v_alue, v_ec);
      }

      public static void DataTableLookup(IntPtr p,double v_alue,ref double v_ec) {
         vsy_DataTableLookup(p, v_alue,ref v_ec);
      }

      public static void DataTableEval(IntPtr p,double v_alue,double [] v_ec) {
         vsy_DataTableEval(p, v_alue, v_ec);
      }

      public static void DataTableEvalGrad(IntPtr p,double v_alue,double [] v_ec,double [] g_rad) {
         vsy_DataTableEvalGrad(p, v_alue, v_ec, g_rad);
      }

      public static void DataTableClear(IntPtr p) {
         vsy_DataTableClear(p);
      }

      public static void DataTableInitIter(IntPtr p) {
         vsy_DataTableInitIter(p);
      }

      public static void DataTableNextIter(IntPtr p,ref double v_ar,out double [] v_alue) {
         vsy_DataTableNextIter(p,ref v_ar,out v_alue);
      }

      public static void DataTableForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_DataTableForEach(p, f_unc);
      }

      public const int DOUBLE_DICTIONARY_MIN_STORAGE = 128;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_DblDictBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_DblDictError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictDef(IntPtr p,int n_umint);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictInsert(IntPtr p,StringBuilder n_ame,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictLookup(IntPtr p,StringBuilder n_ame,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictNextIter(IntPtr p,out IntPtr n_ame,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictInitIterOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblDictPrint(IntPtr p);

      public static IntPtr DblDictBegin() {
         return vsy_DblDictBegin();
      }

      public static void DblDictEnd(IntPtr p) {
         vsy_DblDictEnd(p);
      }

      public static int DblDictError(IntPtr p) {
         return vsy_DblDictError(p);
      }

      public static void DblDictDef(IntPtr p,int n_umint) {
         vsy_DblDictDef(p, n_umint);
      }

      public static void DblDictInq(IntPtr p,ref int n_ument) {
         vsy_DblDictInq(p,ref n_ument);
      }

      public static void DblDictCount(IntPtr p,ref int n_um) {
         vsy_DblDictCount(p,ref n_um);
      }

      public static void DblDictInsert(IntPtr p,StringBuilder n_ame,double v_alue) {
         vsy_DblDictInsert(p, n_ame, v_alue);
      }

      public static void DblDictLookup(IntPtr p,StringBuilder n_ame,ref double v_alue) {
         vsy_DblDictLookup(p, n_ame,ref v_alue);
      }

      public static void DblDictClear(IntPtr p) {
         vsy_DblDictClear(p);
      }

      public static void DblDictInitIter(IntPtr p) {
         vsy_DblDictInitIter(p);
      }

      public static void DblDictNextIter(IntPtr p,out IntPtr n_ame,ref double v_alue) {
         vsy_DblDictNextIter(p,out n_ame,ref v_alue);
      }

      public static void DblDictInitIterOrder(IntPtr p) {
         vsy_DblDictInitIterOrder(p);
      }

      public static void DblDictPrint(IntPtr p) {
         vsy_DblDictPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_DblHashBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_DblHashError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashDef(IntPtr p,int s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashInq(IntPtr p,ref int s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashInsert(IntPtr p,double k_ey,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashInsertUndef(IntPtr p,double k_ey,int v_alue,ref int o_ldvalue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashLookup(IntPtr p,double k_ey,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashRemove(IntPtr p,double k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblHashNextIter(IntPtr p,ref double k_ey,ref int v_alue);

      public static IntPtr DblHashBegin() {
         return vsy_DblHashBegin();
      }

      public static void DblHashEnd(IntPtr p) {
         vsy_DblHashEnd(p);
      }

      public static int DblHashError(IntPtr p) {
         return vsy_DblHashError(p);
      }

      public static void DblHashDef(IntPtr p,int s_ize) {
         vsy_DblHashDef(p, s_ize);
      }

      public static void DblHashInq(IntPtr p,ref int s_ize) {
         vsy_DblHashInq(p,ref s_ize);
      }

      public static void DblHashCount(IntPtr p,ref int n_um) {
         vsy_DblHashCount(p,ref n_um);
      }

      public static void DblHashInsert(IntPtr p,double k_ey,int v_alue) {
         vsy_DblHashInsert(p, k_ey, v_alue);
      }

      public static void DblHashInsertUndef(IntPtr p,double k_ey,int v_alue,ref int o_ldvalue) {
         vsy_DblHashInsertUndef(p, k_ey, v_alue,ref o_ldvalue);
      }

      public static void DblHashLookup(IntPtr p,double k_ey,ref int v_alue) {
         vsy_DblHashLookup(p, k_ey,ref v_alue);
      }

      public static void DblHashRemove(IntPtr p,double k_ey) {
         vsy_DblHashRemove(p, k_ey);
      }

      public static void DblHashClear(IntPtr p) {
         vsy_DblHashClear(p);
      }

      public static void DblHashInitIter(IntPtr p) {
         vsy_DblHashInitIter(p);
      }

      public static void DblHashNextIter(IntPtr p,ref double k_ey,ref int v_alue) {
         vsy_DblHashNextIter(p,ref k_ey,ref v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_DblVecBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_DblVecError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecDef(IntPtr p,int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecInq(IntPtr p,ref int m_axind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecSet(IntPtr p,int i_ndex,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecSetMult(IntPtr p,int n_um,int i_dx,double [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecSum(IntPtr p,int i_ndex,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecAppend(IntPtr p,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecGet(IntPtr p,int i_dx,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecGetMult(IntPtr p,int n_um,int i_dx,double [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecGetPtr(IntPtr p,out double [] p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_DblVecPtr(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecNextIter(IntPtr p,ref int i_ndex,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecMatch(IntPtr p,IntPtr d_blvecm,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DblVecPrint(IntPtr p);

      public static IntPtr DblVecBegin() {
         return vsy_DblVecBegin();
      }

      public static void DblVecEnd(IntPtr p) {
         vsy_DblVecEnd(p);
      }

      public static int DblVecError(IntPtr p) {
         return vsy_DblVecError(p);
      }

      public static void DblVecDef(IntPtr p,int m_axindex) {
         vsy_DblVecDef(p, m_axindex);
      }

      public static void DblVecInq(IntPtr p,ref int m_axind) {
         vsy_DblVecInq(p,ref m_axind);
      }

      public static void DblVecSetParami(IntPtr p,int p_type,int i_param) {
         vsy_DblVecSetParami(p, p_type, i_param);
      }

      public static void DblVecCount(IntPtr p,ref int n_um) {
         vsy_DblVecCount(p,ref n_um);
      }

      public static void DblVecSet(IntPtr p,int i_ndex,double v_alue) {
         vsy_DblVecSet(p, i_ndex, v_alue);
      }

      public static void DblVecSetMult(IntPtr p,int n_um,int i_dx,double [] v_alue) {
         vsy_DblVecSetMult(p, n_um, i_dx, v_alue);
      }

      public static void DblVecSum(IntPtr p,int i_ndex,double v_alue) {
         vsy_DblVecSum(p, i_ndex, v_alue);
      }

      public static void DblVecAppend(IntPtr p,double v_alue) {
         vsy_DblVecAppend(p, v_alue);
      }

      public static void DblVecGet(IntPtr p,int i_dx,ref double v_alue) {
         vsy_DblVecGet(p, i_dx,ref v_alue);
      }

      public static void DblVecGetMult(IntPtr p,int n_um,int i_dx,double [] v_alue) {
         vsy_DblVecGetMult(p, n_um, i_dx, v_alue);
      }

      public static void DblVecClear(IntPtr p) {
         vsy_DblVecClear(p);
      }

      public static void DblVecGetPtr(IntPtr p,out double [] p_tr) {
         vsy_DblVecGetPtr(p,out p_tr);
      }

      public static double DblVecPtr(IntPtr p) {
         return vsy_DblVecPtr(p);
      }

      public static void DblVecInitIter(IntPtr p) {
         vsy_DblVecInitIter(p);
      }

      public static void DblVecNextIter(IntPtr p,ref int i_ndex,ref double v_alue) {
         vsy_DblVecNextIter(p,ref i_ndex,ref v_alue);
      }

      public static void DblVecMatch(IntPtr p,IntPtr d_blvecm,ref int f_lag) {
         vsy_DblVecMatch(p, d_blvecm,ref f_lag);
      }

      public static void DblVecCopy(IntPtr p,IntPtr f_romp) {
         vsy_DblVecCopy(p, f_romp);
      }

      public static void DblVecPrint(IntPtr p) {
         vsy_DblVecPrint(p);
      }

      public const int DICTIONARY_IGNORECASE = 2;
      public const int DICTIONARY_MIN_STORAGE = 128;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_DictionaryBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_DictionaryError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryDef(IntPtr p,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionarySetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryInsert(IntPtr p,StringBuilder n_ame,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryLookup(IntPtr p,StringBuilder n_ame,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryRemove(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryMaxNameChar(IntPtr p,ref int m_axnamechar);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryNextIter(IntPtr p,out IntPtr n_ame,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryInitIterOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryForEach(IntPtr p,Vfunc1 f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_DictionaryPrint(IntPtr p);

      public static IntPtr DictionaryBegin() {
         return vsy_DictionaryBegin();
      }

      public static void DictionaryEnd(IntPtr p) {
         vsy_DictionaryEnd(p);
      }

      public static int DictionaryError(IntPtr p) {
         return vsy_DictionaryError(p);
      }

      public static void DictionaryDef(IntPtr p,int n_umobj) {
         vsy_DictionaryDef(p, n_umobj);
      }

      public static void DictionaryInq(IntPtr p,ref int n_ument) {
         vsy_DictionaryInq(p,ref n_ument);
      }

      public static void DictionarySetParami(IntPtr p,int t_ype,int i_param) {
         vsy_DictionarySetParami(p, t_ype, i_param);
      }

      public static void DictionaryCount(IntPtr p,ref int n_um) {
         vsy_DictionaryCount(p,ref n_um);
      }

      public static void DictionaryInsert(IntPtr p,StringBuilder n_ame,IntPtr v_alue) {
         vsy_DictionaryInsert(p, n_ame, v_alue);
      }

      public static void DictionaryLookup(IntPtr p,StringBuilder n_ame,out IntPtr v_alue) {
         vsy_DictionaryLookup(p, n_ame,out v_alue);
      }

      public static void DictionaryRemove(IntPtr p,StringBuilder n_ame) {
         vsy_DictionaryRemove(p, n_ame);
      }

      public static void DictionaryClear(IntPtr p) {
         vsy_DictionaryClear(p);
      }

      public static void DictionaryMaxNameChar(IntPtr p,ref int m_axnamechar) {
         vsy_DictionaryMaxNameChar(p,ref m_axnamechar);
      }

      public static void DictionaryInitIter(IntPtr p) {
         vsy_DictionaryInitIter(p);
      }

      public static void DictionaryNextIter(IntPtr p,out IntPtr n_ame,out IntPtr v_alue) {
         vsy_DictionaryNextIter(p,out n_ame,out v_alue);
      }

      public static void DictionaryInitIterOrder(IntPtr p) {
         vsy_DictionaryInitIterOrder(p);
      }

      public static void DictionaryForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_DictionaryForEach(p, f_unc);
      }

      public static void DictionaryPrint(IntPtr p) {
         vsy_DictionaryPrint(p);
      }

      public const int ECHO_WRITE = 1;
      public const int ECHO_READ = 2;
      public const int ECHO_MAX_ARGS = 5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_EchoBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_EchoError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoOpen(IntPtr p,StringBuilder f_ilename,int m_ode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoClose(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite0(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite1(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype,int n_,ref IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite2(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite3(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite4(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3,int t_ype4,int n_4,ref IntPtr p_tr4);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoWrite5(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3,int t_ype4,int n_4,ref IntPtr p_tr4,int t_ype5,int n_5,ref IntPtr p_tr5);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoNextIter(IntPtr p,ref int o_type,ref int o_id,StringBuilder m_ethod);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoGetArg(IntPtr p,int i_d,ref int t_ype,ref int l_ength,out IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoNumArgs(IntPtr p,ref int n_args);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoGetLength(IntPtr p,int i_d,ref int l_ength);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoInsertObject(IntPtr p,int i_d,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_EchoLookupObject(IntPtr p,int i_d,ref int t_ype);

      public static IntPtr EchoBegin() {
         return vsy_EchoBegin();
      }

      public static void EchoEnd(IntPtr p) {
         vsy_EchoEnd(p);
      }

      public static int EchoError(IntPtr p) {
         return vsy_EchoError(p);
      }

      public static void EchoOpen(IntPtr p,StringBuilder f_ilename,int m_ode) {
         vsy_EchoOpen(p, f_ilename, m_ode);
      }

      public static void EchoClose(IntPtr p) {
         vsy_EchoClose(p);
      }

      public static void EchoWrite0(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod) {
         vsy_EchoWrite0(p, o_bjtype, o_bj, m_ethod);
      }

      public static void EchoWrite1(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype,int n_,ref IntPtr p_tr) {
         vsy_EchoWrite1(p, o_bjtype, o_bj, m_ethod, t_ype, n_,ref p_tr);
      }

      public static void EchoWrite2(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2) {
         vsy_EchoWrite2(p, o_bjtype, o_bj, m_ethod, t_ype1, n_1,ref p_tr1, t_ype2, n_2,ref p_tr2);
      }

      public static void EchoWrite3(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3) {
         vsy_EchoWrite3(p, o_bjtype, o_bj, m_ethod, t_ype1, n_1,ref p_tr1, t_ype2, n_2,ref p_tr2, t_ype3, n_3,ref p_tr3);
      }

      public static void EchoWrite4(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3,int t_ype4,int n_4,ref IntPtr p_tr4) {
         vsy_EchoWrite4(p, o_bjtype, o_bj, m_ethod, t_ype1, n_1,ref p_tr1, t_ype2, n_2,ref p_tr2, t_ype3, n_3,ref p_tr3, t_ype4, n_4,ref p_tr4);
      }

      public static void EchoWrite5(IntPtr p,int o_bjtype,IntPtr o_bj,StringBuilder m_ethod,int t_ype1,int n_1,ref IntPtr p_tr1,int t_ype2,int n_2,ref IntPtr p_tr2,int t_ype3,int n_3,ref IntPtr p_tr3,int t_ype4,int n_4,ref IntPtr p_tr4,int t_ype5,int n_5,ref IntPtr p_tr5) {
         vsy_EchoWrite5(p, o_bjtype, o_bj, m_ethod, t_ype1, n_1,ref p_tr1, t_ype2, n_2,ref p_tr2, t_ype3, n_3,ref p_tr3, t_ype4, n_4,ref p_tr4, t_ype5, n_5,ref p_tr5);
      }

      public static void EchoInitIter(IntPtr p) {
         vsy_EchoInitIter(p);
      }

      public static void EchoNextIter(IntPtr p,ref int o_type,ref int o_id,StringBuilder m_ethod) {
         vsy_EchoNextIter(p,ref o_type,ref o_id, m_ethod);
      }

      public static void EchoGetArg(IntPtr p,int i_d,ref int t_ype,ref int l_ength,out IntPtr p_tr) {
         vsy_EchoGetArg(p, i_d,ref t_ype,ref l_ength,out p_tr);
      }

      public static void EchoNumArgs(IntPtr p,ref int n_args) {
         vsy_EchoNumArgs(p,ref n_args);
      }

      public static void EchoGetLength(IntPtr p,int i_d,ref int l_ength) {
         vsy_EchoGetLength(p, i_d,ref l_ength);
      }

      public static void EchoInsertObject(IntPtr p,int i_d,int t_ype) {
         vsy_EchoInsertObject(p, i_d, t_ype);
      }

      public static void EchoLookupObject(IntPtr p,int i_d,ref int t_ype) {
         vsy_EchoLookupObject(p, i_d,ref t_ype);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_FileTextBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_FileTextError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextOpenFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextConnectFile(IntPtr p,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextDisconnectFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextQueryFile(IntPtr p,out IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextString(IntPtr p,StringBuilder s_tg);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextNoOp(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FileTextTextFun(IntPtr p,IntPtr t_f);

      public static IntPtr FileTextBegin() {
         return vsy_FileTextBegin();
      }

      public static void FileTextEnd(IntPtr p) {
         vsy_FileTextEnd(p);
      }

      public static int FileTextError(IntPtr p) {
         return vsy_FileTextError(p);
      }

      public static void FileTextOpenFile(IntPtr p,StringBuilder f_ilename) {
         vsy_FileTextOpenFile(p, f_ilename);
      }

      public static void FileTextCloseFile(IntPtr p) {
         vsy_FileTextCloseFile(p);
      }

      public static void FileTextConnectFile(IntPtr p,IntPtr f_d) {
         vsy_FileTextConnectFile(p, f_d);
      }

      public static void FileTextDisconnectFile(IntPtr p) {
         vsy_FileTextDisconnectFile(p);
      }

      public static void FileTextQueryFile(IntPtr p,out IntPtr f_d) {
         vsy_FileTextQueryFile(p,out f_d);
      }

      public static void FileTextString(IntPtr p,StringBuilder s_tg) {
         vsy_FileTextString(p, s_tg);
      }

      public static void FileTextNoOp(IntPtr p) {
         vsy_FileTextNoOp(p);
      }

      public static void FileTextTextFun(IntPtr p,IntPtr t_f) {
         vsy_FileTextTextFun(p, t_f);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_FltVecBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_FltVecError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecDef(IntPtr p,int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecInq(IntPtr p,ref int m_axind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecSet(IntPtr p,int i_dx,float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecSum(IntPtr p,int i_dx,float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecAppend(IntPtr p,float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecGet(IntPtr p,int i_dx,ref float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecGetPtr(IntPtr p,out float [] p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecNextIter(IntPtr p,ref int i_dx,ref float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecMatch(IntPtr p,IntPtr q_,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_FltVecPrint(IntPtr p);

      public static IntPtr FltVecBegin() {
         return vsy_FltVecBegin();
      }

      public static void FltVecEnd(IntPtr p) {
         vsy_FltVecEnd(p);
      }

      public static int FltVecError(IntPtr p) {
         return vsy_FltVecError(p);
      }

      public static void FltVecDef(IntPtr p,int l_en) {
         vsy_FltVecDef(p, l_en);
      }

      public static void FltVecInq(IntPtr p,ref int m_axind) {
         vsy_FltVecInq(p,ref m_axind);
      }

      public static void FltVecSetParami(IntPtr p,int t_ype,int i_param) {
         vsy_FltVecSetParami(p, t_ype, i_param);
      }

      public static void FltVecCount(IntPtr p,ref int n_um) {
         vsy_FltVecCount(p,ref n_um);
      }

      public static void FltVecSet(IntPtr p,int i_dx,float v_alue) {
         vsy_FltVecSet(p, i_dx, v_alue);
      }

      public static void FltVecSum(IntPtr p,int i_dx,float v_alue) {
         vsy_FltVecSum(p, i_dx, v_alue);
      }

      public static void FltVecAppend(IntPtr p,float v_alue) {
         vsy_FltVecAppend(p, v_alue);
      }

      public static void FltVecGet(IntPtr p,int i_dx,ref float v_alue) {
         vsy_FltVecGet(p, i_dx,ref v_alue);
      }

      public static void FltVecClear(IntPtr p) {
         vsy_FltVecClear(p);
      }

      public static void FltVecGetPtr(IntPtr p,out float [] p_tr) {
         vsy_FltVecGetPtr(p,out p_tr);
      }

      public static void FltVecInitIter(IntPtr p) {
         vsy_FltVecInitIter(p);
      }

      public static void FltVecNextIter(IntPtr p,ref int i_dx,ref float v_alue) {
         vsy_FltVecNextIter(p,ref i_dx,ref v_alue);
      }

      public static void FltVecMatch(IntPtr p,IntPtr q_,ref int f_lag) {
         vsy_FltVecMatch(p, q_,ref f_lag);
      }

      public static void FltVecCopy(IntPtr p,IntPtr f_romp) {
         vsy_FltVecCopy(p, f_romp);
      }

      public static void FltVecPrint(IntPtr p) {
         vsy_FltVecPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_HashTableBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_HashTableError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableDef(IntPtr p,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableMaxKey(IntPtr p,ref int m_axkey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableAllKeys(IntPtr p,int [] a_llkeys);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableInsert(IntPtr p,int k_ey,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableLookup(IntPtr p,int k_ey,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableRemove(IntPtr p,int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableInitIterOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableNextIter(IntPtr p,ref int k_ey,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HashTableForEach(IntPtr p,Vfunc1 f_unc);

      public static IntPtr HashTableBegin() {
         return vsy_HashTableBegin();
      }

      public static void HashTableEnd(IntPtr p) {
         vsy_HashTableEnd(p);
      }

      public static int HashTableError(IntPtr p) {
         return vsy_HashTableError(p);
      }

      public static void HashTableDef(IntPtr p,int n_umobj) {
         vsy_HashTableDef(p, n_umobj);
      }

      public static void HashTableInq(IntPtr p,ref int n_ument) {
         vsy_HashTableInq(p,ref n_ument);
      }

      public static void HashTableCount(IntPtr p,ref int n_um) {
         vsy_HashTableCount(p,ref n_um);
      }

      public static void HashTableMaxKey(IntPtr p,ref int m_axkey) {
         vsy_HashTableMaxKey(p,ref m_axkey);
      }

      public static void HashTableAllKeys(IntPtr p,int [] a_llkeys) {
         vsy_HashTableAllKeys(p, a_llkeys);
      }

      public static void HashTableInsert(IntPtr p,int k_ey,IntPtr v_alue) {
         vsy_HashTableInsert(p, k_ey, v_alue);
      }

      public static void HashTableLookup(IntPtr p,int k_ey,out IntPtr v_alue) {
         vsy_HashTableLookup(p, k_ey,out v_alue);
      }

      public static void HashTableRemove(IntPtr p,int k_ey) {
         vsy_HashTableRemove(p, k_ey);
      }

      public static void HashTableClear(IntPtr p) {
         vsy_HashTableClear(p);
      }

      public static void HashTableInitIter(IntPtr p) {
         vsy_HashTableInitIter(p);
      }

      public static void HashTableInitIterOrder(IntPtr p) {
         vsy_HashTableInitIterOrder(p);
      }

      public static void HashTableNextIter(IntPtr p,ref int k_ey,out IntPtr v_alue) {
         vsy_HashTableNextIter(p,ref k_ey,out v_alue);
      }

      public static void HashTableForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_HashTableForEach(p, f_unc);
      }

      public const int HEAP_MIN = 0;
      public const int HEAP_MAX = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_HeapBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_HeapError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapDef(IntPtr p,int m_axindex,int m_inmax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapInq(IntPtr p,ref int n_ument,ref int m_inmax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapRef(IntPtr p,ref int i_ndex,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapRefRemove(IntPtr p,ref int i_ndex,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapRemove(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapInsert(IntPtr p,int i_ndex,double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapLookup(IntPtr p,int i_ndex,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapSetEpsilonCountForComparison(IntPtr p,long e_psilonCount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapSetRelativeTolerance(IntPtr p,double t_olerance);

      public static IntPtr HeapBegin() {
         return vsy_HeapBegin();
      }

      public static void HeapEnd(IntPtr p) {
         vsy_HeapEnd(p);
      }

      public static int HeapError(IntPtr p) {
         return vsy_HeapError(p);
      }

      public static void HeapDef(IntPtr p,int m_axindex,int m_inmax) {
         vsy_HeapDef(p, m_axindex, m_inmax);
      }

      public static void HeapInq(IntPtr p,ref int n_ument,ref int m_inmax) {
         vsy_HeapInq(p,ref n_ument,ref m_inmax);
      }

      public static void HeapClear(IntPtr p) {
         vsy_HeapClear(p);
      }

      public static void HeapRef(IntPtr p,ref int i_ndex,ref double v_al) {
         vsy_HeapRef(p,ref i_ndex,ref v_al);
      }

      public static void HeapRefRemove(IntPtr p,ref int i_ndex,ref double v_al) {
         vsy_HeapRefRemove(p,ref i_ndex,ref v_al);
      }

      public static void HeapRemove(IntPtr p,int i_ndex) {
         vsy_HeapRemove(p, i_ndex);
      }

      public static void HeapInsert(IntPtr p,int i_ndex,double v_al) {
         vsy_HeapInsert(p, i_ndex, v_al);
      }

      public static void HeapLookup(IntPtr p,int i_ndex,ref double v_al) {
         vsy_HeapLookup(p, i_ndex,ref v_al);
      }

      public static void HeapPrint(IntPtr p) {
         vsy_HeapPrint(p);
      }

      public static void HeapSetEpsilonCountForComparison(IntPtr p,long e_psilonCount) {
         vsy_HeapSetEpsilonCountForComparison(p, e_psilonCount);
      }

      public static void HeapSetRelativeTolerance(IntPtr p,double t_olerance) {
         vsy_HeapSetRelativeTolerance(p, t_olerance);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_HeapIndBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_HeapIndError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndDef(IntPtr p,int n_ument,int m_inmax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndInq(IntPtr p,ref int n_ument,ref int m_inmax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndRef(IntPtr p,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndRefRemove(IntPtr p,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndRemove(IntPtr p,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HeapIndInsert(IntPtr p,int v_alue);

      public static IntPtr HeapIndBegin() {
         return vsy_HeapIndBegin();
      }

      public static void HeapIndEnd(IntPtr p) {
         vsy_HeapIndEnd(p);
      }

      public static int HeapIndError(IntPtr p) {
         return vsy_HeapIndError(p);
      }

      public static void HeapIndDef(IntPtr p,int n_ument,int m_inmax) {
         vsy_HeapIndDef(p, n_ument, m_inmax);
      }

      public static void HeapIndInq(IntPtr p,ref int n_ument,ref int m_inmax) {
         vsy_HeapIndInq(p,ref n_ument,ref m_inmax);
      }

      public static void HeapIndClear(IntPtr p) {
         vsy_HeapIndClear(p);
      }

      public static void HeapIndRef(IntPtr p,ref int v_alue) {
         vsy_HeapIndRef(p,ref v_alue);
      }

      public static void HeapIndRefRemove(IntPtr p,ref int v_alue) {
         vsy_HeapIndRefRemove(p,ref v_alue);
      }

      public static void HeapIndRemove(IntPtr p,int v_alue) {
         vsy_HeapIndRemove(p, v_alue);
      }

      public static void HeapIndInsert(IntPtr p,int v_alue) {
         vsy_HeapIndInsert(p, v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_HTMLTextBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_HTMLTextError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextOpenFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextConnectFile(IntPtr p,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextDisconnectFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextQueryFile(IntPtr p,out IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextListType(IntPtr p,int l_isttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextHeadingLevel(IntPtr p,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextRuleWidth(IntPtr p,int r_ulewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextTextColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextTableColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextBackColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextBorderWidth(IntPtr p,int b_orderwidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextTableWidth(IntPtr p,int t_ablewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextFormInit(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextFormTerm(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextFormAction(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextHorizontalRule(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextSpace(IntPtr p,int n_spaces);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextImageFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextColumnAlign(IntPtr p,int a_lign);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextString(IntPtr p,StringBuilder s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_HTMLTextTextFun(IntPtr p,IntPtr t_extfun);

      public static IntPtr HTMLTextBegin() {
         return vsy_HTMLTextBegin();
      }

      public static void HTMLTextEnd(IntPtr p) {
         vsy_HTMLTextEnd(p);
      }

      public static int HTMLTextError(IntPtr p) {
         return vsy_HTMLTextError(p);
      }

      public static void HTMLTextOpenFile(IntPtr p,StringBuilder f_ilename) {
         vsy_HTMLTextOpenFile(p, f_ilename);
      }

      public static void HTMLTextCloseFile(IntPtr p) {
         vsy_HTMLTextCloseFile(p);
      }

      public static void HTMLTextConnectFile(IntPtr p,IntPtr f_d) {
         vsy_HTMLTextConnectFile(p, f_d);
      }

      public static void HTMLTextDisconnectFile(IntPtr p) {
         vsy_HTMLTextDisconnectFile(p);
      }

      public static void HTMLTextQueryFile(IntPtr p,out IntPtr f_d) {
         vsy_HTMLTextQueryFile(p,out f_d);
      }

      public static void HTMLTextListType(IntPtr p,int l_isttype) {
         vsy_HTMLTextListType(p, l_isttype);
      }

      public static void HTMLTextHeadingLevel(IntPtr p,int l_evel) {
         vsy_HTMLTextHeadingLevel(p, l_evel);
      }

      public static void HTMLTextRuleWidth(IntPtr p,int r_ulewidth) {
         vsy_HTMLTextRuleWidth(p, r_ulewidth);
      }

      public static void HTMLTextTextColor(IntPtr p,float [] c_) {
         vsy_HTMLTextTextColor(p, c_);
      }

      public static void HTMLTextTableColor(IntPtr p,float [] c_) {
         vsy_HTMLTextTableColor(p, c_);
      }

      public static void HTMLTextBackColor(IntPtr p,float [] c_) {
         vsy_HTMLTextBackColor(p, c_);
      }

      public static void HTMLTextBorderWidth(IntPtr p,int b_orderwidth) {
         vsy_HTMLTextBorderWidth(p, b_orderwidth);
      }

      public static void HTMLTextTableWidth(IntPtr p,int t_ablewidth) {
         vsy_HTMLTextTableWidth(p, t_ablewidth);
      }

      public static void HTMLTextSetMode(IntPtr p,int m_ode,int f_lag) {
         vsy_HTMLTextSetMode(p, m_ode, f_lag);
      }

      public static void HTMLTextFormInit(IntPtr p,int f_orm) {
         vsy_HTMLTextFormInit(p, f_orm);
      }

      public static void HTMLTextFormTerm(IntPtr p,int f_orm) {
         vsy_HTMLTextFormTerm(p, f_orm);
      }

      public static void HTMLTextFormAction(IntPtr p,int f_orm) {
         vsy_HTMLTextFormAction(p, f_orm);
      }

      public static void HTMLTextHorizontalRule(IntPtr p) {
         vsy_HTMLTextHorizontalRule(p);
      }

      public static void HTMLTextSpace(IntPtr p,int n_spaces) {
         vsy_HTMLTextSpace(p, n_spaces);
      }

      public static void HTMLTextImageFile(IntPtr p,StringBuilder f_ilename) {
         vsy_HTMLTextImageFile(p, f_ilename);
      }

      public static void HTMLTextColumnAlign(IntPtr p,int a_lign) {
         vsy_HTMLTextColumnAlign(p, a_lign);
      }

      public static void HTMLTextString(IntPtr p,StringBuilder s_tring) {
         vsy_HTMLTextString(p, s_tring);
      }

      public static void HTMLTextTextFun(IntPtr p,IntPtr t_extfun) {
         vsy_HTMLTextTextFun(p, t_extfun);
      }

      public const int INTEGER_DICTIONARY_MIN_STORAGE = 128;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntDictBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntDictError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictDef(IntPtr p,int n_umint);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictInsert(IntPtr p,StringBuilder n_ame,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictLookup(IntPtr p,StringBuilder n_ame,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictNextIter(IntPtr p,out IntPtr n_ame,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictInitIterOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntDictPrint(IntPtr p);

      public static IntPtr IntDictBegin() {
         return vsy_IntDictBegin();
      }

      public static void IntDictEnd(IntPtr p) {
         vsy_IntDictEnd(p);
      }

      public static int IntDictError(IntPtr p) {
         return vsy_IntDictError(p);
      }

      public static void IntDictDef(IntPtr p,int n_umint) {
         vsy_IntDictDef(p, n_umint);
      }

      public static void IntDictInq(IntPtr p,ref int n_ument) {
         vsy_IntDictInq(p,ref n_ument);
      }

      public static void IntDictCount(IntPtr p,ref int n_um) {
         vsy_IntDictCount(p,ref n_um);
      }

      public static void IntDictInsert(IntPtr p,StringBuilder n_ame,int v_alue) {
         vsy_IntDictInsert(p, n_ame, v_alue);
      }

      public static void IntDictLookup(IntPtr p,StringBuilder n_ame,ref int v_alue) {
         vsy_IntDictLookup(p, n_ame,ref v_alue);
      }

      public static void IntDictClear(IntPtr p) {
         vsy_IntDictClear(p);
      }

      public static void IntDictInitIter(IntPtr p) {
         vsy_IntDictInitIter(p);
      }

      public static void IntDictNextIter(IntPtr p,out IntPtr n_ame,ref int v_alue) {
         vsy_IntDictNextIter(p,out n_ame,ref v_alue);
      }

      public static void IntDictInitIterOrder(IntPtr p) {
         vsy_IntDictInitIterOrder(p);
      }

      public static void IntDictPrint(IntPtr p) {
         vsy_IntDictPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntHashBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntHashError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashDef(IntPtr p,int n_umint);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashMaxKey(IntPtr p,ref int m_axkey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashAllKeys(IntPtr p,int [] a_llkeys);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashEmptyKey(IntPtr p,ref int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashInsert(IntPtr p,int k_ey,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashInsertUndef(IntPtr p,int k_ey,int v_alue,ref int o_ldvalue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashLookup(IntPtr p,int k_ey,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashInitIterOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashNextIter(IntPtr p,ref int k_ey,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntHashSetParami(IntPtr p,int t_ype,int i_param);

      public static IntPtr IntHashBegin() {
         return vsy_IntHashBegin();
      }

      public static void IntHashEnd(IntPtr p) {
         vsy_IntHashEnd(p);
      }

      public static int IntHashError(IntPtr p) {
         return vsy_IntHashError(p);
      }

      public static void IntHashDef(IntPtr p,int n_umint) {
         vsy_IntHashDef(p, n_umint);
      }

      public static void IntHashInq(IntPtr p,ref int n_ument) {
         vsy_IntHashInq(p,ref n_ument);
      }

      public static void IntHashCount(IntPtr p,ref int n_um) {
         vsy_IntHashCount(p,ref n_um);
      }

      public static void IntHashMaxKey(IntPtr p,ref int m_axkey) {
         vsy_IntHashMaxKey(p,ref m_axkey);
      }

      public static void IntHashAllKeys(IntPtr p,int [] a_llkeys) {
         vsy_IntHashAllKeys(p, a_llkeys);
      }

      public static void IntHashEmptyKey(IntPtr p,ref int k_ey) {
         vsy_IntHashEmptyKey(p,ref k_ey);
      }

      public static void IntHashInsert(IntPtr p,int k_ey,int v_alue) {
         vsy_IntHashInsert(p, k_ey, v_alue);
      }

      public static void IntHashInsertUndef(IntPtr p,int k_ey,int v_alue,ref int o_ldvalue) {
         vsy_IntHashInsertUndef(p, k_ey, v_alue,ref o_ldvalue);
      }

      public static void IntHashLookup(IntPtr p,int k_ey,ref int v_alue) {
         vsy_IntHashLookup(p, k_ey,ref v_alue);
      }

      public static void IntHashClear(IntPtr p) {
         vsy_IntHashClear(p);
      }

      public static void IntHashSetName(IntPtr p,StringBuilder n_ame) {
         vsy_IntHashSetName(p, n_ame);
      }

      public static void IntHashGetName(IntPtr p,StringBuilder n_ame) {
         vsy_IntHashGetName(p, n_ame);
      }

      public static void IntHashInitIter(IntPtr p) {
         vsy_IntHashInitIter(p);
      }

      public static void IntHashInitIterOrder(IntPtr p) {
         vsy_IntHashInitIterOrder(p);
      }

      public static void IntHashNextIter(IntPtr p,ref int k_ey,ref int v_alue) {
         vsy_IntHashNextIter(p,ref k_ey,ref v_alue);
      }

      public static void IntHashPrint(IntPtr p) {
         vsy_IntHashPrint(p);
      }

      public static void IntHashSetParami(IntPtr p,int t_ype,int i_param) {
         vsy_IntHashSetParami(p, t_ype, i_param);
      }

      public const int INTHASH_UNDEFINED = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntQueBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntQueError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueDef(IntPtr p,int n_umint);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQuePut(IntPtr p,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueRef(IntPtr p,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueGet(IntPtr p,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntQueClear(IntPtr p);

      public static IntPtr IntQueBegin() {
         return vsy_IntQueBegin();
      }

      public static void IntQueEnd(IntPtr p) {
         vsy_IntQueEnd(p);
      }

      public static int IntQueError(IntPtr p) {
         return vsy_IntQueError(p);
      }

      public static void IntQueDef(IntPtr p,int n_umint) {
         vsy_IntQueDef(p, n_umint);
      }

      public static void IntQueInq(IntPtr p,ref int n_ument) {
         vsy_IntQueInq(p,ref n_ument);
      }

      public static void IntQueCount(IntPtr p,ref int n_um) {
         vsy_IntQueCount(p,ref n_um);
      }

      public static void IntQuePut(IntPtr p,int v_alue) {
         vsy_IntQuePut(p, v_alue);
      }

      public static void IntQueRef(IntPtr p,ref int v_alue) {
         vsy_IntQueRef(p,ref v_alue);
      }

      public static void IntQueGet(IntPtr p,ref int v_alue) {
         vsy_IntQueGet(p,ref v_alue);
      }

      public static void IntQueClear(IntPtr p) {
         vsy_IntQueClear(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntStackBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntStackError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackDef(IntPtr p,int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackInq(IntPtr p,ref int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackPush(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackPop(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackRef(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntStackPrint(IntPtr p);

      public static IntPtr IntStackBegin() {
         return vsy_IntStackBegin();
      }

      public static void IntStackEnd(IntPtr p) {
         vsy_IntStackEnd(p);
      }

      public static int IntStackError(IntPtr p) {
         return vsy_IntStackError(p);
      }

      public static void IntStackDef(IntPtr p,int l_en) {
         vsy_IntStackDef(p, l_en);
      }

      public static void IntStackInq(IntPtr p,ref int l_en) {
         vsy_IntStackInq(p,ref l_en);
      }

      public static void IntStackCount(IntPtr p,ref int n_um) {
         vsy_IntStackCount(p,ref n_um);
      }

      public static void IntStackPush(IntPtr p,int i_d) {
         vsy_IntStackPush(p, i_d);
      }

      public static void IntStackPop(IntPtr p,ref int i_d) {
         vsy_IntStackPop(p,ref i_d);
      }

      public static void IntStackRef(IntPtr p,ref int i_d) {
         vsy_IntStackRef(p,ref i_d);
      }

      public static void IntStackClear(IntPtr p) {
         vsy_IntStackClear(p);
      }

      public static void IntStackPrint(IntPtr p) {
         vsy_IntStackPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntVecBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntVecError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecDef(IntPtr p,int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecInq(IntPtr p,ref int m_axind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecSet(IntPtr p,int i_ndex,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecExpand(IntPtr p,int i_dx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecAppend(IntPtr p,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecGet(IntPtr p,int i_dx,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecInc(IntPtr p,int i_dx,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecGetPtr(IntPtr p,out int [] p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntVecPtr(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecNextIter(IntPtr p,ref int i_ndex,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecMatch(IntPtr p,IntPtr i_ntvecm,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecUnique(IntPtr p,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVecGetStartingIndex(IntPtr p,ref int i_ndex);

      public static IntPtr IntVecBegin() {
         return vsy_IntVecBegin();
      }

      public static void IntVecEnd(IntPtr p) {
         vsy_IntVecEnd(p);
      }

      public static int IntVecError(IntPtr p) {
         return vsy_IntVecError(p);
      }

      public static void IntVecDef(IntPtr p,int m_axindex) {
         vsy_IntVecDef(p, m_axindex);
      }

      public static void IntVecInq(IntPtr p,ref int m_axind) {
         vsy_IntVecInq(p,ref m_axind);
      }

      public static void IntVecSetParami(IntPtr p,int p_type,int i_param) {
         vsy_IntVecSetParami(p, p_type, i_param);
      }

      public static void IntVecCount(IntPtr p,ref int n_um) {
         vsy_IntVecCount(p,ref n_um);
      }

      public static void IntVecSet(IntPtr p,int i_ndex,int v_alue) {
         vsy_IntVecSet(p, i_ndex, v_alue);
      }

      public static void IntVecExpand(IntPtr p,int i_dx) {
         vsy_IntVecExpand(p, i_dx);
      }

      public static void IntVecAppend(IntPtr p,int v_alue) {
         vsy_IntVecAppend(p, v_alue);
      }

      public static void IntVecGet(IntPtr p,int i_dx,ref int v_alue) {
         vsy_IntVecGet(p, i_dx,ref v_alue);
      }

      public static void IntVecInc(IntPtr p,int i_dx,int v_alue) {
         vsy_IntVecInc(p, i_dx, v_alue);
      }

      public static void IntVecClear(IntPtr p) {
         vsy_IntVecClear(p);
      }

      public static void IntVecGetPtr(IntPtr p,out int [] p_tr) {
         vsy_IntVecGetPtr(p,out p_tr);
      }

      public static int IntVecPtr(IntPtr p) {
         return vsy_IntVecPtr(p);
      }

      public static void IntVecInitIter(IntPtr p) {
         vsy_IntVecInitIter(p);
      }

      public static void IntVecNextIter(IntPtr p,ref int i_ndex,ref int v_alue) {
         vsy_IntVecNextIter(p,ref i_ndex,ref v_alue);
      }

      public static void IntVecMatch(IntPtr p,IntPtr i_ntvecm,ref int f_lag) {
         vsy_IntVecMatch(p, i_ntvecm,ref f_lag);
      }

      public static void IntVecCopy(IntPtr p,IntPtr f_romp) {
         vsy_IntVecCopy(p, f_romp);
      }

      public static void IntVecPrint(IntPtr p) {
         vsy_IntVecPrint(p);
      }

      public static void IntVecUnique(IntPtr p,int v_alue) {
         vsy_IntVecUnique(p, v_alue);
      }

      public static void IntVecGetStartingIndex(IntPtr p,ref int i_ndex) {
         vsy_IntVecGetStartingIndex(p,ref i_ndex);
      }

      public const int INTVHASH_EMPTY_SLOT = 0;
      public const int INTVHASH_TRASH_SLOT = -2147483648;
      public const int INTVHASH_MIN_TABLE_SIZE = 5;
      public const int INTVHASH_HASH_FUNCTION_LEGACY = 0;
      public const int INTVHASH_HASH_FUNCTION_FNV1A = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_IntVHashBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_IntVHashError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashDef(IntPtr p,int s_ize,int n_umint);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashSetHashFunction(IntPtr p,int h_ashFunctionType);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashInq(IntPtr p,ref int s_ize,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashInsert(IntPtr p,int [] k_ey,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashInsertUndef(IntPtr p,int [] k_ey,int v_alue,ref int o_ldvalue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashLookup(IntPtr p,int [] k_ey,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashRemove(IntPtr p,int [] k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashNextIter(IntPtr p,ref int k_ey,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_IntVHashPrint(IntPtr p);

      public static IntPtr IntVHashBegin() {
         return vsy_IntVHashBegin();
      }

      public static void IntVHashEnd(IntPtr p) {
         vsy_IntVHashEnd(p);
      }

      public static int IntVHashError(IntPtr p) {
         return vsy_IntVHashError(p);
      }

      public static void IntVHashDef(IntPtr p,int s_ize,int n_umint) {
         vsy_IntVHashDef(p, s_ize, n_umint);
      }

      public static void IntVHashSetHashFunction(IntPtr p,int h_ashFunctionType) {
         vsy_IntVHashSetHashFunction(p, h_ashFunctionType);
      }

      public static void IntVHashInq(IntPtr p,ref int s_ize,ref int n_ument) {
         vsy_IntVHashInq(p,ref s_ize,ref n_ument);
      }

      public static void IntVHashCount(IntPtr p,ref int n_um) {
         vsy_IntVHashCount(p,ref n_um);
      }

      public static void IntVHashInsert(IntPtr p,int [] k_ey,int v_alue) {
         vsy_IntVHashInsert(p, k_ey, v_alue);
      }

      public static void IntVHashInsertUndef(IntPtr p,int [] k_ey,int v_alue,ref int o_ldvalue) {
         vsy_IntVHashInsertUndef(p, k_ey, v_alue,ref o_ldvalue);
      }

      public static void IntVHashLookup(IntPtr p,int [] k_ey,ref int v_alue) {
         vsy_IntVHashLookup(p, k_ey,ref v_alue);
      }

      public static void IntVHashRemove(IntPtr p,int [] k_ey) {
         vsy_IntVHashRemove(p, k_ey);
      }

      public static void IntVHashClear(IntPtr p) {
         vsy_IntVHashClear(p);
      }

      public static void IntVHashInitIter(IntPtr p) {
         vsy_IntVHashInitIter(p);
      }

      public static void IntVHashNextIter(IntPtr p,ref int k_ey,ref int v_alue) {
         vsy_IntVHashNextIter(p,ref k_ey,ref v_alue);
      }

      public static void IntVHashPrint(IntPtr p) {
         vsy_IntVHashPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_LaTeXTextBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_LaTeXTextError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextOpenFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextConnectFile(IntPtr p,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextDisconnectFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextQueryFile(IntPtr p,out IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextColumnAlign(IntPtr p,int a_lign);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextListType(IntPtr p,int l_isttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextHeadingLevel(IntPtr p,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextRuleWidth(IntPtr p,int r_ulewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextFormInit(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextFormTerm(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextFormAction(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextTextColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextTableColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextBackColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextBorderWidth(IntPtr p,int b_orderwidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextTableWidth(IntPtr p,int t_ablewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextHorizontalRule(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextImageFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextString(IntPtr p,StringBuilder s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextSpace(IntPtr p,int n_spaces);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LaTeXTextTextFun(IntPtr p,IntPtr t_extfun);

      public static IntPtr LaTeXTextBegin() {
         return vsy_LaTeXTextBegin();
      }

      public static void LaTeXTextEnd(IntPtr p) {
         vsy_LaTeXTextEnd(p);
      }

      public static int LaTeXTextError(IntPtr p) {
         return vsy_LaTeXTextError(p);
      }

      public static void LaTeXTextOpenFile(IntPtr p,StringBuilder f_ilename) {
         vsy_LaTeXTextOpenFile(p, f_ilename);
      }

      public static void LaTeXTextCloseFile(IntPtr p) {
         vsy_LaTeXTextCloseFile(p);
      }

      public static void LaTeXTextConnectFile(IntPtr p,IntPtr f_d) {
         vsy_LaTeXTextConnectFile(p, f_d);
      }

      public static void LaTeXTextDisconnectFile(IntPtr p) {
         vsy_LaTeXTextDisconnectFile(p);
      }

      public static void LaTeXTextQueryFile(IntPtr p,out IntPtr f_d) {
         vsy_LaTeXTextQueryFile(p,out f_d);
      }

      public static void LaTeXTextColumnAlign(IntPtr p,int a_lign) {
         vsy_LaTeXTextColumnAlign(p, a_lign);
      }

      public static void LaTeXTextListType(IntPtr p,int l_isttype) {
         vsy_LaTeXTextListType(p, l_isttype);
      }

      public static void LaTeXTextHeadingLevel(IntPtr p,int l_evel) {
         vsy_LaTeXTextHeadingLevel(p, l_evel);
      }

      public static void LaTeXTextRuleWidth(IntPtr p,int r_ulewidth) {
         vsy_LaTeXTextRuleWidth(p, r_ulewidth);
      }

      public static void LaTeXTextSetMode(IntPtr p,int m_ode,int f_lag) {
         vsy_LaTeXTextSetMode(p, m_ode, f_lag);
      }

      public static void LaTeXTextFormInit(IntPtr p,int f_orm) {
         vsy_LaTeXTextFormInit(p, f_orm);
      }

      public static void LaTeXTextFormTerm(IntPtr p,int f_orm) {
         vsy_LaTeXTextFormTerm(p, f_orm);
      }

      public static void LaTeXTextFormAction(IntPtr p,int f_orm) {
         vsy_LaTeXTextFormAction(p, f_orm);
      }

      public static void LaTeXTextTextColor(IntPtr p,float [] c_) {
         vsy_LaTeXTextTextColor(p, c_);
      }

      public static void LaTeXTextTableColor(IntPtr p,float [] c_) {
         vsy_LaTeXTextTableColor(p, c_);
      }

      public static void LaTeXTextBackColor(IntPtr p,float [] c_) {
         vsy_LaTeXTextBackColor(p, c_);
      }

      public static void LaTeXTextBorderWidth(IntPtr p,int b_orderwidth) {
         vsy_LaTeXTextBorderWidth(p, b_orderwidth);
      }

      public static void LaTeXTextTableWidth(IntPtr p,int t_ablewidth) {
         vsy_LaTeXTextTableWidth(p, t_ablewidth);
      }

      public static void LaTeXTextHorizontalRule(IntPtr p) {
         vsy_LaTeXTextHorizontalRule(p);
      }

      public static void LaTeXTextImageFile(IntPtr p,StringBuilder f_ilename) {
         vsy_LaTeXTextImageFile(p, f_ilename);
      }

      public static void LaTeXTextString(IntPtr p,StringBuilder s_tring) {
         vsy_LaTeXTextString(p, s_tring);
      }

      public static void LaTeXTextSpace(IntPtr p,int n_spaces) {
         vsy_LaTeXTextSpace(p, n_spaces);
      }

      public static void LaTeXTextTextFun(IntPtr p,IntPtr t_extfun) {
         vsy_LaTeXTextTextFun(p, t_extfun);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseValidate(StringBuilder l_icenseKey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseRelease();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseIsValid(ref int i_sValidFlag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseHasExpired(ref int h_asExpiredFlag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseIsPerpetual(ref int i_sPerpetualFlag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseHasMesh(ref int h_asMesh);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseHasAccess(ref int h_asAccess);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseHasSolve(ref int h_asSolve);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseCustomerName(out IntPtr c_ustomerName,ref int c_ustomerNameSize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LicenseExpiryDate(out IntPtr e_xpiryDate,ref int e_xpiryDataSize);

      public static void LicenseValidate(StringBuilder l_icenseKey) {
         vsy_LicenseValidate( l_icenseKey);
      }

      public static void LicenseRelease() {
         vsy_LicenseRelease( );
      }

      public static void LicenseIsValid(ref int i_sValidFlag) {
         vsy_LicenseIsValid(ref i_sValidFlag);
      }

      public static void LicenseHasExpired(ref int h_asExpiredFlag) {
         vsy_LicenseHasExpired(ref h_asExpiredFlag);
      }

      public static void LicenseIsPerpetual(ref int i_sPerpetualFlag) {
         vsy_LicenseIsPerpetual(ref i_sPerpetualFlag);
      }

      public static void LicenseHasMesh(ref int h_asMesh) {
         vsy_LicenseHasMesh(ref h_asMesh);
      }

      public static void LicenseHasAccess(ref int h_asAccess) {
         vsy_LicenseHasAccess(ref h_asAccess);
      }

      public static void LicenseHasSolve(ref int h_asSolve) {
         vsy_LicenseHasSolve(ref h_asSolve);
      }

      public static void LicenseCustomerName(out IntPtr c_ustomerName,ref int c_ustomerNameSize) {
         vsy_LicenseCustomerName(out c_ustomerName,ref c_ustomerNameSize);
      }

      public static void LicenseExpiryDate(out IntPtr e_xpiryDate,ref int e_xpiryDataSize) {
         vsy_LicenseExpiryDate(out e_xpiryDate,ref e_xpiryDataSize);
      }

      public const int LINECON_MAXLENGTH = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_LineConBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_LineConError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConDef(IntPtr p,int n_umline);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConInq(IntPtr p,ref int n_umline);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConAppend(IntPtr p,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConRef(IntPtr p,int i_ndex,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConNum(IntPtr p,ref int n_umlin);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConProcess(IntPtr p,ref int n_umstrip,ref int m_axlength);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConStrip(IntPtr p,int i_strip,ref int n_ix,int [] i_t,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LineConPrint(IntPtr p);

      public static IntPtr LineConBegin() {
         return vsy_LineConBegin();
      }

      public static void LineConEnd(IntPtr p) {
         vsy_LineConEnd(p);
      }

      public static int LineConError(IntPtr p) {
         return vsy_LineConError(p);
      }

      public static void LineConDef(IntPtr p,int n_umline) {
         vsy_LineConDef(p, n_umline);
      }

      public static void LineConInq(IntPtr p,ref int n_umline) {
         vsy_LineConInq(p,ref n_umline);
      }

      public static void LineConSetParami(IntPtr p,int p_type,int i_param) {
         vsy_LineConSetParami(p, p_type, i_param);
      }

      public static void LineConAppend(IntPtr p,int [] i_x) {
         vsy_LineConAppend(p, i_x);
      }

      public static void LineConRef(IntPtr p,int i_ndex,int [] i_x) {
         vsy_LineConRef(p, i_ndex, i_x);
      }

      public static void LineConNum(IntPtr p,ref int n_umlin) {
         vsy_LineConNum(p,ref n_umlin);
      }

      public static void LineConClear(IntPtr p) {
         vsy_LineConClear(p);
      }

      public static void LineConProcess(IntPtr p,ref int n_umstrip,ref int m_axlength) {
         vsy_LineConProcess(p,ref n_umstrip,ref m_axlength);
      }

      public static void LineConStrip(IntPtr p,int i_strip,ref int n_ix,int [] i_t,int [] i_x) {
         vsy_LineConStrip(p, i_strip,ref n_ix, i_t, i_x);
      }

      public static void LineConPrint(IntPtr p) {
         vsy_LineConPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_LinkListBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_LinkListError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListDef(IntPtr p,int l_en,int n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListInq(IntPtr p,ref int l_en,ref int n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListAdd(IntPtr p,ref int i_ndex,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListRef(IntPtr p,int i_ndex,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListRemove(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListHead(IntPtr p,ref int i_ndex,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListNextIter(IntPtr p,ref int i_ndex,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListForEach(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_LinkListPrint(IntPtr p);

      public static IntPtr LinkListBegin() {
         return vsy_LinkListBegin();
      }

      public static void LinkListEnd(IntPtr p) {
         vsy_LinkListEnd(p);
      }

      public static int LinkListError(IntPtr p) {
         return vsy_LinkListError(p);
      }

      public static void LinkListDef(IntPtr p,int l_en,int n_bytes) {
         vsy_LinkListDef(p, l_en, n_bytes);
      }

      public static void LinkListInq(IntPtr p,ref int l_en,ref int n_bytes) {
         vsy_LinkListInq(p,ref l_en,ref n_bytes);
      }

      public static void LinkListCount(IntPtr p,ref int n_um) {
         vsy_LinkListCount(p,ref n_um);
      }

      public static void LinkListAdd(IntPtr p,ref int i_ndex,out IntPtr v_alue) {
         vsy_LinkListAdd(p,ref i_ndex,out v_alue);
      }

      public static void LinkListRef(IntPtr p,int i_ndex,out IntPtr v_alue) {
         vsy_LinkListRef(p, i_ndex,out v_alue);
      }

      public static void LinkListRemove(IntPtr p,int i_ndex) {
         vsy_LinkListRemove(p, i_ndex);
      }

      public static void LinkListInit(IntPtr p) {
         vsy_LinkListInit(p);
      }

      public static void LinkListClear(IntPtr p) {
         vsy_LinkListClear(p);
      }

      public static void LinkListHead(IntPtr p,ref int i_ndex,out IntPtr v_alue) {
         vsy_LinkListHead(p,ref i_ndex,out v_alue);
      }

      public static void LinkListInitIter(IntPtr p) {
         vsy_LinkListInitIter(p);
      }

      public static void LinkListNextIter(IntPtr p,ref int i_ndex,out IntPtr v_alue) {
         vsy_LinkListNextIter(p,ref i_ndex,out v_alue);
      }

      public static void LinkListForEach(IntPtr p,Vfunc1 f_unction) {
         vsy_LinkListForEach(p, f_unction);
      }

      public static void LinkListPrint(IntPtr p) {
         vsy_LinkListPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_ListBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_ListError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListDef(IntPtr p,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListInq(IntPtr p,ref int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListMaxIndex(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListAllIndices(IntPtr p,int [] a_llindices);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListInsert(IntPtr p,int i_ndex,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListInsertCopy(IntPtr p,int k_ey,int n_b,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListAdd(IntPtr p,IntPtr v_alue,ref int i_dx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListAppend(IntPtr p,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListRef(IntPtr p,int i_ndex,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListRemove(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListCompact(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListNextIter(IntPtr p,ref int i_dx,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ListForEach(IntPtr p,Vfunc1 f_unc);

      public static IntPtr ListBegin() {
         return vsy_ListBegin();
      }

      public static void ListEnd(IntPtr p) {
         vsy_ListEnd(p);
      }

      public static int ListError(IntPtr p) {
         return vsy_ListError(p);
      }

      public static void ListDef(IntPtr p,int n_umobj) {
         vsy_ListDef(p, n_umobj);
      }

      public static void ListInq(IntPtr p,ref int l_en) {
         vsy_ListInq(p,ref l_en);
      }

      public static void ListCount(IntPtr p,ref int n_um) {
         vsy_ListCount(p,ref n_um);
      }

      public static void ListMaxIndex(IntPtr p,ref int m_axindex) {
         vsy_ListMaxIndex(p,ref m_axindex);
      }

      public static void ListAllIndices(IntPtr p,int [] a_llindices) {
         vsy_ListAllIndices(p, a_llindices);
      }

      public static void ListInsert(IntPtr p,int i_ndex,IntPtr v_alue) {
         vsy_ListInsert(p, i_ndex, v_alue);
      }

      public static void ListInsertCopy(IntPtr p,int k_ey,int n_b,IntPtr v_alue) {
         vsy_ListInsertCopy(p, k_ey, n_b, v_alue);
      }

      public static void ListAdd(IntPtr p,IntPtr v_alue,ref int i_dx) {
         vsy_ListAdd(p, v_alue,ref i_dx);
      }

      public static void ListAppend(IntPtr p,IntPtr v_alue) {
         vsy_ListAppend(p, v_alue);
      }

      public static void ListRef(IntPtr p,int i_ndex,out IntPtr v_alue) {
         vsy_ListRef(p, i_ndex,out v_alue);
      }

      public static void ListRemove(IntPtr p,int i_ndex) {
         vsy_ListRemove(p, i_ndex);
      }

      public static void ListClear(IntPtr p) {
         vsy_ListClear(p);
      }

      public static void ListCompact(IntPtr p) {
         vsy_ListCompact(p);
      }

      public static void ListInitIter(IntPtr p) {
         vsy_ListInitIter(p);
      }

      public static void ListNextIter(IntPtr p,ref int i_dx,out IntPtr v_alue) {
         vsy_ListNextIter(p,ref i_dx,out v_alue);
      }

      public static void ListForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_ListForEach(p, f_unc);
      }

      public const int PLAINTEXT_BORDEREQUALS = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_PlainTextBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_PlainTextError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextOpenFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextConnectFile(IntPtr p,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextDisconnectFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextQueryFile(IntPtr p,out IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextColumnAlign(IntPtr p,int a_lign);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextListType(IntPtr p,int l_isttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextHeadingLevel(IntPtr p,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextRuleWidth(IntPtr p,int r_ulewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextTextColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextTableColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextBackColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextBorderWidth(IntPtr p,int b_orderwidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextTableWidth(IntPtr p,int t_ablewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextFormInit(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextFormTerm(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextFormAction(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextHorizontalRule(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextImageFile(IntPtr p,StringBuilder f_ilename);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextString(IntPtr p,StringBuilder s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextSpace(IntPtr p,int n_spaces);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextSetPageWidth(IntPtr p,int p_agewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextTextFun(IntPtr p,IntPtr t_extfun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PlainTextGetString(IntPtr p,out IntPtr s_tring);

      public static IntPtr PlainTextBegin() {
         return vsy_PlainTextBegin();
      }

      public static void PlainTextEnd(IntPtr p) {
         vsy_PlainTextEnd(p);
      }

      public static int PlainTextError(IntPtr p) {
         return vsy_PlainTextError(p);
      }

      public static void PlainTextOpenFile(IntPtr p,StringBuilder f_ilename) {
         vsy_PlainTextOpenFile(p, f_ilename);
      }

      public static void PlainTextCloseFile(IntPtr p) {
         vsy_PlainTextCloseFile(p);
      }

      public static void PlainTextConnectFile(IntPtr p,IntPtr f_d) {
         vsy_PlainTextConnectFile(p, f_d);
      }

      public static void PlainTextDisconnectFile(IntPtr p) {
         vsy_PlainTextDisconnectFile(p);
      }

      public static void PlainTextQueryFile(IntPtr p,out IntPtr f_d) {
         vsy_PlainTextQueryFile(p,out f_d);
      }

      public static void PlainTextColumnAlign(IntPtr p,int a_lign) {
         vsy_PlainTextColumnAlign(p, a_lign);
      }

      public static void PlainTextListType(IntPtr p,int l_isttype) {
         vsy_PlainTextListType(p, l_isttype);
      }

      public static void PlainTextHeadingLevel(IntPtr p,int l_evel) {
         vsy_PlainTextHeadingLevel(p, l_evel);
      }

      public static void PlainTextRuleWidth(IntPtr p,int r_ulewidth) {
         vsy_PlainTextRuleWidth(p, r_ulewidth);
      }

      public static void PlainTextTextColor(IntPtr p,float [] c_) {
         vsy_PlainTextTextColor(p, c_);
      }

      public static void PlainTextTableColor(IntPtr p,float [] c_) {
         vsy_PlainTextTableColor(p, c_);
      }

      public static void PlainTextBackColor(IntPtr p,float [] c_) {
         vsy_PlainTextBackColor(p, c_);
      }

      public static void PlainTextBorderWidth(IntPtr p,int b_orderwidth) {
         vsy_PlainTextBorderWidth(p, b_orderwidth);
      }

      public static void PlainTextTableWidth(IntPtr p,int t_ablewidth) {
         vsy_PlainTextTableWidth(p, t_ablewidth);
      }

      public static void PlainTextSetMode(IntPtr p,int m_ode,int f_lag) {
         vsy_PlainTextSetMode(p, m_ode, f_lag);
      }

      public static void PlainTextFormInit(IntPtr p,int f_orm) {
         vsy_PlainTextFormInit(p, f_orm);
      }

      public static void PlainTextFormTerm(IntPtr p,int f_orm) {
         vsy_PlainTextFormTerm(p, f_orm);
      }

      public static void PlainTextFormAction(IntPtr p,int f_orm) {
         vsy_PlainTextFormAction(p, f_orm);
      }

      public static void PlainTextHorizontalRule(IntPtr p) {
         vsy_PlainTextHorizontalRule(p);
      }

      public static void PlainTextImageFile(IntPtr p,StringBuilder f_ilename) {
         vsy_PlainTextImageFile(p, f_ilename);
      }

      public static void PlainTextString(IntPtr p,StringBuilder s_tring) {
         vsy_PlainTextString(p, s_tring);
      }

      public static void PlainTextSpace(IntPtr p,int n_spaces) {
         vsy_PlainTextSpace(p, n_spaces);
      }

      public static void PlainTextSetPageWidth(IntPtr p,int p_agewidth) {
         vsy_PlainTextSetPageWidth(p, p_agewidth);
      }

      public static void PlainTextTextFun(IntPtr p,IntPtr t_extfun) {
         vsy_PlainTextTextFun(p, t_extfun);
      }

      public static void PlainTextGetString(IntPtr p,out IntPtr s_tring) {
         vsy_PlainTextGetString(p,out s_tring);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_PQueueBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_PQueueError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueDef(IntPtr p,int m_axindex,int n_umacc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueInq(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueRange(IntPtr p,double m_inval,double m_axval);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueInsert(IntPtr p,int i_ndex,double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueMinMax(IntPtr p,int m_inmax,ref int i_ndex,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueRemove(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueLookup(IntPtr p,int i_ndex,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueNum(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueueClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PQueuePrint(IntPtr p);

      public static IntPtr PQueueBegin() {
         return vsy_PQueueBegin();
      }

      public static void PQueueEnd(IntPtr p) {
         vsy_PQueueEnd(p);
      }

      public static int PQueueError(IntPtr p) {
         return vsy_PQueueError(p);
      }

      public static void PQueueDef(IntPtr p,int m_axindex,int n_umacc) {
         vsy_PQueueDef(p, m_axindex, n_umacc);
      }

      public static void PQueueInq(IntPtr p,ref int m_axindex) {
         vsy_PQueueInq(p,ref m_axindex);
      }

      public static void PQueueRange(IntPtr p,double m_inval,double m_axval) {
         vsy_PQueueRange(p, m_inval, m_axval);
      }

      public static void PQueueInsert(IntPtr p,int i_ndex,double v_al) {
         vsy_PQueueInsert(p, i_ndex, v_al);
      }

      public static void PQueueMinMax(IntPtr p,int m_inmax,ref int i_ndex,ref double v_al) {
         vsy_PQueueMinMax(p, m_inmax,ref i_ndex,ref v_al);
      }

      public static void PQueueRemove(IntPtr p,int i_ndex) {
         vsy_PQueueRemove(p, i_ndex);
      }

      public static void PQueueLookup(IntPtr p,int i_ndex,ref double v_al) {
         vsy_PQueueLookup(p, i_ndex,ref v_al);
      }

      public static void PQueueNum(IntPtr p,ref int n_um) {
         vsy_PQueueNum(p,ref n_um);
      }

      public static void PQueueClear(IntPtr p) {
         vsy_PQueueClear(p);
      }

      public static void PQueuePrint(IntPtr p) {
         vsy_PQueuePrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_PredBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_PredError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredTetGen(IntPtr p,int n_oexact,int n_ofilter,double m_axx,double m_axy,double m_axz);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredTestZeroDet(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredPushFPU(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredPopFPU(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient2d(IntPtr p,ref double a_,ref double b_,ref double c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient2dExact(IntPtr p,ref double p_a,ref double p_b,ref double p_c);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient3d(IntPtr p,ref double b_,ref double a_,ref double c_,ref double d_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient3dExact(IntPtr p,ref double p_b,ref double p_a,ref double p_c,ref double p_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredIncircle(IntPtr p,ref double a_,ref double b_,ref double c_,ref double d_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredInsphere(IntPtr p,ref double a_,ref double b_,ref double c_,ref double d_,ref double e_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredIntersectLineTri(IntPtr p,double [] x_t,double [] x_l,ref int c_ode,ref int i_ent,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredIntersectLineLine(IntPtr p,double [] x_l1,double [] x_l2,ref int c_ode,ref int i_ent,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient4d(IntPtr p,ref double p_a,ref double p_b,ref double p_c,ref double p_d,ref double p_e,double a_height,double b_height,double c_height,double d_height,double e_height);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vsy_PredOrient4dExact(IntPtr p,ref double p_a,ref double p_b,ref double p_c,ref double p_d,ref double p_e,double a_height,double b_height,double c_height,double d_height,double e_height);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PredExact(IntPtr p,ref int p_ass);

      public static IntPtr PredBegin() {
         return vsy_PredBegin();
      }

      public static void PredEnd(IntPtr p) {
         vsy_PredEnd(p);
      }

      public static int PredError(IntPtr p) {
         return vsy_PredError(p);
      }

      public static void PredTetGen(IntPtr p,int n_oexact,int n_ofilter,double m_axx,double m_axy,double m_axz) {
         vsy_PredTetGen(p, n_oexact, n_ofilter, m_axx, m_axy, m_axz);
      }

      public static void PredTestZeroDet(IntPtr p,int f_lag) {
         vsy_PredTestZeroDet(p, f_lag);
      }

      public static void PredPushFPU(IntPtr p) {
         vsy_PredPushFPU(p);
      }

      public static void PredPopFPU(IntPtr p) {
         vsy_PredPopFPU(p);
      }

      public static double PredOrient2d(IntPtr p,ref double a_,ref double b_,ref double c_) {
         return vsy_PredOrient2d(p,ref a_,ref b_,ref c_);
      }

      public static double PredOrient2dExact(IntPtr p,ref double p_a,ref double p_b,ref double p_c) {
         return vsy_PredOrient2dExact(p,ref p_a,ref p_b,ref p_c);
      }

      public static double PredOrient3d(IntPtr p,ref double b_,ref double a_,ref double c_,ref double d_) {
         return vsy_PredOrient3d(p,ref b_,ref a_,ref c_,ref d_);
      }

      public static double PredOrient3dExact(IntPtr p,ref double p_b,ref double p_a,ref double p_c,ref double p_d) {
         return vsy_PredOrient3dExact(p,ref p_b,ref p_a,ref p_c,ref p_d);
      }

      public static double PredIncircle(IntPtr p,ref double a_,ref double b_,ref double c_,ref double d_) {
         return vsy_PredIncircle(p,ref a_,ref b_,ref c_,ref d_);
      }

      public static double PredInsphere(IntPtr p,ref double a_,ref double b_,ref double c_,ref double d_,ref double e_) {
         return vsy_PredInsphere(p,ref a_,ref b_,ref c_,ref d_,ref e_);
      }

      public static void PredIntersectLineTri(IntPtr p,double [] x_t,double [] x_l,ref int c_ode,ref int i_ent,ref int i_err) {
         vsy_PredIntersectLineTri(p, x_t, x_l,ref c_ode,ref i_ent,ref i_err);
      }

      public static void PredIntersectLineLine(IntPtr p,double [] x_l1,double [] x_l2,ref int c_ode,ref int i_ent,ref int i_err) {
         vsy_PredIntersectLineLine(p, x_l1, x_l2,ref c_ode,ref i_ent,ref i_err);
      }

      public static double PredOrient4d(IntPtr p,ref double p_a,ref double p_b,ref double p_c,ref double p_d,ref double p_e,double a_height,double b_height,double c_height,double d_height,double e_height) {
         return vsy_PredOrient4d(p,ref p_a,ref p_b,ref p_c,ref p_d,ref p_e, a_height, b_height, c_height, d_height, e_height);
      }

      public static double PredOrient4dExact(IntPtr p,ref double p_a,ref double p_b,ref double p_c,ref double p_d,ref double p_e,double a_height,double b_height,double c_height,double d_height,double e_height) {
         return vsy_PredOrient4dExact(p,ref p_a,ref p_b,ref p_c,ref p_d,ref p_e, a_height, b_height, c_height, d_height, e_height);
      }

      public static void PredExact(IntPtr p,ref int p_ass) {
         vsy_PredExact(p,ref p_ass);
      }

      public const int PROGRESS_RATE = 1;
      public const int PROGRESS_RATE_NORMAL = 1;
      public const int PROGRESS_RATE_ACCELERATED = 2;
      public const int PROGRESS_RATE_STALLED = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_ProgressBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_ProgressError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressStart(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressStop(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressPush(IntPtr p,StringBuilder n_ame,int n_pri);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressPop(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressInterval(IntPtr p,int i_pri,StringBuilder n_ame,float w_eight,float s_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressPrimary(IntPtr p,int i_pri);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressPrimaryName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressSecondary(IntPtr p,float s_ec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressPercentDone(IntPtr p,ref float p_ercent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressTime(IntPtr p,ref float t_imespent,ref float t_imetogo);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ProgressGetInteger(IntPtr p,int t_ype,ref int v_alue);

      public static IntPtr ProgressBegin() {
         return vsy_ProgressBegin();
      }

      public static void ProgressEnd(IntPtr p) {
         vsy_ProgressEnd(p);
      }

      public static int ProgressError(IntPtr p) {
         return vsy_ProgressError(p);
      }

      public static void ProgressStart(IntPtr p) {
         vsy_ProgressStart(p);
      }

      public static void ProgressStop(IntPtr p) {
         vsy_ProgressStop(p);
      }

      public static void ProgressPush(IntPtr p,StringBuilder n_ame,int n_pri) {
         vsy_ProgressPush(p, n_ame, n_pri);
      }

      public static void ProgressPop(IntPtr p,StringBuilder n_ame) {
         vsy_ProgressPop(p, n_ame);
      }

      public static void ProgressInterval(IntPtr p,int i_pri,StringBuilder n_ame,float w_eight,float s_ec) {
         vsy_ProgressInterval(p, i_pri, n_ame, w_eight, s_ec);
      }

      public static void ProgressPrimary(IntPtr p,int i_pri) {
         vsy_ProgressPrimary(p, i_pri);
      }

      public static void ProgressPrimaryName(IntPtr p,StringBuilder n_ame) {
         vsy_ProgressPrimaryName(p, n_ame);
      }

      public static void ProgressSecondary(IntPtr p,float s_ec) {
         vsy_ProgressSecondary(p, s_ec);
      }

      public static void ProgressPercentDone(IntPtr p,ref float p_ercent) {
         vsy_ProgressPercentDone(p,ref p_ercent);
      }

      public static void ProgressTime(IntPtr p,ref float t_imespent,ref float t_imetogo) {
         vsy_ProgressTime(p,ref t_imespent,ref t_imetogo);
      }

      public static void ProgressGetInteger(IntPtr p,int t_ype,ref int v_alue) {
         vsy_ProgressGetInteger(p, t_ype,ref v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_PropSetBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_PropSetError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetDef(IntPtr p,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInserti(IntPtr p,StringBuilder n_ame,int v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertiv(IntPtr p,StringBuilder n_ame,int n_um,int [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertf(IntPtr p,StringBuilder n_ame,float v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertfv(IntPtr p,StringBuilder n_ame,int n_um,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertd(IntPtr p,StringBuilder n_ame,double v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertdv(IntPtr p,StringBuilder n_ame,int n_um,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertl(IntPtr p,StringBuilder n_ame,long v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertlv(IntPtr p,StringBuilder n_ame,int n_um,long [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertp(IntPtr p,StringBuilder n_ame,IntPtr v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertpv(IntPtr p,StringBuilder n_ame,int n_um,IntPtr v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInsertc(IntPtr p,StringBuilder n_ame,StringBuilder p_rop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupInteger(IntPtr p,StringBuilder n_ame,ref int v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupFloat(IntPtr p,StringBuilder n_ame,ref float v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupDouble(IntPtr p,StringBuilder n_ame,ref double p_rop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupLong(IntPtr p,StringBuilder n_ame,ref long v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupString(IntPtr p,StringBuilder n_ame,StringBuilder v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookupObject(IntPtr p,StringBuilder n_ame,out IntPtr v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetLookup(IntPtr p,StringBuilder n_ame,ref int t_ype,ref int n_um,ref int s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetRemove(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetNextIter(IntPtr p,out IntPtr n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PropSetCopy(IntPtr p,IntPtr q_);

      public static IntPtr PropSetBegin() {
         return vsy_PropSetBegin();
      }

      public static void PropSetEnd(IntPtr p) {
         vsy_PropSetEnd(p);
      }

      public static int PropSetError(IntPtr p) {
         return vsy_PropSetError(p);
      }

      public static void PropSetDef(IntPtr p,int n_umobj) {
         vsy_PropSetDef(p, n_umobj);
      }

      public static void PropSetInq(IntPtr p,ref int n_ument) {
         vsy_PropSetInq(p,ref n_ument);
      }

      public static void PropSetCount(IntPtr p,ref int n_um) {
         vsy_PropSetCount(p,ref n_um);
      }

      public static void PropSetInserti(IntPtr p,StringBuilder n_ame,int v_) {
         vsy_PropSetInserti(p, n_ame, v_);
      }

      public static void PropSetInsertiv(IntPtr p,StringBuilder n_ame,int n_um,int [] v_) {
         vsy_PropSetInsertiv(p, n_ame, n_um, v_);
      }

      public static void PropSetInsertf(IntPtr p,StringBuilder n_ame,float v_) {
         vsy_PropSetInsertf(p, n_ame, v_);
      }

      public static void PropSetInsertfv(IntPtr p,StringBuilder n_ame,int n_um,float [] v_) {
         vsy_PropSetInsertfv(p, n_ame, n_um, v_);
      }

      public static void PropSetInsertd(IntPtr p,StringBuilder n_ame,double v_) {
         vsy_PropSetInsertd(p, n_ame, v_);
      }

      public static void PropSetInsertdv(IntPtr p,StringBuilder n_ame,int n_um,double [] v_) {
         vsy_PropSetInsertdv(p, n_ame, n_um, v_);
      }

      public static void PropSetInsertl(IntPtr p,StringBuilder n_ame,long v_) {
         vsy_PropSetInsertl(p, n_ame, v_);
      }

      public static void PropSetInsertlv(IntPtr p,StringBuilder n_ame,int n_um,long [] v_) {
         vsy_PropSetInsertlv(p, n_ame, n_um, v_);
      }

      public static void PropSetInsertp(IntPtr p,StringBuilder n_ame,IntPtr v_) {
         vsy_PropSetInsertp(p, n_ame, v_);
      }

      public static void PropSetInsertpv(IntPtr p,StringBuilder n_ame,int n_um,IntPtr v_) {
         vsy_PropSetInsertpv(p, n_ame, n_um, v_);
      }

      public static void PropSetInsertc(IntPtr p,StringBuilder n_ame,StringBuilder p_rop) {
         vsy_PropSetInsertc(p, n_ame, p_rop);
      }

      public static void PropSetLookupInteger(IntPtr p,StringBuilder n_ame,ref int v_) {
         vsy_PropSetLookupInteger(p, n_ame,ref v_);
      }

      public static void PropSetLookupFloat(IntPtr p,StringBuilder n_ame,ref float v_) {
         vsy_PropSetLookupFloat(p, n_ame,ref v_);
      }

      public static void PropSetLookupDouble(IntPtr p,StringBuilder n_ame,ref double p_rop) {
         vsy_PropSetLookupDouble(p, n_ame,ref p_rop);
      }

      public static void PropSetLookupLong(IntPtr p,StringBuilder n_ame,ref long v_) {
         vsy_PropSetLookupLong(p, n_ame,ref v_);
      }

      public static void PropSetLookupString(IntPtr p,StringBuilder n_ame,StringBuilder v_) {
         vsy_PropSetLookupString(p, n_ame, v_);
      }

      public static void PropSetLookupObject(IntPtr p,StringBuilder n_ame,out IntPtr v_) {
         vsy_PropSetLookupObject(p, n_ame,out v_);
      }

      public static void PropSetLookup(IntPtr p,StringBuilder n_ame,ref int t_ype,ref int n_um,ref int s_ize) {
         vsy_PropSetLookup(p, n_ame,ref t_ype,ref n_um,ref s_ize);
      }

      public static void PropSetRemove(IntPtr p,StringBuilder n_ame) {
         vsy_PropSetRemove(p, n_ame);
      }

      public static void PropSetClear(IntPtr p) {
         vsy_PropSetClear(p);
      }

      public static void PropSetInitIter(IntPtr p) {
         vsy_PropSetInitIter(p);
      }

      public static void PropSetNextIter(IntPtr p,out IntPtr n_ame) {
         vsy_PropSetNextIter(p,out n_ame);
      }

      public static void PropSetCopy(IntPtr p,IntPtr q_) {
         vsy_PropSetCopy(p, q_);
      }

      public const int PTASK_SERIALMODE = 1;
      public const int PTASK_EXEC = 1;
      public const int PTASK_START = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_PTaskBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_PTaskError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskDef(IntPtr p,int n_umthreads,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskInq(IntPtr p,ref int n_um,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskExec(IntPtr p,int n_tasks,Vfunc1 f_unc,out IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskStart(IntPtr p,Vfunc1 f_unc,IntPtr d_ata,ref int t_askid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskLock(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskUnlock(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskJoin(IntPtr p,int t_askid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskGetThreadId(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_PTaskGetMode(IntPtr p,int m_ode,ref int v_alue);

      public static IntPtr PTaskBegin() {
         return vsy_PTaskBegin();
      }

      public static void PTaskEnd(IntPtr p) {
         vsy_PTaskEnd(p);
      }

      public static int PTaskError(IntPtr p) {
         return vsy_PTaskError(p);
      }

      public static void PTaskDef(IntPtr p,int n_umthreads,int t_ype) {
         vsy_PTaskDef(p, n_umthreads, t_ype);
      }

      public static void PTaskInq(IntPtr p,ref int n_um,ref int t_ype) {
         vsy_PTaskInq(p,ref n_um,ref t_ype);
      }

      public static void PTaskExec(IntPtr p,int n_tasks,Vfunc1 f_unc,out IntPtr d_ata) {
         vsy_PTaskExec(p, n_tasks, f_unc,out d_ata);
      }

      public static void PTaskStart(IntPtr p,Vfunc1 f_unc,IntPtr d_ata,ref int t_askid) {
         vsy_PTaskStart(p, f_unc, d_ata,ref t_askid);
      }

      public static void PTaskLock(IntPtr p) {
         vsy_PTaskLock(p);
      }

      public static void PTaskUnlock(IntPtr p) {
         vsy_PTaskUnlock(p);
      }

      public static void PTaskJoin(IntPtr p,int t_askid) {
         vsy_PTaskJoin(p, t_askid);
      }

      public static void PTaskGetThreadId(IntPtr p,ref int n_um) {
         vsy_PTaskGetThreadId(p,ref n_um);
      }

      public static void PTaskSetMode(IntPtr p,int m_ode,int f_lag) {
         vsy_PTaskSetMode(p, m_ode, f_lag);
      }

      public static void PTaskGetMode(IntPtr p,int m_ode,ref int v_alue) {
         vsy_PTaskGetMode(p, m_ode,ref v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_RandomBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RandomEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_RandomError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RandomInit(IntPtr p,int s_eed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RandomNumber(IntPtr p,ref float n_umber);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RandomInteger(IntPtr p,ref int n_umber);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_RandomRand(IntPtr p);

      public static IntPtr RandomBegin() {
         return vsy_RandomBegin();
      }

      public static void RandomEnd(IntPtr p) {
         vsy_RandomEnd(p);
      }

      public static int RandomError(IntPtr p) {
         return vsy_RandomError(p);
      }

      public static void RandomInit(IntPtr p,int s_eed) {
         vsy_RandomInit(p, s_eed);
      }

      public static void RandomNumber(IntPtr p,ref float n_umber) {
         vsy_RandomNumber(p,ref n_umber);
      }

      public static void RandomInteger(IntPtr p,ref int n_umber) {
         vsy_RandomInteger(p,ref n_umber);
      }

      public static int RandomRand(IntPtr p) {
         return vsy_RandomRand(p);
      }

      public const int PREC_MANTISSA = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_RedPreBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_RedPreError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreExtent(IntPtr p,float m_in,float m_ax);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreInq(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreLoad(IntPtr p,int n_,float [] a_,ref IntPtr b_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreLoaddv(IntPtr p,int n_,double [] a_,ref IntPtr b_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreStore(IntPtr p,int n_,ref IntPtr a_,float [] b_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RedPreStoredv(IntPtr p,int n_,ref IntPtr a_,double [] b_);

      public static IntPtr RedPreBegin() {
         return vsy_RedPreBegin();
      }

      public static void RedPreEnd(IntPtr p) {
         vsy_RedPreEnd(p);
      }

      public static int RedPreError(IntPtr p) {
         return vsy_RedPreError(p);
      }

      public static void RedPreExtent(IntPtr p,float m_in,float m_ax) {
         vsy_RedPreExtent(p, m_in, m_ax);
      }

      public static void RedPreDef(IntPtr p,int t_ype) {
         vsy_RedPreDef(p, t_ype);
      }

      public static void RedPreInq(IntPtr p,ref int t_ype) {
         vsy_RedPreInq(p,ref t_ype);
      }

      public static void RedPreLoad(IntPtr p,int n_,float [] a_,ref IntPtr b_) {
         vsy_RedPreLoad(p, n_, a_,ref b_);
      }

      public static void RedPreLoaddv(IntPtr p,int n_,double [] a_,ref IntPtr b_) {
         vsy_RedPreLoaddv(p, n_, a_,ref b_);
      }

      public static void RedPreStore(IntPtr p,int n_,ref IntPtr a_,float [] b_) {
         vsy_RedPreStore(p, n_,ref a_, b_);
      }

      public static void RedPreStoredv(IntPtr p,int n_,ref IntPtr a_,double [] b_) {
         vsy_RedPreStoredv(p, n_,ref a_, b_);
      }

      public const int REGEXP_MAXDFA = 1024;
      public const int REGEXP_MAXTAG = 10;
      public const int REGEXP_MAXCHR = 128;
      public const int REGEXP_CHRBIT = 8;
      public const int REGEXP_SQUAREBRACKET = 1;
      public const int REGEXP_POSIX = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_RegExpBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RegExpEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_RegExpError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RegExpSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RegExpForm(IntPtr p,StringBuilder e_xp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_RegExpMatch(IntPtr p,StringBuilder s_tg,ref int i_match);

      public static IntPtr RegExpBegin() {
         return vsy_RegExpBegin();
      }

      public static void RegExpEnd(IntPtr p) {
         vsy_RegExpEnd(p);
      }

      public static int RegExpError(IntPtr p) {
         return vsy_RegExpError(p);
      }

      public static void RegExpSetParami(IntPtr p,int t_ype,int i_param) {
         vsy_RegExpSetParami(p, t_ype, i_param);
      }

      public static void RegExpForm(IntPtr p,StringBuilder e_xp) {
         vsy_RegExpForm(p, e_xp);
      }

      public static void RegExpMatch(IntPtr p,StringBuilder s_tg,ref int i_match) {
         vsy_RegExpMatch(p, s_tg,ref i_match);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_StackBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_StackError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackDef(IntPtr p,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackInq(IntPtr p,ref int l_en);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackPush(IntPtr p,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackPop(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackRef(IntPtr p,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackCompact(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_StackForEach(IntPtr p,Vfunc1 f_unc);

      public static IntPtr StackBegin() {
         return vsy_StackBegin();
      }

      public static void StackEnd(IntPtr p) {
         vsy_StackEnd(p);
      }

      public static int StackError(IntPtr p) {
         return vsy_StackError(p);
      }

      public static void StackDef(IntPtr p,int n_umobj) {
         vsy_StackDef(p, n_umobj);
      }

      public static void StackInq(IntPtr p,ref int l_en) {
         vsy_StackInq(p,ref l_en);
      }

      public static void StackCount(IntPtr p,ref int n_um) {
         vsy_StackCount(p,ref n_um);
      }

      public static void StackPush(IntPtr p,IntPtr v_alue) {
         vsy_StackPush(p, v_alue);
      }

      public static void StackPop(IntPtr p) {
         vsy_StackPop(p);
      }

      public static void StackRef(IntPtr p,out IntPtr v_alue) {
         vsy_StackRef(p,out v_alue);
      }

      public static void StackClear(IntPtr p) {
         vsy_StackClear(p);
      }

      public static void StackCompact(IntPtr p) {
         vsy_StackCompact(p);
      }

      public static void StackForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_StackForEach(p, f_unc);
      }

      public const int _XOPEN_SOURCE = 500;
      public const double PI = 3.141592653589793238462643383279502884197169399;
      public const double SQUAREROOTTWO = 1.414213562373095048801688724209698078569671875;
      public const double SQUAREROOTTHREE = 1.7320508075688772;
      public const double ONETHIRD = 0.333333333333333333333333333333333333333333333;
      public const double SMALL = 1.0E-12;
      public const double LARGE = 1.0E+12;
      public const double SPRE = 2.0E-07;
      public const double DPRE = 4.0E-16;
      public const double SEPS = 1.0E-37;
      public const double SBIG = 1.0E+37;
      public const int VKI_FUN_DEFINE = 1;

      public const int TEXTFUN_UNDEFINED = -1;
      public const int TEXTFUN_OPENFILE = 1;
      public const int TEXTFUN_CLOSEFILE = 2;
      public const int TEXTFUN_LISTTYPE = 3;
      public const int TEXTFUN_HEADINGLEVEL = 4;
      public const int TEXTFUN_RULEWIDTH = 5;
      public const int TEXTFUN_SETMODE = 6;
      public const int TEXTFUN_FORMINIT = 7;
      public const int TEXTFUN_FORMTERM = 8;
      public const int TEXTFUN_FORMACTION = 9;
      public const int TEXTFUN_HORIZONTALRULE = 10;
      public const int TEXTFUN_IMAGEFILE = 11;
      public const int TEXTFUN_STRING = 12;
      public const int TEXTFUN_CONNECTFILE = 13;
      public const int TEXTFUN_DISCONNECTFILE = 14;
      public const int TEXTFUN_QUERYFILE = 15;
      public const int TEXTFUN_COLUMNALIGN = 16;
      public const int TEXTFUN_SPACE = 17;
      public const int TEXTFUN_TEXTCOLOR = 18;
      public const int TEXTFUN_TABLECOLOR = 19;
      public const int TEXTFUN_BACKCOLOR = 20;
      public const int TEXTFUN_BORDERWIDTH = 21;
      public const int TEXTFUN_TABLEWIDTH = 22;
      public const int TEXTFUN_ERROR = 23;
      public const int TEXTFUN_MAX = 24;
      public const int TEXTFUN_APIPRINT = 0;
      public const int TEXTFUN_APIRETURN = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_TextFunBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_TextFunError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetErrorFunction(IntPtr p,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunGet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetObj(IntPtr p,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunGetObj(IntPtr p,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunAPI(IntPtr p,int a_pi);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunOpenFile(IntPtr p,StringBuilder p_athname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunCloseFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunConnectFile(IntPtr p,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunDisconnectFile(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunQueryFile(IntPtr p,out IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunListType(IntPtr p,int l_isttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunHeadingLevel(IntPtr p,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunRuleWidth(IntPtr p,int r_ulewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetMode(IntPtr p,int m_ode,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunFormInit(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunFormTerm(IntPtr p,int f_orm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunFormAction(IntPtr p,int f_ormaction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunHorizontalRule(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunImageFile(IntPtr p,StringBuilder p_athname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunString(IntPtr p,StringBuilder s_tring);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSpace(IntPtr p,int n_spaces);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunTextColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunTableColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunBackColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunBorderWidth(IntPtr p,int b_orderwidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunTableWidth(IntPtr p,int t_ablewidth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunColumnAlign(IntPtr p,int a_lign);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetOpenFileFun(IntPtr p,VTextFunOpenFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetCloseFileFun(IntPtr p,VTextFunCloseFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetConnectFileFun(IntPtr p,VTextFunConnectFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetDisconnectFileFun(IntPtr p,VTextFunDisconnectFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetQueryFileFun(IntPtr p,VTextFunQueryFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetListTypeFun(IntPtr p,VTextFunListType f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetHeadingLevelFun(IntPtr p,VTextFunHeadingLevel f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetRuleWidthFun(IntPtr p,VTextFunRuleWidth f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetSetModeFun(IntPtr p,VTextFunSetMode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetFormInitFun(IntPtr p,VTextFunFormInit f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetFormTermFun(IntPtr p,VTextFunFormTerm f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetFormActionFun(IntPtr p,VTextFunFormAction f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetHorizontalRuleFun(IntPtr p,VTextFunHorizontalRule f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetImageFileFun(IntPtr p,VTextFunImageFile f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetStringFun(IntPtr p,VTextFunString f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetSpaceFun(IntPtr p,VTextFunSpace f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetTextColorFun(IntPtr p,VTextFunTextColor f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetTableColorFun(IntPtr p,VTextFunTableColor f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetBackColorFun(IntPtr p,VTextFunBackColor f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetBorderWidthFun(IntPtr p,VTextFunBorderWidth f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetTableWidthFun(IntPtr p,VTextFunTableWidth f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextFunSetColumnAlignFun(IntPtr p,VTextFunColumnAlign f_unc);

      public static IntPtr TextFunBegin() {
         return vsy_TextFunBegin();
      }

      public static void TextFunEnd(IntPtr p) {
         vsy_TextFunEnd(p);
      }

      public static int TextFunError(IntPtr p) {
         return vsy_TextFunError(p);
      }

      public static void TextFunInit(IntPtr p) {
         vsy_TextFunInit(p);
      }

      public static void TextFunSet(IntPtr p,int t_ype,Vfunc f_unction) {
         vsy_TextFunSet(p, t_ype, f_unction);
      }

      public static void TextFunSetErrorFunction(IntPtr p,Vfunc f_unction) {
         vsy_TextFunSetErrorFunction(p, f_unction);
      }

      public static void TextFunGet(IntPtr p,int t_ype,Vfunc f_unction) {
         vsy_TextFunGet(p, t_ype, f_unction);
      }

      public static void TextFunSetObj(IntPtr p,IntPtr o_bj) {
         vsy_TextFunSetObj(p, o_bj);
      }

      public static void TextFunGetObj(IntPtr p,out IntPtr o_bj) {
         vsy_TextFunGetObj(p,out o_bj);
      }

      public static void TextFunCopy(IntPtr p,IntPtr f_romp) {
         vsy_TextFunCopy(p, f_romp);
      }

      public static void TextFunAPI(IntPtr p,int a_pi) {
         vsy_TextFunAPI(p, a_pi);
      }

      public static void TextFunOpenFile(IntPtr p,StringBuilder p_athname) {
         vsy_TextFunOpenFile(p, p_athname);
      }

      public static void TextFunCloseFile(IntPtr p) {
         vsy_TextFunCloseFile(p);
      }

      public static void TextFunConnectFile(IntPtr p,IntPtr f_d) {
         vsy_TextFunConnectFile(p, f_d);
      }

      public static void TextFunDisconnectFile(IntPtr p) {
         vsy_TextFunDisconnectFile(p);
      }

      public static void TextFunQueryFile(IntPtr p,out IntPtr f_d) {
         vsy_TextFunQueryFile(p,out f_d);
      }

      public static void TextFunListType(IntPtr p,int l_isttype) {
         vsy_TextFunListType(p, l_isttype);
      }

      public static void TextFunHeadingLevel(IntPtr p,int l_evel) {
         vsy_TextFunHeadingLevel(p, l_evel);
      }

      public static void TextFunRuleWidth(IntPtr p,int r_ulewidth) {
         vsy_TextFunRuleWidth(p, r_ulewidth);
      }

      public static void TextFunSetMode(IntPtr p,int m_ode,int f_lag) {
         vsy_TextFunSetMode(p, m_ode, f_lag);
      }

      public static void TextFunFormInit(IntPtr p,int f_orm) {
         vsy_TextFunFormInit(p, f_orm);
      }

      public static void TextFunFormTerm(IntPtr p,int f_orm) {
         vsy_TextFunFormTerm(p, f_orm);
      }

      public static void TextFunFormAction(IntPtr p,int f_ormaction) {
         vsy_TextFunFormAction(p, f_ormaction);
      }

      public static void TextFunHorizontalRule(IntPtr p) {
         vsy_TextFunHorizontalRule(p);
      }

      public static void TextFunImageFile(IntPtr p,StringBuilder p_athname) {
         vsy_TextFunImageFile(p, p_athname);
      }

      public static void TextFunString(IntPtr p,StringBuilder s_tring) {
         vsy_TextFunString(p, s_tring);
      }

      public static void TextFunSpace(IntPtr p,int n_spaces) {
         vsy_TextFunSpace(p, n_spaces);
      }

      public static void TextFunTextColor(IntPtr p,float [] c_) {
         vsy_TextFunTextColor(p, c_);
      }

      public static void TextFunTableColor(IntPtr p,float [] c_) {
         vsy_TextFunTableColor(p, c_);
      }

      public static void TextFunBackColor(IntPtr p,float [] c_) {
         vsy_TextFunBackColor(p, c_);
      }

      public static void TextFunBorderWidth(IntPtr p,int b_orderwidth) {
         vsy_TextFunBorderWidth(p, b_orderwidth);
      }

      public static void TextFunTableWidth(IntPtr p,int t_ablewidth) {
         vsy_TextFunTableWidth(p, t_ablewidth);
      }

      public static void TextFunColumnAlign(IntPtr p,int a_lign) {
         vsy_TextFunColumnAlign(p, a_lign);
      }

      public static void TextFunSetOpenFileFun(IntPtr p,VTextFunOpenFile f_unc) {
         vsy_TextFunSetOpenFileFun(p, f_unc);
      }

      public static void TextFunSetCloseFileFun(IntPtr p,VTextFunCloseFile f_unc) {
         vsy_TextFunSetCloseFileFun(p, f_unc);
      }

      public static void TextFunSetConnectFileFun(IntPtr p,VTextFunConnectFile f_unc) {
         vsy_TextFunSetConnectFileFun(p, f_unc);
      }

      public static void TextFunSetDisconnectFileFun(IntPtr p,VTextFunDisconnectFile f_unc) {
         vsy_TextFunSetDisconnectFileFun(p, f_unc);
      }

      public static void TextFunSetQueryFileFun(IntPtr p,VTextFunQueryFile f_unc) {
         vsy_TextFunSetQueryFileFun(p, f_unc);
      }

      public static void TextFunSetListTypeFun(IntPtr p,VTextFunListType f_unc) {
         vsy_TextFunSetListTypeFun(p, f_unc);
      }

      public static void TextFunSetHeadingLevelFun(IntPtr p,VTextFunHeadingLevel f_unc) {
         vsy_TextFunSetHeadingLevelFun(p, f_unc);
      }

      public static void TextFunSetRuleWidthFun(IntPtr p,VTextFunRuleWidth f_unc) {
         vsy_TextFunSetRuleWidthFun(p, f_unc);
      }

      public static void TextFunSetSetModeFun(IntPtr p,VTextFunSetMode f_unc) {
         vsy_TextFunSetSetModeFun(p, f_unc);
      }

      public static void TextFunSetFormInitFun(IntPtr p,VTextFunFormInit f_unc) {
         vsy_TextFunSetFormInitFun(p, f_unc);
      }

      public static void TextFunSetFormTermFun(IntPtr p,VTextFunFormTerm f_unc) {
         vsy_TextFunSetFormTermFun(p, f_unc);
      }

      public static void TextFunSetFormActionFun(IntPtr p,VTextFunFormAction f_unc) {
         vsy_TextFunSetFormActionFun(p, f_unc);
      }

      public static void TextFunSetHorizontalRuleFun(IntPtr p,VTextFunHorizontalRule f_unc) {
         vsy_TextFunSetHorizontalRuleFun(p, f_unc);
      }

      public static void TextFunSetImageFileFun(IntPtr p,VTextFunImageFile f_unc) {
         vsy_TextFunSetImageFileFun(p, f_unc);
      }

      public static void TextFunSetStringFun(IntPtr p,VTextFunString f_unc) {
         vsy_TextFunSetStringFun(p, f_unc);
      }

      public static void TextFunSetSpaceFun(IntPtr p,VTextFunSpace f_unc) {
         vsy_TextFunSetSpaceFun(p, f_unc);
      }

      public static void TextFunSetTextColorFun(IntPtr p,VTextFunTextColor f_unc) {
         vsy_TextFunSetTextColorFun(p, f_unc);
      }

      public static void TextFunSetTableColorFun(IntPtr p,VTextFunTableColor f_unc) {
         vsy_TextFunSetTableColorFun(p, f_unc);
      }

      public static void TextFunSetBackColorFun(IntPtr p,VTextFunBackColor f_unc) {
         vsy_TextFunSetBackColorFun(p, f_unc);
      }

      public static void TextFunSetBorderWidthFun(IntPtr p,VTextFunBorderWidth f_unc) {
         vsy_TextFunSetBorderWidthFun(p, f_unc);
      }

      public static void TextFunSetTableWidthFun(IntPtr p,VTextFunTableWidth f_unc) {
         vsy_TextFunSetTableWidthFun(p, f_unc);
      }

      public static void TextFunSetColumnAlignFun(IntPtr p,VTextFunColumnAlign f_unc) {
         vsy_TextFunSetColumnAlignFun(p, f_unc);
      }

      public const int VSY_TEXTTEE_MAX = 8;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_TextTeeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextTeeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_TextTeeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextTeeSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TextTeeTextFun(IntPtr p,IntPtr t_extfun);

      public static IntPtr TextTeeBegin() {
         return vsy_TextTeeBegin();
      }

      public static void TextTeeEnd(IntPtr p) {
         vsy_TextTeeEnd(p);
      }

      public static int TextTeeError(IntPtr p) {
         return vsy_TextTeeError(p);
      }

      public static void TextTeeSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vsy_TextTeeSetObject(p, o_bjecttype, o_bject);
      }

      public static void TextTeeTextFun(IntPtr p,IntPtr t_extfun) {
         vsy_TextTeeTextFun(p, t_extfun);
      }

      public const int TREE_FUNCTION_PRINT = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_TreeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_TreeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeAddNode(IntPtr p,int p_key,ref int c_key);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeDelNode(IntPtr p,int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeFirstChild(IntPtr p,int p_key,ref int c_hild);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeNextChild(IntPtr p,int c_key,ref int c_hild);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeSetValue(IntPtr p,int k_ey,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeGetValue(IntPtr p,int k_ey,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreePrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TreeForEach(IntPtr p,Vfunc1 f_unc);

      public static IntPtr TreeBegin() {
         return vsy_TreeBegin();
      }

      public static void TreeEnd(IntPtr p) {
         vsy_TreeEnd(p);
      }

      public static int TreeError(IntPtr p) {
         return vsy_TreeError(p);
      }

      public static void TreeAddNode(IntPtr p,int p_key,ref int c_key) {
         vsy_TreeAddNode(p, p_key,ref c_key);
      }

      public static void TreeDelNode(IntPtr p,int k_ey) {
         vsy_TreeDelNode(p, k_ey);
      }

      public static void TreeFirstChild(IntPtr p,int p_key,ref int c_hild) {
         vsy_TreeFirstChild(p, p_key,ref c_hild);
      }

      public static void TreeNextChild(IntPtr p,int c_key,ref int c_hild) {
         vsy_TreeNextChild(p, c_key,ref c_hild);
      }

      public static void TreeSetValue(IntPtr p,int k_ey,IntPtr v_alue) {
         vsy_TreeSetValue(p, k_ey, v_alue);
      }

      public static void TreeGetValue(IntPtr p,int k_ey,out IntPtr v_alue) {
         vsy_TreeGetValue(p, k_ey,out v_alue);
      }

      public static void TreePrint(IntPtr p) {
         vsy_TreePrint(p);
      }

      public static void TreeForEach(IntPtr p,Vfunc1 f_unc) {
         vsy_TreeForEach(p, f_unc);
      }

      public const int TRICON_MAXLENGTH = 1;
      public const int TRICON_SWAP = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_TriConBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_TriConError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConDef(IntPtr p,int n_umtri);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConInq(IntPtr p,ref int n_umtri);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConAppend(IntPtr p,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConRef(IntPtr p,int i_ndex,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConNum(IntPtr p,ref int n_umtri);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConProcess(IntPtr p,ref int n_umstrip,ref int m_axlength);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConStrip(IntPtr p,int i_strip,ref int n_ix,int [] i_t,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConAdj(IntPtr p,int i_ndex,int [] a_ix,int [] a_ed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_TriConPrint(IntPtr p);

      public static IntPtr TriConBegin() {
         return vsy_TriConBegin();
      }

      public static void TriConEnd(IntPtr p) {
         vsy_TriConEnd(p);
      }

      public static int TriConError(IntPtr p) {
         return vsy_TriConError(p);
      }

      public static void TriConDef(IntPtr p,int n_umtri) {
         vsy_TriConDef(p, n_umtri);
      }

      public static void TriConInq(IntPtr p,ref int n_umtri) {
         vsy_TriConInq(p,ref n_umtri);
      }

      public static void TriConSetParami(IntPtr p,int p_type,int i_param) {
         vsy_TriConSetParami(p, p_type, i_param);
      }

      public static void TriConAppend(IntPtr p,int [] i_x) {
         vsy_TriConAppend(p, i_x);
      }

      public static void TriConRef(IntPtr p,int i_ndex,int [] i_x) {
         vsy_TriConRef(p, i_ndex, i_x);
      }

      public static void TriConNum(IntPtr p,ref int n_umtri) {
         vsy_TriConNum(p,ref n_umtri);
      }

      public static void TriConClear(IntPtr p) {
         vsy_TriConClear(p);
      }

      public static void TriConProcess(IntPtr p,ref int n_umstrip,ref int m_axlength) {
         vsy_TriConProcess(p,ref n_umstrip,ref m_axlength);
      }

      public static void TriConStrip(IntPtr p,int i_strip,ref int n_ix,int [] i_t,int [] i_x) {
         vsy_TriConStrip(p, i_strip,ref n_ix, i_t, i_x);
      }

      public static void TriConAdj(IntPtr p,int i_ndex,int [] a_ix,int [] a_ed) {
         vsy_TriConAdj(p, i_ndex, a_ix, a_ed);
      }

      public static void TriConPrint(IntPtr p) {
         vsy_TriConPrint(p);
      }

      public const int VKI_VERSION_MAJOR = 3;
      public const int VKI_VERSION_MINOR = 1;
      public const int VKI_VERSION_PATCH = 0;

      public const int VERTLOC_TOL = 1;
      public const int VERTLOC_NTOL = 2;
      public const int VERTLOC_NORMALATT = 3;
      public const int VERTLOC_COLORTRANSATT = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_VertLocBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_VertLocError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocDef(IntPtr p,int n_umvert);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocInq(IntPtr p,ref int n_umvert);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocSetParamf(IntPtr p,int p_type,float f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocSetColor(IntPtr p,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocSetTrans(IntPtr p,float t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocSetNormal(IntPtr p,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocInsert(IntPtr p,int i_ndex,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocRef(IntPtr p,int i_ndex,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocNum(IntPtr p,ref int n_umvert);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocColor(IntPtr p,int i_ndex,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocTrans(IntPtr p,int i_ndex,ref float t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocNormal(IntPtr p,int i_ndex,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocMerge(IntPtr p,ref int n_umunique,ref int m_axlocate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocUnique(IntPtr p,int i_unique,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocLowest(IntPtr p,int i_ndex,ref int i_unique,ref int l_owestindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VertLocPrint(IntPtr p);

      public static IntPtr VertLocBegin() {
         return vsy_VertLocBegin();
      }

      public static void VertLocEnd(IntPtr p) {
         vsy_VertLocEnd(p);
      }

      public static int VertLocError(IntPtr p) {
         return vsy_VertLocError(p);
      }

      public static void VertLocDef(IntPtr p,int n_umvert) {
         vsy_VertLocDef(p, n_umvert);
      }

      public static void VertLocInq(IntPtr p,ref int n_umvert) {
         vsy_VertLocInq(p,ref n_umvert);
      }

      public static void VertLocSetParamf(IntPtr p,int p_type,float f_param) {
         vsy_VertLocSetParamf(p, p_type, f_param);
      }

      public static void VertLocSetParami(IntPtr p,int p_type,int i_param) {
         vsy_VertLocSetParami(p, p_type, i_param);
      }

      public static void VertLocSetColor(IntPtr p,float [] c_) {
         vsy_VertLocSetColor(p, c_);
      }

      public static void VertLocSetTrans(IntPtr p,float t_) {
         vsy_VertLocSetTrans(p, t_);
      }

      public static void VertLocSetNormal(IntPtr p,float [] v_) {
         vsy_VertLocSetNormal(p, v_);
      }

      public static void VertLocInsert(IntPtr p,int i_ndex,float [] x_) {
         vsy_VertLocInsert(p, i_ndex, x_);
      }

      public static void VertLocRef(IntPtr p,int i_ndex,float [] x_) {
         vsy_VertLocRef(p, i_ndex, x_);
      }

      public static void VertLocNum(IntPtr p,ref int n_umvert) {
         vsy_VertLocNum(p,ref n_umvert);
      }

      public static void VertLocColor(IntPtr p,int i_ndex,float [] c_) {
         vsy_VertLocColor(p, i_ndex, c_);
      }

      public static void VertLocTrans(IntPtr p,int i_ndex,ref float t_) {
         vsy_VertLocTrans(p, i_ndex,ref t_);
      }

      public static void VertLocNormal(IntPtr p,int i_ndex,float [] v_) {
         vsy_VertLocNormal(p, i_ndex, v_);
      }

      public static void VertLocClear(IntPtr p) {
         vsy_VertLocClear(p);
      }

      public static void VertLocMerge(IntPtr p,ref int n_umunique,ref int m_axlocate) {
         vsy_VertLocMerge(p,ref n_umunique,ref m_axlocate);
      }

      public static void VertLocUnique(IntPtr p,int i_unique,ref int n_ix,int [] i_x) {
         vsy_VertLocUnique(p, i_unique,ref n_ix, i_x);
      }

      public static void VertLocLowest(IntPtr p,int i_ndex,ref int i_unique,ref int l_owestindex) {
         vsy_VertLocLowest(p, i_ndex,ref i_unique,ref l_owestindex);
      }

      public static void VertLocPrint(IntPtr p) {
         vsy_VertLocPrint(p);
      }

      public const int VHASHTABLE_HASH_FUNCTION_LEGACY = 0;
      public const int VHASHTABLE_HASH_FUNCTION_FNV1A = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_VHashTableBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_VHashTableError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableDef(IntPtr p,int s_ize,int n_umobj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableSetHashFunction(IntPtr p,int h_ashFunctionType);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableInq(IntPtr p,ref int s_ize,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableCount(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableInsert(IntPtr p,ref int k_ey,IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableLookup(IntPtr p,ref int k_ey,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableRemove(IntPtr p,ref int k_ey);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableNextIter(IntPtr p,int [] k_ey,out IntPtr v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTableForEach(IntPtr p,Vfunc1 f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VHashTablePrint(IntPtr p);

      public static IntPtr VHashTableBegin() {
         return vsy_VHashTableBegin();
      }

      public static void VHashTableEnd(IntPtr p) {
         vsy_VHashTableEnd(p);
      }

      public static int VHashTableError(IntPtr p) {
         return vsy_VHashTableError(p);
      }

      public static void VHashTableDef(IntPtr p,int s_ize,int n_umobj) {
         vsy_VHashTableDef(p, s_ize, n_umobj);
      }

      public static void VHashTableSetHashFunction(IntPtr p,int h_ashFunctionType) {
         vsy_VHashTableSetHashFunction(p, h_ashFunctionType);
      }

      public static void VHashTableInq(IntPtr p,ref int s_ize,ref int n_ument) {
         vsy_VHashTableInq(p,ref s_ize,ref n_ument);
      }

      public static void VHashTableCount(IntPtr p,ref int n_um) {
         vsy_VHashTableCount(p,ref n_um);
      }

      public static void VHashTableInsert(IntPtr p,ref int k_ey,IntPtr v_alue) {
         vsy_VHashTableInsert(p,ref k_ey, v_alue);
      }

      public static void VHashTableLookup(IntPtr p,ref int k_ey,out IntPtr v_alue) {
         vsy_VHashTableLookup(p,ref k_ey,out v_alue);
      }

      public static void VHashTableRemove(IntPtr p,ref int k_ey) {
         vsy_VHashTableRemove(p,ref k_ey);
      }

      public static void VHashTableClear(IntPtr p) {
         vsy_VHashTableClear(p);
      }

      public static void VHashTableInitIter(IntPtr p) {
         vsy_VHashTableInitIter(p);
      }

      public static void VHashTableNextIter(IntPtr p,int [] k_ey,out IntPtr v_alue) {
         vsy_VHashTableNextIter(p, k_ey,out v_alue);
      }

      public static void VHashTableForEach(IntPtr p,Vfunc1 f_unction) {
         vsy_VHashTableForEach(p, f_unction);
      }

      public static void VHashTablePrint(IntPtr p) {
         vsy_VHashTablePrint(p);
      }

      public const int VSOCKET_NONE = 0;
      public const int VSOCKET_CLIENT = 1;
      public const int VSOCKET_SERVER = 2;
      public const int VSOCKET_WAITTIME = 1;
      public const int VSOCKET_DEBUG = 2;
      public const int VSOCKET_SCOPE = 3;
      public const int VSOCKET_MAXCONNECTIONS = 4;
      public const int VSOCKET_LOCAL = 1;
      public const int VSOCKET_NET = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_VSocketBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_VSocketError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketDef(IntPtr p,int t_ype,int s_cope);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketSetNet(IntPtr p,ushort p_ortnumber,StringBuilder s_erverhost);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketSetLocal(IntPtr p,StringBuilder l_ocalfile);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketInq(IntPtr p,ref int t_ype,ref int s_cope);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketOpen(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketAccept(IntPtr p,ref int c_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketClose(IntPtr p,int c_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketRead(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketReadString(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer,ref int s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketWrite(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketWriteString(IntPtr p,int c_id,StringBuilder b_uffer);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_VSocketSetParami(IntPtr p,int t_ype,int i_param);

      public static IntPtr VSocketBegin() {
         return vsy_VSocketBegin();
      }

      public static void VSocketEnd(IntPtr p) {
         vsy_VSocketEnd(p);
      }

      public static int VSocketError(IntPtr p) {
         return vsy_VSocketError(p);
      }

      public static void VSocketDef(IntPtr p,int t_ype,int s_cope) {
         vsy_VSocketDef(p, t_ype, s_cope);
      }

      public static void VSocketSetNet(IntPtr p,ushort p_ortnumber,StringBuilder s_erverhost) {
         vsy_VSocketSetNet(p, p_ortnumber, s_erverhost);
      }

      public static void VSocketSetLocal(IntPtr p,StringBuilder l_ocalfile) {
         vsy_VSocketSetLocal(p, l_ocalfile);
      }

      public static void VSocketInq(IntPtr p,ref int t_ype,ref int s_cope) {
         vsy_VSocketInq(p,ref t_ype,ref s_cope);
      }

      public static void VSocketOpen(IntPtr p) {
         vsy_VSocketOpen(p);
      }

      public static void VSocketAccept(IntPtr p,ref int c_id) {
         vsy_VSocketAccept(p,ref c_id);
      }

      public static void VSocketClose(IntPtr p,int c_id) {
         vsy_VSocketClose(p, c_id);
      }

      public static void VSocketRead(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer) {
         vsy_VSocketRead(p, c_id, b_uflen, b_uffer);
      }

      public static void VSocketReadString(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer,ref int s_ize) {
         vsy_VSocketReadString(p, c_id, b_uflen, b_uffer,ref s_ize);
      }

      public static void VSocketWrite(IntPtr p,int c_id,int b_uflen,StringBuilder b_uffer) {
         vsy_VSocketWrite(p, c_id, b_uflen, b_uffer);
      }

      public static void VSocketWriteString(IntPtr p,int c_id,StringBuilder b_uffer) {
         vsy_VSocketWriteString(p, c_id, b_uffer);
      }

      public static void VSocketSetParami(IntPtr p,int t_ype,int i_param) {
         vsy_VSocketSetParami(p, t_ype, i_param);
      }

      public const int ZMEM_BUFFER = 1;
      public const int ZMEM_FINISH = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vsy_ZMemBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ZMemEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vsy_ZMemError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ZMemCompress(IntPtr p,int m_ode,long n_in,StringBuilder i_n,long n_out,StringBuilder o_ut,ref long l_ength,ref int r_epeat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vsy_ZMemUncompress(IntPtr p,int m_ode,long n_in,StringBuilder i_n,long n_out,StringBuilder o_ut,ref long l_ength,ref int r_epeat);

      public static IntPtr ZMemBegin() {
         return vsy_ZMemBegin();
      }

      public static void ZMemEnd(IntPtr p) {
         vsy_ZMemEnd(p);
      }

      public static int ZMemError(IntPtr p) {
         return vsy_ZMemError(p);
      }

      public static void ZMemCompress(IntPtr p,int m_ode,long n_in,StringBuilder i_n,long n_out,StringBuilder o_ut,ref long l_ength,ref int r_epeat) {
         vsy_ZMemCompress(p, m_ode, n_in, i_n, n_out, o_ut,ref l_ength,ref r_epeat);
      }

      public static void ZMemUncompress(IntPtr p,int m_ode,long n_in,StringBuilder i_n,long n_out,StringBuilder o_ut,ref long l_ength,ref int r_epeat) {
         vsy_ZMemUncompress(p, m_ode, n_in, i_n, n_out, o_ut,ref l_ength,ref r_epeat);
      }

   }
}
