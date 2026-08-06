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
   public delegate int VConnectMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VDataIntFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNumber(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunTopology(IntPtr a0,int a1,ref int a2,ref int a3,ref int a4,ref int a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemNode(IntPtr a0,int a1,ref int a2,int [] a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunMaxElemNode(IntPtr a0,ref int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunCoords(IntPtr a0,int a1,int [] a2,float [] a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNodeAssoc(IntPtr a0,int a1,int a2,int [] a3,int [] a4);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemAssoc(IntPtr a0,int a1,int a2,int [] a3,int [] a4);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemNum(IntPtr a0,int a1,int a2,ref int a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemCon(IntPtr a0,int a1,int a2,int a3,ref int a4,int [] a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemTopo(IntPtr a0,int a1,int a2,int a3,ref int a4,ref int a5,ref int a6);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemAdj(IntPtr a0,int a1,int a2,int a3,ref int a4,int [] a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunMaxNodeElem(IntPtr a0,ref int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNodeElem(IntPtr a0,int a1,ref int a2,int [] a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunExtent(IntPtr a0,IntPtr a1,float [] a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemCnn(IntPtr a0,int a1,int a2,int a3,ref int a4,int [] a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNodeAdj(IntPtr a0,int a1,int [] a2,ref int a3,int [] a4);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunCoordsdv(IntPtr a0,int a1,int [] a2,double [] a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunLngElemNode(IntPtr a0,ref long a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate int VGridFunError(IntPtr a0);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNumElemNode(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNumNodeElem(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemCorn(IntPtr a0,int a1,int a2,int a3,ref int a4,int [] a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunIndElemNode(IntPtr a0,int a1,ref long a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunDimension(IntPtr a0,ref int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunExtentdv(IntPtr a0,IntPtr a1,double [] a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunElemEntAssoc(IntPtr a0,int a1,int a2,int a3,int a4,ref int a5);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNodeNode(IntPtr a0,int a1,ref int a2,int [] a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNumEIP(IntPtr a0,int a1,ref int a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunLngEIP(IntPtr a0,ref long a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunIndEIP(IntPtr a0,int a1,ref long a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunPartName(IntPtr a0,int a1,StringBuilder a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunNumPartName(IntPtr a0,ref int a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VGridFunIthPartName(IntPtr a0,int a1,ref int a2,StringBuilder a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTriMeshDebugFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTriMeshMonitorFunc(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTriMeshSizingFunc(IntPtr a0,IntPtr a1,[MarshalAs(UnmanagedType.LPArray, SizeConst = 3)] double [] a2,ref double a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VTriMeshASizingFunc(IntPtr a0,IntPtr a1,[MarshalAs(UnmanagedType.LPArray, SizeConst = 3)] double [] a2,double a3);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterWriteState(IntPtr a0,IntPtr a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterWriteRedMat(IntPtr a0,IntPtr a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterWriteHistory(IntPtr a0,IntPtr a1,IntPtr a2);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterWriteModel(IntPtr a0,IntPtr a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterGetFilePath(IntPtr a0,StringBuilder a1);

   [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
   public delegate void VFuncWriterGetFileType(IntPtr a0,ref int a1);

   public class vis {

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ASurfBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ASurfError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfInq(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetPoint(IntPtr p,int i_d,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetPointdv(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetPoint(IntPtr p,int i_d,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetPointdv(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfNumPoints(IntPtr p,ref int n_umpnt);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegment(IntPtr p,int i_d,int t_ype,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegment(IntPtr p,int i_d,ref int t_ype,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfNumSegments(IntPtr p,ref int n_umseg);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentRule(IntPtr p,float [] a_,float [] b_,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentRuledv(IntPtr p,double [] a_,double [] b_,double [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentRule(IntPtr p,float [] a_,float [] b_,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentRuledv(IntPtr p,double [] a_,double [] b_,double [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentRev(IntPtr p,float [] a_,float [] b_,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentRevdv(IntPtr p,double [] a_,double [] b_,double [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentRev(IntPtr p,float [] a_,float [] b_,float [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentRevdv(IntPtr p,double [] a_,double [] b_,double [] c_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentFillet(IntPtr p,float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSegmentFilletdv(IntPtr p,double r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentFillet(IntPtr p,ref float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSegmentFilletdv(IntPtr p,ref double r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetPlane(IntPtr p,float [] a_,float [] b_,float [] c_,float l_ength,float w_idth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetPlanedv(IntPtr p,double [] a_,double [] b_,double [] c_,double l_ength,double w_idth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetPlane(IntPtr p,float [] a_,float [] b_,float [] c_,ref float l_ength,ref float w_idth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetPlanedv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double l_ength,ref double w_idth);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetBox(IntPtr p,float [] a_,float [] b_,float [] c_,float l_ength,float w_idth,float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetBoxdv(IntPtr p,double [] a_,double [] b_,double [] c_,double l_ength,double w_idth,double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetBox(IntPtr p,float [] a_,float [] b_,float [] c_,ref float l_ength,ref float w_idth,ref float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetBoxdv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double l_ength,ref double w_idth,ref double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetCylinder(IntPtr p,float [] a_,float [] b_,float [] c_,float r_adius,float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetCylinderdv(IntPtr p,double [] a_,double [] b_,double [] c_,double r_,double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetCylinder(IntPtr p,float [] a_,float [] b_,float [] c_,ref float r_,ref float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetCylinderdv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double r_,ref double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetCone(IntPtr p,float [] a_,float [] b_,float [] c_,float r_1,float r_2,float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetConedv(IntPtr p,double [] a_,double [] b_,double [] c_,double r_1,double r_2,double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetCone(IntPtr p,float [] a_,float [] b_,float [] c_,ref float r_1,ref float r_2,ref float h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetConedv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double r_1,ref double r_2,ref double h_eight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSphere(IntPtr p,float [] c_,float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetSpheredv(IntPtr p,double [] c_,double r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSphere(IntPtr p,float [] c_,ref float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetSpheredv(IntPtr p,double [] c_,ref double r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetNURBS(IntPtr p,int i_d,int t_ype,int n_ptu,int n_ordu,int n_ptv,int n_ordv,int [] i_x,float [] h_omo,float [] k_nots,int n_trim,int [] t_rimlist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetNURBSdv(IntPtr p,int i_d,int t_ype,int n_ptu,int n_ordu,int n_ptv,int n_ordv,int [] i_x,double [] h_omos,double [] k_nots,int n_trim,int [] t_rimlist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfNumNURBS(IntPtr p,ref int n_umnurbs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfMaxNURBSOrder(IntPtr p,ref int m_axord);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetNURBSNum(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,ref int n_trim);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetNURBS(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,int [] i_x,float [] h_omos,float [] k_nots,ref int n_trim,int [] t_rimlist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetNURBSdv(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,int [] i_x,double [] h_omos,double [] k_nots,ref int n_trim,int [] t_rimlist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetNURBSTrim(IntPtr p,int i_d,int n_pts,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfNumNURBSTrim(IntPtr p,ref int n_umtrim);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetNURBSTrimNum(IntPtr p,int i_d,ref int n_pts);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetNURBSTrim(IntPtr p,int i_d,ref int n_pts,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfSetFacet(IntPtr p,int i_d,int t_ype,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfNumFacets(IntPtr p,ref int n_umfacet);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ASurfGetFacet(IntPtr p,int i_d,ref int t_ype,int [] i_x);

      public static IntPtr ASurfBegin() {
         return vis_ASurfBegin();
      }

      public static void ASurfEnd(IntPtr p) {
         vis_ASurfEnd(p);
      }

      public static int ASurfError(IntPtr p) {
         return vis_ASurfError(p);
      }

      public static void ASurfDef(IntPtr p,int t_ype) {
         vis_ASurfDef(p, t_ype);
      }

      public static void ASurfInq(IntPtr p,ref int t_ype) {
         vis_ASurfInq(p,ref t_ype);
      }

      public static void ASurfSetName(IntPtr p,StringBuilder n_ame) {
         vis_ASurfSetName(p, n_ame);
      }

      public static void ASurfGetName(IntPtr p,StringBuilder n_ame) {
         vis_ASurfGetName(p, n_ame);
      }

      public static void ASurfSetPoint(IntPtr p,int i_d,float [] x_) {
         vis_ASurfSetPoint(p, i_d, x_);
      }

      public static void ASurfSetPointdv(IntPtr p,int i_d,double [] x_) {
         vis_ASurfSetPointdv(p, i_d, x_);
      }

      public static void ASurfGetPoint(IntPtr p,int i_d,float [] x_) {
         vis_ASurfGetPoint(p, i_d, x_);
      }

      public static void ASurfGetPointdv(IntPtr p,int i_d,double [] x_) {
         vis_ASurfGetPointdv(p, i_d, x_);
      }

      public static void ASurfNumPoints(IntPtr p,ref int n_umpnt) {
         vis_ASurfNumPoints(p,ref n_umpnt);
      }

      public static void ASurfSetSegment(IntPtr p,int i_d,int t_ype,int [] i_x) {
         vis_ASurfSetSegment(p, i_d, t_ype, i_x);
      }

      public static void ASurfGetSegment(IntPtr p,int i_d,ref int t_ype,int [] i_x) {
         vis_ASurfGetSegment(p, i_d,ref t_ype, i_x);
      }

      public static void ASurfNumSegments(IntPtr p,ref int n_umseg) {
         vis_ASurfNumSegments(p,ref n_umseg);
      }

      public static void ASurfSetSegmentRule(IntPtr p,float [] a_,float [] b_,float [] c_) {
         vis_ASurfSetSegmentRule(p, a_, b_, c_);
      }

      public static void ASurfSetSegmentRuledv(IntPtr p,double [] a_,double [] b_,double [] c_) {
         vis_ASurfSetSegmentRuledv(p, a_, b_, c_);
      }

      public static void ASurfGetSegmentRule(IntPtr p,float [] a_,float [] b_,float [] c_) {
         vis_ASurfGetSegmentRule(p, a_, b_, c_);
      }

      public static void ASurfGetSegmentRuledv(IntPtr p,double [] a_,double [] b_,double [] c_) {
         vis_ASurfGetSegmentRuledv(p, a_, b_, c_);
      }

      public static void ASurfSetSegmentRev(IntPtr p,float [] a_,float [] b_,float [] c_) {
         vis_ASurfSetSegmentRev(p, a_, b_, c_);
      }

      public static void ASurfSetSegmentRevdv(IntPtr p,double [] a_,double [] b_,double [] c_) {
         vis_ASurfSetSegmentRevdv(p, a_, b_, c_);
      }

      public static void ASurfGetSegmentRev(IntPtr p,float [] a_,float [] b_,float [] c_) {
         vis_ASurfGetSegmentRev(p, a_, b_, c_);
      }

      public static void ASurfGetSegmentRevdv(IntPtr p,double [] a_,double [] b_,double [] c_) {
         vis_ASurfGetSegmentRevdv(p, a_, b_, c_);
      }

      public static void ASurfSetSegmentFillet(IntPtr p,float r_) {
         vis_ASurfSetSegmentFillet(p, r_);
      }

      public static void ASurfSetSegmentFilletdv(IntPtr p,double r_) {
         vis_ASurfSetSegmentFilletdv(p, r_);
      }

      public static void ASurfGetSegmentFillet(IntPtr p,ref float r_) {
         vis_ASurfGetSegmentFillet(p,ref r_);
      }

      public static void ASurfGetSegmentFilletdv(IntPtr p,ref double r_) {
         vis_ASurfGetSegmentFilletdv(p,ref r_);
      }

      public static void ASurfSetPlane(IntPtr p,float [] a_,float [] b_,float [] c_,float l_ength,float w_idth) {
         vis_ASurfSetPlane(p, a_, b_, c_, l_ength, w_idth);
      }

      public static void ASurfSetPlanedv(IntPtr p,double [] a_,double [] b_,double [] c_,double l_ength,double w_idth) {
         vis_ASurfSetPlanedv(p, a_, b_, c_, l_ength, w_idth);
      }

      public static void ASurfGetPlane(IntPtr p,float [] a_,float [] b_,float [] c_,ref float l_ength,ref float w_idth) {
         vis_ASurfGetPlane(p, a_, b_, c_,ref l_ength,ref w_idth);
      }

      public static void ASurfGetPlanedv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double l_ength,ref double w_idth) {
         vis_ASurfGetPlanedv(p, a_, b_, c_,ref l_ength,ref w_idth);
      }

      public static void ASurfSetBox(IntPtr p,float [] a_,float [] b_,float [] c_,float l_ength,float w_idth,float h_eight) {
         vis_ASurfSetBox(p, a_, b_, c_, l_ength, w_idth, h_eight);
      }

      public static void ASurfSetBoxdv(IntPtr p,double [] a_,double [] b_,double [] c_,double l_ength,double w_idth,double h_eight) {
         vis_ASurfSetBoxdv(p, a_, b_, c_, l_ength, w_idth, h_eight);
      }

      public static void ASurfGetBox(IntPtr p,float [] a_,float [] b_,float [] c_,ref float l_ength,ref float w_idth,ref float h_eight) {
         vis_ASurfGetBox(p, a_, b_, c_,ref l_ength,ref w_idth,ref h_eight);
      }

      public static void ASurfGetBoxdv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double l_ength,ref double w_idth,ref double h_eight) {
         vis_ASurfGetBoxdv(p, a_, b_, c_,ref l_ength,ref w_idth,ref h_eight);
      }

      public static void ASurfSetCylinder(IntPtr p,float [] a_,float [] b_,float [] c_,float r_adius,float h_eight) {
         vis_ASurfSetCylinder(p, a_, b_, c_, r_adius, h_eight);
      }

      public static void ASurfSetCylinderdv(IntPtr p,double [] a_,double [] b_,double [] c_,double r_,double h_eight) {
         vis_ASurfSetCylinderdv(p, a_, b_, c_, r_, h_eight);
      }

      public static void ASurfGetCylinder(IntPtr p,float [] a_,float [] b_,float [] c_,ref float r_,ref float h_eight) {
         vis_ASurfGetCylinder(p, a_, b_, c_,ref r_,ref h_eight);
      }

      public static void ASurfGetCylinderdv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double r_,ref double h_eight) {
         vis_ASurfGetCylinderdv(p, a_, b_, c_,ref r_,ref h_eight);
      }

      public static void ASurfSetCone(IntPtr p,float [] a_,float [] b_,float [] c_,float r_1,float r_2,float h_eight) {
         vis_ASurfSetCone(p, a_, b_, c_, r_1, r_2, h_eight);
      }

      public static void ASurfSetConedv(IntPtr p,double [] a_,double [] b_,double [] c_,double r_1,double r_2,double h_eight) {
         vis_ASurfSetConedv(p, a_, b_, c_, r_1, r_2, h_eight);
      }

      public static void ASurfGetCone(IntPtr p,float [] a_,float [] b_,float [] c_,ref float r_1,ref float r_2,ref float h_eight) {
         vis_ASurfGetCone(p, a_, b_, c_,ref r_1,ref r_2,ref h_eight);
      }

      public static void ASurfGetConedv(IntPtr p,double [] a_,double [] b_,double [] c_,ref double r_1,ref double r_2,ref double h_eight) {
         vis_ASurfGetConedv(p, a_, b_, c_,ref r_1,ref r_2,ref h_eight);
      }

      public static void ASurfSetSphere(IntPtr p,float [] c_,float r_) {
         vis_ASurfSetSphere(p, c_, r_);
      }

      public static void ASurfSetSpheredv(IntPtr p,double [] c_,double r_) {
         vis_ASurfSetSpheredv(p, c_, r_);
      }

      public static void ASurfGetSphere(IntPtr p,float [] c_,ref float r_) {
         vis_ASurfGetSphere(p, c_,ref r_);
      }

      public static void ASurfGetSpheredv(IntPtr p,double [] c_,ref double r_) {
         vis_ASurfGetSpheredv(p, c_,ref r_);
      }

      public static void ASurfPrint(IntPtr p) {
         vis_ASurfPrint(p);
      }

      public static void ASurfSetNURBS(IntPtr p,int i_d,int t_ype,int n_ptu,int n_ordu,int n_ptv,int n_ordv,int [] i_x,float [] h_omo,float [] k_nots,int n_trim,int [] t_rimlist) {
         vis_ASurfSetNURBS(p, i_d, t_ype, n_ptu, n_ordu, n_ptv, n_ordv, i_x, h_omo, k_nots, n_trim, t_rimlist);
      }

      public static void ASurfSetNURBSdv(IntPtr p,int i_d,int t_ype,int n_ptu,int n_ordu,int n_ptv,int n_ordv,int [] i_x,double [] h_omos,double [] k_nots,int n_trim,int [] t_rimlist) {
         vis_ASurfSetNURBSdv(p, i_d, t_ype, n_ptu, n_ordu, n_ptv, n_ordv, i_x, h_omos, k_nots, n_trim, t_rimlist);
      }

      public static void ASurfNumNURBS(IntPtr p,ref int n_umnurbs) {
         vis_ASurfNumNURBS(p,ref n_umnurbs);
      }

      public static void ASurfMaxNURBSOrder(IntPtr p,ref int m_axord) {
         vis_ASurfMaxNURBSOrder(p,ref m_axord);
      }

      public static void ASurfGetNURBSNum(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,ref int n_trim) {
         vis_ASurfGetNURBSNum(p, i_d,ref t_ype,ref n_ptu,ref n_ordu,ref n_ptv,ref n_ordv,ref n_trim);
      }

      public static void ASurfGetNURBS(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,int [] i_x,float [] h_omos,float [] k_nots,ref int n_trim,int [] t_rimlist) {
         vis_ASurfGetNURBS(p, i_d,ref t_ype,ref n_ptu,ref n_ordu,ref n_ptv,ref n_ordv, i_x, h_omos, k_nots,ref n_trim, t_rimlist);
      }

      public static void ASurfGetNURBSdv(IntPtr p,int i_d,ref int t_ype,ref int n_ptu,ref int n_ordu,ref int n_ptv,ref int n_ordv,int [] i_x,double [] h_omos,double [] k_nots,ref int n_trim,int [] t_rimlist) {
         vis_ASurfGetNURBSdv(p, i_d,ref t_ype,ref n_ptu,ref n_ordu,ref n_ptv,ref n_ordv, i_x, h_omos, k_nots,ref n_trim, t_rimlist);
      }

      public static void ASurfSetNURBSTrim(IntPtr p,int i_d,int n_pts,int [] i_x) {
         vis_ASurfSetNURBSTrim(p, i_d, n_pts, i_x);
      }

      public static void ASurfNumNURBSTrim(IntPtr p,ref int n_umtrim) {
         vis_ASurfNumNURBSTrim(p,ref n_umtrim);
      }

      public static void ASurfGetNURBSTrimNum(IntPtr p,int i_d,ref int n_pts) {
         vis_ASurfGetNURBSTrimNum(p, i_d,ref n_pts);
      }

      public static void ASurfGetNURBSTrim(IntPtr p,int i_d,ref int n_pts,int [] i_x) {
         vis_ASurfGetNURBSTrim(p, i_d,ref n_pts, i_x);
      }

      public static void ASurfSetFacet(IntPtr p,int i_d,int t_ype,int [] i_x) {
         vis_ASurfSetFacet(p, i_d, t_ype, i_x);
      }

      public static void ASurfNumFacets(IntPtr p,ref int n_umfacet) {
         vis_ASurfNumFacets(p,ref n_umfacet);
      }

      public static void ASurfGetFacet(IntPtr p,int i_d,ref int t_ype,int [] i_x) {
         vis_ASurfGetFacet(p, i_d,ref t_ype, i_x);
      }

      public const int ASURF_SEGMENT = 1;
      public const int ASURF_SEGMENT_RULE = 2;
      public const int ASURF_SEGMENT_REV = 3;
      public const int ASURF_PLANE = 4;
      public const int ASURF_BOX = 5;
      public const int ASURF_SPHERE = 6;
      public const int ASURF_CYLINDER = 7;
      public const int ASURF_CONE = 8;
      public const int ASURF_FACET = 9;
      public const int ASURF_NURBS = 10;
      public const int ASURF_SEG_LINE = 1;
      public const int ASURF_SEG_ARC = 2;
      public const int ASURF_SEG_PARAB = 3;
      public const int ASURF_FACET_TRI = 1;
      public const int ASURF_FACET_PARATRI = 2;
      public const int ASURF_FACET_QUAD = 3;
      public const int ASURF_FACET_PARAQUAD = 4;
      public const int ASURF_NURBS_LINE = 1;
      public const int ASURF_NURBS_SURF = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_BandOptBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BandOptEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_BandOptError(IntPtr p);

      public static IntPtr BandOptBegin() {
         return vis_BandOptBegin();
      }

      public static void BandOptEnd(IntPtr p) {
         vis_BandOptEnd(p);
      }

      public static int BandOptError(IntPtr p) {
         return vis_BandOptError(p);
      }

      public const int BEAMSECT_MAXPROPS = 16;
      public const int BEAMSECT_MAXDIMES = 14;
      public const int BEAMSECT_MAXFILLETS = 10;
      public const int BEAMSECT_PROPS = 0;
      public const int BEAMSECT_GEOMETRY = 1;
      public const int BEAMSECT_BOX = 2;
      public const int BEAMSECT_ANGLE = 3;
      public const int BEAMSECT_IBEAM = 4;
      public const int BEAMSECT_CIRCLE = 5;
      public const int BEAMSECT_TUBE = 6;
      public const int BEAMSECT_PANEL = 7;
      public const int BEAMSECT_RECTANGLE = 8;
      public const int BEAMSECT_TRAPEZOID = 9;
      public const int BEAMSECT_HEXAGON = 10;
      public const int BEAMSECT_TEE = 11;
      public const int BEAMSECT_ZEE = 12;
      public const int BEAMSECT_CHANNEL = 13;
      public const int BEAMSECT_SECTOR = 14;
      public const int BEAMSECT_ELLIPSE = 15;
      public const int BEAMSECT_HAT = 16;
      public const int BEAMSECT_CROSS = 17;
      public const int BEAMSECT_DBOX = 18;
      public const int BEAMSECT_HAT1 = 19;
      public const int BEAMSECT_QUAD = 20;
      public const int BEAMSECT_HATG = 21;
      public const int BEAMSECT_SOLIDHEXA = 22;
      public const int BEAMSECT_RECTTUBE = 23;
      public const int BEAMSECT_HATT = 24;
      public const int BEAMSECT_SEGMENTS = 25;
      public const int BEAMSECT_MAXSECTIONS = 26;
      public const int BEAMSECT_TORSION = 0;
      public const int BEAMSECT_FLEXURE1 = 1;
      public const int BEAMSECT_FLEXURE2 = 2;
      public const int BEAMSECT_QUALITYGRID = 0;
      public const int BEAMSECT_AXESBASIC = 1;
      public const int BEAMSECT_AXESPRINCIPAL = 2;
      public const int BEAMSECT_SHEARCENTER = 3;
      public const int BEAMSECT_CENTROID = 4;
      public const int BEAMSECT_POLYLINE = 5;
      public const int BEAMSECT_EDGELENGTH = 6;
      public const int BEAMSECT_TRIMESHWRITE = 8;
      public const int BEAMSECT_MESHSMOOTH = 9;
      public const int BEAMSECT_ERRORTOL = 10;
      public const int BEAMSECT_MAXERRITER = 11;
      public const int BEAMSECT_REFINE = 12;
      public const int BEAMSECT_NUMELEMENTS = 13;
      public const int BEAMSECT_NASTRANWRITE = 14;
      public const int BEAMSECT_VABS = 15;
      public const int BEAMSECT_MAXELEMENTS = 16;
      public const int BEAMSECT_TRIMESHFILETYPE = 17;
      public const int BEAMSECT_CENTROID_NONE = 0;
      public const int BEAMSECT_CENTROID_CIRCLE = 1;
      public const int BEAMSECT_CENTROID_SPHERE = 2;
      public const int BEAMSECT_ERROR = 0;
      public const int BEAMSECT_EDGELEN = 1;
      public const int BEAMSECT_NUMITER = 2;
      public const int BEAMSECT_PROP_A = 0;
      public const int BEAMSECT_PROP_IYY = 1;
      public const int BEAMSECT_PROP_IZZ = 2;
      public const int BEAMSECT_PROP_IYZ = 3;
      public const int BEAMSECT_PROP_ANG = 4;
      public const int BEAMSECT_PROP_J = 5;
      public const int BEAMSECT_PROP_KSY = 6;
      public const int BEAMSECT_PROP_KSZ = 7;
      public const int BEAMSECT_PROP_KSYZ = 8;
      public const int BEAMSECT_PROP_EY = 9;
      public const int BEAMSECT_PROP_EZ = 10;
      public const int BEAMSECT_PROP_DSY = 11;
      public const int BEAMSECT_PROP_DSZ = 12;
      public const int BEAMSECT_PROP_CW = 13;
      public const int BEAMSECT_PROP_NEUTRALY = 14;
      public const int BEAMSECT_PROP_NEUTRALZ = 15;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_BeamSectCalculatorBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_BeamSectCalculatorError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetPointdv(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetDimensionsdv(IntPtr p,double [] d_imes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetReflect(IntPtr p,int r_eflecty,int r_eflectz);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetLoop(IntPtr p,int i_d,int m_id,int n_pts,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetRotatedv(IntPtr p,double a_ngle);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorProps(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetPropsdv(IntPtr p,double [] p_rops,double [] d_mat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorGetPropsdv(IntPtr p,double [] p_rops,double [] d_mat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorFreeGeometry(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetElasPropdv(IntPtr p,int m_id,int t_ype,double [] e_las);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetParamd(IntPtr p,int p_type,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_BeamSectCalculatorGetNum(IntPtr p,ref int n_points,ref int n_loops,ref int n_polylines,ref int n_tris,ref int n_qualpnts,ref int n_qualtris);

      public static IntPtr BeamSectCalculatorBegin() {
         return vis_BeamSectCalculatorBegin();
      }

      public static void BeamSectCalculatorEnd(IntPtr p) {
         vis_BeamSectCalculatorEnd(p);
      }

      public static int BeamSectCalculatorError(IntPtr p) {
         return vis_BeamSectCalculatorError(p);
      }

      public static void BeamSectCalculatorDef(IntPtr p,int t_ype) {
         vis_BeamSectCalculatorDef(p, t_ype);
      }

      public static void BeamSectCalculatorSetPointdv(IntPtr p,int i_d,double [] x_) {
         vis_BeamSectCalculatorSetPointdv(p, i_d, x_);
      }

      public static void BeamSectCalculatorSetDimensionsdv(IntPtr p,double [] d_imes) {
         vis_BeamSectCalculatorSetDimensionsdv(p, d_imes);
      }

      public static void BeamSectCalculatorSetReflect(IntPtr p,int r_eflecty,int r_eflectz) {
         vis_BeamSectCalculatorSetReflect(p, r_eflecty, r_eflectz);
      }

      public static void BeamSectCalculatorSetLoop(IntPtr p,int i_d,int m_id,int n_pts,int [] i_x) {
         vis_BeamSectCalculatorSetLoop(p, i_d, m_id, n_pts, i_x);
      }

      public static void BeamSectCalculatorSetRotatedv(IntPtr p,double a_ngle) {
         vis_BeamSectCalculatorSetRotatedv(p, a_ngle);
      }

      public static void BeamSectCalculatorProps(IntPtr p) {
         vis_BeamSectCalculatorProps(p);
      }

      public static void BeamSectCalculatorSetPropsdv(IntPtr p,double [] p_rops,double [] d_mat) {
         vis_BeamSectCalculatorSetPropsdv(p, p_rops, d_mat);
      }

      public static void BeamSectCalculatorGetPropsdv(IntPtr p,double [] p_rops,double [] d_mat) {
         vis_BeamSectCalculatorGetPropsdv(p, p_rops, d_mat);
      }

      public static void BeamSectCalculatorFreeGeometry(IntPtr p) {
         vis_BeamSectCalculatorFreeGeometry(p);
      }

      public static void BeamSectCalculatorSetElasPropdv(IntPtr p,int m_id,int t_ype,double [] e_las) {
         vis_BeamSectCalculatorSetElasPropdv(p, m_id, t_ype, e_las);
      }

      public static void BeamSectCalculatorSetParamd(IntPtr p,int p_type,double d_param) {
         vis_BeamSectCalculatorSetParamd(p, p_type, d_param);
      }

      public static void BeamSectCalculatorSetParami(IntPtr p,int p_type,int i_param) {
         vis_BeamSectCalculatorSetParami(p, p_type, i_param);
      }

      public static void BeamSectCalculatorGetNum(IntPtr p,ref int n_points,ref int n_loops,ref int n_polylines,ref int n_tris,ref int n_qualpnts,ref int n_qualtris) {
         vis_BeamSectCalculatorGetNum(p,ref n_points,ref n_loops,ref n_polylines,ref n_tris,ref n_qualpnts,ref n_qualtris);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_CHashBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_CHashError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashSet(IntPtr p,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashGet(IntPtr p,int i_ndex,int n_o,ref int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashAdd(IntPtr p,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashUni(IntPtr p,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashNum(IntPtr p,int i_ndex,int n_o,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashAll(IntPtr p,int i_ndex,int n_o,ref int n_um,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashDel(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CHashPrint(IntPtr p);

      public static IntPtr CHashBegin() {
         return vis_CHashBegin();
      }

      public static void CHashEnd(IntPtr p) {
         vis_CHashEnd(p);
      }

      public static int CHashError(IntPtr p) {
         return vis_CHashError(p);
      }

      public static void CHashSet(IntPtr p,int i_ndex,int n_o,int a_id) {
         vis_CHashSet(p, i_ndex, n_o, a_id);
      }

      public static void CHashGet(IntPtr p,int i_ndex,int n_o,ref int a_id) {
         vis_CHashGet(p, i_ndex, n_o,ref a_id);
      }

      public static void CHashAdd(IntPtr p,int i_ndex,int n_o,int a_id) {
         vis_CHashAdd(p, i_ndex, n_o, a_id);
      }

      public static void CHashUni(IntPtr p,int i_ndex,int n_o,int a_id) {
         vis_CHashUni(p, i_ndex, n_o, a_id);
      }

      public static void CHashNum(IntPtr p,int i_ndex,int n_o,ref int n_um) {
         vis_CHashNum(p, i_ndex, n_o,ref n_um);
      }

      public static void CHashAll(IntPtr p,int i_ndex,int n_o,ref int n_um,int [] a_ids) {
         vis_CHashAll(p, i_ndex, n_o,ref n_um, a_ids);
      }

      public static void CHashDel(IntPtr p,int i_ndex,int n_o) {
         vis_CHashDel(p, i_ndex, n_o);
      }

      public static void CHashPrint(IntPtr p) {
         vis_CHashPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ConnectBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ConnectError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPre(IntPtr p,int p_re);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGetPre(IntPtr p,ref int i_pre);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDef(IntPtr p,int n_node,int n_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectInq(IntPtr p,ref int n_node,ref int n_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMode(IntPtr p,int m_ode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetParamf(IntPtr p,int p_type,float p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetParamfv(IntPtr p,int t_ype,float [] p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumber(IntPtr p,int t_ype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetDimension(IntPtr p,int n_dim);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGetInteger(IntPtr p,int t_ype,int [] i_params);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetTopology(IntPtr p,int i_ndex,int s_hape,int m_axi,int m_axj,int m_axk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectTopology(IntPtr p,int i_ndex,ref int s_hape,ref int m_axi,ref int m_axj,ref int m_axk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectTopologyShapeArray(IntPtr p,int [] s_hape);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectTopologyMIJKArray(IntPtr p,int [] m_ijk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDelElem(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIsElem(IntPtr p,int i_ndex,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGenElem(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetNumEIP(IntPtr p,int i_ndex,int n_umeip);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumEIP(IntPtr p,int i_ndex,ref int n_umeip);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectLngEIP(IntPtr p,ref long l_ng);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIndEIP(IntPtr p,int i_d,ref long i_nd);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemNode(IntPtr p,int i_ndex,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMaxElemNode(IntPtr p,ref int m_axnum);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumElemNode(IntPtr p,int i_ndex,ref int n_ix);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumElemNodeArray(IntPtr p,int [] n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectProcessPoly(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectLngElemNode(IntPtr p,ref long l_ng);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIndElemNode(IntPtr p,int i_d,ref long i_nd);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIndElemNodei(IntPtr p,int i_d,ref int i_nd);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNode(IntPtr p,int i_ndex,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNodeArray(IntPtr p,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNodePtr(IntPtr p,int i_d,ref int n_ix,out int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetCoords(IntPtr p,int i_ndex,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetCoordsArray(IntPtr p,int n_umnp,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetCoordsArraydv(IntPtr p,int n_umnp,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetCoordsdv(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCoords(IntPtr p,int n_ix,int [] i_x,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCoordsArray(IntPtr p,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCoordsdv(IntPtr p,int n_ids,int [] i_ds,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCoordsArraydv(IntPtr p,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeIndex(IntPtr p,int i_d,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemIndex(IntPtr p,int i_d,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetPartName(IntPtr p,int p_artid,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPartName(IntPtr p,int p_artid,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumPartName(IntPtr p,ref int n_umpartname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIthPartName(IntPtr p,int i_th,ref int p_artid,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetPartIJK(IntPtr p,int p_artid,int [] i_jk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPartIJK(IntPtr p,int p_artid,int [] i_jk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumPartIJK(IntPtr p,ref int n_umpartijk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIthPartIJK(IntPtr p,int i_th,ref int p_artid,int [] i_jk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDelNode(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIsNode(IntPtr p,int i_ndex,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGenNode(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetNodeAssocArray(IntPtr p,int t_ype,int n_um,int [] a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeAssocArray(IntPtr p,int t_ype,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAddNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectUniNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDelNodeAssoc(IntPtr p,int t_ype,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumNodeAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAllNodeAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAnyNodeAssoc(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemAssocArray(IntPtr p,int t_ype,int n_um,int [] a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAssocArray(IntPtr p,int t_ype,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMultipleElemAssocArray(IntPtr p,int t_ype,int i_d1,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAddElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectUniElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDelElemAssoc(IntPtr p,int t_ype,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumElemAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAllElemAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAnyElemAssoc(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAnyMultipleElemAssoc(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMaxMultipleElemAssoc(IntPtr p,int t_ype,ref int m_axNumMultAssoc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAddElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDelElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectUniElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAllElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int n_um,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAnyElemEntAssoc(IntPtr p,int t_ype,int e_nttype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDimension(IntPtr p,ref int n_dim);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMallocElemNode(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectFreeElemNode(IntPtr p,ref IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMallocNodeElem(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectFreeNodeElem(IntPtr p,ref IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDemo(IntPtr p,int o_per,float f_,int s_hape,int n_umi,int n_umj,int n_umk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectRead(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectProcess(IntPtr p,ref int e_index,ref int n_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectKernel(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectClearKernel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectWrite(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectDual(IntPtr p,IntPtr c_onnectsrc,IntPtr g_roupsrc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMaxNodeElem(IntPtr p,ref int m_axnum);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNumNodeElem(IntPtr p,int i_ndex,ref int n_ix);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeElem(IntPtr p,int i_ndex,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeNode(IntPtr p,int i_d,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeEdgeCornNode(IntPtr p,int i_d,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAdj(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAdjExact(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj,int [] l_ocalFaceId);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAdjEntWithCornerNodesOption(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_xadj,int [] n_oadj,int c_ornerNodesOnlyFlag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemAdjEnt(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_xadj,int [] n_oadj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeAdj(IntPtr p,int n_indices,int [] i_ndices,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNum(IntPtr p,int t_ype,int i_ndex,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemMax(IntPtr p,int t_ype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemCon(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemCnn(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemCorn(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemTopo(IntPtr p,int t_ype,int i_ndex,int n_o,ref int s_hape,ref int m_axi,ref int m_axj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemNorm(IntPtr p,int i_ndex,int n_o,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemNormdv(IntPtr p,int i_d,int n_o,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectLngElemNorm(IntPtr p,ref int l_ng,ref int n_ent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIsElemNorm(IntPtr p,int i_ndex,int n_o,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNorm(IntPtr p,int i_ndex,int n_o,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemNormdv(IntPtr p,int i_d,int n_o,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemTang(IntPtr p,int i_ndex,int n_o,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetElemTangdv(IntPtr p,int i_d,int n_o,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectLngElemTang(IntPtr p,ref int l_ng,ref int n_ent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectIsElemTang(IntPtr p,int i_ndex,int n_o,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemTang(IntPtr p,int i_ndex,int n_o,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemTangdv(IntPtr p,int i_d,int n_o,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectExtent(IntPtr p,IntPtr g_roup,float [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectExtentdv(IntPtr p,IntPtr g_roup,double [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectExtentLoc(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCoordSysExtentLoc(IntPtr p,IntPtr g_roup,IntPtr c_oordsys,float [] e_xtent,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetGroupParamf(IntPtr p,int p_type,float v_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetGroupParamfv(IntPtr p,int p_type,float [] p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetGroupParami(IntPtr p,int p_type,int p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetGroupObject(IntPtr p,int t_ype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMergeIdTran(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMergeWithNodeMapping(IntPtr p,IntPtr g_roup,IntPtr p_reviousToNewNodeIndices);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectMerge(IntPtr p,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectFaceGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectEdgeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectElemIdTran(IntPtr p,int o_per,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectNodeIdTran(IntPtr p,int o_per,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSplitElem(IntPtr p,int t_ype,int i_ndex,int n_o,int n_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSizeElemdv(IntPtr p,int t_ype,int i_ndex,int n_o,ref double s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectAppend(IntPtr p,IntPtr f_romconnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSubset(IntPtr p,IntPtr g_roup,IntPtr s_ubconnect,IntPtr i_dtrannode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSubsetWithElementMapping(IntPtr p,IntPtr g_roup,IntPtr s_ubconnect,IntPtr i_dtranNode,IntPtr i_dtranElement);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPrintSummary(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectTess(IntPtr p,IntPtr i_nput);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectGridFun(IntPtr p,IntPtr g_ridfun);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ConnectCheckElemIndex(IntPtr p,int i_d,StringBuilder f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectPlaneIntersect(IntPtr p,double [] p_lane_eq,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ConnectSetNumThreads(IntPtr p,int n_um);

      public static IntPtr ConnectBegin() {
         return vis_ConnectBegin();
      }

      public static void ConnectEnd(IntPtr p) {
         vis_ConnectEnd(p);
      }

      public static int ConnectError(IntPtr p) {
         return vis_ConnectError(p);
      }

      public static void ConnectPre(IntPtr p,int p_re) {
         vis_ConnectPre(p, p_re);
      }

      public static void ConnectGetPre(IntPtr p,ref int i_pre) {
         vis_ConnectGetPre(p,ref i_pre);
      }

      public static void ConnectDef(IntPtr p,int n_node,int n_elem) {
         vis_ConnectDef(p, n_node, n_elem);
      }

      public static void ConnectInq(IntPtr p,ref int n_node,ref int n_elem) {
         vis_ConnectInq(p,ref n_node,ref n_elem);
      }

      public static void ConnectMode(IntPtr p,int m_ode) {
         vis_ConnectMode(p, m_ode);
      }

      public static void ConnectSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_ConnectSetObject(p, o_bjecttype, o_bject);
      }

      public static void ConnectGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_ConnectGetObject(p, o_bjecttype,out o_bject);
      }

      public static void ConnectSetParamf(IntPtr p,int p_type,float p_aram) {
         vis_ConnectSetParamf(p, p_type, p_aram);
      }

      public static void ConnectSetParamfv(IntPtr p,int t_ype,float [] p_aram) {
         vis_ConnectSetParamfv(p, t_ype, p_aram);
      }

      public static void ConnectSetParami(IntPtr p,int p_type,int i_param) {
         vis_ConnectSetParami(p, p_type, i_param);
      }

      public static void ConnectNumber(IntPtr p,int t_ype,ref int n_umentity) {
         vis_ConnectNumber(p, t_ype,ref n_umentity);
      }

      public static void ConnectSetDimension(IntPtr p,int n_dim) {
         vis_ConnectSetDimension(p, n_dim);
      }

      public static void ConnectGetInteger(IntPtr p,int t_ype,int [] i_params) {
         vis_ConnectGetInteger(p, t_ype, i_params);
      }

      public static void ConnectSetTopology(IntPtr p,int i_ndex,int s_hape,int m_axi,int m_axj,int m_axk) {
         vis_ConnectSetTopology(p, i_ndex, s_hape, m_axi, m_axj, m_axk);
      }

      public static void ConnectTopology(IntPtr p,int i_ndex,ref int s_hape,ref int m_axi,ref int m_axj,ref int m_axk) {
         vis_ConnectTopology(p, i_ndex,ref s_hape,ref m_axi,ref m_axj,ref m_axk);
      }

      public static void ConnectTopologyShapeArray(IntPtr p,int [] s_hape) {
         vis_ConnectTopologyShapeArray(p, s_hape);
      }

      public static void ConnectTopologyMIJKArray(IntPtr p,int [] m_ijk) {
         vis_ConnectTopologyMIJKArray(p, m_ijk);
      }

      public static void ConnectDelElem(IntPtr p,int i_ndex) {
         vis_ConnectDelElem(p, i_ndex);
      }

      public static void ConnectIsElem(IntPtr p,int i_ndex,ref int f_lag) {
         vis_ConnectIsElem(p, i_ndex,ref f_lag);
      }

      public static void ConnectGenElem(IntPtr p,ref int i_ndex) {
         vis_ConnectGenElem(p,ref i_ndex);
      }

      public static void ConnectSetNumEIP(IntPtr p,int i_ndex,int n_umeip) {
         vis_ConnectSetNumEIP(p, i_ndex, n_umeip);
      }

      public static void ConnectNumEIP(IntPtr p,int i_ndex,ref int n_umeip) {
         vis_ConnectNumEIP(p, i_ndex,ref n_umeip);
      }

      public static void ConnectLngEIP(IntPtr p,ref long l_ng) {
         vis_ConnectLngEIP(p,ref l_ng);
      }

      public static void ConnectIndEIP(IntPtr p,int i_d,ref long i_nd) {
         vis_ConnectIndEIP(p, i_d,ref i_nd);
      }

      public static void ConnectSetElemNode(IntPtr p,int i_ndex,int [] i_x) {
         vis_ConnectSetElemNode(p, i_ndex, i_x);
      }

      public static void ConnectMaxElemNode(IntPtr p,ref int m_axnum) {
         vis_ConnectMaxElemNode(p,ref m_axnum);
      }

      public static void ConnectNumElemNode(IntPtr p,int i_ndex,ref int n_ix) {
         vis_ConnectNumElemNode(p, i_ndex,ref n_ix);
      }

      public static void ConnectNumElemNodeArray(IntPtr p,int [] n_um) {
         vis_ConnectNumElemNodeArray(p, n_um);
      }

      public static void ConnectProcessPoly(IntPtr p) {
         vis_ConnectProcessPoly(p);
      }

      public static void ConnectLngElemNode(IntPtr p,ref long l_ng) {
         vis_ConnectLngElemNode(p,ref l_ng);
      }

      public static void ConnectIndElemNode(IntPtr p,int i_d,ref long i_nd) {
         vis_ConnectIndElemNode(p, i_d,ref i_nd);
      }

      public static void ConnectIndElemNodei(IntPtr p,int i_d,ref int i_nd) {
         vis_ConnectIndElemNodei(p, i_d,ref i_nd);
      }

      public static void ConnectElemNode(IntPtr p,int i_ndex,ref int n_ix,int [] i_x) {
         vis_ConnectElemNode(p, i_ndex,ref n_ix, i_x);
      }

      public static void ConnectElemNodeArray(IntPtr p,int [] i_x) {
         vis_ConnectElemNodeArray(p, i_x);
      }

      public static void ConnectElemNodePtr(IntPtr p,int i_d,ref int n_ix,out int [] i_x) {
         vis_ConnectElemNodePtr(p, i_d,ref n_ix,out i_x);
      }

      public static void ConnectSetCoords(IntPtr p,int i_ndex,float [] x_) {
         vis_ConnectSetCoords(p, i_ndex, x_);
      }

      public static void ConnectSetCoordsArray(IntPtr p,int n_umnp,float [] x_) {
         vis_ConnectSetCoordsArray(p, n_umnp, x_);
      }

      public static void ConnectSetCoordsArraydv(IntPtr p,int n_umnp,double [] x_) {
         vis_ConnectSetCoordsArraydv(p, n_umnp, x_);
      }

      public static void ConnectSetCoordsdv(IntPtr p,int i_d,double [] x_) {
         vis_ConnectSetCoordsdv(p, i_d, x_);
      }

      public static void ConnectCoords(IntPtr p,int n_ix,int [] i_x,float [] x_) {
         vis_ConnectCoords(p, n_ix, i_x, x_);
      }

      public static void ConnectCoordsArray(IntPtr p,float [] x_) {
         vis_ConnectCoordsArray(p, x_);
      }

      public static void ConnectCoordsdv(IntPtr p,int n_ids,int [] i_ds,double [] x_) {
         vis_ConnectCoordsdv(p, n_ids, i_ds, x_);
      }

      public static void ConnectCoordsArraydv(IntPtr p,double [] x_) {
         vis_ConnectCoordsArraydv(p, x_);
      }

      public static void ConnectNodeIndex(IntPtr p,int i_d,ref int i_ndex) {
         vis_ConnectNodeIndex(p, i_d,ref i_ndex);
      }

      public static void ConnectNodeIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndex) {
         vis_ConnectNodeIndices(p, n_ids, i_ds, i_ndex);
      }

      public static void ConnectElemIndex(IntPtr p,int i_d,ref int i_ndex) {
         vis_ConnectElemIndex(p, i_d,ref i_ndex);
      }

      public static void ConnectElemIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndex) {
         vis_ConnectElemIndices(p, n_ids, i_ds, i_ndex);
      }

      public static void ConnectSetPartName(IntPtr p,int p_artid,StringBuilder n_ame) {
         vis_ConnectSetPartName(p, p_artid, n_ame);
      }

      public static void ConnectPartName(IntPtr p,int p_artid,StringBuilder n_ame) {
         vis_ConnectPartName(p, p_artid, n_ame);
      }

      public static void ConnectNumPartName(IntPtr p,ref int n_umpartname) {
         vis_ConnectNumPartName(p,ref n_umpartname);
      }

      public static void ConnectIthPartName(IntPtr p,int i_th,ref int p_artid,StringBuilder n_ame) {
         vis_ConnectIthPartName(p, i_th,ref p_artid, n_ame);
      }

      public static void ConnectSetPartIJK(IntPtr p,int p_artid,int [] i_jk) {
         vis_ConnectSetPartIJK(p, p_artid, i_jk);
      }

      public static void ConnectPartIJK(IntPtr p,int p_artid,int [] i_jk) {
         vis_ConnectPartIJK(p, p_artid, i_jk);
      }

      public static void ConnectNumPartIJK(IntPtr p,ref int n_umpartijk) {
         vis_ConnectNumPartIJK(p,ref n_umpartijk);
      }

      public static void ConnectIthPartIJK(IntPtr p,int i_th,ref int p_artid,int [] i_jk) {
         vis_ConnectIthPartIJK(p, i_th,ref p_artid, i_jk);
      }

      public static void ConnectDelNode(IntPtr p,int i_ndex) {
         vis_ConnectDelNode(p, i_ndex);
      }

      public static void ConnectIsNode(IntPtr p,int i_ndex,ref int f_lag) {
         vis_ConnectIsNode(p, i_ndex,ref f_lag);
      }

      public static void ConnectGenNode(IntPtr p,ref int i_ndex) {
         vis_ConnectGenNode(p,ref i_ndex);
      }

      public static void ConnectSetNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectSetNodeAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectSetNodeAssocArray(IntPtr p,int t_ype,int n_um,int [] a_id) {
         vis_ConnectSetNodeAssocArray(p, t_ype, n_um, a_id);
      }

      public static void ConnectNodeAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids) {
         vis_ConnectNodeAssoc(p, t_ype, n_ix, i_x, a_ids);
      }

      public static void ConnectNodeAssocArray(IntPtr p,int t_ype,int [] a_ids) {
         vis_ConnectNodeAssocArray(p, t_ype, a_ids);
      }

      public static void ConnectAddNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectAddNodeAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectUniNodeAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectUniNodeAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectDelNodeAssoc(IntPtr p,int t_ype,int i_ndex) {
         vis_ConnectDelNodeAssoc(p, t_ype, i_ndex);
      }

      public static void ConnectNumNodeAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um) {
         vis_ConnectNumNodeAssoc(p, t_ype, i_ndex,ref n_um);
      }

      public static void ConnectAllNodeAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um,int [] a_ids) {
         vis_ConnectAllNodeAssoc(p, t_ype, i_ndex,ref n_um, a_ids);
      }

      public static void ConnectAnyNodeAssoc(IntPtr p,int t_ype,ref int f_lag) {
         vis_ConnectAnyNodeAssoc(p, t_ype,ref f_lag);
      }

      public static void ConnectSetElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectSetElemAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectSetElemAssocArray(IntPtr p,int t_ype,int n_um,int [] a_id) {
         vis_ConnectSetElemAssocArray(p, t_ype, n_um, a_id);
      }

      public static void ConnectElemAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids) {
         vis_ConnectElemAssoc(p, t_ype, n_ix, i_x, a_ids);
      }

      public static void ConnectElemAssocArray(IntPtr p,int t_ype,int [] a_ids) {
         vis_ConnectElemAssocArray(p, t_ype, a_ids);
      }

      public static void ConnectMultipleElemAssocArray(IntPtr p,int t_ype,int i_d1,int [] a_ids) {
         vis_ConnectMultipleElemAssocArray(p, t_ype, i_d1, a_ids);
      }

      public static void ConnectAddElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectAddElemAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectUniElemAssoc(IntPtr p,int t_ype,int i_ndex,int a_id) {
         vis_ConnectUniElemAssoc(p, t_ype, i_ndex, a_id);
      }

      public static void ConnectDelElemAssoc(IntPtr p,int t_ype,int i_ndex) {
         vis_ConnectDelElemAssoc(p, t_ype, i_ndex);
      }

      public static void ConnectNumElemAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um) {
         vis_ConnectNumElemAssoc(p, t_ype, i_ndex,ref n_um);
      }

      public static void ConnectAllElemAssoc(IntPtr p,int t_ype,int i_ndex,ref int n_um,int [] a_ids) {
         vis_ConnectAllElemAssoc(p, t_ype, i_ndex,ref n_um, a_ids);
      }

      public static void ConnectAnyElemAssoc(IntPtr p,int t_ype,ref int f_lag) {
         vis_ConnectAnyElemAssoc(p, t_ype,ref f_lag);
      }

      public static void ConnectAnyMultipleElemAssoc(IntPtr p,int t_ype,ref int f_lag) {
         vis_ConnectAnyMultipleElemAssoc(p, t_ype,ref f_lag);
      }

      public static void ConnectMaxMultipleElemAssoc(IntPtr p,int t_ype,ref int m_axNumMultAssoc) {
         vis_ConnectMaxMultipleElemAssoc(p, t_ype,ref m_axNumMultAssoc);
      }

      public static void ConnectSetElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id) {
         vis_ConnectSetElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o, a_id);
      }

      public static void ConnectAddElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id) {
         vis_ConnectAddElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o, a_id);
      }

      public static void ConnectNumElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int n_um) {
         vis_ConnectNumElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o,ref n_um);
      }

      public static void ConnectDelElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o) {
         vis_ConnectDelElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o);
      }

      public static void ConnectUniElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,int a_id) {
         vis_ConnectUniElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o, a_id);
      }

      public static void ConnectElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int a_id) {
         vis_ConnectElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o,ref a_id);
      }

      public static void ConnectAllElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_ndex,int n_o,ref int n_um,int [] a_ids) {
         vis_ConnectAllElemEntAssoc(p, t_ype, e_nttype, i_ndex, n_o,ref n_um, a_ids);
      }

      public static void ConnectAnyElemEntAssoc(IntPtr p,int t_ype,int e_nttype,ref int f_lag) {
         vis_ConnectAnyElemEntAssoc(p, t_ype, e_nttype,ref f_lag);
      }

      public static void ConnectDimension(IntPtr p,ref int n_dim) {
         vis_ConnectDimension(p,ref n_dim);
      }

      public static void ConnectMallocElemNode(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr) {
         vis_ConnectMallocElemNode(p, n_rows, s_ize,out p_tr);
      }

      public static void ConnectFreeElemNode(IntPtr p,ref IntPtr p_tr) {
         vis_ConnectFreeElemNode(p,ref p_tr);
      }

      public static void ConnectMallocNodeElem(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr) {
         vis_ConnectMallocNodeElem(p, n_rows, s_ize,out p_tr);
      }

      public static void ConnectFreeNodeElem(IntPtr p,ref IntPtr p_tr) {
         vis_ConnectFreeNodeElem(p,ref p_tr);
      }

      public static void ConnectDemo(IntPtr p,int o_per,float f_,int s_hape,int n_umi,int n_umj,int n_umk) {
         vis_ConnectDemo(p, o_per, f_, s_hape, n_umi, n_umj, n_umk);
      }

      public static void ConnectRead(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_ConnectRead(p, t_ype, p_ath);
      }

      public static void ConnectProcess(IntPtr p,ref int e_index,ref int n_id) {
         vis_ConnectProcess(p,ref e_index,ref n_id);
      }

      public static void ConnectKernel(IntPtr p,int f_lag) {
         vis_ConnectKernel(p, f_lag);
      }

      public static void ConnectClearKernel(IntPtr p) {
         vis_ConnectClearKernel(p);
      }

      public static void ConnectWrite(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_ConnectWrite(p, t_ype, p_ath);
      }

      public static void ConnectDual(IntPtr p,IntPtr c_onnectsrc,IntPtr g_roupsrc) {
         vis_ConnectDual(p, c_onnectsrc, g_roupsrc);
      }

      public static void ConnectMaxNodeElem(IntPtr p,ref int m_axnum) {
         vis_ConnectMaxNodeElem(p,ref m_axnum);
      }

      public static void ConnectNumNodeElem(IntPtr p,int i_ndex,ref int n_ix) {
         vis_ConnectNumNodeElem(p, i_ndex,ref n_ix);
      }

      public static void ConnectNodeElem(IntPtr p,int i_ndex,ref int n_ix,int [] i_x) {
         vis_ConnectNodeElem(p, i_ndex,ref n_ix, i_x);
      }

      public static void ConnectNodeNode(IntPtr p,int i_d,ref int n_ix,int [] i_x) {
         vis_ConnectNodeNode(p, i_d,ref n_ix, i_x);
      }

      public static void ConnectNodeEdgeCornNode(IntPtr p,int i_d,ref int n_ix,int [] i_x) {
         vis_ConnectNodeEdgeCornNode(p, i_d,ref n_ix, i_x);
      }

      public static void ConnectElemAdj(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj) {
         vis_ConnectElemAdj(p, t_ype, i_d, n_o,ref n_idadj, i_dadj);
      }

      public static void ConnectElemAdjExact(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj,int [] l_ocalFaceId) {
         vis_ConnectElemAdjExact(p, t_ype, i_d, n_o,ref n_idadj, i_dadj, l_ocalFaceId);
      }

      public static void ConnectElemAdjEntWithCornerNodesOption(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_xadj,int [] n_oadj,int c_ornerNodesOnlyFlag) {
         vis_ConnectElemAdjEntWithCornerNodesOption(p, t_ype, i_ndex, n_o,ref n_ix, i_xadj, n_oadj, c_ornerNodesOnlyFlag);
      }

      public static void ConnectElemAdjEnt(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_xadj,int [] n_oadj) {
         vis_ConnectElemAdjEnt(p, t_ype, i_ndex, n_o,ref n_ix, i_xadj, n_oadj);
      }

      public static void ConnectNodeAdj(IntPtr p,int n_indices,int [] i_ndices,ref int n_ix,int [] i_x) {
         vis_ConnectNodeAdj(p, n_indices, i_ndices,ref n_ix, i_x);
      }

      public static void ConnectElemNum(IntPtr p,int t_ype,int i_ndex,ref int n_um) {
         vis_ConnectElemNum(p, t_ype, i_ndex,ref n_um);
      }

      public static void ConnectElemMax(IntPtr p,int t_ype,ref int n_um) {
         vis_ConnectElemMax(p, t_ype,ref n_um);
      }

      public static void ConnectElemCon(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_x) {
         vis_ConnectElemCon(p, t_ype, i_ndex, n_o,ref n_ix, i_x);
      }

      public static void ConnectElemCnn(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_n) {
         vis_ConnectElemCnn(p, t_ype, i_ndex, n_o,ref n_ix, i_n);
      }

      public static void ConnectElemCorn(IntPtr p,int t_ype,int i_ndex,int n_o,ref int n_ix,int [] i_n) {
         vis_ConnectElemCorn(p, t_ype, i_ndex, n_o,ref n_ix, i_n);
      }

      public static void ConnectElemTopo(IntPtr p,int t_ype,int i_ndex,int n_o,ref int s_hape,ref int m_axi,ref int m_axj) {
         vis_ConnectElemTopo(p, t_ype, i_ndex, n_o,ref s_hape,ref m_axi,ref m_axj);
      }

      public static void ConnectSetElemNorm(IntPtr p,int i_ndex,int n_o,float [] v_) {
         vis_ConnectSetElemNorm(p, i_ndex, n_o, v_);
      }

      public static void ConnectSetElemNormdv(IntPtr p,int i_d,int n_o,double [] v_) {
         vis_ConnectSetElemNormdv(p, i_d, n_o, v_);
      }

      public static void ConnectLngElemNorm(IntPtr p,ref int l_ng,ref int n_ent) {
         vis_ConnectLngElemNorm(p,ref l_ng,ref n_ent);
      }

      public static void ConnectIsElemNorm(IntPtr p,int i_ndex,int n_o,ref int f_lag) {
         vis_ConnectIsElemNorm(p, i_ndex, n_o,ref f_lag);
      }

      public static void ConnectElemNorm(IntPtr p,int i_ndex,int n_o,float [] v_) {
         vis_ConnectElemNorm(p, i_ndex, n_o, v_);
      }

      public static void ConnectElemNormdv(IntPtr p,int i_d,int n_o,double [] v_) {
         vis_ConnectElemNormdv(p, i_d, n_o, v_);
      }

      public static void ConnectSetElemTang(IntPtr p,int i_ndex,int n_o,float [] v_) {
         vis_ConnectSetElemTang(p, i_ndex, n_o, v_);
      }

      public static void ConnectSetElemTangdv(IntPtr p,int i_d,int n_o,double [] v_) {
         vis_ConnectSetElemTangdv(p, i_d, n_o, v_);
      }

      public static void ConnectLngElemTang(IntPtr p,ref int l_ng,ref int n_ent) {
         vis_ConnectLngElemTang(p,ref l_ng,ref n_ent);
      }

      public static void ConnectIsElemTang(IntPtr p,int i_ndex,int n_o,ref int f_lag) {
         vis_ConnectIsElemTang(p, i_ndex, n_o,ref f_lag);
      }

      public static void ConnectElemTang(IntPtr p,int i_ndex,int n_o,float [] v_) {
         vis_ConnectElemTang(p, i_ndex, n_o, v_);
      }

      public static void ConnectElemTangdv(IntPtr p,int i_d,int n_o,double [] v_) {
         vis_ConnectElemTangdv(p, i_d, n_o, v_);
      }

      public static void ConnectExtent(IntPtr p,IntPtr g_roup,float [] e_xtent) {
         vis_ConnectExtent(p, g_roup, e_xtent);
      }

      public static void ConnectExtentdv(IntPtr p,IntPtr g_roup,double [] e_xtent) {
         vis_ConnectExtentdv(p, g_roup, e_xtent);
      }

      public static void ConnectExtentLoc(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x) {
         vis_ConnectExtentLoc(p, g_roup, e_xtent, i_x);
      }

      public static void ConnectCoordSysExtentLoc(IntPtr p,IntPtr g_roup,IntPtr c_oordsys,float [] e_xtent,int [] i_x) {
         vis_ConnectCoordSysExtentLoc(p, g_roup, c_oordsys, e_xtent, i_x);
      }

      public static void ConnectSetGroupParamf(IntPtr p,int p_type,float v_param) {
         vis_ConnectSetGroupParamf(p, p_type, v_param);
      }

      public static void ConnectSetGroupParamfv(IntPtr p,int p_type,float [] p_aram) {
         vis_ConnectSetGroupParamfv(p, p_type, p_aram);
      }

      public static void ConnectSetGroupParami(IntPtr p,int p_type,int p_aram) {
         vis_ConnectSetGroupParami(p, p_type, p_aram);
      }

      public static void ConnectSetGroupObject(IntPtr p,int t_ype,IntPtr o_bject) {
         vis_ConnectSetGroupObject(p, t_ype, o_bject);
      }

      public static void ConnectMergeIdTran(IntPtr p,IntPtr i_dtran) {
         vis_ConnectMergeIdTran(p, i_dtran);
      }

      public static void ConnectMergeWithNodeMapping(IntPtr p,IntPtr g_roup,IntPtr p_reviousToNewNodeIndices) {
         vis_ConnectMergeWithNodeMapping(p, g_roup, p_reviousToNewNodeIndices);
      }

      public static void ConnectMerge(IntPtr p,IntPtr g_roup) {
         vis_ConnectMerge(p, g_roup);
      }

      public static void ConnectElemGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ConnectElemGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void ConnectFaceGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ConnectFaceGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void ConnectEdgeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ConnectEdgeGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void ConnectNodeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ConnectNodeGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void ConnectElemIdTran(IntPtr p,int o_per,IntPtr g_roup,IntPtr i_dtran) {
         vis_ConnectElemIdTran(p, o_per, g_roup, i_dtran);
      }

      public static void ConnectNodeIdTran(IntPtr p,int o_per,IntPtr g_roup,IntPtr i_dtran) {
         vis_ConnectNodeIdTran(p, o_per, g_roup, i_dtran);
      }

      public static void ConnectSplitElem(IntPtr p,int t_ype,int i_ndex,int n_o,int n_ind) {
         vis_ConnectSplitElem(p, t_ype, i_ndex, n_o, n_ind);
      }

      public static void ConnectSizeElemdv(IntPtr p,int t_ype,int i_ndex,int n_o,ref double s_) {
         vis_ConnectSizeElemdv(p, t_ype, i_ndex, n_o,ref s_);
      }

      public static void ConnectCopy(IntPtr p,IntPtr f_romp) {
         vis_ConnectCopy(p, f_romp);
      }

      public static void ConnectAppend(IntPtr p,IntPtr f_romconnect) {
         vis_ConnectAppend(p, f_romconnect);
      }

      public static void ConnectSubset(IntPtr p,IntPtr g_roup,IntPtr s_ubconnect,IntPtr i_dtrannode) {
         vis_ConnectSubset(p, g_roup, s_ubconnect, i_dtrannode);
      }

      public static void ConnectSubsetWithElementMapping(IntPtr p,IntPtr g_roup,IntPtr s_ubconnect,IntPtr i_dtranNode,IntPtr i_dtranElement) {
         vis_ConnectSubsetWithElementMapping(p, g_roup, s_ubconnect, i_dtranNode, i_dtranElement);
      }

      public static void ConnectPrintSummary(IntPtr p) {
         vis_ConnectPrintSummary(p);
      }

      public static void ConnectPrint(IntPtr p) {
         vis_ConnectPrint(p);
      }

      public static void ConnectTess(IntPtr p,IntPtr i_nput) {
         vis_ConnectTess(p, i_nput);
      }

      public static void ConnectGridFun(IntPtr p,IntPtr g_ridfun) {
         vis_ConnectGridFun(p, g_ridfun);
      }

      public static int ConnectCheckElemIndex(IntPtr p,int i_d,StringBuilder f_unc) {
         return vis_ConnectCheckElemIndex(p, i_d, f_unc);
      }

      public static void ConnectPlaneIntersect(IntPtr p,double [] p_lane_eq,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ConnectPlaneIntersect(p, p_lane_eq, g_roup, g_roupdst);
      }

      public static void ConnectSetNumThreads(IntPtr p,int n_um) {
         vis_ConnectSetNumThreads(p, n_um);
      }

      public const int CONNECT_KERNELEXIST = 1;
      public const int CONNECT_STATIC = 0;
      public const int CONNECT_DYNAMIC = 1;
      public const int CONNECT_UNIQUE = 0;
      public const int CONNECT_FREE = 1;
      public const int CONNECT_ELEM = 2;
      public const int CONNECT_FEATURE = 3;
      public const int CONNECT_ASSOC = 4;
      public const int CONNECT_SHAPE = 5;
      public const int CONNECT_DIMENSION = 6;
      public const int CONNECT_EXTENT = 7;
      public const int CONNECT_CONTAINED = 12;
      public const int CONNECT_USE = 13;
      public const int CONNECT_CONNECTED = 15;
      public const int CONNECT_INCONSISTENT = 17;
      public const int CONNECT_CURVATURE = 18;
      public const int CONNECT_SEED = 23;
      public const int CONNECT_NONMAN = 27;
      public const int CONNECT_CORNER = 28;
      public const int CONNECT_ASSOCANY = 29;
      public const int CONNECT_ASSOCDIFF = 30;
      public const int CONNECT_INTERSECT = 31;
      public const int CONNECT_UNIQUEASSOCDIFF = 32;
      public const int CONNECT_FEATUREASSOCDIFF = 33;
      public const int CONNECT_UNIQUEASSOC = 34;
      public const int CONNECT_FLOOD = 35;
      public const int CONNECT_SILHOUETTE = 8;
      public const int CONNECT_INTERVAL = 9;
      public const int CONNECT_SAMPLE = 20;
      public const int CONNECT_FREEBODY = 50;
      public const int CONNECT_TOPOBODY = 51;
      public const int CONNECT_MAP = 53;
      public const int CONNECT_USERID = 54;
      public const int CONNECT_TRIPOD = 52;
      public const int CONNECT_REDEFINETOPO = 22;
      public const int CONNECT_EXACTADJACENCY = 27;
      public const int CONNECT_LAYERASSOC = 34;
      public const int CONNECT_ZEROUSERID = 36;
      public const int CONNECT_ASSOCID = 2;
      public const int CONNECT_FEATURESENSE = 4;
      public const int CONNECT_NUMBER = 14;
      public const int CONNECT_SEEDNODE = 24;
      public const int CONNECT_CURVATUREFLAT = 26;
      public const int CONNECT_SEEDELEM = 28;
      public const int CONNECT_SEEDEDGE = 29;
      public const int CONNECT_SEEDFACE = 30;
      public const int CONNECT_FEATURENONMAN = 33;
      public const int CONNECT_ASSOCFREE = 35;
      public const int CONNECT_ASSOCTYPE = 1;
      public const int CONNECT_INTERVALNUMBER = 10;
      public const int CONNECT_INTERVALVALUE = 11;
      public const int CONNECT_DEMO_CUBE = 1;
      public const int CONNECT_DEMO_CYLINDER = 2;
      public const int CONNECT_DEMO_SPHERE = 3;
      public const int CONNECT_READ_ASCII = -1;
      public const int CONNECT_READ_BINARY = -2;
      public const int CONNECT_READ_STL = -4;
      public const int CONNECT_READ_STL_BINARY = -5;
      public const int CONNECT_READ_OBJ = -6;
      public const int CONNECT_WRITE_ASCII = -1;
      public const int CONNECT_WRITE_BINARY = -2;
      public const int CONNECT_WRITE_ABAQUS_INPUT = 13;
      public const int CONNECT_WRITE_ANSYS_INPUT = 22;
      public const int CONNECT_WRITE_LS_DYNA_INPUT = 25;
      public const int CONNECT_WRITE_NASTRAN_BULKDATA = 18;
      public const int CONNECT_WRITE_PATRAN_NEUTRAL = 20;
      public const int CONNECT_WRITE_SDRC_UNIVERSAL = 14;
      public const int CONNECT_GHS3D_DATA = -10;
      public const int CONNECT_GHS3D_NOBOITE = -11;
      public const int CONNECT_TEXT_SUMMARY = -16;
      public const int CONNECT_TEXT_LISTING = -17;
      public const int CONNECT_SRF = -19;
      public const int CONNECT_TETGEN_NODEELEM = -20;
      public const int CONNECT_TETGEN_POLY = -21;
      public const int CONNECT_CADENCE_MESH = -22;
      public const int CONNECT_GROUP_EXTENT = 7;
      public const int CONNECT_MODELVIEWMATRIX = 3;
      public const int CONNECT_SEEDGROUP = 25;
      public const int CONNECT_NORMAL = 32;
      public const int CONNECT_TOLERANCE = 16;
      public const int CONNECT_SIZE = 31;
      public const int CONNECT_FEATUREANGLE = 0;
      public const int CONNECT_GROUP_TOLERANCE = 16;
      public const int CONNECT_CURVATURECHANGE = 19;
      public const int CONNECT_SAMPLEDISTANCE = 21;

      public const int COORDSYS_XAXIS_XYPLANE = 0;
      public const int COORDSYS_XAXIS_XZPLANE = 1;
      public const int COORDSYS_ZAXIS_XZPLANE = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_CoordSysBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_CoordSysError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysInq(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetNode(IntPtr p,int i_op,int g_id1,int g_id2,int g_id3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetCoord(IntPtr p,int i_op,float [] x_1,float [] x_2,float [] x_3,int r_cid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetCoorddv(IntPtr p,int i_op,double [] x_1,double [] x_2,double [] x_3,int r_cid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginZAxis(IntPtr p,float [] x_,float [] z_v);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginZAxisdv(IntPtr p,double [] x_,double [] z_v);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginVectors(IntPtr p,float [] x_,float [] v_1,float [] v_2);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginVectorsdv(IntPtr p,double [] x_,double [] x_a,double [] y_a);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginRotAng(IntPtr p,float [] x_,float [] r_a);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginRotAngdv(IntPtr p,double [] x_,double [] r_otang);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginTriad(IntPtr p,float [] x_,float [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetOriginTriaddv(IntPtr p,double [] x_,double [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetRadius(IntPtr p,float r_adius);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetRadiusdv(IntPtr p,double r_adius);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetRadiusdv(IntPtr p,ref double r_adius);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetSurface(IntPtr p,int i_dir,float x_c);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetSurfacedv(IntPtr p,int i_dir,double x_c);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetSurfacedv(IntPtr p,ref int i_dir,ref double x_c);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetSurfaceSense(IntPtr p,int i_sens);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetSurfaceSense(IntPtr p,ref int i_sens);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysChkSurfacedv(IntPtr p,double c_l,double [] x_,double [] v_,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysResolve(IntPtr p,ref int r_esolve);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysDirCos(IntPtr p,float [] x_,float [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysDirCosdv(IntPtr p,double [] x_,double [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysRotAng(IntPtr p,float [] x_,float [] r_a);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysRotAngdv(IntPtr p,double [] x_,double [] r_otang);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysOriginTriad(IntPtr p,float [] x_,float [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysOriginTriaddv(IntPtr p,double [] x_,double [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysOriginRotAng(IntPtr p,float [] x_,float [] r_otang);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysOriginRotAngdv(IntPtr p,double [] x_,double [] r_otang);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertCoord(IntPtr p,float [] x_,float [] x_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertCoorddv(IntPtr p,double [] x_,double [] x_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeCoord(IntPtr p,float [] x_l,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeCoorddv(IntPtr p,double [] x_,double [] x_g);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysProjSurfacedv(IntPtr p,double [] x_,double [] x_p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysNormSurfacedv(IntPtr p,double [] x_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeVector(IntPtr p,float [] x_,float [] v_l,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeVectordv(IntPtr p,double [] x_,double [] t_,double [] t_g);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeTensor(IntPtr p,float [] x_,float [] t_l,float [] t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeTensordv(IntPtr p,double [] x_,double [] t_,double [] t_g);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeMatrix(IntPtr p,float [] x_,float [] g_l,float [] g_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysComputeMatrixdv(IntPtr p,double [] x_,double [] t_,double [] t_g);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertVector(IntPtr p,float [] x_,float [] v_,float [] v_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertVectordv(IntPtr p,double [] x_,double [] t_,double [] t_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertTensor(IntPtr p,float [] x_,float [] t_,float [] t_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertTensordv(IntPtr p,double [] x_,double [] t_,double [] t_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertMatrix(IntPtr p,float [] x_,float [] g_,float [] g_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysConvertMatrixdv(IntPtr p,double [] x_,double [] t_,double [] t_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysLineInterpolatedv(IntPtr p,double [] x_l,double s_,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysQuadSurfaceCoord(IntPtr p,double [] x_,double [] x_s,ref double c_ho,ref double c_hs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetCSystem(IntPtr p,out IntPtr c_system);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysCopy(IntPtr p,IntPtr q_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CoordSysTransform(IntPtr p,double [] u_,double [] t_m);

      public static IntPtr CoordSysBegin() {
         return vis_CoordSysBegin();
      }

      public static void CoordSysEnd(IntPtr p) {
         vis_CoordSysEnd(p);
      }

      public static int CoordSysError(IntPtr p) {
         return vis_CoordSysError(p);
      }

      public static void CoordSysSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_CoordSysSetObject(p, o_bjecttype, o_bject);
      }

      public static void CoordSysGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_CoordSysGetObject(p, o_bjecttype,out o_bject);
      }

      public static void CoordSysDef(IntPtr p,int t_ype) {
         vis_CoordSysDef(p, t_ype);
      }

      public static void CoordSysInq(IntPtr p,ref int t_ype) {
         vis_CoordSysInq(p,ref t_ype);
      }

      public static void CoordSysSetNode(IntPtr p,int i_op,int g_id1,int g_id2,int g_id3) {
         vis_CoordSysSetNode(p, i_op, g_id1, g_id2, g_id3);
      }

      public static void CoordSysSetCoord(IntPtr p,int i_op,float [] x_1,float [] x_2,float [] x_3,int r_cid) {
         vis_CoordSysSetCoord(p, i_op, x_1, x_2, x_3, r_cid);
      }

      public static void CoordSysSetCoorddv(IntPtr p,int i_op,double [] x_1,double [] x_2,double [] x_3,int r_cid) {
         vis_CoordSysSetCoorddv(p, i_op, x_1, x_2, x_3, r_cid);
      }

      public static void CoordSysSetOriginZAxis(IntPtr p,float [] x_,float [] z_v) {
         vis_CoordSysSetOriginZAxis(p, x_, z_v);
      }

      public static void CoordSysSetOriginZAxisdv(IntPtr p,double [] x_,double [] z_v) {
         vis_CoordSysSetOriginZAxisdv(p, x_, z_v);
      }

      public static void CoordSysSetOriginVectors(IntPtr p,float [] x_,float [] v_1,float [] v_2) {
         vis_CoordSysSetOriginVectors(p, x_, v_1, v_2);
      }

      public static void CoordSysSetOriginVectorsdv(IntPtr p,double [] x_,double [] x_a,double [] y_a) {
         vis_CoordSysSetOriginVectorsdv(p, x_, x_a, y_a);
      }

      public static void CoordSysSetOriginRotAng(IntPtr p,float [] x_,float [] r_a) {
         vis_CoordSysSetOriginRotAng(p, x_, r_a);
      }

      public static void CoordSysSetOriginRotAngdv(IntPtr p,double [] x_,double [] r_otang) {
         vis_CoordSysSetOriginRotAngdv(p, x_, r_otang);
      }

      public static void CoordSysSetOriginTriad(IntPtr p,float [] x_,float [] t_m) {
         vis_CoordSysSetOriginTriad(p, x_, t_m);
      }

      public static void CoordSysSetOriginTriaddv(IntPtr p,double [] x_,double [] t_m) {
         vis_CoordSysSetOriginTriaddv(p, x_, t_m);
      }

      public static void CoordSysSetRadius(IntPtr p,float r_adius) {
         vis_CoordSysSetRadius(p, r_adius);
      }

      public static void CoordSysSetRadiusdv(IntPtr p,double r_adius) {
         vis_CoordSysSetRadiusdv(p, r_adius);
      }

      public static void CoordSysGetRadiusdv(IntPtr p,ref double r_adius) {
         vis_CoordSysGetRadiusdv(p,ref r_adius);
      }

      public static void CoordSysSetSurface(IntPtr p,int i_dir,float x_c) {
         vis_CoordSysSetSurface(p, i_dir, x_c);
      }

      public static void CoordSysSetSurfacedv(IntPtr p,int i_dir,double x_c) {
         vis_CoordSysSetSurfacedv(p, i_dir, x_c);
      }

      public static void CoordSysGetSurfacedv(IntPtr p,ref int i_dir,ref double x_c) {
         vis_CoordSysGetSurfacedv(p,ref i_dir,ref x_c);
      }

      public static void CoordSysSetSurfaceSense(IntPtr p,int i_sens) {
         vis_CoordSysSetSurfaceSense(p, i_sens);
      }

      public static void CoordSysGetSurfaceSense(IntPtr p,ref int i_sens) {
         vis_CoordSysGetSurfaceSense(p,ref i_sens);
      }

      public static void CoordSysChkSurfacedv(IntPtr p,double c_l,double [] x_,double [] v_,ref int f_lag) {
         vis_CoordSysChkSurfacedv(p, c_l, x_, v_,ref f_lag);
      }

      public static void CoordSysResolve(IntPtr p,ref int r_esolve) {
         vis_CoordSysResolve(p,ref r_esolve);
      }

      public static void CoordSysDirCos(IntPtr p,float [] x_,float [] t_m) {
         vis_CoordSysDirCos(p, x_, t_m);
      }

      public static void CoordSysDirCosdv(IntPtr p,double [] x_,double [] t_m) {
         vis_CoordSysDirCosdv(p, x_, t_m);
      }

      public static void CoordSysRotAng(IntPtr p,float [] x_,float [] r_a) {
         vis_CoordSysRotAng(p, x_, r_a);
      }

      public static void CoordSysRotAngdv(IntPtr p,double [] x_,double [] r_otang) {
         vis_CoordSysRotAngdv(p, x_, r_otang);
      }

      public static void CoordSysOriginTriad(IntPtr p,float [] x_,float [] t_m) {
         vis_CoordSysOriginTriad(p, x_, t_m);
      }

      public static void CoordSysOriginTriaddv(IntPtr p,double [] x_,double [] t_m) {
         vis_CoordSysOriginTriaddv(p, x_, t_m);
      }

      public static void CoordSysOriginRotAng(IntPtr p,float [] x_,float [] r_otang) {
         vis_CoordSysOriginRotAng(p, x_, r_otang);
      }

      public static void CoordSysOriginRotAngdv(IntPtr p,double [] x_,double [] r_otang) {
         vis_CoordSysOriginRotAngdv(p, x_, r_otang);
      }

      public static void CoordSysConvertCoord(IntPtr p,float [] x_,float [] x_l) {
         vis_CoordSysConvertCoord(p, x_, x_l);
      }

      public static void CoordSysConvertCoorddv(IntPtr p,double [] x_,double [] x_l) {
         vis_CoordSysConvertCoorddv(p, x_, x_l);
      }

      public static void CoordSysComputeCoord(IntPtr p,float [] x_l,float [] x_) {
         vis_CoordSysComputeCoord(p, x_l, x_);
      }

      public static void CoordSysComputeCoorddv(IntPtr p,double [] x_,double [] x_g) {
         vis_CoordSysComputeCoorddv(p, x_, x_g);
      }

      public static void CoordSysProjSurfacedv(IntPtr p,double [] x_,double [] x_p) {
         vis_CoordSysProjSurfacedv(p, x_, x_p);
      }

      public static void CoordSysNormSurfacedv(IntPtr p,double [] x_,double [] v_) {
         vis_CoordSysNormSurfacedv(p, x_, v_);
      }

      public static void CoordSysComputeVector(IntPtr p,float [] x_,float [] v_l,float [] v_) {
         vis_CoordSysComputeVector(p, x_, v_l, v_);
      }

      public static void CoordSysComputeVectordv(IntPtr p,double [] x_,double [] t_,double [] t_g) {
         vis_CoordSysComputeVectordv(p, x_, t_, t_g);
      }

      public static void CoordSysComputeTensor(IntPtr p,float [] x_,float [] t_l,float [] t_) {
         vis_CoordSysComputeTensor(p, x_, t_l, t_);
      }

      public static void CoordSysComputeTensordv(IntPtr p,double [] x_,double [] t_,double [] t_g) {
         vis_CoordSysComputeTensordv(p, x_, t_, t_g);
      }

      public static void CoordSysComputeMatrix(IntPtr p,float [] x_,float [] g_l,float [] g_) {
         vis_CoordSysComputeMatrix(p, x_, g_l, g_);
      }

      public static void CoordSysComputeMatrixdv(IntPtr p,double [] x_,double [] t_,double [] t_g) {
         vis_CoordSysComputeMatrixdv(p, x_, t_, t_g);
      }

      public static void CoordSysConvertVector(IntPtr p,float [] x_,float [] v_,float [] v_l) {
         vis_CoordSysConvertVector(p, x_, v_, v_l);
      }

      public static void CoordSysConvertVectordv(IntPtr p,double [] x_,double [] t_,double [] t_l) {
         vis_CoordSysConvertVectordv(p, x_, t_, t_l);
      }

      public static void CoordSysConvertTensor(IntPtr p,float [] x_,float [] t_,float [] t_l) {
         vis_CoordSysConvertTensor(p, x_, t_, t_l);
      }

      public static void CoordSysConvertTensordv(IntPtr p,double [] x_,double [] t_,double [] t_l) {
         vis_CoordSysConvertTensordv(p, x_, t_, t_l);
      }

      public static void CoordSysConvertMatrix(IntPtr p,float [] x_,float [] g_,float [] g_l) {
         vis_CoordSysConvertMatrix(p, x_, g_, g_l);
      }

      public static void CoordSysConvertMatrixdv(IntPtr p,double [] x_,double [] t_,double [] t_l) {
         vis_CoordSysConvertMatrixdv(p, x_, t_, t_l);
      }

      public static void CoordSysLineInterpolatedv(IntPtr p,double [] x_l,double s_,double [] x_) {
         vis_CoordSysLineInterpolatedv(p, x_l, s_, x_);
      }

      public static void CoordSysQuadSurfaceCoord(IntPtr p,double [] x_,double [] x_s,ref double c_ho,ref double c_hs) {
         vis_CoordSysQuadSurfaceCoord(p, x_, x_s,ref c_ho,ref c_hs);
      }

      public static void CoordSysGetCSystem(IntPtr p,out IntPtr c_system) {
         vis_CoordSysGetCSystem(p,out c_system);
      }

      public static void CoordSysSetId(IntPtr p,int i_d) {
         vis_CoordSysSetId(p, i_d);
      }

      public static void CoordSysGetId(IntPtr p,ref int i_d) {
         vis_CoordSysGetId(p,ref i_d);
      }

      public static void CoordSysSetName(IntPtr p,StringBuilder n_ame) {
         vis_CoordSysSetName(p, n_ame);
      }

      public static void CoordSysGetName(IntPtr p,StringBuilder n_ame) {
         vis_CoordSysGetName(p, n_ame);
      }

      public static void CoordSysPrint(IntPtr p) {
         vis_CoordSysPrint(p);
      }

      public static void CoordSysCopy(IntPtr p,IntPtr q_) {
         vis_CoordSysCopy(p, q_);
      }

      public static void CoordSysTransform(IntPtr p,double [] u_,double [] t_m) {
         vis_CoordSysTransform(p, u_, t_m);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_CPairBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_CPairError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairDef(IntPtr p,int m_astent,int s_lavent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairInq(IntPtr p,ref int m_astent,ref int s_lavent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetType(IntPtr p,int c_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairGetType(IntPtr p,ref int c_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetSlaveNode(IntPtr p,int i_ndex,float a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetSlaveNodedv(IntPtr p,int i_ndex,double a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetSlaveElem(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetMaster(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNodeInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNodeNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNum(IntPtr p,ref int n_umindex,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveFlag(IntPtr p,int i_ndex,ref int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveEnt(IntPtr p,int i_ndex,ref int n_umno,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNode(IntPtr p,int i_ndex,ref float a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNodedv(IntPtr p,int i_ndex,ref double a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterNum(IntPtr p,ref int n_umindex,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterFlag(IntPtr p,int i_ndex,ref int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterEnt(IntPtr p,int i_ndex,ref int n_umno,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetValuef(IntPtr p,int t_ype,float r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueFloat(IntPtr p,int t_ype,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairNodeIdTran(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairFaceIdTran(IntPtr p,int o_per,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairEdgeIdTran(IntPtr p,int o_per,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveNodeMaster(IntPtr p,int i_ndex,ref int i_x,ref int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSetMasterASurf(IntPtr p,int a_sid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterASurf(IntPtr p,ref int a_sid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterSetElementSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairMasterGetElementSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveSetElementSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_CPairSlaveGetElementSetName(IntPtr p,StringBuilder n_ame);

      public static IntPtr CPairBegin() {
         return vis_CPairBegin();
      }

      public static void CPairEnd(IntPtr p) {
         vis_CPairEnd(p);
      }

      public static int CPairError(IntPtr p) {
         return vis_CPairError(p);
      }

      public static void CPairDef(IntPtr p,int m_astent,int s_lavent) {
         vis_CPairDef(p, m_astent, s_lavent);
      }

      public static void CPairInq(IntPtr p,ref int m_astent,ref int s_lavent) {
         vis_CPairInq(p,ref m_astent,ref s_lavent);
      }

      public static void CPairSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_CPairSetObject(p, o_bjecttype, o_bject);
      }

      public static void CPairSetType(IntPtr p,int c_type) {
         vis_CPairSetType(p, c_type);
      }

      public static void CPairGetType(IntPtr p,ref int c_type) {
         vis_CPairGetType(p,ref c_type);
      }

      public static void CPairSetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairSetName(p, n_ame);
      }

      public static void CPairGetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairGetName(p, n_ame);
      }

      public static void CPairSetSlaveNode(IntPtr p,int i_ndex,float a_rea) {
         vis_CPairSetSlaveNode(p, i_ndex, a_rea);
      }

      public static void CPairSetSlaveNodedv(IntPtr p,int i_ndex,double a_rea) {
         vis_CPairSetSlaveNodedv(p, i_ndex, a_rea);
      }

      public static void CPairSetSlaveElem(IntPtr p,int i_ndex,int n_o) {
         vis_CPairSetSlaveElem(p, i_ndex, n_o);
      }

      public static void CPairSetMaster(IntPtr p,int i_ndex,int n_o) {
         vis_CPairSetMaster(p, i_ndex, n_o);
      }

      public static void CPairSlaveInitIter(IntPtr p) {
         vis_CPairSlaveInitIter(p);
      }

      public static void CPairSlaveNextIter(IntPtr p,ref int i_ndex) {
         vis_CPairSlaveNextIter(p,ref i_ndex);
      }

      public static void CPairSlaveNodeInitIter(IntPtr p) {
         vis_CPairSlaveNodeInitIter(p);
      }

      public static void CPairSlaveNodeNextIter(IntPtr p,ref int i_ndex) {
         vis_CPairSlaveNodeNextIter(p,ref i_ndex);
      }

      public static void CPairSlaveMax(IntPtr p,ref int m_axindex) {
         vis_CPairSlaveMax(p,ref m_axindex);
      }

      public static void CPairSlaveNum(IntPtr p,ref int n_umindex,ref int n_umentity) {
         vis_CPairSlaveNum(p,ref n_umindex,ref n_umentity);
      }

      public static void CPairSlaveFlag(IntPtr p,int i_ndex,ref int f_lags) {
         vis_CPairSlaveFlag(p, i_ndex,ref f_lags);
      }

      public static void CPairSlaveEnt(IntPtr p,int i_ndex,ref int n_umno,int [] n_o) {
         vis_CPairSlaveEnt(p, i_ndex,ref n_umno, n_o);
      }

      public static void CPairSlaveNode(IntPtr p,int i_ndex,ref float a_rea) {
         vis_CPairSlaveNode(p, i_ndex,ref a_rea);
      }

      public static void CPairSlaveNodedv(IntPtr p,int i_ndex,ref double a_rea) {
         vis_CPairSlaveNodedv(p, i_ndex,ref a_rea);
      }

      public static void CPairMasterInitIter(IntPtr p) {
         vis_CPairMasterInitIter(p);
      }

      public static void CPairMasterNextIter(IntPtr p,ref int i_ndex) {
         vis_CPairMasterNextIter(p,ref i_ndex);
      }

      public static void CPairMasterMax(IntPtr p,ref int m_axindex) {
         vis_CPairMasterMax(p,ref m_axindex);
      }

      public static void CPairMasterNum(IntPtr p,ref int n_umindex,ref int n_umentity) {
         vis_CPairMasterNum(p,ref n_umindex,ref n_umentity);
      }

      public static void CPairMasterFlag(IntPtr p,int i_ndex,ref int f_lags) {
         vis_CPairMasterFlag(p, i_ndex,ref f_lags);
      }

      public static void CPairMasterEnt(IntPtr p,int i_ndex,ref int n_umno,int [] n_o) {
         vis_CPairMasterEnt(p, i_ndex,ref n_umno, n_o);
      }

      public static void CPairSpecFlag(IntPtr p,ref int f_lag) {
         vis_CPairSpecFlag(p,ref f_lag);
      }

      public static void CPairSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_CPairSetValuei(p, t_ype, i_value);
      }

      public static void CPairSetValuef(IntPtr p,int t_ype,float r_value) {
         vis_CPairSetValuef(p, t_ype, r_value);
      }

      public static void CPairSetValued(IntPtr p,int t_ype,double d_param) {
         vis_CPairSetValued(p, t_ype, d_param);
      }

      public static void CPairValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_CPairValueType(p,ref n_types, t_ype);
      }

      public static void CPairValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_CPairValueFlag(p, t_ype,ref f_lag);
      }

      public static void CPairValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_CPairValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void CPairValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_CPairValueName(p, t_ype, n_ame);
      }

      public static void CPairValueFloat(IntPtr p,int t_ype,float [] f_param) {
         vis_CPairValueFloat(p, t_ype, f_param);
      }

      public static void CPairValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_CPairValueDouble(p, t_ype, d_param);
      }

      public static void CPairValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_CPairValueInteger(p, t_ype, i_param);
      }

      public static void CPairNodeIdTran(IntPtr p,IntPtr i_dtran) {
         vis_CPairNodeIdTran(p, i_dtran);
      }

      public static void CPairFaceIdTran(IntPtr p,int o_per,IntPtr i_dtran) {
         vis_CPairFaceIdTran(p, o_per, i_dtran);
      }

      public static void CPairEdgeIdTran(IntPtr p,int o_per,IntPtr i_dtran) {
         vis_CPairEdgeIdTran(p, o_per, i_dtran);
      }

      public static void CPairSlaveNodeMaster(IntPtr p,int i_ndex,ref int i_x,ref int n_o) {
         vis_CPairSlaveNodeMaster(p, i_ndex,ref i_x,ref n_o);
      }

      public static void CPairPrint(IntPtr p) {
         vis_CPairPrint(p);
      }

      public static void CPairSetMasterASurf(IntPtr p,int a_sid) {
         vis_CPairSetMasterASurf(p, a_sid);
      }

      public static void CPairMasterASurf(IntPtr p,ref int a_sid) {
         vis_CPairMasterASurf(p,ref a_sid);
      }

      public static void CPairMasterSetElementSetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairMasterSetElementSetName(p, n_ame);
      }

      public static void CPairMasterGetElementSetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairMasterGetElementSetName(p, n_ame);
      }

      public static void CPairSlaveSetElementSetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairSlaveSetElementSetName(p, n_ame);
      }

      public static void CPairSlaveGetElementSetName(IntPtr p,StringBuilder n_ame) {
         vis_CPairSlaveGetElementSetName(p, n_ame);
      }

      public const int CPAIR_CONTACT = 1;
      public const int CPAIR_COSIM = 2;
      public const int CPAIR_CYCLIC = 3;
      public const int CPAIR_TIE_DEF = 4;
      public const int CPAIR_MASTER = 1;
      public const int CPAIR_SLAVE = 2;
      public const int CPAIR_UNDEFINED = 0;
      public const int CPAIR_VALUE = 1;
      public const int CPAIR_CURVE = 2;
      public const int CPAIR_PID = 0;
      public const int CPAIR_SMALLSLIDING = 2;
      public const int CPAIR_SYMMETRIC = 7;
      public const int CPAIR_SURFTOSURF = 8;
      public const int CPAIR_PROJECT = 10;
      public const int CPAIR_NUMSECTOR = 11;
      public const int CPAIR_CID = 12;
      public const int CPAIR_MASTER_SET = 13;
      public const int CPAIR_SLAVE_SET = 14;
      public const int CPAIR_CONTACT_BEHAVIOR = 16;
      public const int CPAIR_SEPARATIONTHRESHOLDTYPE = 18;
      public const int CPAIR_ID = 21;
      public const int CPAIR_CYCLIC_MATCHING = 22;
      public const int CPAIR_MATLID = 23;
      public const int CPAIR_ADJUST = 1;
      public const int CPAIR_SMOOTH = 4;
      public const int CPAIR_HCRIT = 5;
      public const int CPAIR_EXTENSIONZONE = 6;
      public const int CPAIR_POSITIONTOL = 9;
      public const int CPAIR_CYCLICTOLERANCE = 15;
      public const int CPAIR_MINPOSITIONTOL = 17;
      public const int CPAIR_SEPARATIONTHRESHOLD = 19;
      public const int CPAIR_BIAS_POSITIONTOL = 20;
      public const int CPAIR_UNUSED = 3;
      public const int CPAIR_MAX = 24;
      public const int CPAIR_CONTACT_BEHAVIOR_STANDARD = 0;
      public const int CPAIR_CONTACT_BEHAVIOR_ROUGH = 1;
      public const int CPAIR_CONTACT_BEHAVIOR_NO_SEPARATION = 2;
      public const int CPAIR_CONTACT_BEHAVIOR_BONDED = 3;
      public const int CPAIR_SEPARATION_FORCE = 0;
      public const int CPAIR_SEPARATION_STRESS = 1;
      public const int CPAIR_SEPARATION_STRESS_EXTRAPOL = 2;
      public const int CPAIR_SEPARATION_STRESS_NODAL = 3;
      public const int CPAIR_SEPARATION_STRESS_RELATIVE = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_DataIntBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_DataIntError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntSetDataPtr(IntPtr p,int i_ndex,int n_rws,float [] d_ataptr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntGetDataPtr(IntPtr p,int i_ndex,ref int n_rws,out float [] d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntSetFunction(IntPtr p,int i_ndex,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntSetDataIntFunction(IntPtr p,int i_ndex,VDataIntFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntCallFunction(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntSetState(IntPtr p,int i_ndex,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntGetState(IntPtr p,int i_ndex,out IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_DataIntCopy(IntPtr p,IntPtr f_romp);

      public static IntPtr DataIntBegin() {
         return vis_DataIntBegin();
      }

      public static void DataIntEnd(IntPtr p) {
         vis_DataIntEnd(p);
      }

      public static int DataIntError(IntPtr p) {
         return vis_DataIntError(p);
      }

      public static void DataIntSetDataPtr(IntPtr p,int i_ndex,int n_rws,float [] d_ataptr) {
         vis_DataIntSetDataPtr(p, i_ndex, n_rws, d_ataptr);
      }

      public static void DataIntGetDataPtr(IntPtr p,int i_ndex,ref int n_rws,out float [] d_ata) {
         vis_DataIntGetDataPtr(p, i_ndex,ref n_rws,out d_ata);
      }

      public static void DataIntSetFunction(IntPtr p,int i_ndex,Vfunc f_unction,IntPtr o_bject) {
         vis_DataIntSetFunction(p, i_ndex, f_unction, o_bject);
      }

      public static void DataIntSetDataIntFunction(IntPtr p,int i_ndex,VDataIntFunc f_unction,IntPtr o_bject) {
         vis_DataIntSetDataIntFunction(p, i_ndex, f_unction, o_bject);
      }

      public static void DataIntCallFunction(IntPtr p,int i_ndex) {
         vis_DataIntCallFunction(p, i_ndex);
      }

      public static void DataIntSetState(IntPtr p,int i_ndex,IntPtr s_tate) {
         vis_DataIntSetState(p, i_ndex, s_tate);
      }

      public static void DataIntGetState(IntPtr p,int i_ndex,out IntPtr s_tate) {
         vis_DataIntGetState(p, i_ndex,out s_tate);
      }

      public static void DataIntCopy(IntPtr p,IntPtr f_romp) {
         vis_DataIntCopy(p, f_romp);
      }

      public const int ELEMCHK_ALL = -1;
      public const int ELEMCHK_JACOBIAN_SUM = 0;
      public const int ELEMCHK_JACOBIAN_RATIO = 1;
      public const int ELEMCHK_JACOBIAN_SMALL = 2;
      public const int ELEMCHK_ASPECT_RATIO = 3;
      public const int ELEMCHK_FACE_TAPER = 4;
      public const int ELEMCHK_SKEW = 5;
      public const int ELEMCHK_TWIST = 6;
      public const int ELEMCHK_SUBTENDED_ANGLE = 7;
      public const int ELEMCHK_CIRCUM_RATIO = 8;
      public const int ELEMCHK_MIN_ANGLE = 9;
      public const int ELEMCHK_FACE_WARP = 10;
      public const int ELEMCHK_CG_X = 11;
      public const int ELEMCHK_CG_Y = 12;
      public const int ELEMCHK_CG_Z = 13;
      public const int ELEMCHK_EDGEALT_RATIO = 14;
      public const int ELEMCHK_JACOBIAN_NODAL = 15;
      public const int ELEMCHK_DIMENSION = 16;
      public const int ELEMCHK_PORDER = 17;
      public const int ELEMCHK_H = 18;
      public const int ELEMCHK_MAX_ANGLE = 19;
      public const int ELEMCHK_MIN_DIHEDANGLE = 20;
      public const int ELEMCHK_MAX_DIHEDANGLE = 21;
      public const int ELEMCHK_HANDEDNESS = 22;
      public const int ELEMCHK_MIN_EDGELENGTH = 23;
      public const int ELEMCHK_MAX_EDGELENGTH = 24;
      public const int ELEMCHK_CORN_WARP = 25;
      public const int ELEMCHK_CORN_SKEW = 26;
      public const int ELEMCHK_MIDSIDE_OFF = 27;
      public const int ELEMCHK_JACOBIAN_CORN = 28;
      public const int ELEMCHK_EDGELENGTH = 29;
      public const int ELEMCHK_MAX = 30;
      public const int ELEMCHK_CHEAP = 1;
      public const int ELEMCHK_ADAPTTOL = 1;
      public const int ELEMCHK_MINREFINE = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ElemChkBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ElemChkError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkSetType(IntPtr p,int t_ype,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkGetType(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkSetParamd(IntPtr p,int p_type,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkDatadv(IntPtr p,int i_ndex,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkData(IntPtr p,int i_ndex,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkRatedv(IntPtr p,IntPtr s_tate,IntPtr g_roup,int i_ndex,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkRate(IntPtr p,IntPtr s_tate,IntPtr g_roup,int i_ndex,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkNormdv(IntPtr p,IntPtr g_roup,int i_ndex,double [] v_n,ref int e_dgeflags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkNorm(IntPtr p,IntPtr g_roup,int i_ndex,float [] v_n,ref int e_dgeflags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkDelaunay(IntPtr p,IntPtr g_roup,int i_ndex,ref int n_ixn,int [] i_xn);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkAdapt(IntPtr p,IntPtr s_etot,IntPtr s_eerr,IntPtr g_roup,IntPtr e_size);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkEnergy(IntPtr p,IntPtr s_tress,IntPtr s_train,IntPtr g_roup,IntPtr s_etot,IntPtr s_eerr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkFaceWeight(IntPtr p,IntPtr g_roup,IntPtr n_weight);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkCompliesWithShapeParameters(IntPtr p,int i_ndex,double [] t_argetShapeParameters,double r_elativeTolerance,ref int a_reShapeParametersCompliant,ref int n_onCompliantShapeParameter);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemChkFindNonCompliedShapeParameters(IntPtr p,int i_ndex,double [] t_argetShapeParameters,double r_elativeTolerance,IntPtr s_hapeParameterCompliantFlags);

      public static IntPtr ElemChkBegin() {
         return vis_ElemChkBegin();
      }

      public static void ElemChkEnd(IntPtr p) {
         vis_ElemChkEnd(p);
      }

      public static int ElemChkError(IntPtr p) {
         return vis_ElemChkError(p);
      }

      public static void ElemChkSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_ElemChkSetObject(p, o_bjecttype, o_bject);
      }

      public static void ElemChkSetType(IntPtr p,int t_ype,int f_lag) {
         vis_ElemChkSetType(p, t_ype, f_lag);
      }

      public static void ElemChkGetType(IntPtr p,int t_ype,ref int f_lag) {
         vis_ElemChkGetType(p, t_ype,ref f_lag);
      }

      public static void ElemChkSetParami(IntPtr p,int p_type,int i_param) {
         vis_ElemChkSetParami(p, p_type, i_param);
      }

      public static void ElemChkSetParamd(IntPtr p,int p_type,double d_param) {
         vis_ElemChkSetParamd(p, p_type, d_param);
      }

      public static void ElemChkDatadv(IntPtr p,int i_ndex,double [] s_) {
         vis_ElemChkDatadv(p, i_ndex, s_);
      }

      public static void ElemChkData(IntPtr p,int i_ndex,float [] s_) {
         vis_ElemChkData(p, i_ndex, s_);
      }

      public static void ElemChkRatedv(IntPtr p,IntPtr s_tate,IntPtr g_roup,int i_ndex,double [] s_) {
         vis_ElemChkRatedv(p, s_tate, g_roup, i_ndex, s_);
      }

      public static void ElemChkRate(IntPtr p,IntPtr s_tate,IntPtr g_roup,int i_ndex,float [] s_) {
         vis_ElemChkRate(p, s_tate, g_roup, i_ndex, s_);
      }

      public static void ElemChkNormdv(IntPtr p,IntPtr g_roup,int i_ndex,double [] v_n,ref int e_dgeflags) {
         vis_ElemChkNormdv(p, g_roup, i_ndex, v_n,ref e_dgeflags);
      }

      public static void ElemChkNorm(IntPtr p,IntPtr g_roup,int i_ndex,float [] v_n,ref int e_dgeflags) {
         vis_ElemChkNorm(p, g_roup, i_ndex, v_n,ref e_dgeflags);
      }

      public static void ElemChkDelaunay(IntPtr p,IntPtr g_roup,int i_ndex,ref int n_ixn,int [] i_xn) {
         vis_ElemChkDelaunay(p, g_roup, i_ndex,ref n_ixn, i_xn);
      }

      public static void ElemChkAdapt(IntPtr p,IntPtr s_etot,IntPtr s_eerr,IntPtr g_roup,IntPtr e_size) {
         vis_ElemChkAdapt(p, s_etot, s_eerr, g_roup, e_size);
      }

      public static void ElemChkEnergy(IntPtr p,IntPtr s_tress,IntPtr s_train,IntPtr g_roup,IntPtr s_etot,IntPtr s_eerr) {
         vis_ElemChkEnergy(p, s_tress, s_train, g_roup, s_etot, s_eerr);
      }

      public static void ElemChkFaceWeight(IntPtr p,IntPtr g_roup,IntPtr n_weight) {
         vis_ElemChkFaceWeight(p, g_roup, n_weight);
      }

      public static void ElemChkCompliesWithShapeParameters(IntPtr p,int i_ndex,double [] t_argetShapeParameters,double r_elativeTolerance,ref int a_reShapeParametersCompliant,ref int n_onCompliantShapeParameter) {
         vis_ElemChkCompliesWithShapeParameters(p, i_ndex, t_argetShapeParameters, r_elativeTolerance,ref a_reShapeParametersCompliant,ref n_onCompliantShapeParameter);
      }

      public static void ElemChkFindNonCompliedShapeParameters(IntPtr p,int i_ndex,double [] t_argetShapeParameters,double r_elativeTolerance,IntPtr s_hapeParameterCompliantFlags) {
         vis_ElemChkFindNonCompliedShapeParameters(p, i_ndex, t_argetShapeParameters, r_elativeTolerance, s_hapeParameterCompliantFlags);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ElemDatBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ElemDatError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatPre(IntPtr p,int p_re);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatGetPre(IntPtr p,ref int i_pre);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype,int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetParamf(IntPtr p,int p_type,float p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatGetComplex(IntPtr p,ref int c_omplexflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetData(IntPtr p,int i_ndex,int n_o,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatSetDatadv(IntPtr p,int i_d,int n_o,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatLng(IntPtr p,ref int l_ng,ref int n_ent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatData(IntPtr p,int i_ndex,int n_o,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatDatadv(IntPtr p,int i_d,int n_o,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatDataStat(IntPtr p,int i_ndex,int n_o,ref int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatNormal(IntPtr p,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatIdTran(IntPtr p,int o_per,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatWrite(IntPtr p,IntPtr r_prop,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ElemDatPrint(IntPtr p);

      public static IntPtr ElemDatBegin() {
         return vis_ElemDatBegin();
      }

      public static void ElemDatEnd(IntPtr p) {
         vis_ElemDatEnd(p);
      }

      public static int ElemDatError(IntPtr p) {
         return vis_ElemDatError(p);
      }

      public static void ElemDatPre(IntPtr p,int p_re) {
         vis_ElemDatPre(p, p_re);
      }

      public static void ElemDatGetPre(IntPtr p,ref int i_pre) {
         vis_ElemDatGetPre(p,ref i_pre);
      }

      public static void ElemDatSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_ElemDatSetObject(p, o_bjecttype, o_bject);
      }

      public static void ElemDatGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_ElemDatGetObject(p, o_bjecttype,out o_bject);
      }

      public static void ElemDatDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype,int d_atatype) {
         vis_ElemDatDef(p, n_ument, p_arenttype, c_hildtype, d_atatype);
      }

      public static void ElemDatInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype) {
         vis_ElemDatInq(p,ref n_ument,ref e_nttype,ref s_ubtype,ref d_atatype);
      }

      public static void ElemDatSetParami(IntPtr p,int p_type,int i_param) {
         vis_ElemDatSetParami(p, p_type, i_param);
      }

      public static void ElemDatSetParamf(IntPtr p,int p_type,float p_aram) {
         vis_ElemDatSetParamf(p, p_type, p_aram);
      }

      public static void ElemDatSetComplexMode(IntPtr p,int c_omplexmode) {
         vis_ElemDatSetComplexMode(p, c_omplexmode);
      }

      public static void ElemDatGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_ElemDatGetComplexMode(p,ref c_omplexmode);
      }

      public static void ElemDatGetComplex(IntPtr p,ref int c_omplexflag) {
         vis_ElemDatGetComplex(p,ref c_omplexflag);
      }

      public static void ElemDatSetData(IntPtr p,int i_ndex,int n_o,float [] s_) {
         vis_ElemDatSetData(p, i_ndex, n_o, s_);
      }

      public static void ElemDatSetDatadv(IntPtr p,int i_d,int n_o,double [] s_) {
         vis_ElemDatSetDatadv(p, i_d, n_o, s_);
      }

      public static void ElemDatLng(IntPtr p,ref int l_ng,ref int n_ent) {
         vis_ElemDatLng(p,ref l_ng,ref n_ent);
      }

      public static void ElemDatData(IntPtr p,int i_ndex,int n_o,float [] s_) {
         vis_ElemDatData(p, i_ndex, n_o, s_);
      }

      public static void ElemDatDatadv(IntPtr p,int i_d,int n_o,double [] s_) {
         vis_ElemDatDatadv(p, i_d, n_o, s_);
      }

      public static void ElemDatClear(IntPtr p) {
         vis_ElemDatClear(p);
      }

      public static void ElemDatDataStat(IntPtr p,int i_ndex,int n_o,ref int s_tat) {
         vis_ElemDatDataStat(p, i_ndex, n_o,ref s_tat);
      }

      public static void ElemDatNormal(IntPtr p,IntPtr g_roup) {
         vis_ElemDatNormal(p, g_roup);
      }

      public static void ElemDatIdTran(IntPtr p,int o_per,IntPtr i_dtran) {
         vis_ElemDatIdTran(p, o_per, i_dtran);
      }

      public static void ElemDatWrite(IntPtr p,IntPtr r_prop,int t_ype,StringBuilder p_ath) {
         vis_ElemDatWrite(p, r_prop, t_ype, p_ath);
      }

      public static void ElemDatCopy(IntPtr p,IntPtr f_romp) {
         vis_ElemDatCopy(p, f_romp);
      }

      public static void ElemDatPrint(IntPtr p) {
         vis_ElemDatPrint(p);
      }

      public const int ELEMDAT_SETDATA = 1;
      public const int ELEMDAT_LINNORMAL = 3;
      public const int ELEMDAT_FEATUREBRANCH = 2;
      public const int ELEMDAT_FEATUREANGLE = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_EPropBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_EPropError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropDef(IntPtr p,int p_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropInq(IntPtr p,ref int e_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropMatNum(IntPtr p,ref int n_dof);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropMatCon(IntPtr p,int [] i_con,int [] i_dof);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValueiv(IntPtr p,int t_ype,int [] i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValuef(IntPtr p,int t_ype,float r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValuefv(IntPtr p,int t_ype,float [] r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValuedv(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetValueId(IntPtr p,int t_ype,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropUnSetValue(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueTypeNum(IntPtr p,ref int n_types);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueId(IntPtr p,int t_ype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int n_loc,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueFloat(IntPtr p,int t_ype,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropFill(IntPtr p,IntPtr e_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropStreamNum(IntPtr p,int s_trmtype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropEval(IntPtr p,int t_ype,int s_hape,int m_axi,int m_axj,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropEvaldv(IntPtr p,int t_ype,int s_hape,int m_axi,int m_axj,double [] d_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_EPropPrint(IntPtr p);

      public static IntPtr EPropBegin() {
         return vis_EPropBegin();
      }

      public static void EPropEnd(IntPtr p) {
         vis_EPropEnd(p);
      }

      public static int EPropError(IntPtr p) {
         return vis_EPropError(p);
      }

      public static void EPropDef(IntPtr p,int p_type) {
         vis_EPropDef(p, p_type);
      }

      public static void EPropInq(IntPtr p,ref int e_type) {
         vis_EPropInq(p,ref e_type);
      }

      public static void EPropSetParami(IntPtr p,int t_ype,int i_param) {
         vis_EPropSetParami(p, t_ype, i_param);
      }

      public static void EPropMatNum(IntPtr p,ref int n_dof) {
         vis_EPropMatNum(p,ref n_dof);
      }

      public static void EPropMatCon(IntPtr p,int [] i_con,int [] i_dof) {
         vis_EPropMatCon(p, i_con, i_dof);
      }

      public static void EPropSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_EPropSetValuei(p, t_ype, i_value);
      }

      public static void EPropSetValueiv(IntPtr p,int t_ype,int [] i_value) {
         vis_EPropSetValueiv(p, t_ype, i_value);
      }

      public static void EPropSetValuef(IntPtr p,int t_ype,float r_value) {
         vis_EPropSetValuef(p, t_ype, r_value);
      }

      public static void EPropSetValuefv(IntPtr p,int t_ype,float [] r_value) {
         vis_EPropSetValuefv(p, t_ype, r_value);
      }

      public static void EPropSetValued(IntPtr p,int t_ype,double d_param) {
         vis_EPropSetValued(p, t_ype, d_param);
      }

      public static void EPropSetValuedv(IntPtr p,int t_ype,double [] d_param) {
         vis_EPropSetValuedv(p, t_ype, d_param);
      }

      public static void EPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value) {
         vis_EPropSetValuec(p, t_ype, c_value);
      }

      public static void EPropSetValueId(IntPtr p,int t_ype,int i_d) {
         vis_EPropSetValueId(p, t_ype, i_d);
      }

      public static void EPropUnSetValue(IntPtr p,int t_ype) {
         vis_EPropUnSetValue(p, t_ype);
      }

      public static void EPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at) {
         vis_EPropAddUserValue(p, n_dim, n_ame, d_im, d_type,ref d_at);
      }

      public static void EPropValueTypeNum(IntPtr p,ref int n_types) {
         vis_EPropValueTypeNum(p,ref n_types);
      }

      public static void EPropValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_EPropValueType(p,ref n_types, t_ype);
      }

      public static void EPropValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_EPropValueFlag(p, t_ype,ref f_lag);
      }

      public static void EPropValueId(IntPtr p,int t_ype,ref int i_d) {
         vis_EPropValueId(p, t_ype,ref i_d);
      }

      public static void EPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int n_loc,ref int d_typ) {
         vis_EPropValueParams(p, t_ype,ref n_val,ref n_loc,ref d_typ);
      }

      public static void EPropValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_EPropValueName(p, t_ype, n_ame);
      }

      public static void EPropValueFloat(IntPtr p,int t_ype,float [] f_param) {
         vis_EPropValueFloat(p, t_ype, f_param);
      }

      public static void EPropValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_EPropValueDouble(p, t_ype, d_param);
      }

      public static void EPropValueString(IntPtr p,int t_ype,StringBuilder c_param) {
         vis_EPropValueString(p, t_ype, c_param);
      }

      public static void EPropValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_EPropValueInteger(p, t_ype, i_param);
      }

      public static void EPropFill(IntPtr p,IntPtr e_prop) {
         vis_EPropFill(p, e_prop);
      }

      public static void EPropStreamNum(IntPtr p,int s_trmtype,ref int n_um) {
         vis_EPropStreamNum(p, s_trmtype,ref n_um);
      }

      public static void EPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata) {
         vis_EPropStreamSave(p, s_trmtype,ref d_ata);
      }

      public static void EPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata) {
         vis_EPropStreamLoad(p, s_trmtype, n_dat,ref d_ata);
      }

      public static void EPropSetId(IntPtr p,int i_d) {
         vis_EPropSetId(p, i_d);
      }

      public static void EPropGetId(IntPtr p,ref int i_d) {
         vis_EPropGetId(p,ref i_d);
      }

      public static void EPropSetName(IntPtr p,StringBuilder n_ame) {
         vis_EPropSetName(p, n_ame);
      }

      public static void EPropGetName(IntPtr p,StringBuilder n_ame) {
         vis_EPropGetName(p, n_ame);
      }

      public static void EPropEval(IntPtr p,int t_ype,int s_hape,int m_axi,int m_axj,float [] v_alue) {
         vis_EPropEval(p, t_ype, s_hape, m_axi, m_axj, v_alue);
      }

      public static void EPropEvaldv(IntPtr p,int t_ype,int s_hape,int m_axi,int m_axj,double [] d_value) {
         vis_EPropEvaldv(p, t_ype, s_hape, m_axi, m_axj, d_value);
      }

      public static void EPropCopy(IntPtr p,IntPtr f_romp) {
         vis_EPropCopy(p, f_romp);
      }

      public static void EPropPrint(IntPtr p) {
         vis_EPropPrint(p);
      }

      public const int EPROP_UNDEFINED = 0;
      public const int EPROP_VALUE = 1;
      public const int EPROP_IDENTIFIER = 2;
      public const int EPROP_360 = 1;
      public const int EPROP_MID = 0;
      public const int EPROP_MID_BEND = 1;
      public const int EPROP_MID_TRAN = 2;
      public const int EPROP_MID_COUP = 3;
      public const int EPROP_MATLCID = 5;
      public const int EPROP_RULE = 6;
      public const int EPROP_NOSEPARATION = 45;
      public const int EPROP_NOSLIP = 46;
      public const int EPROP_DOF1 = 49;
      public const int EPROP_DOF2 = 50;
      public const int EPROP_HEATEXCH = 62;
      public const int EPROP_BEAMSECT = 81;
      public const int EPROP_DOFFLAG_NUM = 83;
      public const int EPROP_DOFFLAG_IND = 85;
      public const int EPROP_DOFFLAG_DEP = 86;
      public const int EPROP_SHELLWALL = 89;
      public const int EPROP_LAYER_NUM = 96;
      public const int EPROP_LAYER_MID = 99;
      public const int EPROP_LAYER_NIP = 100;
      public const int EPROP_BEAMREFLECTY = 102;
      public const int EPROP_BEAMREFLECTZ = 103;
      public const int EPROP_BEAMPNTS_NUM = 111;
      public const int EPROP_BEAMLOOP_NUM = 113;
      public const int EPROP_BEAMLOOP_PNTSNUM = 114;
      public const int EPROP_BEAMLOOP_TYPE = 115;
      public const int EPROP_BEAMLOOP_MID = 116;
      public const int EPROP_BEAMLOOP_PNTS = 117;
      public const int EPROP_BEAMSEGS_NUM = 118;
      public const int EPROP_LAYER_GID = 130;
      public const int EPROP_TIED = 136;
      public const int EPROP_NSM_ID = 141;
      public const int EPROP_NSM_NUM = 142;
      public const int EPROP_NSM_VAL_SETIDS = 144;
      public const int EPROP_NSM_VAL_LUMP = 145;
      public const int EPROP_BEND_FLEXFACTOR = 150;
      public const int EPROP_AMBIENT_TYPE = 154;
      public const int EPROP_GALERKIN_SPLINE_TYPE = 158;
      public const int EPROP_GALERKIN_DILATION_TYPE = 159;
      public const int EPROP_GALERKIN_ESSENTIAL_BC_TYPE = 160;
      public const int EPROP_GALERKIN_DOMAIN_INTEGRATION_TYPE = 161;
      public const int EPROP_GALERKIN_PRESSURE_SMOOTHING = 163;
      public const int EPROP_GALERKIN_KERNEL = 164;
      public const int EPROP_GALERKIN_SMOOTHING_STEPS_INTERVAL = 165;
      public const int EPROP_GALERKIN_SMOOTHING_SCHEME = 166;
      public const int EPROP_GALERKIN_BOND_FAILURE_TYPE = 167;
      public const int EPROP_GALERKIN_STABILIZATION_TYPE = 170;
      public const int EPROP_GALERKIN_SELF_CONTACT = 172;
      public const int EPROP_GALERKIN_BOX_ID = 173;
      public const int EPROP_TENSION_TABLES = 179;
      public const int EPROP_REINFSECT_NUM = 180;
      public const int EPROP_REINFSECT = 181;
      public const int EPROP_REINFSECT_MID = 182;
      public const int EPROP_REINFSECT_CID = 185;
      public const int EPROP_REINFSECT_LOCATION_TYPE = 187;
      public const int EPROP_COHESIVE_RESPONSE_TYPE = 188;
      public const int EPROP_FRICTION_TYPE = 189;
      public const int EPROP_THICKNESS = 7;
      public const int EPROP_OFFSET = 8;
      public const int EPROP_KS = 9;
      public const int EPROP_BENDSTF = 10;
      public const int EPROP_NSM = 11;
      public const int EPROP_SRBOT = 12;
      public const int EPROP_SRTOP = 13;
      public const int EPROP_AREA = 14;
      public const int EPROP_IYY = 15;
      public const int EPROP_IZZ = 16;
      public const int EPROP_IYZ = 17;
      public const int EPROP_J = 18;
      public const int EPROP_KSY = 19;
      public const int EPROP_KSZ = 20;
      public const int EPROP_DSY = 21;
      public const int EPROP_DSZ = 22;
      public const int EPROP_OFFSETY = 23;
      public const int EPROP_OFFSETZ = 24;
      public const int EPROP_CW = 25;
      public const int EPROP_DIN = 26;
      public const int EPROP_DOUT = 27;
      public const int EPROP_BENDRADIUS = 28;
      public const int EPROP_STRSCOEFROT = 29;
      public const int EPROP_SRC = 30;
      public const int EPROP_SRD = 31;
      public const int EPROP_SRE = 32;
      public const int EPROP_SRF = 33;
      public const int EPROP_UZERO = 34;
      public const int EPROP_FZERO = 35;
      public const int EPROP_KCLOSE = 36;
      public const int EPROP_KOPEN = 37;
      public const int EPROP_KTRANS = 38;
      public const int EPROP_MUSY = 39;
      public const int EPROP_MUSZ = 40;
      public const int EPROP_MU_ISO = 39;
      public const int EPROP_MU1_ORTHO = 39;
      public const int EPROP_MU2_ORTHO = 40;
      public const int EPROP_MUKY = 41;
      public const int EPROP_MUKZ = 42;
      public const int EPROP_STIFF = 47;
      public const int EPROP_DAMP = 48;
      public const int EPROP_MASS = 51;
      public const int EPROP_OFFSETVEC = 52;
      public const int EPROP_INERTIA = 53;
      public const int EPROP_MASSMATRIX = 54;
      public const int EPROP_STIFFMATRIX = 55;
      public const int EPROP_PENALTY = 56;
      public const int EPROP_FILM = 61;
      public const int EPROP_CONVEXP = 63;
      public const int EPROP_AREAFACT = 64;
      public const int EPROP_STRSCOEF = 65;
      public const int EPROP_STIFFTRA = 74;
      public const int EPROP_STIFFROT = 75;
      public const int EPROP_DAMPTRA = 76;
      public const int EPROP_DAMPROT = 77;
      public const int EPROP_STRSCOEFTRA = 78;
      public const int EPROP_STRNCOEFTRA = 79;
      public const int EPROP_STRNCOEFROT = 80;
      public const int EPROP_BEAMDIME = 82;
      public const int EPROP_DOFFLAG_WGTS = 84;
      public const int EPROP_SHELLMATRIX = 90;
      public const int EPROP_SHELLALPHA = 91;
      public const int EPROP_QMATRIX = 92;
      public const int EPROP_QALPHA = 93;
      public const int EPROP_BEAMMATRIX = 94;
      public const int EPROP_BEAMALPHA = 95;
      public const int EPROP_LAYER_THK = 97;
      public const int EPROP_LAYER_PHI = 98;
      public const int EPROP_ECC = 101;
      public const int EPROP_BEAMROTANGLE = 104;
      public const int EPROP_RIGIDALPHA = 108;
      public const int EPROP_BEAMPNTS = 112;
      public const int EPROP_BEAMSEGS_THICK = 119;
      public const int EPROP_BEAMSEGS_PNTS = 120;
      public const int EPROP_EMIS = 135;
      public const int EPROP_SDAMP = 137;
      public const int EPROP_SDAMPTRA = 138;
      public const int EPROP_SDAMPROT = 139;
      public const int EPROP_NSM_VAL = 143;
      public const int EPROP_BEND_THETA = 146;
      public const int EPROP_BEND_INTERNALPRESSURE = 147;
      public const int EPROP_BEND_RCOFFSET = 148;
      public const int EPROP_BEND_ZCOFFSET = 149;
      public const int EPROP_BEND_ROFFSET = 151;
      public const int EPROP_BEND_RADIUSMEAN = 152;
      public const int EPROP_COHESIVE_LAYER = 155;
      public const int EPROP_GASKET_THICKNESS = 156;
      public const int EPROP_GALERKIN_DILATION_PARAMETERS = 157;
      public const int EPROP_GALERKIN_DEFORMATION_TOLERANCE = 162;
      public const int EPROP_GALERKIN_CRITICAL_BOND_FAILURE = 168;
      public const int EPROP_GALERKIN_CRITICAL_STRETCH = 169;
      public const int EPROP_GALERKIN_SHEAR_LOCKING_FACTOR = 171;
      public const int EPROP_GALERKIN_PARTICLE_DAMPING = 174;
      public const int EPROP_GALERKIN_SWITCH_TIME_LTE = 175;
      public const int EPROP_GALERKIN_LENGTH_SCALE = 176;
      public const int EPROP_VISCOUS_DAMP_TC = 177;
      public const int EPROP_VISCOUS_EXPNT_TC = 178;
      public const int EPROP_REINFSECT_AREA = 183;
      public const int EPROP_REINFSECT_FIBER_DISTANCE = 184;
      public const int EPROP_REINFSECT_THETA = 186;
      public const int EPROP_CID = 4;
      public const int EPROP_UDELTA = 43;
      public const int EPROP_KDELTA = 44;
      public const int EPROP_NUMDIST = 57;
      public const int EPROP_WEIGHTS = 58;
      public const int EPROP_DOFFLAGDEP = 59;
      public const int EPROP_DOFFLAGIND = 60;
      public const int EPROP_CONVEXCH = 62;
      public const int EPROP_ELEMPOINT = 66;
      public const int EPROP_ELEMLINE = 67;
      public const int EPROP_ELEMTRI = 68;
      public const int EPROP_ELEMQUAD = 69;
      public const int EPROP_ELEMTET = 70;
      public const int EPROP_ELEMPYR = 71;
      public const int EPROP_ELEMWED = 72;
      public const int EPROP_ELEMHEX = 73;
      public const int EPROP_SHEAR_F1 = 87;
      public const int EPROP_SHEAR_F2 = 88;
      public const int EPROP_SOLIDMIX = 105;
      public const int EPROP_MIX_NUM = 106;
      public const int EPROP_MIX_MID = 107;
      public const int EPROP_KSYZ = 121;
      public const int EPROP_SUPER_MASSTYPE = 122;
      public const int EPROP_SUPER_STIFFTYPE = 123;
      public const int EPROP_SUPER_MASS = 124;
      public const int EPROP_SUPER_STIFF = 125;
      public const int EPROP_SUPER_ID = 126;
      public const int EPROP_SUPER_TRANS = 127;
      public const int EPROP_SUPER_ORIGIN = 128;
      public const int EPROP_SUPER_DIRCOS = 129;
      public const int EPROP_ORIGIN = 131;
      public const int EPROP_TRANS = 132;
      public const int EPROP_ROTANG = 133;
      public const int EPROP_USER_NUM = 134;
      public const int EPROP_COMP_PSDIR = 140;
      public const int EPROP_FORMULATION = 153;
      public const int EPROP_MAX = 190;
      public const int EPROP_USERDIMENUM = -1000000;
      public const int EPROP_USERDIME = -2000000;
      public const int EPROP_USERNAME = -3000000;
      public const int EPROP_USERDATATYPE = -4000000;
      public const int EPROP_USERDATA = -5000000;
      public const int EPROP_USERBASE = -5000000;
      public const int EPROP_FRICTION_NOFRICTION = 0;
      public const int EPROP_FRICTION_BILINEAR_COULOMB = 1;
      public const int EPROP_FRICTION_BILINEAR_SHEAR = 2;
      public const int COHESIVE_RESP_NONE = 0;
      public const int COHESIVE_RESP_TRACTIONSEPARATION = 1;
      public const int COHESIVE_RESP_CONTINUUM = 2;
      public const int COHESIVE_RESP_GASKET = 3;

      public const int GEOMFUN_OPEN = 1;
      public const int GEOMFUN_CLOSE = 2;
      public const int GEOMFUN_MODELLER = 4;
      public const int GEOMFUN_NUMBODY = 5;
      public const int GEOMFUN_BODY = 6;
      public const int GEOMFUN_FACE = 7;
      public const int GEOMFUN_EDGE = 8;
      public const int GEOMFUN_NODE = 9;
      public const int GEOMFUN_FACELOOP = 10;
      public const int GEOMFUN_EXTENT = 11;
      public const int GEOMFUN_EDGEPOINT = 12;
      public const int GEOMFUN_EDGENEAREST = 13;
      public const int GEOMFUN_FACEPOINT = 14;
      public const int GEOMFUN_FACENEAREST = 15;
      public const int GEOMFUN_FACENORMAL = 16;
      public const int GEOMFUN_ERROR = 17;
      public const int GEOMFUN_MAX = 18;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_GeomFunBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GeomFunError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunSet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunGet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunSetObj(IntPtr p,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunGetObj(IntPtr p,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GeomFunCopy(IntPtr p,IntPtr f_romp);

      public static IntPtr GeomFunBegin() {
         return vis_GeomFunBegin();
      }

      public static void GeomFunEnd(IntPtr p) {
         vis_GeomFunEnd(p);
      }

      public static int GeomFunError(IntPtr p) {
         return vis_GeomFunError(p);
      }

      public static void GeomFunInit(IntPtr p) {
         vis_GeomFunInit(p);
      }

      public static void GeomFunSet(IntPtr p,int t_ype,Vfunc f_unction) {
         vis_GeomFunSet(p, t_ype, f_unction);
      }

      public static void GeomFunGet(IntPtr p,int t_ype,Vfunc f_unction) {
         vis_GeomFunGet(p, t_ype, f_unction);
      }

      public static void GeomFunSetObj(IntPtr p,IntPtr o_bj) {
         vis_GeomFunSetObj(p, o_bj);
      }

      public static void GeomFunGetObj(IntPtr p,out IntPtr o_bj) {
         vis_GeomFunGetObj(p,out o_bj);
      }

      public static void GeomFunCopy(IntPtr p,IntPtr f_romp) {
         vis_GeomFunCopy(p, f_romp);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_GPropBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GPropError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValueiv(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValuef(IntPtr p,int t_ype,float f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValuefv(IntPtr p,int t_ype,float [] r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValuedv(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropSetValueId(IntPtr p,int t_ype,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropUnSetValue(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueTypeNum(IntPtr p,ref int n_types);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueId(IntPtr p,int t_ype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueFloat(IntPtr p,int i_d,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueDouble(IntPtr p,int i_d,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropStreamNum(IntPtr p,int s_trmtype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GPropPrint(IntPtr p);

      public static IntPtr GPropBegin() {
         return vis_GPropBegin();
      }

      public static void GPropEnd(IntPtr p) {
         vis_GPropEnd(p);
      }

      public static int GPropError(IntPtr p) {
         return vis_GPropError(p);
      }

      public static void GPropSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_GPropSetValuei(p, t_ype, i_value);
      }

      public static void GPropSetValueiv(IntPtr p,int t_ype,int [] i_param) {
         vis_GPropSetValueiv(p, t_ype, i_param);
      }

      public static void GPropSetValuef(IntPtr p,int t_ype,float f_param) {
         vis_GPropSetValuef(p, t_ype, f_param);
      }

      public static void GPropSetValuefv(IntPtr p,int t_ype,float [] r_value) {
         vis_GPropSetValuefv(p, t_ype, r_value);
      }

      public static void GPropSetValued(IntPtr p,int t_ype,double d_param) {
         vis_GPropSetValued(p, t_ype, d_param);
      }

      public static void GPropSetValuedv(IntPtr p,int t_ype,double [] d_param) {
         vis_GPropSetValuedv(p, t_ype, d_param);
      }

      public static void GPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value) {
         vis_GPropSetValuec(p, t_ype, c_value);
      }

      public static void GPropSetValueId(IntPtr p,int t_ype,int i_d) {
         vis_GPropSetValueId(p, t_ype, i_d);
      }

      public static void GPropUnSetValue(IntPtr p,int t_ype) {
         vis_GPropUnSetValue(p, t_ype);
      }

      public static void GPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at) {
         vis_GPropAddUserValue(p, n_dim, n_ame, d_im, d_type,ref d_at);
      }

      public static void GPropValueTypeNum(IntPtr p,ref int n_types) {
         vis_GPropValueTypeNum(p,ref n_types);
      }

      public static void GPropValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_GPropValueType(p,ref n_types, t_ype);
      }

      public static void GPropValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_GPropValueFlag(p, t_ype,ref f_lag);
      }

      public static void GPropValueId(IntPtr p,int t_ype,ref int i_d) {
         vis_GPropValueId(p, t_ype,ref i_d);
      }

      public static void GPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_GPropValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void GPropValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_GPropValueName(p, t_ype, n_ame);
      }

      public static void GPropValueFloat(IntPtr p,int i_d,float [] f_param) {
         vis_GPropValueFloat(p, i_d, f_param);
      }

      public static void GPropValueDouble(IntPtr p,int i_d,double [] d_param) {
         vis_GPropValueDouble(p, i_d, d_param);
      }

      public static void GPropValueString(IntPtr p,int t_ype,StringBuilder c_param) {
         vis_GPropValueString(p, t_ype, c_param);
      }

      public static void GPropValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_GPropValueInteger(p, t_ype, i_param);
      }

      public static void GPropStreamNum(IntPtr p,int s_trmtype,ref int n_um) {
         vis_GPropStreamNum(p, s_trmtype,ref n_um);
      }

      public static void GPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata) {
         vis_GPropStreamSave(p, s_trmtype,ref d_ata);
      }

      public static void GPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata) {
         vis_GPropStreamLoad(p, s_trmtype, n_dat,ref d_ata);
      }

      public static void GPropPrint(IntPtr p) {
         vis_GPropPrint(p);
      }

      public const int GPROP_UNDEFINED = 0;
      public const int GPROP_VALUE = 1;
      public const int GPROP_IDENTIFIER = 2;
      public const int GPROP_TITLE = 3;
      public const int GPROP_SUBTITLE = 4;
      public const int GPROP_ORIGCODE = 5;
      public const int GPROP_ORIGVERSION = 6;
      public const int GPROP_ORIGTIME = 7;
      public const int GPROP_ORIGDATE = 8;
      public const int GPROP_2DPLANE = 0;
      public const int GPROP_2DTYPE = 1;
      public const int GPROP_LIBRARY = 2;
      public const int GPROP_2DAXIS = 15;
      public const int GPROP_AUTOSPC = 22;
      public const int GPROP_IMPORT_VENDOR = 25;
      public const int GPROP_EXPORT_VENDOR = 26;
      public const int GPROP_CYCLIC_NSEC = 10;
      public const int GPROP_SYMM_NUM = 16;
      public const int GPROP_SYMM_ID = 17;
      public const int GPROP_SYMM_CID = 18;
      public const int GPROP_SYMM_NSEC = 19;
      public const int GPROP_SYMM_STAGEID = 27;
      public const int GPROP_CYCLIC_CSYSID = 28;
      public const int GPROP_PERMANENT_GLUE = 29;
      public const int GPROP_SYMM_ESET = 24;
      public const int GPROP_CYCLIC_ORIG = 11;
      public const int GPROP_CYCLIC_AXIS = 12;
      public const int GPROP_STEFAN_BOLTZMANN = 13;
      public const int GPROP_ABSOLUTE_ZERO = 14;
      public const int GPROP_SYMM_ORIG = 20;
      public const int GPROP_SYMM_AXIS = 21;
      public const int GPROP_STIFF_DAMP = 23;
      public const int GPROP_USER_NUM = 9;
      public const int GPROP_MAX = 30;
      public const int GPROP_USERDIMENUM = -1000000;
      public const int GPROP_USERDIME = -2000000;
      public const int GPROP_USERNAME = -3000000;
      public const int GPROP_USERDATATYPE = -4000000;
      public const int GPROP_USERDATA = -5000000;
      public const int GPROP_USERBASE = -5000000;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_GridFunBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GridFunError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunInit(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetErrorFunction(IntPtr p,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunGet(IntPtr p,int t_ype,Vfunc f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetObj(IntPtr p,IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunGetObj(IntPtr p,out IntPtr o_bj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunMallocElemNode(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunFreeElemNode(IntPtr p,ref IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunMallocNodeElem(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunFreeNodeElem(IntPtr p,ref IntPtr p_tr);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumber(IntPtr p,int t_ype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunTopology(IntPtr p,int i_d,ref int s_hape,ref int m_axi,ref int m_axj,ref int m_axk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunMaxElemNode(IntPtr p,ref int m_axnum);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemNode(IntPtr p,int i_d,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunCoords(IntPtr p,int n_ids,int [] i_ds,float [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunCoordsdv(IntPtr p,int n_ids,int [] i_ds,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNodeAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunMaxNodeElem(IntPtr p,ref int m_axnum);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNodeElem(IntPtr p,int i_d,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemAdj(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemNum(IntPtr p,int t_ype,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemCon(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemCnn(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemTopo(IntPtr p,int t_ype,int i_d,int n_o,ref int s_hapet,ref int m_axit,ref int m_axjt);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunExtent(IntPtr p,IntPtr g_roup,float [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunLngElemNode(IntPtr p,ref long l_ng);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumElemNode(IntPtr p,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumNodeElem(IntPtr p,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNodeAdj(IntPtr p,int n_ix,int [] i_x,ref int n_idadj,int [] i_dadj);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemCorn(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunIndElemNode(IntPtr p,int i_d,ref long n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunDimension(IntPtr p,ref int n_dim);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunExtentdv(IntPtr p,IntPtr g_roup,double [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_d,int n_o,ref int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNodeNode(IntPtr p,int i_d,ref int n_ix,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumEIP(IntPtr p,int i_d,ref int n_umeip);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunLngEIP(IntPtr p,ref long l_ngeip);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunIndEIP(IntPtr p,int i_d,ref long i_ndeip);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunPartName(IntPtr p,int p_artid,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumPartName(IntPtr p,ref int n_umname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunIthPartName(IntPtr p,int i_th,ref int p_artid,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNumberFun(IntPtr p,VGridFunNumber f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetTopologyFun(IntPtr p,VGridFunTopology f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemNodeFun(IntPtr p,VGridFunElemNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetMaxElemNodeFun(IntPtr p,VGridFunMaxElemNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetCoordsFun(IntPtr p,VGridFunCoords f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNodeAssocFun(IntPtr p,VGridFunNodeAssoc f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemAssocFun(IntPtr p,VGridFunElemAssoc f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetSetElemNumFun(IntPtr p,VGridFunElemNum f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemConFun(IntPtr p,VGridFunElemCon f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemTopoFun(IntPtr p,VGridFunElemTopo f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemAdjFun(IntPtr p,VGridFunElemAdj f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetMaxNodeElemFun(IntPtr p,VGridFunMaxNodeElem f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNodeElemFun(IntPtr p,VGridFunNodeElem f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetExtentFun(IntPtr p,VGridFunExtent f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemCnnFun(IntPtr p,VGridFunElemCnn f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNodeAdjFun(IntPtr p,VGridFunNodeAdj f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetCoordsdvFun(IntPtr p,VGridFunCoordsdv f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetLngElemNodeFun(IntPtr p,VGridFunLngElemNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetErrorFun(IntPtr p,VGridFunError f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNumElemNodeFun(IntPtr p,VGridFunNumElemNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetNumNodeElemFun(IntPtr p,VGridFunNumNodeElem f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemCornFun(IntPtr p,VGridFunElemCorn f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetIndElemNodeFun(IntPtr p,VGridFunIndElemNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetDimensionFun(IntPtr p,VGridFunDimension f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetExtentdvFun(IntPtr p,VGridFunExtentdv f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunSetElemEntAssocFun(IntPtr p,VGridFunElemEntAssoc f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNodeNodeFun(IntPtr p,VGridFunNodeNode f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumEIPFun(IntPtr p,VGridFunNumEIP f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunLngEIPFun(IntPtr p,VGridFunLngEIP f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunIndEIPFun(IntPtr p,VGridFunIndEIP f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunPartNameFun(IntPtr p,VGridFunPartName f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunNumPartNameFun(IntPtr p,VGridFunNumPartName f_unc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GridFunIthPartNameFun(IntPtr p,VGridFunIthPartName f_unc);

      public static IntPtr GridFunBegin() {
         return vis_GridFunBegin();
      }

      public static void GridFunEnd(IntPtr p) {
         vis_GridFunEnd(p);
      }

      public static int GridFunError(IntPtr p) {
         return vis_GridFunError(p);
      }

      public static void GridFunInit(IntPtr p) {
         vis_GridFunInit(p);
      }

      public static void GridFunSet(IntPtr p,int t_ype,Vfunc f_unction) {
         vis_GridFunSet(p, t_ype, f_unction);
      }

      public static void GridFunSetErrorFunction(IntPtr p,Vfunc f_unction) {
         vis_GridFunSetErrorFunction(p, f_unction);
      }

      public static void GridFunGet(IntPtr p,int t_ype,Vfunc f_unction) {
         vis_GridFunGet(p, t_ype, f_unction);
      }

      public static void GridFunSetObj(IntPtr p,IntPtr o_bj) {
         vis_GridFunSetObj(p, o_bj);
      }

      public static void GridFunGetObj(IntPtr p,out IntPtr o_bj) {
         vis_GridFunGetObj(p,out o_bj);
      }

      public static void GridFunCopy(IntPtr p,IntPtr f_romp) {
         vis_GridFunCopy(p, f_romp);
      }

      public static void GridFunMallocElemNode(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr) {
         vis_GridFunMallocElemNode(p, n_rows, s_ize,out p_tr);
      }

      public static void GridFunFreeElemNode(IntPtr p,ref IntPtr p_tr) {
         vis_GridFunFreeElemNode(p,ref p_tr);
      }

      public static void GridFunMallocNodeElem(IntPtr p,int n_rows,int s_ize,out IntPtr p_tr) {
         vis_GridFunMallocNodeElem(p, n_rows, s_ize,out p_tr);
      }

      public static void GridFunFreeNodeElem(IntPtr p,ref IntPtr p_tr) {
         vis_GridFunFreeNodeElem(p,ref p_tr);
      }

      public static void GridFunNumber(IntPtr p,int t_ype,ref int n_umentity) {
         vis_GridFunNumber(p, t_ype,ref n_umentity);
      }

      public static void GridFunTopology(IntPtr p,int i_d,ref int s_hape,ref int m_axi,ref int m_axj,ref int m_axk) {
         vis_GridFunTopology(p, i_d,ref s_hape,ref m_axi,ref m_axj,ref m_axk);
      }

      public static void GridFunMaxElemNode(IntPtr p,ref int m_axnum) {
         vis_GridFunMaxElemNode(p,ref m_axnum);
      }

      public static void GridFunElemNode(IntPtr p,int i_d,ref int n_ix,int [] i_x) {
         vis_GridFunElemNode(p, i_d,ref n_ix, i_x);
      }

      public static void GridFunCoords(IntPtr p,int n_ids,int [] i_ds,float [] x_) {
         vis_GridFunCoords(p, n_ids, i_ds, x_);
      }

      public static void GridFunCoordsdv(IntPtr p,int n_ids,int [] i_ds,double [] x_) {
         vis_GridFunCoordsdv(p, n_ids, i_ds, x_);
      }

      public static void GridFunNodeAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids) {
         vis_GridFunNodeAssoc(p, t_ype, n_ix, i_x, a_ids);
      }

      public static void GridFunElemAssoc(IntPtr p,int t_ype,int n_ix,int [] i_x,int [] a_ids) {
         vis_GridFunElemAssoc(p, t_ype, n_ix, i_x, a_ids);
      }

      public static void GridFunMaxNodeElem(IntPtr p,ref int m_axnum) {
         vis_GridFunMaxNodeElem(p,ref m_axnum);
      }

      public static void GridFunNodeElem(IntPtr p,int i_d,ref int n_ix,int [] i_x) {
         vis_GridFunNodeElem(p, i_d,ref n_ix, i_x);
      }

      public static void GridFunElemAdj(IntPtr p,int t_ype,int i_d,int n_o,ref int n_idadj,int [] i_dadj) {
         vis_GridFunElemAdj(p, t_ype, i_d, n_o,ref n_idadj, i_dadj);
      }

      public static void GridFunElemNum(IntPtr p,int t_ype,int i_d,ref int n_um) {
         vis_GridFunElemNum(p, t_ype, i_d,ref n_um);
      }

      public static void GridFunElemCon(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_x) {
         vis_GridFunElemCon(p, t_ype, i_d, n_o,ref n_ix, i_x);
      }

      public static void GridFunElemCnn(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_n) {
         vis_GridFunElemCnn(p, t_ype, i_d, n_o,ref n_ix, i_n);
      }

      public static void GridFunElemTopo(IntPtr p,int t_ype,int i_d,int n_o,ref int s_hapet,ref int m_axit,ref int m_axjt) {
         vis_GridFunElemTopo(p, t_ype, i_d, n_o,ref s_hapet,ref m_axit,ref m_axjt);
      }

      public static void GridFunExtent(IntPtr p,IntPtr g_roup,float [] e_xtent) {
         vis_GridFunExtent(p, g_roup, e_xtent);
      }

      public static void GridFunLngElemNode(IntPtr p,ref long l_ng) {
         vis_GridFunLngElemNode(p,ref l_ng);
      }

      public static void GridFunNumElemNode(IntPtr p,int i_d,ref int n_um) {
         vis_GridFunNumElemNode(p, i_d,ref n_um);
      }

      public static void GridFunNumNodeElem(IntPtr p,int i_d,ref int n_um) {
         vis_GridFunNumNodeElem(p, i_d,ref n_um);
      }

      public static void GridFunNodeAdj(IntPtr p,int n_ix,int [] i_x,ref int n_idadj,int [] i_dadj) {
         vis_GridFunNodeAdj(p, n_ix, i_x,ref n_idadj, i_dadj);
      }

      public static void GridFunElemCorn(IntPtr p,int t_ype,int i_d,int n_o,ref int n_ix,int [] i_n) {
         vis_GridFunElemCorn(p, t_ype, i_d, n_o,ref n_ix, i_n);
      }

      public static void GridFunIndElemNode(IntPtr p,int i_d,ref long n_um) {
         vis_GridFunIndElemNode(p, i_d,ref n_um);
      }

      public static void GridFunDimension(IntPtr p,ref int n_dim) {
         vis_GridFunDimension(p,ref n_dim);
      }

      public static void GridFunExtentdv(IntPtr p,IntPtr g_roup,double [] e_xtent) {
         vis_GridFunExtentdv(p, g_roup, e_xtent);
      }

      public static void GridFunElemEntAssoc(IntPtr p,int t_ype,int e_nttype,int i_d,int n_o,ref int a_id) {
         vis_GridFunElemEntAssoc(p, t_ype, e_nttype, i_d, n_o,ref a_id);
      }

      public static void GridFunNodeNode(IntPtr p,int i_d,ref int n_ix,int [] i_x) {
         vis_GridFunNodeNode(p, i_d,ref n_ix, i_x);
      }

      public static void GridFunNumEIP(IntPtr p,int i_d,ref int n_umeip) {
         vis_GridFunNumEIP(p, i_d,ref n_umeip);
      }

      public static void GridFunLngEIP(IntPtr p,ref long l_ngeip) {
         vis_GridFunLngEIP(p,ref l_ngeip);
      }

      public static void GridFunIndEIP(IntPtr p,int i_d,ref long i_ndeip) {
         vis_GridFunIndEIP(p, i_d,ref i_ndeip);
      }

      public static void GridFunPartName(IntPtr p,int p_artid,StringBuilder n_ame) {
         vis_GridFunPartName(p, p_artid, n_ame);
      }

      public static void GridFunNumPartName(IntPtr p,ref int n_umname) {
         vis_GridFunNumPartName(p,ref n_umname);
      }

      public static void GridFunIthPartName(IntPtr p,int i_th,ref int p_artid,StringBuilder n_ame) {
         vis_GridFunIthPartName(p, i_th,ref p_artid, n_ame);
      }

      public static void GridFunSetNumberFun(IntPtr p,VGridFunNumber f_unc) {
         vis_GridFunSetNumberFun(p, f_unc);
      }

      public static void GridFunSetTopologyFun(IntPtr p,VGridFunTopology f_unc) {
         vis_GridFunSetTopologyFun(p, f_unc);
      }

      public static void GridFunSetElemNodeFun(IntPtr p,VGridFunElemNode f_unc) {
         vis_GridFunSetElemNodeFun(p, f_unc);
      }

      public static void GridFunSetMaxElemNodeFun(IntPtr p,VGridFunMaxElemNode f_unc) {
         vis_GridFunSetMaxElemNodeFun(p, f_unc);
      }

      public static void GridFunSetCoordsFun(IntPtr p,VGridFunCoords f_unc) {
         vis_GridFunSetCoordsFun(p, f_unc);
      }

      public static void GridFunSetNodeAssocFun(IntPtr p,VGridFunNodeAssoc f_unc) {
         vis_GridFunSetNodeAssocFun(p, f_unc);
      }

      public static void GridFunSetElemAssocFun(IntPtr p,VGridFunElemAssoc f_unc) {
         vis_GridFunSetElemAssocFun(p, f_unc);
      }

      public static void GridFunSetSetElemNumFun(IntPtr p,VGridFunElemNum f_unc) {
         vis_GridFunSetSetElemNumFun(p, f_unc);
      }

      public static void GridFunSetElemConFun(IntPtr p,VGridFunElemCon f_unc) {
         vis_GridFunSetElemConFun(p, f_unc);
      }

      public static void GridFunSetElemTopoFun(IntPtr p,VGridFunElemTopo f_unc) {
         vis_GridFunSetElemTopoFun(p, f_unc);
      }

      public static void GridFunSetElemAdjFun(IntPtr p,VGridFunElemAdj f_unc) {
         vis_GridFunSetElemAdjFun(p, f_unc);
      }

      public static void GridFunSetMaxNodeElemFun(IntPtr p,VGridFunMaxNodeElem f_unc) {
         vis_GridFunSetMaxNodeElemFun(p, f_unc);
      }

      public static void GridFunSetNodeElemFun(IntPtr p,VGridFunNodeElem f_unc) {
         vis_GridFunSetNodeElemFun(p, f_unc);
      }

      public static void GridFunSetExtentFun(IntPtr p,VGridFunExtent f_unc) {
         vis_GridFunSetExtentFun(p, f_unc);
      }

      public static void GridFunSetElemCnnFun(IntPtr p,VGridFunElemCnn f_unc) {
         vis_GridFunSetElemCnnFun(p, f_unc);
      }

      public static void GridFunSetNodeAdjFun(IntPtr p,VGridFunNodeAdj f_unc) {
         vis_GridFunSetNodeAdjFun(p, f_unc);
      }

      public static void GridFunSetCoordsdvFun(IntPtr p,VGridFunCoordsdv f_unc) {
         vis_GridFunSetCoordsdvFun(p, f_unc);
      }

      public static void GridFunSetLngElemNodeFun(IntPtr p,VGridFunLngElemNode f_unc) {
         vis_GridFunSetLngElemNodeFun(p, f_unc);
      }

      public static void GridFunSetErrorFun(IntPtr p,VGridFunError f_unc) {
         vis_GridFunSetErrorFun(p, f_unc);
      }

      public static void GridFunSetNumElemNodeFun(IntPtr p,VGridFunNumElemNode f_unc) {
         vis_GridFunSetNumElemNodeFun(p, f_unc);
      }

      public static void GridFunSetNumNodeElemFun(IntPtr p,VGridFunNumNodeElem f_unc) {
         vis_GridFunSetNumNodeElemFun(p, f_unc);
      }

      public static void GridFunSetElemCornFun(IntPtr p,VGridFunElemCorn f_unc) {
         vis_GridFunSetElemCornFun(p, f_unc);
      }

      public static void GridFunSetIndElemNodeFun(IntPtr p,VGridFunIndElemNode f_unc) {
         vis_GridFunSetIndElemNodeFun(p, f_unc);
      }

      public static void GridFunSetDimensionFun(IntPtr p,VGridFunDimension f_unc) {
         vis_GridFunSetDimensionFun(p, f_unc);
      }

      public static void GridFunSetExtentdvFun(IntPtr p,VGridFunExtentdv f_unc) {
         vis_GridFunSetExtentdvFun(p, f_unc);
      }

      public static void GridFunSetElemEntAssocFun(IntPtr p,VGridFunElemEntAssoc f_unc) {
         vis_GridFunSetElemEntAssocFun(p, f_unc);
      }

      public static void GridFunNodeNodeFun(IntPtr p,VGridFunNodeNode f_unc) {
         vis_GridFunNodeNodeFun(p, f_unc);
      }

      public static void GridFunNumEIPFun(IntPtr p,VGridFunNumEIP f_unc) {
         vis_GridFunNumEIPFun(p, f_unc);
      }

      public static void GridFunLngEIPFun(IntPtr p,VGridFunLngEIP f_unc) {
         vis_GridFunLngEIPFun(p, f_unc);
      }

      public static void GridFunIndEIPFun(IntPtr p,VGridFunIndEIP f_unc) {
         vis_GridFunIndEIPFun(p, f_unc);
      }

      public static void GridFunPartNameFun(IntPtr p,VGridFunPartName f_unc) {
         vis_GridFunPartNameFun(p, f_unc);
      }

      public static void GridFunNumPartNameFun(IntPtr p,VGridFunNumPartName f_unc) {
         vis_GridFunNumPartNameFun(p, f_unc);
      }

      public static void GridFunIthPartNameFun(IntPtr p,VGridFunIthPartName f_unc) {
         vis_GridFunIthPartNameFun(p, f_unc);
      }

      public const int GRIDFUN_NUMBER = 1;
      public const int GRIDFUN_TOPOLOGY = 2;
      public const int GRIDFUN_ELEMNODE = 3;
      public const int GRIDFUN_MAXELEMNODE = 4;
      public const int GRIDFUN_COORDS = 5;
      public const int GRIDFUN_NODEASSOC = 6;
      public const int GRIDFUN_ELEMASSOC = 7;
      public const int GRIDFUN_ELEMNUM = 8;
      public const int GRIDFUN_ELEMCON = 9;
      public const int GRIDFUN_ELEMTOPO = 10;
      public const int GRIDFUN_ELEMADJ = 11;
      public const int GRIDFUN_MAXNODEELEM = 12;
      public const int GRIDFUN_NODEELEM = 13;
      public const int GRIDFUN_EXTENT = 14;
      public const int GRIDFUN_ELEMCNN = 15;
      public const int GRIDFUN_NODEADJ = 16;
      public const int GRIDFUN_COORDSDV = 17;
      public const int GRIDFUN_ERROR = 19;
      public const int GRIDFUN_NUMELEMNODE = 20;
      public const int GRIDFUN_NUMNODEELEM = 21;
      public const int GRIDFUN_ELEMCORN = 22;
      public const int GRIDFUN_DIMENSION = 24;
      public const int GRIDFUN_EXTENTDV = 25;
      public const int GRIDFUN_ELEMENTASSOC = 26;
      public const int GRIDFUN_NUMEIP = 28;
      public const int GRIDFUN_PARTNAME = 31;
      public const int GRIDFUN_NUMPARTNAME = 32;
      public const int GRIDFUN_ITHPARTNAME = 33;
      public const int GRIDFUN_LNGELEMNODE = 18;
      public const int GRIDFUN_INDELEMNODE = 23;
      public const int GRIDFUN_NODENODE = 27;
      public const int GRIDFUN_LNGEIP = 29;
      public const int GRIDFUN_INDEIP = 30;
      public const int GRIDFUN_MAX = 34;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_GroupBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GroupError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GroupErr(IntPtr p,int n_ument,int e_nttype,int s_ubtype,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetIndex(IntPtr p,int i_ndex,int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetIndices(IntPtr p,int n_ix,int [] i_ndices,int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetIndex(IntPtr p,int i_ndex,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetEntFlag(IntPtr p,int i_ndex,int n_o,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetEntFlag(IntPtr p,int i_ndex,int n_o,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupNthEntFlag(IntPtr p,int i_ndex,int n_o,ref int n_th);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupNumEntFlag(IntPtr p,int i_ndex,ref int n_umno,ref int m_axno);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GroupNode(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GroupElem(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_GroupElemEnt(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetUID(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetUID(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetUserData(IntPtr p,int u_serdata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetUserData(IntPtr p,ref int u_serdata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetType(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetType(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupSetSpec(IntPtr p,int s_pec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupGetSpec(IntPtr p,ref int s_pec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupInitIndex(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupNextIndex(IntPtr p,ref int i_ndex,ref int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupAll(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupBoolean(IntPtr p,int o_peration,IntPtr g_roupsrc);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupComplement(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupCount(IntPtr p,ref int n_parent,ref int n_child);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupIdTran(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupConfigure(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_GroupPrint(IntPtr p);

      public static IntPtr GroupBegin() {
         return vis_GroupBegin();
      }

      public static void GroupEnd(IntPtr p) {
         vis_GroupEnd(p);
      }

      public static int GroupError(IntPtr p) {
         return vis_GroupError(p);
      }

      public static void GroupDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype) {
         vis_GroupDef(p, n_ument, p_arenttype, c_hildtype);
      }

      public static void GroupInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype) {
         vis_GroupInq(p,ref n_ument,ref e_nttype,ref s_ubtype);
      }

      public static int GroupErr(IntPtr p,int n_ument,int e_nttype,int s_ubtype,ref int i_err) {
         return vis_GroupErr(p, n_ument, e_nttype, s_ubtype,ref i_err);
      }

      public static void GroupSetIndex(IntPtr p,int i_ndex,int f_lags) {
         vis_GroupSetIndex(p, i_ndex, f_lags);
      }

      public static void GroupSetIndices(IntPtr p,int n_ix,int [] i_ndices,int f_lags) {
         vis_GroupSetIndices(p, n_ix, i_ndices, f_lags);
      }

      public static void GroupGetIndex(IntPtr p,int i_ndex,ref int f_lag) {
         vis_GroupGetIndex(p, i_ndex,ref f_lag);
      }

      public static void GroupSetEntFlag(IntPtr p,int i_ndex,int n_o,int f_lag) {
         vis_GroupSetEntFlag(p, i_ndex, n_o, f_lag);
      }

      public static void GroupGetEntFlag(IntPtr p,int i_ndex,int n_o,ref int f_lag) {
         vis_GroupGetEntFlag(p, i_ndex, n_o,ref f_lag);
      }

      public static void GroupNthEntFlag(IntPtr p,int i_ndex,int n_o,ref int n_th) {
         vis_GroupNthEntFlag(p, i_ndex, n_o,ref n_th);
      }

      public static void GroupNumEntFlag(IntPtr p,int i_ndex,ref int n_umno,ref int m_axno) {
         vis_GroupNumEntFlag(p, i_ndex,ref n_umno,ref m_axno);
      }

      public static int GroupNode(IntPtr p,int i_ndex) {
         return vis_GroupNode(p, i_ndex);
      }

      public static int GroupElem(IntPtr p,int i_ndex) {
         return vis_GroupElem(p, i_ndex);
      }

      public static int GroupElemEnt(IntPtr p,int i_ndex,int n_o) {
         return vis_GroupElemEnt(p, i_ndex, n_o);
      }

      public static void GroupSetUID(IntPtr p,int i_d) {
         vis_GroupSetUID(p, i_d);
      }

      public static void GroupGetUID(IntPtr p,ref int i_d) {
         vis_GroupGetUID(p,ref i_d);
      }

      public static void GroupSetName(IntPtr p,StringBuilder n_ame) {
         vis_GroupSetName(p, n_ame);
      }

      public static void GroupGetName(IntPtr p,StringBuilder n_ame) {
         vis_GroupGetName(p, n_ame);
      }

      public static void GroupSetUserData(IntPtr p,int u_serdata) {
         vis_GroupSetUserData(p, u_serdata);
      }

      public static void GroupGetUserData(IntPtr p,ref int u_serdata) {
         vis_GroupGetUserData(p,ref u_serdata);
      }

      public static void GroupSetType(IntPtr p,int t_ype) {
         vis_GroupSetType(p, t_ype);
      }

      public static void GroupGetType(IntPtr p,ref int t_ype) {
         vis_GroupGetType(p,ref t_ype);
      }

      public static void GroupSetSpec(IntPtr p,int s_pec) {
         vis_GroupSetSpec(p, s_pec);
      }

      public static void GroupGetSpec(IntPtr p,ref int s_pec) {
         vis_GroupGetSpec(p,ref s_pec);
      }

      public static void GroupInitIndex(IntPtr p) {
         vis_GroupInitIndex(p);
      }

      public static void GroupNextIndex(IntPtr p,ref int i_ndex,ref int f_lags) {
         vis_GroupNextIndex(p,ref i_ndex,ref f_lags);
      }

      public static void GroupClear(IntPtr p) {
         vis_GroupClear(p);
      }

      public static void GroupAll(IntPtr p) {
         vis_GroupAll(p);
      }

      public static void GroupBoolean(IntPtr p,int o_peration,IntPtr g_roupsrc) {
         vis_GroupBoolean(p, o_peration, g_roupsrc);
      }

      public static void GroupComplement(IntPtr p) {
         vis_GroupComplement(p);
      }

      public static void GroupCount(IntPtr p,ref int n_parent,ref int n_child) {
         vis_GroupCount(p,ref n_parent,ref n_child);
      }

      public static void GroupIdTran(IntPtr p,IntPtr i_dtran) {
         vis_GroupIdTran(p, i_dtran);
      }

      public static void GroupConfigure(IntPtr p,IntPtr c_onnect) {
         vis_GroupConfigure(p, c_onnect);
      }

      public static void GroupCopy(IntPtr p,IntPtr f_romp) {
         vis_GroupCopy(p, f_romp);
      }

      public static void GroupPrint(IntPtr p) {
         vis_GroupPrint(p);
      }

      public const int GROUP_SET = 1;
      public const int GROUP_INSERT = 2;
      public const int GROUP_DELETE = 3;
      public const int GROUP_MASK = 4;

      public const int HISTORY_ELEMNODE = 0;
      public const int HISTORY_NODE = 1;
      public const int HISTORY_ELEM = 4;
      public const int HISTORY_LISTWIDTH = 1;
      public const int HISTORY_LISTTRANSPOSE = 2;
      public const int HISTORY_GLOBAL = 0;
      public const int HISTORY_LOCAL = 1;
      public const int HISTORY_LOWPASS = 0;
      public const int HISTORY_TEXT_SUMMARY = -5;
      public const int HISTORY_TEXT_LISTING = -6;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_HistoryBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_HistoryError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryPre(IntPtr p,int p_re);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetPre(IntPtr p,ref int i_pre);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDef(IntPtr p,int n_umstp,int n_ument,int p_arenttype,int c_hildtype,int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryInq(IntPtr p,ref int n_umstp,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetComplex(IntPtr p,ref int c_omplexflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetEngineeringStrain(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetEngineeringStrain(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDataSect(IntPtr p,int i_ndex,int n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataSect(IntPtr p,int n_ix,int [] i_x,int [] n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDataLayPos(IntPtr p,int i_ndex,int l_pos);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataLayPos(IntPtr p,int n_ix,ref int l_pos);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetData(IntPtr p,int i_step,int i_ndex,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDatadv(IntPtr p,int i_step,int i_d,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDataStat(IntPtr p,int i_ndex,int [] s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetIndep(IntPtr p,int i_step,float t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetIndepdv(IntPtr p,int i_step,double t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryIndep(IntPtr p,int i_step,ref float t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryIndepdv(IntPtr p,int i_step,ref double t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetIndepName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetIndepName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryData(IntPtr p,int i_step,int n_ix,int [] i_x,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDatadv(IntPtr p,int i_step,int n_ids,int [] i_ds,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataNum(IntPtr p,int i_ndex,ref int n_dat,ref int n_loc,ref int n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataMax(IntPtr p,ref int m_axdat,ref int m_axloc,ref int m_axsec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataStat(IntPtr p,int i_ndex,int [] s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataSteps(IntPtr p,int n_ix,int [] i_x,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryDataStepsdv(IntPtr p,int n_ids,int [] i_ds,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetDerive(IntPtr p,int d_erive);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetDerive(IntPtr p,ref int d_erive);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryNumDerive(IntPtr p,ref int n_cmp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetSection(IntPtr p,int s_ection);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetSection(IntPtr p,ref int s_ection);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySetSystem(IntPtr p,int s_ystem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetSystem(IntPtr p,ref int s_ystem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryNumIndices(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetIndex(IntPtr p,int i_n,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryIndices(IntPtr p,ref int n_ument,int [] i_ndices);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryNumSteps(IntPtr p,ref int n_umstp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetStep(IntPtr p,int i_n,ref int i_step);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySteps(IntPtr p,ref int n_umstp,int [] i_steps);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryIndepSteps(IntPtr p,float [] t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryIndepStepsdv(IntPtr p,double [] t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryExtent(IntPtr p,float [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryFilter(IntPtr p,int f_ilter);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryGetRank(IntPtr p,int i_step,ref int r_ank);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryCutoffRank(IntPtr p,int i_step1,int i_step2,int n_um,ref int c_utoffrank);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistorySample(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryList(IntPtr p,int t_ype,IntPtr g_roup,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_HistoryPrint(IntPtr p);

      public static IntPtr HistoryBegin() {
         return vis_HistoryBegin();
      }

      public static void HistoryEnd(IntPtr p) {
         vis_HistoryEnd(p);
      }

      public static int HistoryError(IntPtr p) {
         return vis_HistoryError(p);
      }

      public static void HistoryPre(IntPtr p,int p_re) {
         vis_HistoryPre(p, p_re);
      }

      public static void HistoryGetPre(IntPtr p,ref int i_pre) {
         vis_HistoryGetPre(p,ref i_pre);
      }

      public static void HistorySetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_HistorySetObject(p, o_bjecttype, o_bject);
      }

      public static void HistoryGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_HistoryGetObject(p, o_bjecttype,out o_bject);
      }

      public static void HistorySetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable) {
         vis_HistorySetHashTable(p, t_ype, h_ashtable);
      }

      public static void HistorySetParami(IntPtr p,int t_ype,int i_param) {
         vis_HistorySetParami(p, t_ype, i_param);
      }

      public static void HistoryDef(IntPtr p,int n_umstp,int n_ument,int p_arenttype,int c_hildtype,int d_atatype) {
         vis_HistoryDef(p, n_umstp, n_ument, p_arenttype, c_hildtype, d_atatype);
      }

      public static void HistoryInq(IntPtr p,ref int n_umstp,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype) {
         vis_HistoryInq(p,ref n_umstp,ref n_ument,ref e_nttype,ref s_ubtype,ref d_atatype);
      }

      public static void HistorySetComplexMode(IntPtr p,int c_omplexmode) {
         vis_HistorySetComplexMode(p, c_omplexmode);
      }

      public static void HistoryGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_HistoryGetComplexMode(p,ref c_omplexmode);
      }

      public static void HistoryGetComplex(IntPtr p,ref int c_omplexflag) {
         vis_HistoryGetComplex(p,ref c_omplexflag);
      }

      public static void HistorySetEngineeringStrain(IntPtr p,int f_lag) {
         vis_HistorySetEngineeringStrain(p, f_lag);
      }

      public static void HistoryGetEngineeringStrain(IntPtr p,ref int f_lag) {
         vis_HistoryGetEngineeringStrain(p,ref f_lag);
      }

      public static void HistoryClear(IntPtr p) {
         vis_HistoryClear(p);
      }

      public static void HistorySetDataSect(IntPtr p,int i_ndex,int n_sec) {
         vis_HistorySetDataSect(p, i_ndex, n_sec);
      }

      public static void HistoryDataSect(IntPtr p,int n_ix,int [] i_x,int [] n_sec) {
         vis_HistoryDataSect(p, n_ix, i_x, n_sec);
      }

      public static void HistorySetDataLayPos(IntPtr p,int i_ndex,int l_pos) {
         vis_HistorySetDataLayPos(p, i_ndex, l_pos);
      }

      public static void HistoryDataLayPos(IntPtr p,int n_ix,ref int l_pos) {
         vis_HistoryDataLayPos(p, n_ix,ref l_pos);
      }

      public static void HistorySetDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay) {
         vis_HistorySetDataLayers(p, i_ndex, p_os, l_ay);
      }

      public static void HistoryDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay) {
         vis_HistoryDataLayers(p, i_ndex, p_os, l_ay);
      }

      public static void HistorySetData(IntPtr p,int i_step,int i_ndex,float [] s_) {
         vis_HistorySetData(p, i_step, i_ndex, s_);
      }

      public static void HistorySetDatadv(IntPtr p,int i_step,int i_d,double [] s_) {
         vis_HistorySetDatadv(p, i_step, i_d, s_);
      }

      public static void HistorySetDataStat(IntPtr p,int i_ndex,int [] s_tat) {
         vis_HistorySetDataStat(p, i_ndex, s_tat);
      }

      public static void HistorySetIndep(IntPtr p,int i_step,float t_) {
         vis_HistorySetIndep(p, i_step, t_);
      }

      public static void HistorySetIndepdv(IntPtr p,int i_step,double t_) {
         vis_HistorySetIndepdv(p, i_step, t_);
      }

      public static void HistoryIndep(IntPtr p,int i_step,ref float t_) {
         vis_HistoryIndep(p, i_step,ref t_);
      }

      public static void HistoryIndepdv(IntPtr p,int i_step,ref double t_) {
         vis_HistoryIndepdv(p, i_step,ref t_);
      }

      public static void HistorySetIndepName(IntPtr p,StringBuilder n_ame) {
         vis_HistorySetIndepName(p, n_ame);
      }

      public static void HistoryGetIndepName(IntPtr p,StringBuilder n_ame) {
         vis_HistoryGetIndepName(p, n_ame);
      }

      public static void HistoryData(IntPtr p,int i_step,int n_ix,int [] i_x,float [] s_) {
         vis_HistoryData(p, i_step, n_ix, i_x, s_);
      }

      public static void HistoryDatadv(IntPtr p,int i_step,int n_ids,int [] i_ds,double [] s_) {
         vis_HistoryDatadv(p, i_step, n_ids, i_ds, s_);
      }

      public static void HistoryDataNum(IntPtr p,int i_ndex,ref int n_dat,ref int n_loc,ref int n_sec) {
         vis_HistoryDataNum(p, i_ndex,ref n_dat,ref n_loc,ref n_sec);
      }

      public static void HistoryDataMax(IntPtr p,ref int m_axdat,ref int m_axloc,ref int m_axsec) {
         vis_HistoryDataMax(p,ref m_axdat,ref m_axloc,ref m_axsec);
      }

      public static void HistoryDataStat(IntPtr p,int i_ndex,int [] s_tat) {
         vis_HistoryDataStat(p, i_ndex, s_tat);
      }

      public static void HistoryDataSteps(IntPtr p,int n_ix,int [] i_x,float [] s_) {
         vis_HistoryDataSteps(p, n_ix, i_x, s_);
      }

      public static void HistoryDataStepsdv(IntPtr p,int n_ids,int [] i_ds,double [] s_) {
         vis_HistoryDataStepsdv(p, n_ids, i_ds, s_);
      }

      public static void HistorySetDerive(IntPtr p,int d_erive) {
         vis_HistorySetDerive(p, d_erive);
      }

      public static void HistoryGetDerive(IntPtr p,ref int d_erive) {
         vis_HistoryGetDerive(p,ref d_erive);
      }

      public static void HistoryNumDerive(IntPtr p,ref int n_cmp) {
         vis_HistoryNumDerive(p,ref n_cmp);
      }

      public static void HistorySetSection(IntPtr p,int s_ection) {
         vis_HistorySetSection(p, s_ection);
      }

      public static void HistoryGetSection(IntPtr p,ref int s_ection) {
         vis_HistoryGetSection(p,ref s_ection);
      }

      public static void HistorySetSystem(IntPtr p,int s_ystem) {
         vis_HistorySetSystem(p, s_ystem);
      }

      public static void HistoryGetSystem(IntPtr p,ref int s_ystem) {
         vis_HistoryGetSystem(p,ref s_ystem);
      }

      public static void HistoryNumIndices(IntPtr p,ref int n_ument) {
         vis_HistoryNumIndices(p,ref n_ument);
      }

      public static void HistoryGetIndex(IntPtr p,int i_n,ref int i_ndex) {
         vis_HistoryGetIndex(p, i_n,ref i_ndex);
      }

      public static void HistoryIndices(IntPtr p,ref int n_ument,int [] i_ndices) {
         vis_HistoryIndices(p,ref n_ument, i_ndices);
      }

      public static void HistoryNumSteps(IntPtr p,ref int n_umstp) {
         vis_HistoryNumSteps(p,ref n_umstp);
      }

      public static void HistoryGetStep(IntPtr p,int i_n,ref int i_step) {
         vis_HistoryGetStep(p, i_n,ref i_step);
      }

      public static void HistorySteps(IntPtr p,ref int n_umstp,int [] i_steps) {
         vis_HistorySteps(p,ref n_umstp, i_steps);
      }

      public static void HistoryIndepSteps(IntPtr p,float [] t_) {
         vis_HistoryIndepSteps(p, t_);
      }

      public static void HistoryIndepStepsdv(IntPtr p,double [] t_) {
         vis_HistoryIndepStepsdv(p, t_);
      }

      public static void HistoryExtent(IntPtr p,float [] e_xtent) {
         vis_HistoryExtent(p, e_xtent);
      }

      public static void HistoryFilter(IntPtr p,int f_ilter) {
         vis_HistoryFilter(p, f_ilter);
      }

      public static void HistoryGetRank(IntPtr p,int i_step,ref int r_ank) {
         vis_HistoryGetRank(p, i_step,ref r_ank);
      }

      public static void HistoryCutoffRank(IntPtr p,int i_step1,int i_step2,int n_um,ref int c_utoffrank) {
         vis_HistoryCutoffRank(p, i_step1, i_step2, n_um,ref c_utoffrank);
      }

      public static void HistorySample(IntPtr p) {
         vis_HistorySample(p);
      }

      public static void HistoryList(IntPtr p,int t_ype,IntPtr g_roup,StringBuilder p_ath) {
         vis_HistoryList(p, t_ype, g_roup, p_ath);
      }

      public static void HistoryCopy(IntPtr p,IntPtr f_romp) {
         vis_HistoryCopy(p, f_romp);
      }

      public static void HistoryPrint(IntPtr p) {
         vis_HistoryPrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ICaseBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ICaseError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSetSPV(IntPtr p,int i_ndex,int t_ype,int n_tags,int [] t_ag,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSetSPVdv(IntPtr p,int i_ndex,int t_ype,int n_tags,int [] t_ag,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPVMax(IntPtr p,int t_ype,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPVNum(IntPtr p,int t_ype,ref int n_umindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPVType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPV(IntPtr p,int i_ndex,int t_ype,ref int n_tags,int [] t_ag,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPVdv(IntPtr p,int i_ndex,int t_ype,ref int n_tags,int [] t_ag,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSPVUseTag(IntPtr p,int t_ype,ref int n_tags,int [] t_ag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICaseGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ICasePrint(IntPtr p);

      public static IntPtr ICaseBegin() {
         return vis_ICaseBegin();
      }

      public static void ICaseEnd(IntPtr p) {
         vis_ICaseEnd(p);
      }

      public static int ICaseError(IntPtr p) {
         return vis_ICaseError(p);
      }

      public static void ICaseSetSPV(IntPtr p,int i_ndex,int t_ype,int n_tags,int [] t_ag,float [] v_alue) {
         vis_ICaseSetSPV(p, i_ndex, t_ype, n_tags, t_ag, v_alue);
      }

      public static void ICaseSetSPVdv(IntPtr p,int i_ndex,int t_ype,int n_tags,int [] t_ag,double [] v_al) {
         vis_ICaseSetSPVdv(p, i_ndex, t_ype, n_tags, t_ag, v_al);
      }

      public static void ICaseSPVMax(IntPtr p,int t_ype,ref int m_axindex) {
         vis_ICaseSPVMax(p, t_ype,ref m_axindex);
      }

      public static void ICaseSPVNum(IntPtr p,int t_ype,ref int n_umindex) {
         vis_ICaseSPVNum(p, t_ype,ref n_umindex);
      }

      public static void ICaseSPVType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype) {
         vis_ICaseSPVType(p, i_ndex,ref n_types, t_ype);
      }

      public static void ICaseSPV(IntPtr p,int i_ndex,int t_ype,ref int n_tags,int [] t_ag,float [] v_alue) {
         vis_ICaseSPV(p, i_ndex, t_ype,ref n_tags, t_ag, v_alue);
      }

      public static void ICaseSPVdv(IntPtr p,int i_ndex,int t_ype,ref int n_tags,int [] t_ag,double [] v_al) {
         vis_ICaseSPVdv(p, i_ndex, t_ype,ref n_tags, t_ag, v_al);
      }

      public static void ICaseSPVUseTag(IntPtr p,int t_ype,ref int n_tags,int [] t_ag) {
         vis_ICaseSPVUseTag(p, t_ype,ref n_tags, t_ag);
      }

      public static void ICaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_ICaseNodeGroup(p, g_roup, g_roupdst);
      }

      public static void ICaseClear(IntPtr p) {
         vis_ICaseClear(p);
      }

      public static void ICaseSpecFlag(IntPtr p,ref int f_lag) {
         vis_ICaseSpecFlag(p,ref f_lag);
      }

      public static void ICaseSetId(IntPtr p,int i_d) {
         vis_ICaseSetId(p, i_d);
      }

      public static void ICaseGetId(IntPtr p,ref int i_d) {
         vis_ICaseGetId(p,ref i_d);
      }

      public static void ICaseSetName(IntPtr p,StringBuilder n_ame) {
         vis_ICaseSetName(p, n_ame);
      }

      public static void ICaseGetName(IntPtr p,StringBuilder n_ame) {
         vis_ICaseGetName(p, n_ame);
      }

      public static void ICasePrint(IntPtr p) {
         vis_ICasePrint(p);
      }

      public const int ICASE_DOF = 1;
      public const int ICASE_DOFDOT = 2;
      public const int ICASE_SPV_MAX = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_IdTranBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_IdTranError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranDef(IntPtr p,int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranInq(IntPtr p,ref int n_ument);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetId(IntPtr p,int i_ndex,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetId(IntPtr p,int i_ndex,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetIds(IntPtr p,int n_indices,int [] i_ndices,int [] i_ds);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranPtrIds(IntPtr p,ref int n_ids,out int [] i_ds);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetEnt(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetEnt(IntPtr p,int i_ndex,ref int e_nt);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetEnts(IntPtr p,int n_indices,int [] i_ndices,int [] e_nts);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranAddId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranAddThruByIds(IntPtr p,int n_um,int [] l_istids);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranEquId(IntPtr p,int i_ndex,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranEquSweep(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranEquReNumber(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetUID(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetUID(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetUserData(IntPtr p,int u_serdata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetUserData(IntPtr p,ref int u_serdata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetUserObj(IntPtr p,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetUserObj(IntPtr p,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetUProp(IntPtr p,IntPtr u_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetUProp(IntPtr p,out IntPtr u_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranDelete(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetType(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetType(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetSpec(IntPtr p,int s_pec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetSpec(IntPtr p,ref int s_pec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSetEntType(IntPtr p,int p_arenttype,int c_hildtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGetEntType(IntPtr p,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranInit(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranAppend(IntPtr p,IntPtr a_ppendp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranCount(IntPtr p,int t_ype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranGroup(IntPtr p,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranUnique(IntPtr p,IntPtr f_romidtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranOrder(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranType(IntPtr p,ref int s_orttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranIndex(IntPtr p,int i_d,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndices);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranNumIndex(IntPtr p,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranAllIndex(IntPtr p,int i_d,ref int n_um,int [] i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranSort(IntPtr p,IntPtr s_ortp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranMatch(IntPtr p,IntPtr i_dtranm,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranCheckSum(IntPtr p,ref int c_hecksum);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_IdTranPrint(IntPtr p);

      public static IntPtr IdTranBegin() {
         return vis_IdTranBegin();
      }

      public static void IdTranEnd(IntPtr p) {
         vis_IdTranEnd(p);
      }

      public static int IdTranError(IntPtr p) {
         return vis_IdTranError(p);
      }

      public static void IdTranDef(IntPtr p,int n_ument) {
         vis_IdTranDef(p, n_ument);
      }

      public static void IdTranInq(IntPtr p,ref int n_ument) {
         vis_IdTranInq(p,ref n_ument);
      }

      public static void IdTranSetId(IntPtr p,int i_ndex,int i_d) {
         vis_IdTranSetId(p, i_ndex, i_d);
      }

      public static void IdTranGetId(IntPtr p,int i_ndex,ref int i_d) {
         vis_IdTranGetId(p, i_ndex,ref i_d);
      }

      public static void IdTranGetIds(IntPtr p,int n_indices,int [] i_ndices,int [] i_ds) {
         vis_IdTranGetIds(p, n_indices, i_ndices, i_ds);
      }

      public static void IdTranPtrIds(IntPtr p,ref int n_ids,out int [] i_ds) {
         vis_IdTranPtrIds(p,ref n_ids,out i_ds);
      }

      public static void IdTranSetEnt(IntPtr p,int i_ndex,int n_o) {
         vis_IdTranSetEnt(p, i_ndex, n_o);
      }

      public static void IdTranGetEnt(IntPtr p,int i_ndex,ref int e_nt) {
         vis_IdTranGetEnt(p, i_ndex,ref e_nt);
      }

      public static void IdTranGetEnts(IntPtr p,int n_indices,int [] i_ndices,int [] e_nts) {
         vis_IdTranGetEnts(p, n_indices, i_ndices, e_nts);
      }

      public static void IdTranAddId(IntPtr p,int i_d) {
         vis_IdTranAddId(p, i_d);
      }

      public static void IdTranAddThruByIds(IntPtr p,int n_um,int [] l_istids) {
         vis_IdTranAddThruByIds(p, n_um, l_istids);
      }

      public static void IdTranEquId(IntPtr p,int i_ndex,int i_d) {
         vis_IdTranEquId(p, i_ndex, i_d);
      }

      public static void IdTranEquSweep(IntPtr p) {
         vis_IdTranEquSweep(p);
      }

      public static void IdTranEquReNumber(IntPtr p,ref int n_um) {
         vis_IdTranEquReNumber(p,ref n_um);
      }

      public static void IdTranSetUID(IntPtr p,int i_d) {
         vis_IdTranSetUID(p, i_d);
      }

      public static void IdTranGetUID(IntPtr p,ref int i_d) {
         vis_IdTranGetUID(p,ref i_d);
      }

      public static void IdTranSetName(IntPtr p,StringBuilder n_ame) {
         vis_IdTranSetName(p, n_ame);
      }

      public static void IdTranGetName(IntPtr p,StringBuilder n_ame) {
         vis_IdTranGetName(p, n_ame);
      }

      public static void IdTranSetUserData(IntPtr p,int u_serdata) {
         vis_IdTranSetUserData(p, u_serdata);
      }

      public static void IdTranGetUserData(IntPtr p,ref int u_serdata) {
         vis_IdTranGetUserData(p,ref u_serdata);
      }

      public static void IdTranSetUserObj(IntPtr p,IntPtr o_bject) {
         vis_IdTranSetUserObj(p, o_bject);
      }

      public static void IdTranGetUserObj(IntPtr p,out IntPtr o_bject) {
         vis_IdTranGetUserObj(p,out o_bject);
      }

      public static void IdTranSetUProp(IntPtr p,IntPtr u_prop) {
         vis_IdTranSetUProp(p, u_prop);
      }

      public static void IdTranGetUProp(IntPtr p,out IntPtr u_prop) {
         vis_IdTranGetUProp(p,out u_prop);
      }

      public static void IdTranDelete(IntPtr p) {
         vis_IdTranDelete(p);
      }

      public static void IdTranSetType(IntPtr p,int t_ype) {
         vis_IdTranSetType(p, t_ype);
      }

      public static void IdTranGetType(IntPtr p,ref int t_ype) {
         vis_IdTranGetType(p,ref t_ype);
      }

      public static void IdTranSetSpec(IntPtr p,int s_pec) {
         vis_IdTranSetSpec(p, s_pec);
      }

      public static void IdTranGetSpec(IntPtr p,ref int s_pec) {
         vis_IdTranGetSpec(p,ref s_pec);
      }

      public static void IdTranSetEntType(IntPtr p,int p_arenttype,int c_hildtype) {
         vis_IdTranSetEntType(p, p_arenttype, c_hildtype);
      }

      public static void IdTranGetEntType(IntPtr p,ref int e_nttype,ref int s_ubtype) {
         vis_IdTranGetEntType(p,ref e_nttype,ref s_ubtype);
      }

      public static void IdTranClear(IntPtr p) {
         vis_IdTranClear(p);
      }

      public static void IdTranInit(IntPtr p,int i_d) {
         vis_IdTranInit(p, i_d);
      }

      public static void IdTranAppend(IntPtr p,IntPtr a_ppendp) {
         vis_IdTranAppend(p, a_ppendp);
      }

      public static void IdTranCount(IntPtr p,int t_ype,ref int n_um) {
         vis_IdTranCount(p, t_ype,ref n_um);
      }

      public static void IdTranGroup(IntPtr p,IntPtr g_roup) {
         vis_IdTranGroup(p, g_roup);
      }

      public static void IdTranUnique(IntPtr p,IntPtr f_romidtran) {
         vis_IdTranUnique(p, f_romidtran);
      }

      public static void IdTranOrder(IntPtr p) {
         vis_IdTranOrder(p);
      }

      public static void IdTranType(IntPtr p,ref int s_orttype) {
         vis_IdTranType(p,ref s_orttype);
      }

      public static void IdTranIndex(IntPtr p,int i_d,ref int i_ndex) {
         vis_IdTranIndex(p, i_d,ref i_ndex);
      }

      public static void IdTranIndices(IntPtr p,int n_ids,int [] i_ds,int [] i_ndices) {
         vis_IdTranIndices(p, n_ids, i_ds, i_ndices);
      }

      public static void IdTranNumIndex(IntPtr p,int i_d,ref int n_um) {
         vis_IdTranNumIndex(p, i_d,ref n_um);
      }

      public static void IdTranAllIndex(IntPtr p,int i_d,ref int n_um,int [] i_ndex) {
         vis_IdTranAllIndex(p, i_d,ref n_um, i_ndex);
      }

      public static void IdTranSort(IntPtr p,IntPtr s_ortp) {
         vis_IdTranSort(p, s_ortp);
      }

      public static void IdTranMatch(IntPtr p,IntPtr i_dtranm,ref int f_lag) {
         vis_IdTranMatch(p, i_dtranm,ref f_lag);
      }

      public static void IdTranCheckSum(IntPtr p,ref int c_hecksum) {
         vis_IdTranCheckSum(p,ref c_hecksum);
      }

      public static void IdTranCopy(IntPtr p,IntPtr f_romp) {
         vis_IdTranCopy(p, f_romp);
      }

      public static void IdTranPrint(IntPtr p) {
         vis_IdTranPrint(p);
      }

      public const int IDTRAN_MAXINDEX = 0;
      public const int IDTRAN_NUMINDICES = 1;
      public const int IDTRAN_NUMUNIQUE = 2;
      public const int IDTRAN_THRU = -1;
      public const int IDTRAN_BY = -2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_LCaseBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_LCaseError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetParamd(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseGetComplex(IntPtr p,ref int c_omplexflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetConcTId(IntPtr p,int i_ndex,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcNumTId(IntPtr p,int t_ype,ref int n_umtid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcMax(IntPtr p,int t_ype,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcNum(IntPtr p,int t_ype,ref int n_umindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcInitIter(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcNextIter(IntPtr p,int t_ype,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcFlag(IntPtr p,int i_ndex,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseConcTId(IntPtr p,int i_ndex,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetDistTId(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistNumTId(IntPtr p,int t_ype,ref int n_umtid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddDistCentdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddDistCorndv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistMax(IntPtr p,int e_nttype,int t_ype,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistNum(IntPtr p,int e_nttype,int t_ype,ref int n_umindex,ref int l_ngindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistInitIter(IntPtr p,int e_nttype,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistNextIter(IntPtr p,int e_nttype,int t_ype,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistFlag(IntPtr p,int e_nttype,int i_ndex,int t_ype,ref int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_LCaseDistFlagEnt(IntPtr p,int e_nttype,int i_ndex,int t_ype,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistType(IntPtr p,int e_nttype,int i_ndex,int n_o,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int e_nflag,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int e_nflag,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseDistTId(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetElemTId(IntPtr p,int i_ndex,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemNumTId(IntPtr p,int t_ype,ref int n_umtid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAddElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemMax(IntPtr p,int t_ype,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemNum(IntPtr p,int t_ype,ref int n_umindex,ref int l_ngindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemInitIter(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemNextIter(IntPtr p,int t_ype,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemFlag(IntPtr p,int i_ndex,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemTId(IntPtr p,int i_ndex,int t_ype,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetAccel(IntPtr p,float [] g_rav,float [] c_ent,float [] w_,float [] w_dot);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetAcceldv(IntPtr p,double [] g_rav,double [] c_ent,double [] w_,double [] w_dot);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAccelFlag(IntPtr p,ref int a_ccelflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAccel(IntPtr p,float [] g_rav,float [] c_ent,float [] w_,float [] w_dot);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAcceldv(IntPtr p,double [] g_rav,double [] c_ent,double [] w_,double [] w_dot);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseElemGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseFaceGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseEdgeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseClearConc(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseClearDist(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseClearElem(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseClearAccel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseAdd(IntPtr p,IntPtr a_ddlcase);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCaseGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_LCasePrint(IntPtr p);

      public static IntPtr LCaseBegin() {
         return vis_LCaseBegin();
      }

      public static void LCaseEnd(IntPtr p) {
         vis_LCaseEnd(p);
      }

      public static int LCaseError(IntPtr p) {
         return vis_LCaseError(p);
      }

      public static void LCaseSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_LCaseSetObject(p, o_bjecttype, o_bject);
      }

      public static void LCaseGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_LCaseGetObject(p, o_bjecttype,out o_bject);
      }

      public static void LCaseSetParamd(IntPtr p,int t_ype,double d_param) {
         vis_LCaseSetParamd(p, t_ype, d_param);
      }

      public static void LCaseSetComplexMode(IntPtr p,int c_omplexmode) {
         vis_LCaseSetComplexMode(p, c_omplexmode);
      }

      public static void LCaseGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_LCaseGetComplexMode(p,ref c_omplexmode);
      }

      public static void LCaseGetComplex(IntPtr p,ref int c_omplexflag) {
         vis_LCaseGetComplex(p,ref c_omplexflag);
      }

      public static void LCaseSetConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseSetConc(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseSetConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseSetConcdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseSetConcTId(IntPtr p,int i_ndex,int t_ype,int [] t_id) {
         vis_LCaseSetConcTId(p, i_ndex, t_ype, t_id);
      }

      public static void LCaseConcNumTId(IntPtr p,int t_ype,ref int n_umtid) {
         vis_LCaseConcNumTId(p, t_ype,ref n_umtid);
      }

      public static void LCaseAddConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseAddConc(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseAddConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseAddConcdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseConcMax(IntPtr p,int t_ype,ref int m_axindex) {
         vis_LCaseConcMax(p, t_ype,ref m_axindex);
      }

      public static void LCaseConcNum(IntPtr p,int t_ype,ref int n_umindex) {
         vis_LCaseConcNum(p, t_ype,ref n_umindex);
      }

      public static void LCaseConcInitIter(IntPtr p,int t_ype) {
         vis_LCaseConcInitIter(p, t_ype);
      }

      public static void LCaseConcNextIter(IntPtr p,int t_ype,ref int i_ndex) {
         vis_LCaseConcNextIter(p, t_ype,ref i_ndex);
      }

      public static void LCaseConcFlag(IntPtr p,int i_ndex,int t_ype,ref int f_lag) {
         vis_LCaseConcFlag(p, i_ndex, t_ype,ref f_lag);
      }

      public static void LCaseConcType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype) {
         vis_LCaseConcType(p, i_ndex,ref n_types, t_ype);
      }

      public static void LCaseConc(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseConc(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseConcdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseConcdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseConcTId(IntPtr p,int i_ndex,int t_ype,int [] t_id) {
         vis_LCaseConcTId(p, i_ndex, t_ype, t_id);
      }

      public static void LCaseSetDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,float [] v_alue) {
         vis_LCaseSetDist(p, e_nttype, i_ndex, n_o, t_ype, v_alue);
      }

      public static void LCaseSetDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al) {
         vis_LCaseSetDistdv(p, e_nttype, i_ndex, n_o, t_ype, v_al);
      }

      public static void LCaseSetDistTId(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int [] t_id) {
         vis_LCaseSetDistTId(p, e_nttype, i_ndex, n_o, t_ype, t_id);
      }

      public static void LCaseDistNumTId(IntPtr p,int t_ype,ref int n_umtid) {
         vis_LCaseDistNumTId(p, t_ype,ref n_umtid);
      }

      public static void LCaseAddDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,float [] v_alue) {
         vis_LCaseAddDist(p, e_nttype, i_ndex, n_o, t_ype, v_alue);
      }

      public static void LCaseAddDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al) {
         vis_LCaseAddDistdv(p, e_nttype, i_ndex, n_o, t_ype, v_al);
      }

      public static void LCaseAddDistCentdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al) {
         vis_LCaseAddDistCentdv(p, e_nttype, i_ndex, n_o, t_ype, v_al);
      }

      public static void LCaseAddDistCorndv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,double [] v_al) {
         vis_LCaseAddDistCorndv(p, e_nttype, i_ndex, n_o, t_ype, v_al);
      }

      public static void LCaseDistMax(IntPtr p,int e_nttype,int t_ype,ref int m_axindex) {
         vis_LCaseDistMax(p, e_nttype, t_ype,ref m_axindex);
      }

      public static void LCaseDistNum(IntPtr p,int e_nttype,int t_ype,ref int n_umindex,ref int l_ngindex) {
         vis_LCaseDistNum(p, e_nttype, t_ype,ref n_umindex,ref l_ngindex);
      }

      public static void LCaseDistInitIter(IntPtr p,int e_nttype,int t_ype) {
         vis_LCaseDistInitIter(p, e_nttype, t_ype);
      }

      public static void LCaseDistNextIter(IntPtr p,int e_nttype,int t_ype,ref int i_ndex) {
         vis_LCaseDistNextIter(p, e_nttype, t_ype,ref i_ndex);
      }

      public static void LCaseDistFlag(IntPtr p,int e_nttype,int i_ndex,int t_ype,ref int f_lags) {
         vis_LCaseDistFlag(p, e_nttype, i_ndex, t_ype,ref f_lags);
      }

      public static int LCaseDistFlagEnt(IntPtr p,int e_nttype,int i_ndex,int t_ype,int n_o) {
         return vis_LCaseDistFlagEnt(p, e_nttype, i_ndex, t_ype, n_o);
      }

      public static void LCaseDistType(IntPtr p,int e_nttype,int i_ndex,int n_o,ref int n_types,int [] t_ype) {
         vis_LCaseDistType(p, e_nttype, i_ndex, n_o,ref n_types, t_ype);
      }

      public static void LCaseDist(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int e_nflag,float [] v_alue) {
         vis_LCaseDist(p, e_nttype, i_ndex, n_o, t_ype, e_nflag, v_alue);
      }

      public static void LCaseDistdv(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int e_nflag,double [] v_al) {
         vis_LCaseDistdv(p, e_nttype, i_ndex, n_o, t_ype, e_nflag, v_al);
      }

      public static void LCaseDistTId(IntPtr p,int e_nttype,int i_ndex,int n_o,int t_ype,int [] t_id) {
         vis_LCaseDistTId(p, e_nttype, i_ndex, n_o, t_ype, t_id);
      }

      public static void LCaseSetElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseSetElem(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseSetElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseSetElemdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseSetElemTId(IntPtr p,int i_ndex,int t_ype,int [] t_id) {
         vis_LCaseSetElemTId(p, i_ndex, t_ype, t_id);
      }

      public static void LCaseElemNumTId(IntPtr p,int t_ype,ref int n_umtid) {
         vis_LCaseElemNumTId(p, t_ype,ref n_umtid);
      }

      public static void LCaseAddElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseAddElem(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseAddElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseAddElemdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseElemMax(IntPtr p,int t_ype,ref int m_axindex) {
         vis_LCaseElemMax(p, t_ype,ref m_axindex);
      }

      public static void LCaseElemNum(IntPtr p,int t_ype,ref int n_umindex,ref int l_ngindex) {
         vis_LCaseElemNum(p, t_ype,ref n_umindex,ref l_ngindex);
      }

      public static void LCaseElemInitIter(IntPtr p,int t_ype) {
         vis_LCaseElemInitIter(p, t_ype);
      }

      public static void LCaseElemNextIter(IntPtr p,int t_ype,ref int i_ndex) {
         vis_LCaseElemNextIter(p, t_ype,ref i_ndex);
      }

      public static void LCaseElemFlag(IntPtr p,int i_ndex,int t_ype,ref int f_lag) {
         vis_LCaseElemFlag(p, i_ndex, t_ype,ref f_lag);
      }

      public static void LCaseElemType(IntPtr p,int i_ndex,ref int n_types,int [] t_ype) {
         vis_LCaseElemType(p, i_ndex,ref n_types, t_ype);
      }

      public static void LCaseElem(IntPtr p,int i_ndex,int t_ype,float [] v_alue) {
         vis_LCaseElem(p, i_ndex, t_ype, v_alue);
      }

      public static void LCaseElemdv(IntPtr p,int i_ndex,int t_ype,double [] v_al) {
         vis_LCaseElemdv(p, i_ndex, t_ype, v_al);
      }

      public static void LCaseElemTId(IntPtr p,int i_ndex,int t_ype,int [] t_id) {
         vis_LCaseElemTId(p, i_ndex, t_ype, t_id);
      }

      public static void LCaseSetAccel(IntPtr p,float [] g_rav,float [] c_ent,float [] w_,float [] w_dot) {
         vis_LCaseSetAccel(p, g_rav, c_ent, w_, w_dot);
      }

      public static void LCaseSetAcceldv(IntPtr p,double [] g_rav,double [] c_ent,double [] w_,double [] w_dot) {
         vis_LCaseSetAcceldv(p, g_rav, c_ent, w_, w_dot);
      }

      public static void LCaseAccelFlag(IntPtr p,ref int a_ccelflag) {
         vis_LCaseAccelFlag(p,ref a_ccelflag);
      }

      public static void LCaseAccel(IntPtr p,float [] g_rav,float [] c_ent,float [] w_,float [] w_dot) {
         vis_LCaseAccel(p, g_rav, c_ent, w_, w_dot);
      }

      public static void LCaseAcceldv(IntPtr p,double [] g_rav,double [] c_ent,double [] w_,double [] w_dot) {
         vis_LCaseAcceldv(p, g_rav, c_ent, w_, w_dot);
      }

      public static void LCaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_LCaseNodeGroup(p, g_roup, g_roupdst);
      }

      public static void LCaseElemGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_LCaseElemGroup(p, g_roup, g_roupdst);
      }

      public static void LCaseFaceGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_LCaseFaceGroup(p, g_roup, g_roupdst);
      }

      public static void LCaseEdgeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_LCaseEdgeGroup(p, g_roup, g_roupdst);
      }

      public static void LCaseClearConc(IntPtr p,int t_ype) {
         vis_LCaseClearConc(p, t_ype);
      }

      public static void LCaseClearDist(IntPtr p,int t_ype) {
         vis_LCaseClearDist(p, t_ype);
      }

      public static void LCaseClearElem(IntPtr p,int t_ype) {
         vis_LCaseClearElem(p, t_ype);
      }

      public static void LCaseClearAccel(IntPtr p) {
         vis_LCaseClearAccel(p);
      }

      public static void LCaseClear(IntPtr p) {
         vis_LCaseClear(p);
      }

      public static void LCaseSpecFlag(IntPtr p,ref int f_lag) {
         vis_LCaseSpecFlag(p,ref f_lag);
      }

      public static void LCaseAdd(IntPtr p,IntPtr a_ddlcase) {
         vis_LCaseAdd(p, a_ddlcase);
      }

      public static void LCaseSetId(IntPtr p,int i_d) {
         vis_LCaseSetId(p, i_d);
      }

      public static void LCaseGetId(IntPtr p,ref int i_d) {
         vis_LCaseGetId(p,ref i_d);
      }

      public static void LCaseSetName(IntPtr p,StringBuilder n_ame) {
         vis_LCaseSetName(p, n_ame);
      }

      public static void LCaseGetName(IntPtr p,StringBuilder n_ame) {
         vis_LCaseGetName(p, n_ame);
      }

      public static void LCasePrint(IntPtr p) {
         vis_LCasePrint(p);
      }

      public const int LCASE_ADDFACTOR = 1;
      public const int LCASE_FORCE = 1;
      public const int LCASE_MOMENT = 2;
      public const int LCASE_HEAT = 3;
      public const int LCASE_TEMP = 4;
      public const int LCASE_CSCA = 5;
      public const int LCASE_CVEC = 6;
      public const int LCASE_CONC_FORCE = 1;
      public const int LCASE_CONC_MOMENT = 2;
      public const int LCASE_CONC_HEAT = 3;
      public const int LCASE_CONC_TEMP = 4;
      public const int LCASE_CONC_SCA = 5;
      public const int LCASE_CONC_VEC = 6;
      public const int LCASE_CONC_MAX = 6;
      public const int LCASE_FORMOM = 7;
      public const int LCASE_TRAC = 1;
      public const int LCASE_PRES = 2;
      public const int LCASE_TANGFORCE = 3;
      public const int LCASE_TANGMOMENT = 4;
      public const int LCASE_HEATFLUX = 5;
      public const int LCASE_HEATCONV = 6;
      public const int LCASE_DMOM = 7;
      public const int LCASE_DSCA = 8;
      public const int LCASE_DVEC = 9;
      public const int LCASE_HEATRAD = 10;
      public const int LCASE_HEATRAD_ABSORPTIVITY = 11;
      public const int LCASE_DIST_TRAC = 1;
      public const int LCASE_DIST_PRES = 2;
      public const int LCASE_DIST_TANGFORCE = 3;
      public const int LCASE_DIST_TANGMOMENT = 4;
      public const int LCASE_DIST_HEATFLUX = 5;
      public const int LCASE_DIST_HEATCONV = 6;
      public const int LCASE_DIST_MOM = 7;
      public const int LCASE_DIST_SCA = 8;
      public const int LCASE_DIST_VEC = 9;
      public const int LCASE_DIST_HEATRAD = 10;
      public const int LCASE_DIST_HEATRAD_ABSORPTIVITY = 11;
      public const int LCASE_DIST_MAX = 11;
      public const int LCASE_ACCLELEM = 1;
      public const int LCASE_HEATELEM = 2;
      public const int LCASE_ELEM_ACCL = 1;
      public const int LCASE_ELEM_HEAT = 2;
      public const int LCASE_ELEM_MAX = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MassPrpBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MassPrpEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MassPrpError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MassPrpSetObject(IntPtr p,int t_ype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MassPrpCompute(IntPtr p,IntPtr g_roup,ref float v_tot,ref float m_tot,float [] x_com,float [] m_ten);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MassPrpPrincipal(IntPtr p,float [] m_ten,float [] m_pri,float [] t_m);

      public static IntPtr MassPrpBegin() {
         return vis_MassPrpBegin();
      }

      public static void MassPrpEnd(IntPtr p) {
         vis_MassPrpEnd(p);
      }

      public static int MassPrpError(IntPtr p) {
         return vis_MassPrpError(p);
      }

      public static void MassPrpSetObject(IntPtr p,int t_ype,IntPtr o_bject) {
         vis_MassPrpSetObject(p, t_ype, o_bject);
      }

      public static void MassPrpCompute(IntPtr p,IntPtr g_roup,ref float v_tot,ref float m_tot,float [] x_com,float [] m_ten) {
         vis_MassPrpCompute(p, g_roup,ref v_tot,ref m_tot, x_com, m_ten);
      }

      public static void MassPrpPrincipal(IntPtr p,float [] m_ten,float [] m_pri,float [] t_m) {
         vis_MassPrpPrincipal(p, m_ten, m_pri, t_m);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MCaseBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MCaseError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetMPC(IntPtr p,int i_ndex,int n_terms,int [] i_x,int [] t_ag,float [] c_,float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetMPCdv(IntPtr p,int i_ndex,int n_umterms,int [] i_x,int [] i_g,double [] c_,double r_hs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetRHS(IntPtr p,int i_ndex,float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetRHSdv(IntPtr p,int i_ndex,double r_hs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetCon(IntPtr p,int i_ndex,int t_ype,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseNum(IntPtr p,int i_ndex,ref int n_terms);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseMPC(IntPtr p,int i_ndex,ref int n_terms,int [] i_x,int [] t_ag,float [] c_,ref float r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseMPCdv(IntPtr p,int i_ndex,ref int n_umterms,int [] i_x,int [] i_g,double [] c_,ref double r_hs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseCon(IntPtr p,int i_ndex,ref int t_ype,ref int n_terms,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseDel(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseType(IntPtr p,int i_ndex,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseMax(IntPtr p,ref int m_axindex,ref int m_axterms,ref int m_axrhs);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseAdd(IntPtr p,IntPtr a_ddmcase);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCasePrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MCaseGetNumberOfterms(IntPtr p,int t_ype,ref int n_umterms);

      public static IntPtr MCaseBegin() {
         return vis_MCaseBegin();
      }

      public static void MCaseEnd(IntPtr p) {
         vis_MCaseEnd(p);
      }

      public static int MCaseError(IntPtr p) {
         return vis_MCaseError(p);
      }

      public static void MCaseSetMPC(IntPtr p,int i_ndex,int n_terms,int [] i_x,int [] t_ag,float [] c_,float r_) {
         vis_MCaseSetMPC(p, i_ndex, n_terms, i_x, t_ag, c_, r_);
      }

      public static void MCaseSetMPCdv(IntPtr p,int i_ndex,int n_umterms,int [] i_x,int [] i_g,double [] c_,double r_hs) {
         vis_MCaseSetMPCdv(p, i_ndex, n_umterms, i_x, i_g, c_, r_hs);
      }

      public static void MCaseSetRHS(IntPtr p,int i_ndex,float r_) {
         vis_MCaseSetRHS(p, i_ndex, r_);
      }

      public static void MCaseSetRHSdv(IntPtr p,int i_ndex,double r_hs) {
         vis_MCaseSetRHSdv(p, i_ndex, r_hs);
      }

      public static void MCaseSetCon(IntPtr p,int i_ndex,int t_ype,int [] i_x) {
         vis_MCaseSetCon(p, i_ndex, t_ype, i_x);
      }

      public static void MCaseNum(IntPtr p,int i_ndex,ref int n_terms) {
         vis_MCaseNum(p, i_ndex,ref n_terms);
      }

      public static void MCaseMPC(IntPtr p,int i_ndex,ref int n_terms,int [] i_x,int [] t_ag,float [] c_,ref float r_) {
         vis_MCaseMPC(p, i_ndex,ref n_terms, i_x, t_ag, c_,ref r_);
      }

      public static void MCaseMPCdv(IntPtr p,int i_ndex,ref int n_umterms,int [] i_x,int [] i_g,double [] c_,ref double r_hs) {
         vis_MCaseMPCdv(p, i_ndex,ref n_umterms, i_x, i_g, c_,ref r_hs);
      }

      public static void MCaseCon(IntPtr p,int i_ndex,ref int t_ype,ref int n_terms,int [] i_x) {
         vis_MCaseCon(p, i_ndex,ref t_ype,ref n_terms, i_x);
      }

      public static void MCaseDel(IntPtr p,int i_ndex) {
         vis_MCaseDel(p, i_ndex);
      }

      public static void MCaseType(IntPtr p,int i_ndex,ref int t_ype) {
         vis_MCaseType(p, i_ndex,ref t_ype);
      }

      public static void MCaseMax(IntPtr p,ref int m_axindex,ref int m_axterms,ref int m_axrhs) {
         vis_MCaseMax(p,ref m_axindex,ref m_axterms,ref m_axrhs);
      }

      public static void MCaseInitIter(IntPtr p) {
         vis_MCaseInitIter(p);
      }

      public static void MCaseNextIter(IntPtr p,ref int i_ndex) {
         vis_MCaseNextIter(p,ref i_ndex);
      }

      public static void MCaseClear(IntPtr p) {
         vis_MCaseClear(p);
      }

      public static void MCaseSpecFlag(IntPtr p,ref int f_lag) {
         vis_MCaseSpecFlag(p,ref f_lag);
      }

      public static void MCaseAdd(IntPtr p,IntPtr a_ddmcase) {
         vis_MCaseAdd(p, a_ddmcase);
      }

      public static void MCaseSetId(IntPtr p,int i_d) {
         vis_MCaseSetId(p, i_d);
      }

      public static void MCaseGetId(IntPtr p,ref int i_d) {
         vis_MCaseGetId(p,ref i_d);
      }

      public static void MCaseSetName(IntPtr p,StringBuilder n_ame) {
         vis_MCaseSetName(p, n_ame);
      }

      public static void MCaseGetName(IntPtr p,StringBuilder n_ame) {
         vis_MCaseGetName(p, n_ame);
      }

      public static void MCasePrint(IntPtr p) {
         vis_MCasePrint(p);
      }

      public static void MCaseGetNumberOfterms(IntPtr p,int t_ype,ref int n_umterms) {
         vis_MCaseGetNumberOfterms(p, t_ype,ref n_umterms);
      }

      public const int MCASE_MPC = 1;
      public const int MCASE_TIE = 2;
      public const int MCASE_PIN = 3;
      public const int MCASE_LINK = 4;
      public const int MCASE_BEAM = 5;
      public const int MCASE_ELBOW = 6;
      public const int MCASE_MAX = 7;

      public const int MESHCON_GLOBALPROJECT = 1;
      public const int MESHCON_CONSISTENT = 100;
      public const int MESHCON_PATCHPROJECT = 101;
      public const int MESHCON_CHECKCLOSEDFRNT = 102;
      public const int MESHCON_EXTEND = 103;
      public const int MESHCON_NORMAL = 104;
      public const int MESHCON_CTRLSPACE = 107;
      public const int MESHCON_PATCHRESTRICT = 108;
      public const int MESHCON_VERBOSE = 110;
      public const int MESHCON_MAXNOED = 12;
      public const int MESHCON_STAT_ALL = 0;
      public const int MESHCON_STAT_FREE = -1;
      public const int MESHCON_STAT_PRES = -2;
      public const int MESHCON_STAT_TEMP = -3;
      public const int MESHCON_STAT_PREF = -4;
      public const int MESHCON_MINELEMANG = 1;
      public const int MESHCON_MAXELEMLEN = 2;
      public const int MESHCON_MINELEMLEN = 3;
      public const int MESHCON_MAXEDGELEN = 4;
      public const int MESHCON_MINEDGELEN = 5;
      public const int MESHCON_MINFRNTLEN = 6;
      public const int MESHCON_FRNTANG = 7;
      public const int MESHCON_CORNANG = 8;
      public const int MESHCON_COLLREL = 9;
      public const int MESHCON_COLLRELFLAG = 10;
      public const int MESHCON_COLLMET = 11;
      public const int MESHCON_COLLMETFLAG = 12;
      public const int MESHCON_COLLANG = 13;
      public const int MESHCON_COLLANGFLAG = 14;
      public const int MESHCON_MAXMINELEMANG = 15;
      public const int MESHCON_COLLIMPFLAG = 16;
      public const int MESHCON_GROWTHRATE = 17;
      public const int MESHCON_TINYLEN = 18;
      public const int MESHCON_MAXELEMANG = 19;
      public const int MESHCON_ELEMHEAPSIZEFACT = 20;
      public const int MESHCON_EDGEHEAPSIZEFACT = 21;
      public const int MESHCON_EDGEHEAPPRESONLY = 22;
      public const int MESHCON_COLLTOPOFLAG = 23;
      public const int MESHCON_COLLANGIMPFLAG = 24;
      public const int MESHCON_RECOVERCOS = 25;
      public const int MESHCON_COLLLENMAX = 26;
      public const int MESHCON_COLLLENMIN = 27;
      public const int MESHCON_COLLLENFLAG = 28;
      public const int MESHCON_COLLNORMANG = 29;
      public const int MESHCON_COLLNORMANGFLAG = 30;
      public const int MESHCON_FUNSIZINGMIN = 31;
      public const int MESHCON_WALKFACETOL = 32;
      public const int MESHCON_SWAPNORMANG = 33;
      public const int MESHCON_SWAPNORMANGFLAG = 34;
      public const int MESHCON_FUNSIZINGLEGACY = 35;
      public const int MESHCON_MAXNMT = 100;
      public const int MESHCON_MAXNDG = 10000;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MeshConBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshConError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDef(IntPtr p,int n_node,int n_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInq(IntPtr p,ref int n_node,ref int n_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetPred(IntPtr p,IntPtr p_red);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetFunction(IntPtr p,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetSizing(IntPtr p,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetASizing(IntPtr p,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetGeoproj(IntPtr p,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetFunFlag(IntPtr p,int f_unflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshConFunFlag(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCallFunction(IntPtr p,int i_op,StringBuilder s_tg);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetGeomMeshCon(IntPtr p,IntPtr g_meshcon);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetConicList(IntPtr p,IntPtr c_oniclist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetConicList(IntPtr p,out IntPtr c_oniclist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetCoordSys(IntPtr p,int p_tid,out IntPtr c_oordsys);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetGeomMeshSize(IntPtr p,IntPtr m_eshsize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetDepthMeshSize(IntPtr p,IntPtr m_eshsize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetParami(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetParamd(IntPtr p,int t_ype,double p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetParamd(IntPtr p,int t_ype,ref double p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConWarn(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumber(IntPtr p,int t_ype,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetInteger(IntPtr p,int t_ype,int [] i_params);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMaxEdge(IntPtr p,ref int m_axedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConClrAuxVec(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetAuxVec(IntPtr p,int t_ype,int k_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetAuxVec(IntPtr p,int t_ype,int k_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConClrAuxPnt(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetAuxPnt(IntPtr p,int t_ype,int k_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetAuxPnt(IntPtr p,int t_ype,int k_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetCurrEnt(IntPtr p,int e_nttype,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetCurrEnt(IntPtr p,ref int e_nttype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetCurrEntId(IntPtr p,int e_nttype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetDebugSphere(IntPtr p,double [] c_en,double r_ad);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetDebugNodes(IntPtr p,int n_um,int [] n_odes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetDebugLevel(IntPtr p,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDebugEnt(IntPtr p,int e_nttype,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAddNode(IntPtr p,double [] x_,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNode(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDelNode(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNode(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNode2Dim(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodes(IntPtr p,int n_id,int [] i_ds,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodesCtrl(IntPtr p,int n_id,int [] i_ds,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMaxNodeEdge(IntPtr p,ref int m_axnodeedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodeEdge(IntPtr p,int i_d,ref int n_umnodeedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodePresEdge(IntPtr p,int i_d,ref int n_umnodepresedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNodePresEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFindNodePresEdge(IntPtr p,int i_d,int p_res,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAdjPresEdge(IntPtr p,int i_d,int n_oid,ref int n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNodeSpecPresEdge(IntPtr p,int n_oid,int p_res,ref int n_um,int [] i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodePrefEdge(IntPtr p,int i_d,ref int n_umnodeprefedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodeNMEdge(IntPtr p,int i_d,ref int n_umnodenmedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodeFrntEdge(IntPtr p,int i_d,ref int n_umnodefrntedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodeInconEdge(IntPtr p,int i_d,ref int n_umnodeinconedge);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWEdgeBound(IntPtr p,int i_d,int e_lid,int e_did1,int e_did2,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWNextPres(IntPtr p,int i_d,int e_lid,ref int p_elid,ref int p_elk,ref int p_edid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWPresBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oel,long n_oelSize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWNMBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeCCWPresEdgeBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oed);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeNode(IntPtr p,int i_d,ref int n_um,int [] n_ono);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMatchNodeNode(IntPtr p,int i_d,int i_dm,ref int i_match);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNodeNodeLength(IntPtr p,int i_d,int i_dm,ref double f_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckMergeNode(IntPtr p,int i_d,int i_dm,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMergeNode(IntPtr p,int i_d,int i_dm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPurgePresEdge(IntPtr p,int n_oid1,int n_oid2);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckNodeEdgeFree(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeQuad(IntPtr p,int i_d,int [] i_q,int [] i_qe);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeQuadNorm(IntPtr p,int i_d,int [] i_q,int [] i_qe,double [] v_q);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeElem(IntPtr p,int i_d,ref int n_um,int [] n_oel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConOneNodeElem(IntPtr p,int i_d,ref int e_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodeSize(IntPtr p,int i_d,double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeSize(IntPtr p,int i_d,ref double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeSizes(IntPtr p,int n_id,int [] i_ds,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodeDist(IntPtr p,int i_d,double d_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeDist(IntPtr p,int i_d,ref double d_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodeStat(IntPtr p,int i_d,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeStat(IntPtr p,int i_d,ref int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCountNodeStat(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodeTopo(IntPtr p,int i_d,int t_opo);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeTopo(IntPtr p,int i_d,ref int t_opo);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodePres(IntPtr p,int i_d,int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodePres(IntPtr p,int i_d,ref int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodePref(IntPtr p,int i_d,int p_ref);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodePref(IntPtr p,int i_d,ref int p_ref);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumNodePind(IntPtr p,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAllNodePind(IntPtr p,int i_d,ref int n_um,int [] p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNodePind(IntPtr p,int i_d,int p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodePind(IntPtr p,int i_d,ref int p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNodeSizeElem(IntPtr p,int i_d,double [] x_,ref double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNodeSizeEdge(IntPtr p,int i_d,double [] x_,ref double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeElemAngle(IntPtr p,int i_d,int e_lid,ref double a_ngle);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAddElem(IntPtr p,int n_n,int [] i_x,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDelElem(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElem(IntPtr p,int i_d,ref int n_n,int [] n_o,int [] e_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemNum(IntPtr p,int i_d,ref int n_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemNode(IntPtr p,int i_d,ref int n_n,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemEdge(IntPtr p,int i_d,ref int n_n,int [] e_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemSize(IntPtr p,int i_d,double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemSize(IntPtr p,int i_d,ref double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemNorm(IntPtr p,int i_d,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConIsElemNorm(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemNorm(IntPtr p,int i_d,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTang(IntPtr p,int i_d,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConIsEdgeTang(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTang(IntPtr p,int i_d,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeTang(IntPtr p,int i_d,double [] x_p,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeElemNode(IntPtr p,int e_did,int e_lid,int [] e_delno);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemNodeNorm(IntPtr p,int i_d,int n_oid,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemPres(IntPtr p,int i_d,int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemPres(IntPtr p,int i_d,ref int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetPresElem(IntPtr p,int p_res,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemPind(IntPtr p,int i_d,int p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemPind(IntPtr p,int i_d,ref int p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemFlat(IntPtr p,int i_d,int f_lat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemFlat(IntPtr p,int i_d,ref int f_lat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumElemStat(IntPtr p,ref int n_umstat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetElemStat(IntPtr p,int i_d,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemStat(IntPtr p,int i_d,ref int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConStatLastFormElem(IntPtr p,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConStatLastDiagElem(IntPtr p,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSplitElem(IntPtr p,int i_d,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckDiagElem(IntPtr p,int i_d,int n_oid,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDiagElem(IntPtr p,int i_d,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetLeftElem(IntPtr p,int n_oid,int e_did,ref int e_lid,ref int e_lk);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitTree(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConTermTree(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetNumGeomFace(IntPtr p,int n_umgeomface);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNumGeomFace(IntPtr p,ref int n_umgeomface);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitGeomFace(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConTermGeomFace(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGeomFaceNodeElem(IntPtr p,int g_eomface,IntPtr i_dtrann,IntPtr i_dtrane);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetGeomFaceElemHint(IntPtr p,int g_eomface,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetElemGeomFace(IntPtr p,int i_d,ref int g_eomface);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetGeomFaceInternal(IntPtr p,int g_eomface,int i_nternal);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetGeomFaceInternal(IntPtr p,int g_eomface,ref int i_nternal);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetGeomFaceMapMesh(IntPtr p,int g_eomface,int m_apmesh);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetGeomFaceMapMesh(IntPtr p,int g_eomface,ref int m_apmesh);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetAdjElem(IntPtr p,int i_d,int n_o,ref int e_lid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFindNodeEdge(IntPtr p,int n_oid1,int n_oid2,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConBestNodePresElem(IntPtr p,int n_oid,int p_res,double [] x_,ref int e_lid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFindEdgePresElem(IntPtr p,int e_did,int p_res,ref int e_lid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckFormElem(IntPtr p,int n_n,int [] n_o,int [] e_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckInvertFormElem(IntPtr p,int n_n,int [] n_o,double [] v_,ref double m_etric);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFormElem(IntPtr p,int n_n,int [] n_o,int [] e_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConLastFormElem(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSimpElem(IntPtr p,int n_n,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitElemHeap(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextElemHeap(IntPtr p,ref int i_d,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextElemHeapRemove(IntPtr p,ref int i_d,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRemoveElemHeap(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAddFrnt(IntPtr p,int e_lid,int n_o,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDelFrnt(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrnt(IntPtr p,int i_d,int [] n_o,int [] f_r);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrntNode(IntPtr p,int i_d,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrntElem(IntPtr p,int i_d,ref int e_lid,ref int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrntEdge(IntPtr p,int i_d,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetFrntLevel(IntPtr p,int i_d,int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrntLevel(IntPtr p,int i_d,ref int l_evel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetFrntState(IntPtr p,int i_d,int [] s_t,double [] a_n);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdge(IntPtr p,int i_d,int [] n_o,int [] e_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeElem(IntPtr p,int i_d,int [] e_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumEdgeElem(IntPtr p,int i_d,ref int n_ix);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConIthEdgeElem(IntPtr p,int i_d,int n_o,ref int e_lid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeNM(IntPtr p,int i_d,int [] n_o,ref int n_ix,int [] e_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeIncon(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeNode(IntPtr p,int i_d,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConOppEdgeNode(IntPtr p,int i_d,int n_oid,ref int o_pno);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeFrnt(IntPtr p,int i_d,int [] f_r);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeFrntNM(IntPtr p,int i_d,ref int n_ix,int [] f_r);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumEdgeFrnt(IntPtr p,int i_d,ref int n_ix);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeFrntElem(IntPtr p,int i_d,int e_lid,ref int f_rid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetNodeFrnt(IntPtr p,int [] i_x,ref int f_rid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSwapEdge(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckSplitEdge(IntPtr p,int i_d,int n_oid,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSplitEdge(IntPtr p,int i_d,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckCollapseEdge(IntPtr p,int i_d,int n_oid,int m_idflag,double c_ang,double [] v_n,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckCollapseEdgeTopo(IntPtr p,int i_d,int n_oid,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckCollapseEdgeFace(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckCollapseEdgeDAng(IntPtr p,int i_d,int n_oid,int m_idflag,ref double f_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCollapseEdge(IntPtr p,int i_d,int n_oid,int m_idflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRecoverEdge2Dim(IntPtr p,int [] i_x,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRecoverEdge(IntPtr p,double [] v_e,int [] i_x,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCreateEdge(IntPtr p,double [] v_e,int [] i_x,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMergeEdge(IntPtr p,int i_d,int i_dm);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeStat(IntPtr p,int i_d,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPushNodeEdge(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeStat(IntPtr p,int i_d,ref int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgePres(IntPtr p,int i_d,int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgePres(IntPtr p,int i_d,ref int p_res);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetPresEdge(IntPtr p,int p_res,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTopo(IntPtr p,int i_d,int t_opo);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTopoFeat(IntPtr p,int i_d,int f_eat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTopoFeat(IntPtr p,int i_d,ref int f_eat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTopoFlag(IntPtr p,int i_d,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTopoFlag(IntPtr p,int i_d,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTopoLays(IntPtr p,int i_d,int l_ays);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTopoLays(IntPtr p,int i_d,ref int l_ays);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeTopoRate(IntPtr p,int i_d,int r_ate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTopoRate(IntPtr p,int i_d,ref int r_ate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeTopo(IntPtr p,int i_d,ref int t_opo);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgePref(IntPtr p,int i_d,int p_ref);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgePref(IntPtr p,int i_d,ref int p_ref);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumEdgePind(IntPtr p,int i_d,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAllEdgePind(IntPtr p,int i_d,ref int n_um,int [] p_ind);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeCent(IntPtr p,int i_d,int c_ent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeCent(IntPtr p,int i_d,ref int c_ent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSetEdgeSize(IntPtr p,int i_d,double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetEdgeSize(IntPtr p,int i_d,ref double s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumPushEdge(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPushEdge(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPopEdge(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRefEdge(IntPtr p,int i_th,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitEdgeHeap(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextEdgeHeap(IntPtr p,ref int i_d,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRemoveEdgeHeap(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPushEdgeHeapNodeElem(IntPtr p,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRangeMinFrntLen(IntPtr p,double f_min,double f_max);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitMinFrntLen(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextMinFrntLen(IntPtr p,ref int i_d,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConRemoveMinFrntLen(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConLookupMinFrntLen(IntPtr p,int i_d,ref double v_al);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNumFrnt(IntPtr p,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitNode(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextNode(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitEdge(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextEdge(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitElem(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextElem(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckElemLists(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitNodeEdge(IntPtr p,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextNodeEdge(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConInitNodeElem(IntPtr p,int n_oid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNextNodeElem(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConWalkEdge(IntPtr p,int t_id,double [] x_p,ref int e_did,ref int n_oid,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConWalkFace(IntPtr p,int t_id,double [] x_p,ref int e_lid,ref int e_did,ref int n_oid,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProject(IntPtr p,int t_id,double [] x_p,ref int i_d,ref int e_did,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectNorm(IntPtr p,int t_id,double [] x_p,double [] x_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectElems(IntPtr p,int n_el,int [] i_el,double [] x_p,ref int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectGlobal(IntPtr p,int t_id,double [] x_p,ref int i_d,ref int e_did,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectOneTri(IntPtr p,int i_d,double [] x_p,double [] r_,double [] x_,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemNorm(IntPtr p,int i_d,double [] x_p,double [] v_p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemArea(IntPtr p,int t_id,ref double a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemCurvature(IntPtr p,int t_id,double [] v_k,double [] r_k,double [] p_k);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemExtent(IntPtr p,int i_d,double [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConNormal(IntPtr p,int t_id,double [] x_p,double [] v_p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConTangent(IntPtr p,int t_id,double [] x_p,double [] v_p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemGath(IntPtr p,int i_d,ref int n_pts,double [] x_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectEdge(IntPtr p,int e_did,double [] x_p,ref int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectEdgeLocal(IntPtr p,double [] x_l,int e_did,double [] x_p,ref int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectEdgePres(IntPtr p,double [] x_a,int t_a,double [] x_b,int t_b,double w_,double [] x_p,ref int t_p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConProjectOneEdge(IntPtr p,int e_did,double [] x_p,ref double r_,double [] x_,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConGetADTree(IntPtr p,out IntPtr a_dtree);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConMaxEdgeElem(IntPtr p,ref int m_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConDebugEdge(IntPtr p,int i_op);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConConsistent(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConExtent(IntPtr p,double [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConLoadConnect(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConSummary(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConAddEdge(IntPtr p,int e_lid,int [] i_xe,ref int e_did);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConReverseEdge(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConCheckInvertElem(IntPtr p,int i_d,double [] v_,ref double m_etric,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFlatNormal(IntPtr p,int i_d,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFlatTangent(IntPtr p,int i_d,int k_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemCurv(IntPtr p,int i_d,ref int n_pts,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeCurv(IntPtr p,int i_d,ref int n_pts,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConBisect(IntPtr p,int n_oid,int e_did1,int e_did2,double [] v_n,double [] v_t,double [] v_b);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeTangent(IntPtr p,int i_d,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeLength(IntPtr p,int i_d,ref double f_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeTangLeng(IntPtr p,int i_d,double [] v_,ref double f_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConEdgeCurvLength(IntPtr p,int i_d,ref double f_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConElemEdgeNorm(IntPtr p,int i_d,int e_did,int n_oid,int m_idflag,double [] v_e);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshConFrntDirCos(IntPtr p,int i_d,double [] t_m);

      public static IntPtr MeshConBegin() {
         return vis_MeshConBegin();
      }

      public static void MeshConEnd(IntPtr p) {
         vis_MeshConEnd(p);
      }

      public static int MeshConError(IntPtr p) {
         return vis_MeshConError(p);
      }

      public static void MeshConDef(IntPtr p,int n_node,int n_elem) {
         vis_MeshConDef(p, n_node, n_elem);
      }

      public static void MeshConInq(IntPtr p,ref int n_node,ref int n_elem) {
         vis_MeshConInq(p,ref n_node,ref n_elem);
      }

      public static void MeshConSetPred(IntPtr p,IntPtr p_red) {
         vis_MeshConSetPred(p, p_red);
      }

      public static void MeshConSetFunction(IntPtr p,Vfunc f_unction,IntPtr o_bject) {
         vis_MeshConSetFunction(p, f_unction, o_bject);
      }

      public static void MeshConSetSizing(IntPtr p,Vfunc f_unction,IntPtr o_bject) {
         vis_MeshConSetSizing(p, f_unction, o_bject);
      }

      public static void MeshConSetASizing(IntPtr p,Vfunc f_unction,IntPtr o_bject) {
         vis_MeshConSetASizing(p, f_unction, o_bject);
      }

      public static void MeshConSetGeoproj(IntPtr p,Vfunc f_unction,IntPtr o_bject) {
         vis_MeshConSetGeoproj(p, f_unction, o_bject);
      }

      public static void MeshConSetFunFlag(IntPtr p,int f_unflag) {
         vis_MeshConSetFunFlag(p, f_unflag);
      }

      public static int MeshConFunFlag(IntPtr p) {
         return vis_MeshConFunFlag(p);
      }

      public static void MeshConCallFunction(IntPtr p,int i_op,StringBuilder s_tg) {
         vis_MeshConCallFunction(p, i_op, s_tg);
      }

      public static void MeshConSetGeomMeshCon(IntPtr p,IntPtr g_meshcon) {
         vis_MeshConSetGeomMeshCon(p, g_meshcon);
      }

      public static void MeshConSetConicList(IntPtr p,IntPtr c_oniclist) {
         vis_MeshConSetConicList(p, c_oniclist);
      }

      public static void MeshConGetConicList(IntPtr p,out IntPtr c_oniclist) {
         vis_MeshConGetConicList(p,out c_oniclist);
      }

      public static void MeshConGetCoordSys(IntPtr p,int p_tid,out IntPtr c_oordsys) {
         vis_MeshConGetCoordSys(p, p_tid,out c_oordsys);
      }

      public static void MeshConSetGeomMeshSize(IntPtr p,IntPtr m_eshsize) {
         vis_MeshConSetGeomMeshSize(p, m_eshsize);
      }

      public static void MeshConSetDepthMeshSize(IntPtr p,IntPtr m_eshsize) {
         vis_MeshConSetDepthMeshSize(p, m_eshsize);
      }

      public static void MeshConSetParami(IntPtr p,int t_ype,int i_param) {
         vis_MeshConSetParami(p, t_ype, i_param);
      }

      public static void MeshConGetParami(IntPtr p,int t_ype,ref int i_param) {
         vis_MeshConGetParami(p, t_ype,ref i_param);
      }

      public static void MeshConSetParamd(IntPtr p,int t_ype,double p_aram) {
         vis_MeshConSetParamd(p, t_ype, p_aram);
      }

      public static void MeshConGetParamd(IntPtr p,int t_ype,ref double p_aram) {
         vis_MeshConGetParamd(p, t_ype,ref p_aram);
      }

      public static void MeshConWarn(IntPtr p,ref int f_lag) {
         vis_MeshConWarn(p,ref f_lag);
      }

      public static void MeshConNumber(IntPtr p,int t_ype,ref int n_umentity) {
         vis_MeshConNumber(p, t_ype,ref n_umentity);
      }

      public static void MeshConGetInteger(IntPtr p,int t_ype,int [] i_params) {
         vis_MeshConGetInteger(p, t_ype, i_params);
      }

      public static void MeshConMaxEdge(IntPtr p,ref int m_axedge) {
         vis_MeshConMaxEdge(p,ref m_axedge);
      }

      public static void MeshConClrAuxVec(IntPtr p) {
         vis_MeshConClrAuxVec(p);
      }

      public static void MeshConSetAuxVec(IntPtr p,int t_ype,int k_,double [] v_) {
         vis_MeshConSetAuxVec(p, t_ype, k_, v_);
      }

      public static void MeshConGetAuxVec(IntPtr p,int t_ype,int k_,double [] v_) {
         vis_MeshConGetAuxVec(p, t_ype, k_, v_);
      }

      public static void MeshConClrAuxPnt(IntPtr p) {
         vis_MeshConClrAuxPnt(p);
      }

      public static void MeshConSetAuxPnt(IntPtr p,int t_ype,int k_,double [] v_) {
         vis_MeshConSetAuxPnt(p, t_ype, k_, v_);
      }

      public static void MeshConGetAuxPnt(IntPtr p,int t_ype,int k_,double [] v_) {
         vis_MeshConGetAuxPnt(p, t_ype, k_, v_);
      }

      public static void MeshConSetCurrEnt(IntPtr p,int e_nttype,int i_d) {
         vis_MeshConSetCurrEnt(p, e_nttype, i_d);
      }

      public static void MeshConGetCurrEnt(IntPtr p,ref int e_nttype,ref int i_d) {
         vis_MeshConGetCurrEnt(p,ref e_nttype,ref i_d);
      }

      public static void MeshConGetCurrEntId(IntPtr p,int e_nttype,ref int i_d) {
         vis_MeshConGetCurrEntId(p, e_nttype,ref i_d);
      }

      public static void MeshConSetDebugSphere(IntPtr p,double [] c_en,double r_ad) {
         vis_MeshConSetDebugSphere(p, c_en, r_ad);
      }

      public static void MeshConSetDebugNodes(IntPtr p,int n_um,int [] n_odes) {
         vis_MeshConSetDebugNodes(p, n_um, n_odes);
      }

      public static void MeshConSetDebugLevel(IntPtr p,int l_evel) {
         vis_MeshConSetDebugLevel(p, l_evel);
      }

      public static void MeshConDebugEnt(IntPtr p,int e_nttype,int i_d,ref int f_lag) {
         vis_MeshConDebugEnt(p, e_nttype, i_d,ref f_lag);
      }

      public static void MeshConAddNode(IntPtr p,double [] x_,ref int i_d) {
         vis_MeshConAddNode(p, x_,ref i_d);
      }

      public static void MeshConSetNode(IntPtr p,int i_d,double [] x_) {
         vis_MeshConSetNode(p, i_d, x_);
      }

      public static void MeshConDelNode(IntPtr p,int i_d) {
         vis_MeshConDelNode(p, i_d);
      }

      public static void MeshConGetNode(IntPtr p,int i_d,double [] x_) {
         vis_MeshConGetNode(p, i_d, x_);
      }

      public static void MeshConGetNode2Dim(IntPtr p,int i_d,double [] x_) {
         vis_MeshConGetNode2Dim(p, i_d, x_);
      }

      public static void MeshConGetNodes(IntPtr p,int n_id,int [] i_ds,double [] x_) {
         vis_MeshConGetNodes(p, n_id, i_ds, x_);
      }

      public static void MeshConGetNodesCtrl(IntPtr p,int n_id,int [] i_ds,double [] x_) {
         vis_MeshConGetNodesCtrl(p, n_id, i_ds, x_);
      }

      public static void MeshConMaxNodeEdge(IntPtr p,ref int m_axnodeedge) {
         vis_MeshConMaxNodeEdge(p,ref m_axnodeedge);
      }

      public static void MeshConNumNodeEdge(IntPtr p,int i_d,ref int n_umnodeedge) {
         vis_MeshConNumNodeEdge(p, i_d,ref n_umnodeedge);
      }

      public static void MeshConNumNodePresEdge(IntPtr p,int i_d,ref int n_umnodepresedge) {
         vis_MeshConNumNodePresEdge(p, i_d,ref n_umnodepresedge);
      }

      public static void MeshConNodePresEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed) {
         vis_MeshConNodePresEdge(p, i_d,ref n_um, n_oed);
      }

      public static void MeshConFindNodePresEdge(IntPtr p,int i_d,int p_res,ref int e_did) {
         vis_MeshConFindNodePresEdge(p, i_d, p_res,ref e_did);
      }

      public static void MeshConAdjPresEdge(IntPtr p,int i_d,int n_oid,ref int n_oed) {
         vis_MeshConAdjPresEdge(p, i_d, n_oid,ref n_oed);
      }

      public static void MeshConNodeSpecPresEdge(IntPtr p,int n_oid,int p_res,ref int n_um,int [] i_d) {
         vis_MeshConNodeSpecPresEdge(p, n_oid, p_res,ref n_um, i_d);
      }

      public static void MeshConNumNodePrefEdge(IntPtr p,int i_d,ref int n_umnodeprefedge) {
         vis_MeshConNumNodePrefEdge(p, i_d,ref n_umnodeprefedge);
      }

      public static void MeshConNumNodeNMEdge(IntPtr p,int i_d,ref int n_umnodenmedge) {
         vis_MeshConNumNodeNMEdge(p, i_d,ref n_umnodenmedge);
      }

      public static void MeshConNumNodeFrntEdge(IntPtr p,int i_d,ref int n_umnodefrntedge) {
         vis_MeshConNumNodeFrntEdge(p, i_d,ref n_umnodefrntedge);
      }

      public static void MeshConNumNodeInconEdge(IntPtr p,int i_d,ref int n_umnodeinconedge) {
         vis_MeshConNumNodeInconEdge(p, i_d,ref n_umnodeinconedge);
      }

      public static void MeshConGetNodeEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed) {
         vis_MeshConGetNodeEdge(p, i_d,ref n_um, n_oed);
      }

      public static void MeshConGetNodeCCWEdge(IntPtr p,int i_d,ref int n_um,int [] n_oed) {
         vis_MeshConGetNodeCCWEdge(p, i_d,ref n_um, n_oed);
      }

      public static void MeshConGetNodeCCWEdgeBound(IntPtr p,int i_d,int e_lid,int e_did1,int e_did2,ref int n_um,int [] n_oed) {
         vis_MeshConGetNodeCCWEdgeBound(p, i_d, e_lid, e_did1, e_did2,ref n_um, n_oed);
      }

      public static void MeshConGetNodeCCWNextPres(IntPtr p,int i_d,int e_lid,ref int p_elid,ref int p_elk,ref int p_edid) {
         vis_MeshConGetNodeCCWNextPres(p, i_d, e_lid,ref p_elid,ref p_elk,ref p_edid);
      }

      public static void MeshConGetNodeCCWPresBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oel,long n_oelSize) {
         vis_MeshConGetNodeCCWPresBound(p, i_d, e_lid,ref n_um, n_oel, n_oelSize);
      }

      public static void MeshConGetNodeCCWNMBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oed) {
         vis_MeshConGetNodeCCWNMBound(p, i_d, e_lid,ref n_um, n_oed);
      }

      public static void MeshConGetNodeCCWPresEdgeBound(IntPtr p,int i_d,int e_lid,ref int n_um,int [] n_oed) {
         vis_MeshConGetNodeCCWPresEdgeBound(p, i_d, e_lid,ref n_um, n_oed);
      }

      public static void MeshConGetNodeNode(IntPtr p,int i_d,ref int n_um,int [] n_ono) {
         vis_MeshConGetNodeNode(p, i_d,ref n_um, n_ono);
      }

      public static void MeshConMatchNodeNode(IntPtr p,int i_d,int i_dm,ref int i_match) {
         vis_MeshConMatchNodeNode(p, i_d, i_dm,ref i_match);
      }

      public static void MeshConNodeNodeLength(IntPtr p,int i_d,int i_dm,ref double f_l) {
         vis_MeshConNodeNodeLength(p, i_d, i_dm,ref f_l);
      }

      public static void MeshConCheckMergeNode(IntPtr p,int i_d,int i_dm,ref int f_lag) {
         vis_MeshConCheckMergeNode(p, i_d, i_dm,ref f_lag);
      }

      public static void MeshConMergeNode(IntPtr p,int i_d,int i_dm) {
         vis_MeshConMergeNode(p, i_d, i_dm);
      }

      public static void MeshConPurgePresEdge(IntPtr p,int n_oid1,int n_oid2) {
         vis_MeshConPurgePresEdge(p, n_oid1, n_oid2);
      }

      public static void MeshConCheckNodeEdgeFree(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConCheckNodeEdgeFree(p, i_d,ref f_lag);
      }

      public static void MeshConGetEdgeQuad(IntPtr p,int i_d,int [] i_q,int [] i_qe) {
         vis_MeshConGetEdgeQuad(p, i_d, i_q, i_qe);
      }

      public static void MeshConGetEdgeQuadNorm(IntPtr p,int i_d,int [] i_q,int [] i_qe,double [] v_q) {
         vis_MeshConGetEdgeQuadNorm(p, i_d, i_q, i_qe, v_q);
      }

      public static void MeshConGetNodeElem(IntPtr p,int i_d,ref int n_um,int [] n_oel) {
         vis_MeshConGetNodeElem(p, i_d,ref n_um, n_oel);
      }

      public static void MeshConOneNodeElem(IntPtr p,int i_d,ref int e_id) {
         vis_MeshConOneNodeElem(p, i_d,ref e_id);
      }

      public static void MeshConSetNodeSize(IntPtr p,int i_d,double s_ize) {
         vis_MeshConSetNodeSize(p, i_d, s_ize);
      }

      public static void MeshConGetNodeSize(IntPtr p,int i_d,ref double s_ize) {
         vis_MeshConGetNodeSize(p, i_d,ref s_ize);
      }

      public static void MeshConGetNodeSizes(IntPtr p,int n_id,int [] i_ds,double [] s_) {
         vis_MeshConGetNodeSizes(p, n_id, i_ds, s_);
      }

      public static void MeshConSetNodeDist(IntPtr p,int i_d,double d_ist) {
         vis_MeshConSetNodeDist(p, i_d, d_ist);
      }

      public static void MeshConGetNodeDist(IntPtr p,int i_d,ref double d_ist) {
         vis_MeshConGetNodeDist(p, i_d,ref d_ist);
      }

      public static void MeshConSetNodeStat(IntPtr p,int i_d,int s_tat) {
         vis_MeshConSetNodeStat(p, i_d, s_tat);
      }

      public static void MeshConGetNodeStat(IntPtr p,int i_d,ref int s_tat) {
         vis_MeshConGetNodeStat(p, i_d,ref s_tat);
      }

      public static void MeshConCountNodeStat(IntPtr p,ref int n_um) {
         vis_MeshConCountNodeStat(p,ref n_um);
      }

      public static void MeshConSetNodeTopo(IntPtr p,int i_d,int t_opo) {
         vis_MeshConSetNodeTopo(p, i_d, t_opo);
      }

      public static void MeshConGetNodeTopo(IntPtr p,int i_d,ref int t_opo) {
         vis_MeshConGetNodeTopo(p, i_d,ref t_opo);
      }

      public static void MeshConSetNodePres(IntPtr p,int i_d,int p_res) {
         vis_MeshConSetNodePres(p, i_d, p_res);
      }

      public static void MeshConGetNodePres(IntPtr p,int i_d,ref int p_res) {
         vis_MeshConGetNodePres(p, i_d,ref p_res);
      }

      public static void MeshConSetNodePref(IntPtr p,int i_d,int p_ref) {
         vis_MeshConSetNodePref(p, i_d, p_ref);
      }

      public static void MeshConGetNodePref(IntPtr p,int i_d,ref int p_ref) {
         vis_MeshConGetNodePref(p, i_d,ref p_ref);
      }

      public static void MeshConNumNodePind(IntPtr p,int i_d,ref int n_um) {
         vis_MeshConNumNodePind(p, i_d,ref n_um);
      }

      public static void MeshConAllNodePind(IntPtr p,int i_d,ref int n_um,int [] p_ind) {
         vis_MeshConAllNodePind(p, i_d,ref n_um, p_ind);
      }

      public static void MeshConSetNodePind(IntPtr p,int i_d,int p_ind) {
         vis_MeshConSetNodePind(p, i_d, p_ind);
      }

      public static void MeshConGetNodePind(IntPtr p,int i_d,ref int p_ind) {
         vis_MeshConGetNodePind(p, i_d,ref p_ind);
      }

      public static void MeshConNodeSizeElem(IntPtr p,int i_d,double [] x_,ref double s_ize) {
         vis_MeshConNodeSizeElem(p, i_d, x_,ref s_ize);
      }

      public static void MeshConNodeSizeEdge(IntPtr p,int i_d,double [] x_,ref double s_ize) {
         vis_MeshConNodeSizeEdge(p, i_d, x_,ref s_ize);
      }

      public static void MeshConGetNodeElemAngle(IntPtr p,int i_d,int e_lid,ref double a_ngle) {
         vis_MeshConGetNodeElemAngle(p, i_d, e_lid,ref a_ngle);
      }

      public static void MeshConAddElem(IntPtr p,int n_n,int [] i_x,ref int i_d) {
         vis_MeshConAddElem(p, n_n, i_x,ref i_d);
      }

      public static void MeshConDelElem(IntPtr p,int i_d) {
         vis_MeshConDelElem(p, i_d);
      }

      public static void MeshConGetElem(IntPtr p,int i_d,ref int n_n,int [] n_o,int [] e_d) {
         vis_MeshConGetElem(p, i_d,ref n_n, n_o, e_d);
      }

      public static void MeshConGetElemNum(IntPtr p,int i_d,ref int n_n) {
         vis_MeshConGetElemNum(p, i_d,ref n_n);
      }

      public static void MeshConGetElemNode(IntPtr p,int i_d,ref int n_n,int [] n_o) {
         vis_MeshConGetElemNode(p, i_d,ref n_n, n_o);
      }

      public static void MeshConGetElemEdge(IntPtr p,int i_d,ref int n_n,int [] e_d) {
         vis_MeshConGetElemEdge(p, i_d,ref n_n, e_d);
      }

      public static void MeshConSetElemSize(IntPtr p,int i_d,double s_ize) {
         vis_MeshConSetElemSize(p, i_d, s_ize);
      }

      public static void MeshConGetElemSize(IntPtr p,int i_d,ref double s_ize) {
         vis_MeshConGetElemSize(p, i_d,ref s_ize);
      }

      public static void MeshConSetElemNorm(IntPtr p,int i_d,double [] v_e) {
         vis_MeshConSetElemNorm(p, i_d, v_e);
      }

      public static void MeshConIsElemNorm(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConIsElemNorm(p, i_d,ref f_lag);
      }

      public static void MeshConGetElemNorm(IntPtr p,int i_d,double [] v_e) {
         vis_MeshConGetElemNorm(p, i_d, v_e);
      }

      public static void MeshConSetEdgeTang(IntPtr p,int i_d,double [] v_e) {
         vis_MeshConSetEdgeTang(p, i_d, v_e);
      }

      public static void MeshConIsEdgeTang(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConIsEdgeTang(p, i_d,ref f_lag);
      }

      public static void MeshConGetEdgeTang(IntPtr p,int i_d,double [] v_e) {
         vis_MeshConGetEdgeTang(p, i_d, v_e);
      }

      public static void MeshConEdgeTang(IntPtr p,int i_d,double [] x_p,double [] v_e) {
         vis_MeshConEdgeTang(p, i_d, x_p, v_e);
      }

      public static void MeshConEdgeElemNode(IntPtr p,int e_did,int e_lid,int [] e_delno) {
         vis_MeshConEdgeElemNode(p, e_did, e_lid, e_delno);
      }

      public static void MeshConSetElemNodeNorm(IntPtr p,int i_d,int n_oid,double [] v_e) {
         vis_MeshConSetElemNodeNorm(p, i_d, n_oid, v_e);
      }

      public static void MeshConSetElemPres(IntPtr p,int i_d,int p_res) {
         vis_MeshConSetElemPres(p, i_d, p_res);
      }

      public static void MeshConGetElemPres(IntPtr p,int i_d,ref int p_res) {
         vis_MeshConGetElemPres(p, i_d,ref p_res);
      }

      public static void MeshConGetPresElem(IntPtr p,int p_res,ref int i_d) {
         vis_MeshConGetPresElem(p, p_res,ref i_d);
      }

      public static void MeshConSetElemPind(IntPtr p,int i_d,int p_ind) {
         vis_MeshConSetElemPind(p, i_d, p_ind);
      }

      public static void MeshConGetElemPind(IntPtr p,int i_d,ref int p_ind) {
         vis_MeshConGetElemPind(p, i_d,ref p_ind);
      }

      public static void MeshConSetElemFlat(IntPtr p,int i_d,int f_lat) {
         vis_MeshConSetElemFlat(p, i_d, f_lat);
      }

      public static void MeshConGetElemFlat(IntPtr p,int i_d,ref int f_lat) {
         vis_MeshConGetElemFlat(p, i_d,ref f_lat);
      }

      public static void MeshConNumElemStat(IntPtr p,ref int n_umstat) {
         vis_MeshConNumElemStat(p,ref n_umstat);
      }

      public static void MeshConSetElemStat(IntPtr p,int i_d,int s_tat) {
         vis_MeshConSetElemStat(p, i_d, s_tat);
      }

      public static void MeshConGetElemStat(IntPtr p,int i_d,ref int s_tat) {
         vis_MeshConGetElemStat(p, i_d,ref s_tat);
      }

      public static void MeshConStatLastFormElem(IntPtr p,int s_tat) {
         vis_MeshConStatLastFormElem(p, s_tat);
      }

      public static void MeshConStatLastDiagElem(IntPtr p,int s_tat) {
         vis_MeshConStatLastDiagElem(p, s_tat);
      }

      public static void MeshConSplitElem(IntPtr p,int i_d,int n_oid) {
         vis_MeshConSplitElem(p, i_d, n_oid);
      }

      public static void MeshConCheckDiagElem(IntPtr p,int i_d,int n_oid,ref int f_lag) {
         vis_MeshConCheckDiagElem(p, i_d, n_oid,ref f_lag);
      }

      public static void MeshConDiagElem(IntPtr p,int i_d,int n_oid) {
         vis_MeshConDiagElem(p, i_d, n_oid);
      }

      public static void MeshConGetLeftElem(IntPtr p,int n_oid,int e_did,ref int e_lid,ref int e_lk) {
         vis_MeshConGetLeftElem(p, n_oid, e_did,ref e_lid,ref e_lk);
      }

      public static void MeshConInitTree(IntPtr p) {
         vis_MeshConInitTree(p);
      }

      public static void MeshConTermTree(IntPtr p) {
         vis_MeshConTermTree(p);
      }

      public static void MeshConSetNumGeomFace(IntPtr p,int n_umgeomface) {
         vis_MeshConSetNumGeomFace(p, n_umgeomface);
      }

      public static void MeshConGetNumGeomFace(IntPtr p,ref int n_umgeomface) {
         vis_MeshConGetNumGeomFace(p,ref n_umgeomface);
      }

      public static void MeshConInitGeomFace(IntPtr p) {
         vis_MeshConInitGeomFace(p);
      }

      public static void MeshConTermGeomFace(IntPtr p) {
         vis_MeshConTermGeomFace(p);
      }

      public static void MeshConGeomFaceNodeElem(IntPtr p,int g_eomface,IntPtr i_dtrann,IntPtr i_dtrane) {
         vis_MeshConGeomFaceNodeElem(p, g_eomface, i_dtrann, i_dtrane);
      }

      public static void MeshConGetGeomFaceElemHint(IntPtr p,int g_eomface,ref int i_d) {
         vis_MeshConGetGeomFaceElemHint(p, g_eomface,ref i_d);
      }

      public static void MeshConGetElemGeomFace(IntPtr p,int i_d,ref int g_eomface) {
         vis_MeshConGetElemGeomFace(p, i_d,ref g_eomface);
      }

      public static void MeshConSetGeomFaceInternal(IntPtr p,int g_eomface,int i_nternal) {
         vis_MeshConSetGeomFaceInternal(p, g_eomface, i_nternal);
      }

      public static void MeshConGetGeomFaceInternal(IntPtr p,int g_eomface,ref int i_nternal) {
         vis_MeshConGetGeomFaceInternal(p, g_eomface,ref i_nternal);
      }

      public static void MeshConSetGeomFaceMapMesh(IntPtr p,int g_eomface,int m_apmesh) {
         vis_MeshConSetGeomFaceMapMesh(p, g_eomface, m_apmesh);
      }

      public static void MeshConGetGeomFaceMapMesh(IntPtr p,int g_eomface,ref int m_apmesh) {
         vis_MeshConGetGeomFaceMapMesh(p, g_eomface,ref m_apmesh);
      }

      public static void MeshConGetAdjElem(IntPtr p,int i_d,int n_o,ref int e_lid) {
         vis_MeshConGetAdjElem(p, i_d, n_o,ref e_lid);
      }

      public static void MeshConFindNodeEdge(IntPtr p,int n_oid1,int n_oid2,ref int e_did) {
         vis_MeshConFindNodeEdge(p, n_oid1, n_oid2,ref e_did);
      }

      public static void MeshConBestNodePresElem(IntPtr p,int n_oid,int p_res,double [] x_,ref int e_lid) {
         vis_MeshConBestNodePresElem(p, n_oid, p_res, x_,ref e_lid);
      }

      public static void MeshConFindEdgePresElem(IntPtr p,int e_did,int p_res,ref int e_lid) {
         vis_MeshConFindEdgePresElem(p, e_did, p_res,ref e_lid);
      }

      public static void MeshConCheckFormElem(IntPtr p,int n_n,int [] n_o,int [] e_d,ref int f_lag) {
         vis_MeshConCheckFormElem(p, n_n, n_o, e_d,ref f_lag);
      }

      public static void MeshConCheckInvertFormElem(IntPtr p,int n_n,int [] n_o,double [] v_,ref double m_etric) {
         vis_MeshConCheckInvertFormElem(p, n_n, n_o, v_,ref m_etric);
      }

      public static void MeshConFormElem(IntPtr p,int n_n,int [] n_o,int [] e_d) {
         vis_MeshConFormElem(p, n_n, n_o, e_d);
      }

      public static void MeshConLastFormElem(IntPtr p,ref int i_d) {
         vis_MeshConLastFormElem(p,ref i_d);
      }

      public static void MeshConSimpElem(IntPtr p,int n_n,int [] n_o) {
         vis_MeshConSimpElem(p, n_n, n_o);
      }

      public static void MeshConInitElemHeap(IntPtr p,int t_ype) {
         vis_MeshConInitElemHeap(p, t_ype);
      }

      public static void MeshConNextElemHeap(IntPtr p,ref int i_d,ref double v_al) {
         vis_MeshConNextElemHeap(p,ref i_d,ref v_al);
      }

      public static void MeshConNextElemHeapRemove(IntPtr p,ref int i_d,ref double v_al) {
         vis_MeshConNextElemHeapRemove(p,ref i_d,ref v_al);
      }

      public static void MeshConRemoveElemHeap(IntPtr p,int i_d) {
         vis_MeshConRemoveElemHeap(p, i_d);
      }

      public static void MeshConAddFrnt(IntPtr p,int e_lid,int n_o,ref int i_d) {
         vis_MeshConAddFrnt(p, e_lid, n_o,ref i_d);
      }

      public static void MeshConDelFrnt(IntPtr p,int i_d) {
         vis_MeshConDelFrnt(p, i_d);
      }

      public static void MeshConGetFrnt(IntPtr p,int i_d,int [] n_o,int [] f_r) {
         vis_MeshConGetFrnt(p, i_d, n_o, f_r);
      }

      public static void MeshConGetFrntNode(IntPtr p,int i_d,int [] n_o) {
         vis_MeshConGetFrntNode(p, i_d, n_o);
      }

      public static void MeshConGetFrntElem(IntPtr p,int i_d,ref int e_lid,ref int n_o) {
         vis_MeshConGetFrntElem(p, i_d,ref e_lid,ref n_o);
      }

      public static void MeshConGetFrntEdge(IntPtr p,int i_d,ref int e_did) {
         vis_MeshConGetFrntEdge(p, i_d,ref e_did);
      }

      public static void MeshConSetFrntLevel(IntPtr p,int i_d,int l_evel) {
         vis_MeshConSetFrntLevel(p, i_d, l_evel);
      }

      public static void MeshConGetFrntLevel(IntPtr p,int i_d,ref int l_evel) {
         vis_MeshConGetFrntLevel(p, i_d,ref l_evel);
      }

      public static void MeshConGetFrntState(IntPtr p,int i_d,int [] s_t,double [] a_n) {
         vis_MeshConGetFrntState(p, i_d, s_t, a_n);
      }

      public static void MeshConGetEdge(IntPtr p,int i_d,int [] n_o,int [] e_l) {
         vis_MeshConGetEdge(p, i_d, n_o, e_l);
      }

      public static void MeshConGetEdgeElem(IntPtr p,int i_d,int [] e_l) {
         vis_MeshConGetEdgeElem(p, i_d, e_l);
      }

      public static void MeshConNumEdgeElem(IntPtr p,int i_d,ref int n_ix) {
         vis_MeshConNumEdgeElem(p, i_d,ref n_ix);
      }

      public static void MeshConIthEdgeElem(IntPtr p,int i_d,int n_o,ref int e_lid) {
         vis_MeshConIthEdgeElem(p, i_d, n_o,ref e_lid);
      }

      public static void MeshConGetEdgeNM(IntPtr p,int i_d,int [] n_o,ref int n_ix,int [] e_l) {
         vis_MeshConGetEdgeNM(p, i_d, n_o,ref n_ix, e_l);
      }

      public static void MeshConEdgeIncon(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConEdgeIncon(p, i_d,ref f_lag);
      }

      public static void MeshConGetEdgeNode(IntPtr p,int i_d,int [] n_o) {
         vis_MeshConGetEdgeNode(p, i_d, n_o);
      }

      public static void MeshConOppEdgeNode(IntPtr p,int i_d,int n_oid,ref int o_pno) {
         vis_MeshConOppEdgeNode(p, i_d, n_oid,ref o_pno);
      }

      public static void MeshConGetEdgeFrnt(IntPtr p,int i_d,int [] f_r) {
         vis_MeshConGetEdgeFrnt(p, i_d, f_r);
      }

      public static void MeshConGetEdgeFrntNM(IntPtr p,int i_d,ref int n_ix,int [] f_r) {
         vis_MeshConGetEdgeFrntNM(p, i_d,ref n_ix, f_r);
      }

      public static void MeshConNumEdgeFrnt(IntPtr p,int i_d,ref int n_ix) {
         vis_MeshConNumEdgeFrnt(p, i_d,ref n_ix);
      }

      public static void MeshConGetEdgeFrntElem(IntPtr p,int i_d,int e_lid,ref int f_rid) {
         vis_MeshConGetEdgeFrntElem(p, i_d, e_lid,ref f_rid);
      }

      public static void MeshConGetNodeFrnt(IntPtr p,int [] i_x,ref int f_rid) {
         vis_MeshConGetNodeFrnt(p, i_x,ref f_rid);
      }

      public static void MeshConSwapEdge(IntPtr p,int i_d) {
         vis_MeshConSwapEdge(p, i_d);
      }

      public static void MeshConCheckSplitEdge(IntPtr p,int i_d,int n_oid,ref int f_lag) {
         vis_MeshConCheckSplitEdge(p, i_d, n_oid,ref f_lag);
      }

      public static void MeshConSplitEdge(IntPtr p,int i_d,int n_oid) {
         vis_MeshConSplitEdge(p, i_d, n_oid);
      }

      public static void MeshConCheckCollapseEdge(IntPtr p,int i_d,int n_oid,int m_idflag,double c_ang,double [] v_n,ref int f_lag) {
         vis_MeshConCheckCollapseEdge(p, i_d, n_oid, m_idflag, c_ang, v_n,ref f_lag);
      }

      public static void MeshConCheckCollapseEdgeTopo(IntPtr p,int i_d,int n_oid,ref int f_lag) {
         vis_MeshConCheckCollapseEdgeTopo(p, i_d, n_oid,ref f_lag);
      }

      public static void MeshConCheckCollapseEdgeFace(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConCheckCollapseEdgeFace(p, i_d,ref f_lag);
      }

      public static void MeshConCheckCollapseEdgeDAng(IntPtr p,int i_d,int n_oid,int m_idflag,ref double f_l) {
         vis_MeshConCheckCollapseEdgeDAng(p, i_d, n_oid, m_idflag,ref f_l);
      }

      public static void MeshConCollapseEdge(IntPtr p,int i_d,int n_oid,int m_idflag) {
         vis_MeshConCollapseEdge(p, i_d, n_oid, m_idflag);
      }

      public static void MeshConRecoverEdge2Dim(IntPtr p,int [] i_x,ref int e_did) {
         vis_MeshConRecoverEdge2Dim(p, i_x,ref e_did);
      }

      public static void MeshConRecoverEdge(IntPtr p,double [] v_e,int [] i_x,ref int e_did) {
         vis_MeshConRecoverEdge(p, v_e, i_x,ref e_did);
      }

      public static void MeshConCreateEdge(IntPtr p,double [] v_e,int [] i_x,ref int e_did) {
         vis_MeshConCreateEdge(p, v_e, i_x,ref e_did);
      }

      public static void MeshConMergeEdge(IntPtr p,int i_d,int i_dm) {
         vis_MeshConMergeEdge(p, i_d, i_dm);
      }

      public static void MeshConSetEdgeStat(IntPtr p,int i_d,int s_tat) {
         vis_MeshConSetEdgeStat(p, i_d, s_tat);
      }

      public static void MeshConPushNodeEdge(IntPtr p,int i_d) {
         vis_MeshConPushNodeEdge(p, i_d);
      }

      public static void MeshConGetEdgeStat(IntPtr p,int i_d,ref int s_tat) {
         vis_MeshConGetEdgeStat(p, i_d,ref s_tat);
      }

      public static void MeshConSetEdgePres(IntPtr p,int i_d,int p_res) {
         vis_MeshConSetEdgePres(p, i_d, p_res);
      }

      public static void MeshConGetEdgePres(IntPtr p,int i_d,ref int p_res) {
         vis_MeshConGetEdgePres(p, i_d,ref p_res);
      }

      public static void MeshConGetPresEdge(IntPtr p,int p_res,ref int i_d) {
         vis_MeshConGetPresEdge(p, p_res,ref i_d);
      }

      public static void MeshConSetEdgeTopo(IntPtr p,int i_d,int t_opo) {
         vis_MeshConSetEdgeTopo(p, i_d, t_opo);
      }

      public static void MeshConSetEdgeTopoFeat(IntPtr p,int i_d,int f_eat) {
         vis_MeshConSetEdgeTopoFeat(p, i_d, f_eat);
      }

      public static void MeshConGetEdgeTopoFeat(IntPtr p,int i_d,ref int f_eat) {
         vis_MeshConGetEdgeTopoFeat(p, i_d,ref f_eat);
      }

      public static void MeshConSetEdgeTopoFlag(IntPtr p,int i_d,int f_lag) {
         vis_MeshConSetEdgeTopoFlag(p, i_d, f_lag);
      }

      public static void MeshConGetEdgeTopoFlag(IntPtr p,int i_d,ref int f_lag) {
         vis_MeshConGetEdgeTopoFlag(p, i_d,ref f_lag);
      }

      public static void MeshConSetEdgeTopoLays(IntPtr p,int i_d,int l_ays) {
         vis_MeshConSetEdgeTopoLays(p, i_d, l_ays);
      }

      public static void MeshConGetEdgeTopoLays(IntPtr p,int i_d,ref int l_ays) {
         vis_MeshConGetEdgeTopoLays(p, i_d,ref l_ays);
      }

      public static void MeshConSetEdgeTopoRate(IntPtr p,int i_d,int r_ate) {
         vis_MeshConSetEdgeTopoRate(p, i_d, r_ate);
      }

      public static void MeshConGetEdgeTopoRate(IntPtr p,int i_d,ref int r_ate) {
         vis_MeshConGetEdgeTopoRate(p, i_d,ref r_ate);
      }

      public static void MeshConGetEdgeTopo(IntPtr p,int i_d,ref int t_opo) {
         vis_MeshConGetEdgeTopo(p, i_d,ref t_opo);
      }

      public static void MeshConSetEdgePref(IntPtr p,int i_d,int p_ref) {
         vis_MeshConSetEdgePref(p, i_d, p_ref);
      }

      public static void MeshConGetEdgePref(IntPtr p,int i_d,ref int p_ref) {
         vis_MeshConGetEdgePref(p, i_d,ref p_ref);
      }

      public static void MeshConNumEdgePind(IntPtr p,int i_d,ref int n_um) {
         vis_MeshConNumEdgePind(p, i_d,ref n_um);
      }

      public static void MeshConAllEdgePind(IntPtr p,int i_d,ref int n_um,int [] p_ind) {
         vis_MeshConAllEdgePind(p, i_d,ref n_um, p_ind);
      }

      public static void MeshConSetEdgeCent(IntPtr p,int i_d,int c_ent) {
         vis_MeshConSetEdgeCent(p, i_d, c_ent);
      }

      public static void MeshConGetEdgeCent(IntPtr p,int i_d,ref int c_ent) {
         vis_MeshConGetEdgeCent(p, i_d,ref c_ent);
      }

      public static void MeshConSetEdgeSize(IntPtr p,int i_d,double s_ize) {
         vis_MeshConSetEdgeSize(p, i_d, s_ize);
      }

      public static void MeshConGetEdgeSize(IntPtr p,int i_d,ref double s_ize) {
         vis_MeshConGetEdgeSize(p, i_d,ref s_ize);
      }

      public static void MeshConNumPushEdge(IntPtr p,ref int n_um) {
         vis_MeshConNumPushEdge(p,ref n_um);
      }

      public static void MeshConPushEdge(IntPtr p,int i_d) {
         vis_MeshConPushEdge(p, i_d);
      }

      public static void MeshConPopEdge(IntPtr p,ref int i_d) {
         vis_MeshConPopEdge(p,ref i_d);
      }

      public static void MeshConRefEdge(IntPtr p,int i_th,ref int i_d) {
         vis_MeshConRefEdge(p, i_th,ref i_d);
      }

      public static void MeshConInitEdgeHeap(IntPtr p,int t_ype) {
         vis_MeshConInitEdgeHeap(p, t_ype);
      }

      public static void MeshConNextEdgeHeap(IntPtr p,ref int i_d,ref double v_al) {
         vis_MeshConNextEdgeHeap(p,ref i_d,ref v_al);
      }

      public static void MeshConRemoveEdgeHeap(IntPtr p,int i_d) {
         vis_MeshConRemoveEdgeHeap(p, i_d);
      }

      public static void MeshConPushEdgeHeapNodeElem(IntPtr p,int n_oid) {
         vis_MeshConPushEdgeHeapNodeElem(p, n_oid);
      }

      public static void MeshConRangeMinFrntLen(IntPtr p,double f_min,double f_max) {
         vis_MeshConRangeMinFrntLen(p, f_min, f_max);
      }

      public static void MeshConInitMinFrntLen(IntPtr p,ref int n_um) {
         vis_MeshConInitMinFrntLen(p,ref n_um);
      }

      public static void MeshConNextMinFrntLen(IntPtr p,ref int i_d,ref double v_al) {
         vis_MeshConNextMinFrntLen(p,ref i_d,ref v_al);
      }

      public static void MeshConRemoveMinFrntLen(IntPtr p,int i_d) {
         vis_MeshConRemoveMinFrntLen(p, i_d);
      }

      public static void MeshConLookupMinFrntLen(IntPtr p,int i_d,ref double v_al) {
         vis_MeshConLookupMinFrntLen(p, i_d,ref v_al);
      }

      public static void MeshConNumFrnt(IntPtr p,ref int n_um) {
         vis_MeshConNumFrnt(p,ref n_um);
      }

      public static void MeshConInitNode(IntPtr p) {
         vis_MeshConInitNode(p);
      }

      public static void MeshConNextNode(IntPtr p,ref int i_d) {
         vis_MeshConNextNode(p,ref i_d);
      }

      public static void MeshConInitEdge(IntPtr p) {
         vis_MeshConInitEdge(p);
      }

      public static void MeshConNextEdge(IntPtr p,ref int i_d) {
         vis_MeshConNextEdge(p,ref i_d);
      }

      public static void MeshConInitElem(IntPtr p) {
         vis_MeshConInitElem(p);
      }

      public static void MeshConNextElem(IntPtr p,ref int i_d) {
         vis_MeshConNextElem(p,ref i_d);
      }

      public static void MeshConCheckElemLists(IntPtr p,ref int f_lag) {
         vis_MeshConCheckElemLists(p,ref f_lag);
      }

      public static void MeshConInitNodeEdge(IntPtr p,int n_oid) {
         vis_MeshConInitNodeEdge(p, n_oid);
      }

      public static void MeshConNextNodeEdge(IntPtr p,ref int i_d) {
         vis_MeshConNextNodeEdge(p,ref i_d);
      }

      public static void MeshConInitNodeElem(IntPtr p,int n_oid) {
         vis_MeshConInitNodeElem(p, n_oid);
      }

      public static void MeshConNextNodeElem(IntPtr p,ref int i_d) {
         vis_MeshConNextNodeElem(p,ref i_d);
      }

      public static void MeshConWalkEdge(IntPtr p,int t_id,double [] x_p,ref int e_did,ref int n_oid,double [] x_) {
         vis_MeshConWalkEdge(p, t_id, x_p,ref e_did,ref n_oid, x_);
      }

      public static void MeshConWalkFace(IntPtr p,int t_id,double [] x_p,ref int e_lid,ref int e_did,ref int n_oid,double [] x_) {
         vis_MeshConWalkFace(p, t_id, x_p,ref e_lid,ref e_did,ref n_oid, x_);
      }

      public static void MeshConProject(IntPtr p,int t_id,double [] x_p,ref int i_d,ref int e_did,double [] x_) {
         vis_MeshConProject(p, t_id, x_p,ref i_d,ref e_did, x_);
      }

      public static void MeshConProjectNorm(IntPtr p,int t_id,double [] x_p,double [] x_,double [] v_) {
         vis_MeshConProjectNorm(p, t_id, x_p, x_, v_);
      }

      public static void MeshConProjectElems(IntPtr p,int n_el,int [] i_el,double [] x_p,ref int i_d,double [] x_) {
         vis_MeshConProjectElems(p, n_el, i_el, x_p,ref i_d, x_);
      }

      public static void MeshConProjectGlobal(IntPtr p,int t_id,double [] x_p,ref int i_d,ref int e_did,double [] x_) {
         vis_MeshConProjectGlobal(p, t_id, x_p,ref i_d,ref e_did, x_);
      }

      public static void MeshConProjectOneTri(IntPtr p,int i_d,double [] x_p,double [] r_,double [] x_,ref int i_err) {
         vis_MeshConProjectOneTri(p, i_d, x_p, r_, x_,ref i_err);
      }

      public static void MeshConElemNorm(IntPtr p,int i_d,double [] x_p,double [] v_p) {
         vis_MeshConElemNorm(p, i_d, x_p, v_p);
      }

      public static void MeshConElemArea(IntPtr p,int t_id,ref double a_rea) {
         vis_MeshConElemArea(p, t_id,ref a_rea);
      }

      public static void MeshConElemCurvature(IntPtr p,int t_id,double [] v_k,double [] r_k,double [] p_k) {
         vis_MeshConElemCurvature(p, t_id, v_k, r_k, p_k);
      }

      public static void MeshConElemExtent(IntPtr p,int i_d,double [] e_xtent) {
         vis_MeshConElemExtent(p, i_d, e_xtent);
      }

      public static void MeshConNormal(IntPtr p,int t_id,double [] x_p,double [] v_p) {
         vis_MeshConNormal(p, t_id, x_p, v_p);
      }

      public static void MeshConTangent(IntPtr p,int t_id,double [] x_p,double [] v_p) {
         vis_MeshConTangent(p, t_id, x_p, v_p);
      }

      public static void MeshConElemGath(IntPtr p,int i_d,ref int n_pts,double [] x_d) {
         vis_MeshConElemGath(p, i_d,ref n_pts, x_d);
      }

      public static void MeshConProjectEdge(IntPtr p,int e_did,double [] x_p,ref int i_d,double [] x_) {
         vis_MeshConProjectEdge(p, e_did, x_p,ref i_d, x_);
      }

      public static void MeshConProjectEdgeLocal(IntPtr p,double [] x_l,int e_did,double [] x_p,ref int i_d,double [] x_) {
         vis_MeshConProjectEdgeLocal(p, x_l, e_did, x_p,ref i_d, x_);
      }

      public static void MeshConProjectEdgePres(IntPtr p,double [] x_a,int t_a,double [] x_b,int t_b,double w_,double [] x_p,ref int t_p) {
         vis_MeshConProjectEdgePres(p, x_a, t_a, x_b, t_b, w_, x_p,ref t_p);
      }

      public static void MeshConProjectOneEdge(IntPtr p,int e_did,double [] x_p,ref double r_,double [] x_,ref int i_err) {
         vis_MeshConProjectOneEdge(p, e_did, x_p,ref r_, x_,ref i_err);
      }

      public static void MeshConGetADTree(IntPtr p,out IntPtr a_dtree) {
         vis_MeshConGetADTree(p,out a_dtree);
      }

      public static void MeshConMaxEdgeElem(IntPtr p,ref int m_elem) {
         vis_MeshConMaxEdgeElem(p,ref m_elem);
      }

      public static void MeshConDebugEdge(IntPtr p,int i_op) {
         vis_MeshConDebugEdge(p, i_op);
      }

      public static void MeshConConsistent(IntPtr p) {
         vis_MeshConConsistent(p);
      }

      public static void MeshConExtent(IntPtr p,double [] e_xtent) {
         vis_MeshConExtent(p, e_xtent);
      }

      public static void MeshConLoadConnect(IntPtr p,IntPtr c_onnect) {
         vis_MeshConLoadConnect(p, c_onnect);
      }

      public static void MeshConSummary(IntPtr p) {
         vis_MeshConSummary(p);
      }

      public static void MeshConPrint(IntPtr p) {
         vis_MeshConPrint(p);
      }

      public static void MeshConAddEdge(IntPtr p,int e_lid,int [] i_xe,ref int e_did) {
         vis_MeshConAddEdge(p, e_lid, i_xe,ref e_did);
      }

      public static void MeshConReverseEdge(IntPtr p,int i_d) {
         vis_MeshConReverseEdge(p, i_d);
      }

      public static void MeshConCheckInvertElem(IntPtr p,int i_d,double [] v_,ref double m_etric,ref int f_lag) {
         vis_MeshConCheckInvertElem(p, i_d, v_,ref m_etric,ref f_lag);
      }

      public static void MeshConFlatNormal(IntPtr p,int i_d,double [] v_) {
         vis_MeshConFlatNormal(p, i_d, v_);
      }

      public static void MeshConFlatTangent(IntPtr p,int i_d,int k_,double [] v_) {
         vis_MeshConFlatTangent(p, i_d, k_, v_);
      }

      public static void MeshConElemCurv(IntPtr p,int i_d,ref int n_pts,double [] x_) {
         vis_MeshConElemCurv(p, i_d,ref n_pts, x_);
      }

      public static void MeshConEdgeCurv(IntPtr p,int i_d,ref int n_pts,double [] x_) {
         vis_MeshConEdgeCurv(p, i_d,ref n_pts, x_);
      }

      public static void MeshConBisect(IntPtr p,int n_oid,int e_did1,int e_did2,double [] v_n,double [] v_t,double [] v_b) {
         vis_MeshConBisect(p, n_oid, e_did1, e_did2, v_n, v_t, v_b);
      }

      public static void MeshConEdgeTangent(IntPtr p,int i_d,double [] v_) {
         vis_MeshConEdgeTangent(p, i_d, v_);
      }

      public static void MeshConEdgeLength(IntPtr p,int i_d,ref double f_l) {
         vis_MeshConEdgeLength(p, i_d,ref f_l);
      }

      public static void MeshConEdgeTangLeng(IntPtr p,int i_d,double [] v_,ref double f_l) {
         vis_MeshConEdgeTangLeng(p, i_d, v_,ref f_l);
      }

      public static void MeshConEdgeCurvLength(IntPtr p,int i_d,ref double f_l) {
         vis_MeshConEdgeCurvLength(p, i_d,ref f_l);
      }

      public static void MeshConElemEdgeNorm(IntPtr p,int i_d,int e_did,int n_oid,int m_idflag,double [] v_e) {
         vis_MeshConElemEdgeNorm(p, i_d, e_did, n_oid, m_idflag, v_e);
      }

      public static void MeshConFrntDirCos(IntPtr p,int i_d,double [] t_m) {
         vis_MeshConFrntDirCos(p, i_d, t_m);
      }

      public const int VIS_MESHMETRIC_COMPARISON_NONE = 0;
      public const int VIS_MESHMETRIC_COMPARISON_LESSTHANOREQUAL = 1;
      public const int VIS_MESHMETRIC_COMPARISON_GREATERTHANOREQUAL = 2;
      public const int VIS_MESHMETRIC_COMPARISON_EQUALWITHINTOLERANCE = 3;
      public const int VIS_MESHMETRIC_COMPARISON_MAX = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MeshMetricBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshMetricDef(IntPtr p,int e_lementCount,double r_eferenceValue,StringBuilder n_ame,int c_omparisonOperation);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshMetricInq(IntPtr p,ref int e_lementCount,ref double r_eferenceValue,StringBuilder n_ame,ref int c_omparisonOperation);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshMetricEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshMetricError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshMetricComplies(IntPtr p,int e_lementIndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricValue(IntPtr p,int e_lementIndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshMetricSet(IntPtr p,int e_lementIndex,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricMin(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricMax(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricAverage(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricStandardDeviation(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricComplianceRatio(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshMetricSetRelativeTolerance(IntPtr p,double r_elativeTolerance);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern double vis_MeshMetricRelativeTolerance(IntPtr p);

      public static IntPtr MeshMetricBegin() {
         return vis_MeshMetricBegin();
      }

      public static void MeshMetricDef(IntPtr p,int e_lementCount,double r_eferenceValue,StringBuilder n_ame,int c_omparisonOperation) {
         vis_MeshMetricDef(p, e_lementCount, r_eferenceValue, n_ame, c_omparisonOperation);
      }

      public static void MeshMetricInq(IntPtr p,ref int e_lementCount,ref double r_eferenceValue,StringBuilder n_ame,ref int c_omparisonOperation) {
         vis_MeshMetricInq(p,ref e_lementCount,ref r_eferenceValue, n_ame,ref c_omparisonOperation);
      }

      public static void MeshMetricEnd(IntPtr p) {
         vis_MeshMetricEnd(p);
      }

      public static int MeshMetricError(IntPtr p) {
         return vis_MeshMetricError(p);
      }

      public static int MeshMetricComplies(IntPtr p,int e_lementIndex) {
         return vis_MeshMetricComplies(p, e_lementIndex);
      }

      public static double MeshMetricValue(IntPtr p,int e_lementIndex) {
         return vis_MeshMetricValue(p, e_lementIndex);
      }

      public static void MeshMetricSet(IntPtr p,int e_lementIndex,double v_alue) {
         vis_MeshMetricSet(p, e_lementIndex, v_alue);
      }

      public static double MeshMetricMin(IntPtr p) {
         return vis_MeshMetricMin(p);
      }

      public static double MeshMetricMax(IntPtr p) {
         return vis_MeshMetricMax(p);
      }

      public static double MeshMetricAverage(IntPtr p) {
         return vis_MeshMetricAverage(p);
      }

      public static double MeshMetricStandardDeviation(IntPtr p) {
         return vis_MeshMetricStandardDeviation(p);
      }

      public static double MeshMetricComplianceRatio(IntPtr p) {
         return vis_MeshMetricComplianceRatio(p);
      }

      public static void MeshMetricSetRelativeTolerance(IntPtr p,double r_elativeTolerance) {
         vis_MeshMetricSetRelativeTolerance(p, r_elativeTolerance);
      }

      public static double MeshMetricRelativeTolerance(IntPtr p) {
         return vis_MeshMetricRelativeTolerance(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MeshSizeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshSizeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeDef(IntPtr p,int n_umgeom);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeSetExtent(IntPtr p,double [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeNumGeom(IntPtr p,ref int n_umgeom);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeSetGeom(IntPtr p,int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,double s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeIthGeom(IntPtr p,int i_th,ref int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,ref double s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeWrite(IntPtr p,int t_ype,int i_th,IntPtr f_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeProcess(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MeshSizeSize(IntPtr p,double [] x_,ref double s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MeshSizeUnsuitable(IntPtr p,int s_hape,double [] x_);

      public static IntPtr MeshSizeBegin() {
         return vis_MeshSizeBegin();
      }

      public static void MeshSizeEnd(IntPtr p) {
         vis_MeshSizeEnd(p);
      }

      public static int MeshSizeError(IntPtr p) {
         return vis_MeshSizeError(p);
      }

      public static void MeshSizeDef(IntPtr p,int n_umgeom) {
         vis_MeshSizeDef(p, n_umgeom);
      }

      public static void MeshSizeSetExtent(IntPtr p,double [] e_xtent) {
         vis_MeshSizeSetExtent(p, e_xtent);
      }

      public static void MeshSizeNumGeom(IntPtr p,ref int n_umgeom) {
         vis_MeshSizeNumGeom(p,ref n_umgeom);
      }

      public static void MeshSizeSetGeom(IntPtr p,int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,double s_) {
         vis_MeshSizeSetGeom(p, t_ype, x_o, x_a, x_b, d_, s_);
      }

      public static void MeshSizeIthGeom(IntPtr p,int i_th,ref int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,ref double s_) {
         vis_MeshSizeIthGeom(p, i_th,ref t_ype, x_o, x_a, x_b, d_,ref s_);
      }

      public static void MeshSizeWrite(IntPtr p,int t_ype,int i_th,IntPtr f_d) {
         vis_MeshSizeWrite(p, t_ype, i_th, f_d);
      }

      public static void MeshSizeProcess(IntPtr p) {
         vis_MeshSizeProcess(p);
      }

      public static void MeshSizeSize(IntPtr p,double [] x_,ref double s_) {
         vis_MeshSizeSize(p, x_,ref s_);
      }

      public static int MeshSizeUnsuitable(IntPtr p,int s_hape,double [] x_) {
         return vis_MeshSizeUnsuitable(p, s_hape, x_);
      }

      public const int MODEL_CHECKJACOBIAN = 1;
      public const int MODEL_NUMCHECKSTRING = -1;
      public const int MODEL_CHECKSTRING = 0;
      public const int MODEL_CHECKSTRING0 = 0;
      public const int MODEL_CHECKSTRING1 = 1;
      public const int MODEL_CHECKSTRING2 = 2;
      public const int MODEL_CHECKSTRING3 = 3;
      public const int MODEL_CHECKSTRING4 = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ModelBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelEndWithDeleteOption(IntPtr p,int d_eleteOptionFlag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ModelError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelSetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelSetList(IntPtr p,int t_ype,IntPtr l_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetList(IntPtr p,int t_ype,out IntPtr v_list);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelSetSource(IntPtr p,int l_ibtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetSource(IntPtr p,ref int l_ibtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelWrite(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelDelete(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelGetString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelCheck(IntPtr p,ref int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelCheckSProp(IntPtr p,IntPtr s_prop,ref int s_tatus);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelPrintSummary(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelElemThickness(IntPtr p,int i_ndex,double [] t_hickness);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelElemOffset(IntPtr p,int i_ndex,double [] o_ffset);

      public static IntPtr ModelBegin() {
         return vis_ModelBegin();
      }

      public static void ModelEnd(IntPtr p) {
         vis_ModelEnd(p);
      }

      public static void ModelEndWithDeleteOption(IntPtr p,int d_eleteOptionFlag) {
         vis_ModelEndWithDeleteOption(p, d_eleteOptionFlag);
      }

      public static int ModelError(IntPtr p) {
         return vis_ModelError(p);
      }

      public static void ModelSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_ModelSetObject(p, o_bjecttype, o_bject);
      }

      public static void ModelGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_ModelGetObject(p, o_bjecttype,out o_bject);
      }

      public static void ModelSetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable) {
         vis_ModelSetHashTable(p, t_ype, h_ashtable);
      }

      public static void ModelGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable) {
         vis_ModelGetHashTable(p, t_ype,out h_ashtable);
      }

      public static void ModelSetList(IntPtr p,int t_ype,IntPtr l_ist) {
         vis_ModelSetList(p, t_ype, l_ist);
      }

      public static void ModelGetList(IntPtr p,int t_ype,out IntPtr v_list) {
         vis_ModelGetList(p, t_ype,out v_list);
      }

      public static void ModelSetParami(IntPtr p,int t_ype,int i_param) {
         vis_ModelSetParami(p, t_ype, i_param);
      }

      public static void ModelSetSource(IntPtr p,int l_ibtype) {
         vis_ModelSetSource(p, l_ibtype);
      }

      public static void ModelGetSource(IntPtr p,ref int l_ibtype) {
         vis_ModelGetSource(p,ref l_ibtype);
      }

      public static void ModelWrite(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_ModelWrite(p, t_ype, p_ath);
      }

      public static void ModelDelete(IntPtr p) {
         vis_ModelDelete(p);
      }

      public static void ModelGetInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_ModelGetInteger(p, t_ype, i_param);
      }

      public static void ModelGetString(IntPtr p,int t_ype,StringBuilder c_param) {
         vis_ModelGetString(p, t_ype, c_param);
      }

      public static void ModelCheck(IntPtr p,ref int s_tatus) {
         vis_ModelCheck(p,ref s_tatus);
      }

      public static void ModelCheckSProp(IntPtr p,IntPtr s_prop,ref int s_tatus) {
         vis_ModelCheckSProp(p, s_prop,ref s_tatus);
      }

      public static void ModelPrintSummary(IntPtr p) {
         vis_ModelPrintSummary(p);
      }

      public static void ModelPrint(IntPtr p) {
         vis_ModelPrint(p);
      }

      public static void ModelElemThickness(IntPtr p,int i_ndex,double [] t_hickness) {
         vis_ModelElemThickness(p, i_ndex, t_hickness);
      }

      public static void ModelElemOffset(IntPtr p,int i_ndex,double [] o_ffset) {
         vis_ModelElemOffset(p, i_ndex, o_ffset);
      }

      public const int VIS_MODELCHK_ACTION_CHECK = 1;
      public const int VIS_MODELCHK_ACTION_PROCESS = 2;
      public const int VIS_MODELCHK_CIRC_DEPENDENCY = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ModelChkBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelChkEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ModelChkError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelChkDef(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ModelChkMPC(IntPtr p,int M_PCtype,int a_ction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ModelChkGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable);

      public static IntPtr ModelChkBegin() {
         return vis_ModelChkBegin();
      }

      public static void ModelChkEnd(IntPtr p) {
         vis_ModelChkEnd(p);
      }

      public static int ModelChkError(IntPtr p) {
         return vis_ModelChkError(p);
      }

      public static void ModelChkDef(IntPtr p,IntPtr m_odel) {
         vis_ModelChkDef(p, m_odel);
      }

      public static int ModelChkMPC(IntPtr p,int M_PCtype,int a_ction) {
         return vis_ModelChkMPC(p, M_PCtype, a_ction);
      }

      public static void ModelChkGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable) {
         vis_ModelChkGetHashTable(p, t_ype,out h_ashtable);
      }

      public const int MPROP_360 = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_MPropBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_MPropError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropDef(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropInq(IntPtr p,ref int m_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropReDef(IntPtr p,int m_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValuef(IntPtr p,int t_ype,float r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValuefv(IntPtr p,int t_ype,float [] r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValuedv(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetValueId(IntPtr p,int t_ype,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropUnSetValue(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueTypeNum(IntPtr p,ref int n_types);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueId(IntPtr p,int t_ype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueFloat(IntPtr p,int t_ype,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropStreamNum(IntPtr p,int s_trmtype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_MPropCopy(IntPtr p,IntPtr f_romp);

      public static IntPtr MPropBegin() {
         return vis_MPropBegin();
      }

      public static void MPropEnd(IntPtr p) {
         vis_MPropEnd(p);
      }

      public static int MPropError(IntPtr p) {
         return vis_MPropError(p);
      }

      public static void MPropDef(IntPtr p,int t_ype) {
         vis_MPropDef(p, t_ype);
      }

      public static void MPropInq(IntPtr p,ref int m_type) {
         vis_MPropInq(p,ref m_type);
      }

      public static void MPropReDef(IntPtr p,int m_type) {
         vis_MPropReDef(p, m_type);
      }

      public static void MPropSetParami(IntPtr p,int t_ype,int i_param) {
         vis_MPropSetParami(p, t_ype, i_param);
      }

      public static void MPropSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_MPropSetValuei(p, t_ype, i_value);
      }

      public static void MPropSetValuef(IntPtr p,int t_ype,float r_value) {
         vis_MPropSetValuef(p, t_ype, r_value);
      }

      public static void MPropSetValuefv(IntPtr p,int t_ype,float [] r_value) {
         vis_MPropSetValuefv(p, t_ype, r_value);
      }

      public static void MPropSetValued(IntPtr p,int t_ype,double d_param) {
         vis_MPropSetValued(p, t_ype, d_param);
      }

      public static void MPropSetValuedv(IntPtr p,int t_ype,double [] d_param) {
         vis_MPropSetValuedv(p, t_ype, d_param);
      }

      public static void MPropSetValueId(IntPtr p,int t_ype,int i_d) {
         vis_MPropSetValueId(p, t_ype, i_d);
      }

      public static void MPropUnSetValue(IntPtr p,int t_ype) {
         vis_MPropUnSetValue(p, t_ype);
      }

      public static void MPropValueTypeNum(IntPtr p,ref int n_types) {
         vis_MPropValueTypeNum(p,ref n_types);
      }

      public static void MPropValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_MPropValueType(p,ref n_types, t_ype);
      }

      public static void MPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_MPropValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void MPropValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_MPropValueFlag(p, t_ype,ref f_lag);
      }

      public static void MPropValueId(IntPtr p,int t_ype,ref int i_d) {
         vis_MPropValueId(p, t_ype,ref i_d);
      }

      public static void MPropValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_MPropValueName(p, t_ype, n_ame);
      }

      public static void MPropValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_MPropValueDouble(p, t_ype, d_param);
      }

      public static void MPropValueFloat(IntPtr p,int t_ype,float [] f_param) {
         vis_MPropValueFloat(p, t_ype, f_param);
      }

      public static void MPropValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_MPropValueInteger(p, t_ype, i_param);
      }

      public static void MPropStreamNum(IntPtr p,int s_trmtype,ref int n_um) {
         vis_MPropStreamNum(p, s_trmtype,ref n_um);
      }

      public static void MPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata) {
         vis_MPropStreamSave(p, s_trmtype,ref d_ata);
      }

      public static void MPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata) {
         vis_MPropStreamLoad(p, s_trmtype, n_dat,ref d_ata);
      }

      public static void MPropSetId(IntPtr p,int i_d) {
         vis_MPropSetId(p, i_d);
      }

      public static void MPropGetId(IntPtr p,ref int i_d) {
         vis_MPropGetId(p,ref i_d);
      }

      public static void MPropSetName(IntPtr p,StringBuilder n_ame) {
         vis_MPropSetName(p, n_ame);
      }

      public static void MPropGetName(IntPtr p,StringBuilder n_ame) {
         vis_MPropGetName(p, n_ame);
      }

      public static void MPropPrint(IntPtr p) {
         vis_MPropPrint(p);
      }

      public static void MPropCopy(IntPtr p,IntPtr f_romp) {
         vis_MPropCopy(p, f_romp);
      }

      public const int MPROP_UNDEFINED = 0;
      public const int MPROP_VALUE = 1;
      public const int MPROP_IDENTIFIER = 2;
      public const int MPROP_HYPER_N = 31;
      public const int MPROP_PLASTICITY_HARDENING_TYPE = 40;
      public const int MPROP_PLASTICITY_TABULAR_DATA = 41;
      public const int MPROP_DENSITY = 0;
      public const int MPROP_E = 1;
      public const int MPROP_NU = 2;
      public const int MPROP_G = 3;
      public const int MPROP_A = 4;
      public const int MPROP_GE = 5;
      public const int MPROP_TREF = 6;
      public const int MPROP_EORT = 7;
      public const int MPROP_NUORT = 8;
      public const int MPROP_GORT = 9;
      public const int MPROP_AORT = 10;
      public const int MPROP_DMAT = 11;
      public const int MPROP_AVEC = 12;
      public const int MPROP_SXT = 13;
      public const int MPROP_SXC = 14;
      public const int MPROP_SYT = 15;
      public const int MPROP_SYC = 16;
      public const int MPROP_SHR = 17;
      public const int MPROP_K = 19;
      public const int MPROP_CP = 20;
      public const int MPROP_FILM = 21;
      public const int MPROP_HGEN = 22;
      public const int MPROP_EREF = 23;
      public const int MPROP_EMIS = 24;
      public const int MPROP_KMAT = 26;
      public const int MPROP_BULK = 27;
      public const int MPROP_SOUND = 28;
      public const int MPROP_HYPER_CIJ = 29;
      public const int MPROP_HYPER_DI = 30;
      public const int MPROP_F12 = 32;
      public const int MPROP_VISCOSITY = 33;
      public const int MPROP_EXT = 34;
      public const int MPROP_EXC = 35;
      public const int MPROP_EYT = 36;
      public const int MPROP_EYC = 37;
      public const int MPROP_EHR = 38;
      public const int MPROP_USER = 39;
      public const int MPROP_ALLOWTYPE = 18;
      public const int MPROP_MAX = 42;

      public const int RANGE_MAX_STATES = 16;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RangeBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RangeEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RangeError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RangeSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RangeSetState(IntPtr p,int i_ndex,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RangeSurfGroup(IntPtr p,int i_ndex,float v_alue,IntPtr g_roupdst,IntPtr g_roup);

      public static IntPtr RangeBegin() {
         return vis_RangeBegin();
      }

      public static void RangeEnd(IntPtr p) {
         vis_RangeEnd(p);
      }

      public static int RangeError(IntPtr p) {
         return vis_RangeError(p);
      }

      public static void RangeSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_RangeSetObject(p, o_bjecttype, o_bject);
      }

      public static void RangeSetState(IntPtr p,int i_ndex,IntPtr s_tate) {
         vis_RangeSetState(p, i_ndex, s_tate);
      }

      public static void RangeSurfGroup(IntPtr p,int i_ndex,float v_alue,IntPtr g_roupdst,IntPtr g_roup) {
         vis_RangeSurfGroup(p, i_ndex, v_alue, g_roupdst, g_roup);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RBodyBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RBodyError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyDef(IntPtr p,int e_nttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyInq(IntPtr p,ref int e_nttype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetElem(IntPtr p,int i_ndex,int n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyElemMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyElemNum(IntPtr p,ref int n_umindex,ref int n_umentity);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyElemFlag(IntPtr p,int i_ndex,ref int e_lem,ref int f_lags);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyElemEnt(IntPtr p,int i_ndex,ref int e_lem,ref int n_umno,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetNode(IntPtr p,int i_ndex,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyNodeMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyNodeNum(IntPtr p,ref int n_umindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyNodeType(IntPtr p,int i_ndex,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetRefNode(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyGetRefNode(IntPtr p,ref int r_efnode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetValued(IntPtr p,int t_ype,ref double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyFaceIdTran(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyEdgeIdTran(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyNodeIdTran(IntPtr p,int t_ype,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodySetASurf(IntPtr p,int a_sid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RBodyASurf(IntPtr p,ref int a_sid);

      public static IntPtr RBodyBegin() {
         return vis_RBodyBegin();
      }

      public static void RBodyEnd(IntPtr p) {
         vis_RBodyEnd(p);
      }

      public static int RBodyError(IntPtr p) {
         return vis_RBodyError(p);
      }

      public static void RBodyDef(IntPtr p,int e_nttype) {
         vis_RBodyDef(p, e_nttype);
      }

      public static void RBodyInq(IntPtr p,ref int e_nttype) {
         vis_RBodyInq(p,ref e_nttype);
      }

      public static void RBodySetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_RBodySetObject(p, o_bjecttype, o_bject);
      }

      public static void RBodySetName(IntPtr p,StringBuilder n_ame) {
         vis_RBodySetName(p, n_ame);
      }

      public static void RBodyGetName(IntPtr p,StringBuilder n_ame) {
         vis_RBodyGetName(p, n_ame);
      }

      public static void RBodySetElem(IntPtr p,int i_ndex,int n_o) {
         vis_RBodySetElem(p, i_ndex, n_o);
      }

      public static void RBodyElemMax(IntPtr p,ref int m_axindex) {
         vis_RBodyElemMax(p,ref m_axindex);
      }

      public static void RBodyElemNum(IntPtr p,ref int n_umindex,ref int n_umentity) {
         vis_RBodyElemNum(p,ref n_umindex,ref n_umentity);
      }

      public static void RBodyElemFlag(IntPtr p,int i_ndex,ref int e_lem,ref int f_lags) {
         vis_RBodyElemFlag(p, i_ndex,ref e_lem,ref f_lags);
      }

      public static void RBodyElemEnt(IntPtr p,int i_ndex,ref int e_lem,ref int n_umno,int [] n_o) {
         vis_RBodyElemEnt(p, i_ndex,ref e_lem,ref n_umno, n_o);
      }

      public static void RBodySetNode(IntPtr p,int i_ndex,int t_ype) {
         vis_RBodySetNode(p, i_ndex, t_ype);
      }

      public static void RBodyNodeMax(IntPtr p,ref int m_axindex) {
         vis_RBodyNodeMax(p,ref m_axindex);
      }

      public static void RBodyNodeNum(IntPtr p,ref int n_umindex) {
         vis_RBodyNodeNum(p,ref n_umindex);
      }

      public static void RBodyNodeType(IntPtr p,int i_ndex,ref int t_ype) {
         vis_RBodyNodeType(p, i_ndex,ref t_ype);
      }

      public static void RBodySpecFlag(IntPtr p,ref int f_lag) {
         vis_RBodySpecFlag(p,ref f_lag);
      }

      public static void RBodySetRefNode(IntPtr p,int i_ndex) {
         vis_RBodySetRefNode(p, i_ndex);
      }

      public static void RBodyGetRefNode(IntPtr p,ref int r_efnode) {
         vis_RBodyGetRefNode(p,ref r_efnode);
      }

      public static void RBodySetValuei(IntPtr p,int t_ype,int i_value) {
         vis_RBodySetValuei(p, t_ype, i_value);
      }

      public static void RBodySetValued(IntPtr p,int t_ype,ref double d_param) {
         vis_RBodySetValued(p, t_ype,ref d_param);
      }

      public static void RBodyValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_RBodyValueType(p,ref n_types, t_ype);
      }

      public static void RBodyValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_RBodyValueFlag(p, t_ype,ref f_lag);
      }

      public static void RBodyValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_RBodyValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void RBodyValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_RBodyValueName(p, t_ype, n_ame);
      }

      public static void RBodyValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_RBodyValueDouble(p, t_ype, d_param);
      }

      public static void RBodyValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_RBodyValueInteger(p, t_ype, i_param);
      }

      public static void RBodyFaceIdTran(IntPtr p,IntPtr i_dtran) {
         vis_RBodyFaceIdTran(p, i_dtran);
      }

      public static void RBodyEdgeIdTran(IntPtr p,IntPtr i_dtran) {
         vis_RBodyEdgeIdTran(p, i_dtran);
      }

      public static void RBodyNodeIdTran(IntPtr p,int t_ype,IntPtr i_dtran) {
         vis_RBodyNodeIdTran(p, t_ype, i_dtran);
      }

      public static void RBodyPrint(IntPtr p) {
         vis_RBodyPrint(p);
      }

      public static void RBodySetASurf(IntPtr p,int a_sid) {
         vis_RBodySetASurf(p, a_sid);
      }

      public static void RBodyASurf(IntPtr p,ref int a_sid) {
         vis_RBodyASurf(p,ref a_sid);
      }

      public const int RBODY_TIE = 1;
      public const int RBODY_PIN = 2;
      public const int RBODY_UNDEFINED = 0;
      public const int RBODY_VALUE = 1;
      public const int RBODY_CURVE = 2;
      public const int RBODY_PID = 0;
      public const int RBODY_ROTATION_AXIS = 1;
      public const int RBODY_MAX = 2;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RCaseBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RCaseError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseGetComplex(IntPtr p,ref int c_omplexflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetSPC(IntPtr p,int i_ndex,int t_ag,int t_ype,float [] v_alue,int m_aster);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetSPCdv(IntPtr p,int i_ndex,int t_ag,int t_ype,double [] v_alue,int m_aster);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetSPCTId(IntPtr p,int i_ndex,int t_ag,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetSPCDot(IntPtr p,int i_ndex,int t_ag,int d_ottype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCNum(IntPtr p,ref int n_umindex,ref int n_umvalue,ref int n_ummaster);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCNumTId(IntPtr p,ref int n_umtid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCNumDot(IntPtr p,ref int n_umdot);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCUseTag(IntPtr p,ref int n_tags,int [] t_ag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCTag(IntPtr p,int i_ndex,ref int n_tags,int [] t_ag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPC(IntPtr p,int i_ndex,int t_ag,ref int t_ype,float [] v_alue,ref int m_aster);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCdv(IntPtr p,int i_ndex,int t_ag,ref int t_ype,double [] v_alue,ref int m_aster);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCTId(IntPtr p,int i_ndex,int t_ag,int [] t_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSPCDot(IntPtr p,int i_ndex,int t_ag,ref int d_ottype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetElemC(IntPtr p,int i_ndex,int t_ag,int t_ype,float [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetElemCdv(IntPtr p,int i_ndex,int t_ag,int t_ype,double [] v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCMax(IntPtr p,ref int m_axindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCNum(IntPtr p,ref int n_umindex,ref int n_umvalue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCInitIter(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCNextIter(IntPtr p,ref int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCUseTag(IntPtr p,ref int n_tags,int [] t_ag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCTag(IntPtr p,int i_ndex,ref int n_tags,int [] t_ag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemC(IntPtr p,int i_ndex,int t_ag,ref int t_ype,ref float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemCdv(IntPtr p,int i_ndex,int t_ag,ref int t_ype,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseElemGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSpecFlag(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseAdd(IntPtr p,IntPtr a_ddrcase);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCasePrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RCaseCopy(IntPtr p,IntPtr f_romp);

      public static IntPtr RCaseBegin() {
         return vis_RCaseBegin();
      }

      public static void RCaseEnd(IntPtr p) {
         vis_RCaseEnd(p);
      }

      public static int RCaseError(IntPtr p) {
         return vis_RCaseError(p);
      }

      public static void RCaseSetComplexMode(IntPtr p,int c_omplexmode) {
         vis_RCaseSetComplexMode(p, c_omplexmode);
      }

      public static void RCaseGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_RCaseGetComplexMode(p,ref c_omplexmode);
      }

      public static void RCaseGetComplex(IntPtr p,ref int c_omplexflag) {
         vis_RCaseGetComplex(p,ref c_omplexflag);
      }

      public static void RCaseSetSPC(IntPtr p,int i_ndex,int t_ag,int t_ype,float [] v_alue,int m_aster) {
         vis_RCaseSetSPC(p, i_ndex, t_ag, t_ype, v_alue, m_aster);
      }

      public static void RCaseSetSPCdv(IntPtr p,int i_ndex,int t_ag,int t_ype,double [] v_alue,int m_aster) {
         vis_RCaseSetSPCdv(p, i_ndex, t_ag, t_ype, v_alue, m_aster);
      }

      public static void RCaseSetSPCTId(IntPtr p,int i_ndex,int t_ag,int [] t_id) {
         vis_RCaseSetSPCTId(p, i_ndex, t_ag, t_id);
      }

      public static void RCaseSetSPCDot(IntPtr p,int i_ndex,int t_ag,int d_ottype) {
         vis_RCaseSetSPCDot(p, i_ndex, t_ag, d_ottype);
      }

      public static void RCaseSPCMax(IntPtr p,ref int m_axindex) {
         vis_RCaseSPCMax(p,ref m_axindex);
      }

      public static void RCaseSPCNum(IntPtr p,ref int n_umindex,ref int n_umvalue,ref int n_ummaster) {
         vis_RCaseSPCNum(p,ref n_umindex,ref n_umvalue,ref n_ummaster);
      }

      public static void RCaseSPCInitIter(IntPtr p) {
         vis_RCaseSPCInitIter(p);
      }

      public static void RCaseSPCNextIter(IntPtr p,ref int i_ndex) {
         vis_RCaseSPCNextIter(p,ref i_ndex);
      }

      public static void RCaseSPCNumTId(IntPtr p,ref int n_umtid) {
         vis_RCaseSPCNumTId(p,ref n_umtid);
      }

      public static void RCaseSPCNumDot(IntPtr p,ref int n_umdot) {
         vis_RCaseSPCNumDot(p,ref n_umdot);
      }

      public static void RCaseSPCUseTag(IntPtr p,ref int n_tags,int [] t_ag) {
         vis_RCaseSPCUseTag(p,ref n_tags, t_ag);
      }

      public static void RCaseSPCTag(IntPtr p,int i_ndex,ref int n_tags,int [] t_ag) {
         vis_RCaseSPCTag(p, i_ndex,ref n_tags, t_ag);
      }

      public static void RCaseSPC(IntPtr p,int i_ndex,int t_ag,ref int t_ype,float [] v_alue,ref int m_aster) {
         vis_RCaseSPC(p, i_ndex, t_ag,ref t_ype, v_alue,ref m_aster);
      }

      public static void RCaseSPCdv(IntPtr p,int i_ndex,int t_ag,ref int t_ype,double [] v_alue,ref int m_aster) {
         vis_RCaseSPCdv(p, i_ndex, t_ag,ref t_ype, v_alue,ref m_aster);
      }

      public static void RCaseSPCTId(IntPtr p,int i_ndex,int t_ag,int [] t_id) {
         vis_RCaseSPCTId(p, i_ndex, t_ag, t_id);
      }

      public static void RCaseSPCDot(IntPtr p,int i_ndex,int t_ag,ref int d_ottype) {
         vis_RCaseSPCDot(p, i_ndex, t_ag,ref d_ottype);
      }

      public static void RCaseNodeGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_RCaseNodeGroup(p, g_roup, g_roupdst);
      }

      public static void RCaseSetElemC(IntPtr p,int i_ndex,int t_ag,int t_ype,float [] v_alue) {
         vis_RCaseSetElemC(p, i_ndex, t_ag, t_ype, v_alue);
      }

      public static void RCaseSetElemCdv(IntPtr p,int i_ndex,int t_ag,int t_ype,double [] v_alue) {
         vis_RCaseSetElemCdv(p, i_ndex, t_ag, t_ype, v_alue);
      }

      public static void RCaseElemCMax(IntPtr p,ref int m_axindex) {
         vis_RCaseElemCMax(p,ref m_axindex);
      }

      public static void RCaseElemCNum(IntPtr p,ref int n_umindex,ref int n_umvalue) {
         vis_RCaseElemCNum(p,ref n_umindex,ref n_umvalue);
      }

      public static void RCaseElemCInitIter(IntPtr p) {
         vis_RCaseElemCInitIter(p);
      }

      public static void RCaseElemCNextIter(IntPtr p,ref int i_ndex) {
         vis_RCaseElemCNextIter(p,ref i_ndex);
      }

      public static void RCaseElemCUseTag(IntPtr p,ref int n_tags,int [] t_ag) {
         vis_RCaseElemCUseTag(p,ref n_tags, t_ag);
      }

      public static void RCaseElemCTag(IntPtr p,int i_ndex,ref int n_tags,int [] t_ag) {
         vis_RCaseElemCTag(p, i_ndex,ref n_tags, t_ag);
      }

      public static void RCaseElemC(IntPtr p,int i_ndex,int t_ag,ref int t_ype,ref float v_alue) {
         vis_RCaseElemC(p, i_ndex, t_ag,ref t_ype,ref v_alue);
      }

      public static void RCaseElemCdv(IntPtr p,int i_ndex,int t_ag,ref int t_ype,ref double v_alue) {
         vis_RCaseElemCdv(p, i_ndex, t_ag,ref t_ype,ref v_alue);
      }

      public static void RCaseElemGroup(IntPtr p,IntPtr g_roup,IntPtr g_roupdst) {
         vis_RCaseElemGroup(p, g_roup, g_roupdst);
      }

      public static void RCaseClear(IntPtr p) {
         vis_RCaseClear(p);
      }

      public static void RCaseSpecFlag(IntPtr p,ref int f_lag) {
         vis_RCaseSpecFlag(p,ref f_lag);
      }

      public static void RCaseAdd(IntPtr p,IntPtr a_ddrcase) {
         vis_RCaseAdd(p, a_ddrcase);
      }

      public static void RCaseSetId(IntPtr p,int i_d) {
         vis_RCaseSetId(p, i_d);
      }

      public static void RCaseGetId(IntPtr p,ref int i_d) {
         vis_RCaseGetId(p,ref i_d);
      }

      public static void RCaseSetName(IntPtr p,StringBuilder n_ame) {
         vis_RCaseSetName(p, n_ame);
      }

      public static void RCaseGetName(IntPtr p,StringBuilder n_ame) {
         vis_RCaseGetName(p, n_ame);
      }

      public static void RCasePrint(IntPtr p) {
         vis_RCasePrint(p);
      }

      public static void RCaseCopy(IntPtr p,IntPtr f_romp) {
         vis_RCaseCopy(p, f_romp);
      }

      public const int RCASE_FREE = 0;
      public const int RCASE_FIXED = 1;
      public const int RCASE_APPLIED = 2;
      public const int RCASE_MASTER = 3;
      public const int RCASE_DOF = 1;
      public const int RCASE_DOFDOT = 2;
      public const int RCASE_DOFDOTDOT = 3;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RedMatBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RedMatError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatPre(IntPtr p,int p_rec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatGetPre(IntPtr p,ref int p_rec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatDef(IntPtr p,int n_dofs,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatInq(IntPtr p,ref int n_dofs,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatGetComplex(IntPtr p,ref int c_omplexflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSetDatadv(IntPtr p,int i_,int j_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSetData(IntPtr p,int i_dof,int j_dof,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatDatadv(IntPtr p,int i_,int j_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatData(IntPtr p,int i_dof,int j_dof,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSetDof(IntPtr p,int d_of,int i_ndex,int d_oftag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatGetDof(IntPtr p,int d_of,ref int n_id,ref int d_oftag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatNum(IntPtr p,ref long n_ent,ref int n_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSparse(IntPtr p,ref int s_parse);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatIthdv(IntPtr p,long i_,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatIth(IntPtr p,long i_,float [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatSetDataSize(IntPtr p,int i_dof,int n_cols);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatGetDataSize(IntPtr p,int i_,ref int s_ize);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RedMatDataCols(IntPtr p,int i_dof,ref int n_cols,int [] i_cols);

      public static IntPtr RedMatBegin() {
         return vis_RedMatBegin();
      }

      public static void RedMatEnd(IntPtr p) {
         vis_RedMatEnd(p);
      }

      public static int RedMatError(IntPtr p) {
         return vis_RedMatError(p);
      }

      public static void RedMatPre(IntPtr p,int p_rec) {
         vis_RedMatPre(p, p_rec);
      }

      public static void RedMatGetPre(IntPtr p,ref int p_rec) {
         vis_RedMatGetPre(p,ref p_rec);
      }

      public static void RedMatDef(IntPtr p,int n_dofs,int t_ype) {
         vis_RedMatDef(p, n_dofs, t_ype);
      }

      public static void RedMatInq(IntPtr p,ref int n_dofs,ref int t_ype) {
         vis_RedMatInq(p,ref n_dofs,ref t_ype);
      }

      public static void RedMatSetComplexMode(IntPtr p,int c_omplexmode) {
         vis_RedMatSetComplexMode(p, c_omplexmode);
      }

      public static void RedMatGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_RedMatGetComplexMode(p,ref c_omplexmode);
      }

      public static void RedMatGetComplex(IntPtr p,ref int c_omplexflag) {
         vis_RedMatGetComplex(p,ref c_omplexflag);
      }

      public static void RedMatSetDatadv(IntPtr p,int i_,int j_,double [] v_) {
         vis_RedMatSetDatadv(p, i_, j_, v_);
      }

      public static void RedMatSetData(IntPtr p,int i_dof,int j_dof,float [] v_) {
         vis_RedMatSetData(p, i_dof, j_dof, v_);
      }

      public static void RedMatDatadv(IntPtr p,int i_,int j_,double [] v_) {
         vis_RedMatDatadv(p, i_, j_, v_);
      }

      public static void RedMatData(IntPtr p,int i_dof,int j_dof,float [] v_) {
         vis_RedMatData(p, i_dof, j_dof, v_);
      }

      public static void RedMatPrint(IntPtr p) {
         vis_RedMatPrint(p);
      }

      public static void RedMatSetDof(IntPtr p,int d_of,int i_ndex,int d_oftag) {
         vis_RedMatSetDof(p, d_of, i_ndex, d_oftag);
      }

      public static void RedMatGetDof(IntPtr p,int d_of,ref int n_id,ref int d_oftag) {
         vis_RedMatGetDof(p, d_of,ref n_id,ref d_oftag);
      }

      public static void RedMatNum(IntPtr p,ref long n_ent,ref int n_val) {
         vis_RedMatNum(p,ref n_ent,ref n_val);
      }

      public static void RedMatSparse(IntPtr p,ref int s_parse) {
         vis_RedMatSparse(p,ref s_parse);
      }

      public static void RedMatIthdv(IntPtr p,long i_,double [] v_) {
         vis_RedMatIthdv(p, i_, v_);
      }

      public static void RedMatIth(IntPtr p,long i_,float [] v_) {
         vis_RedMatIth(p, i_, v_);
      }

      public static void RedMatSetDataSize(IntPtr p,int i_dof,int n_cols) {
         vis_RedMatSetDataSize(p, i_dof, n_cols);
      }

      public static void RedMatGetDataSize(IntPtr p,int i_,ref int s_ize) {
         vis_RedMatGetDataSize(p, i_,ref s_ize);
      }

      public static void RedMatDataCols(IntPtr p,int i_dof,ref int n_cols,int [] i_cols) {
         vis_RedMatDataCols(p, i_dof,ref n_cols, i_cols);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ResultMetadataBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataSetSize(IntPtr p,long l_ength,int r_owsCount,int c_olumnsCount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataSetType(IntPtr p,int d_atatype,int p_arenttype,int c_hildtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataInq(IntPtr p,StringBuilder n_ame,ref long l_ength,ref int r_owsCount,ref int c_olumnsCount,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataAddAttributeInt(IntPtr p,StringBuilder n_ame,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataAddAttributeFloat(IntPtr p,StringBuilder n_ame,float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataAddAttributeDouble(IntPtr p,StringBuilder n_ame,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataAddAttributeString(IntPtr p,StringBuilder n_ame,StringBuilder v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetAttributeValueInt(IntPtr p,StringBuilder n_ame,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetAttributeValueFloat(IntPtr p,StringBuilder n_ame,ref float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetAttributeValueDouble(IntPtr p,StringBuilder n_ame,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetAttributeValueString(IntPtr p,StringBuilder n_ame,StringBuilder v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataSetResultType(IntPtr p,int r_esultType);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetDimensions(IntPtr p,StringBuilder d_imensions);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataEntType(IntPtr p,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ResultMetadataError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataPrintAttributes(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ResultMetadataGetAttributesNames(IntPtr p,out IntPtr a_ttributesNames);

      public static IntPtr ResultMetadataBegin() {
         return vis_ResultMetadataBegin();
      }

      public static void ResultMetadataEnd(IntPtr p) {
         vis_ResultMetadataEnd(p);
      }

      public static void ResultMetadataSetSize(IntPtr p,long l_ength,int r_owsCount,int c_olumnsCount) {
         vis_ResultMetadataSetSize(p, l_ength, r_owsCount, c_olumnsCount);
      }

      public static void ResultMetadataSetType(IntPtr p,int d_atatype,int p_arenttype,int c_hildtype) {
         vis_ResultMetadataSetType(p, d_atatype, p_arenttype, c_hildtype);
      }

      public static void ResultMetadataSetName(IntPtr p,StringBuilder n_ame) {
         vis_ResultMetadataSetName(p, n_ame);
      }

      public static void ResultMetadataInq(IntPtr p,StringBuilder n_ame,ref long l_ength,ref int r_owsCount,ref int c_olumnsCount,ref int t_ype) {
         vis_ResultMetadataInq(p, n_ame,ref l_ength,ref r_owsCount,ref c_olumnsCount,ref t_ype);
      }

      public static void ResultMetadataAddAttributeInt(IntPtr p,StringBuilder n_ame,int v_alue) {
         vis_ResultMetadataAddAttributeInt(p, n_ame, v_alue);
      }

      public static void ResultMetadataAddAttributeFloat(IntPtr p,StringBuilder n_ame,float v_alue) {
         vis_ResultMetadataAddAttributeFloat(p, n_ame, v_alue);
      }

      public static void ResultMetadataAddAttributeDouble(IntPtr p,StringBuilder n_ame,double v_alue) {
         vis_ResultMetadataAddAttributeDouble(p, n_ame, v_alue);
      }

      public static void ResultMetadataAddAttributeString(IntPtr p,StringBuilder n_ame,StringBuilder v_alue) {
         vis_ResultMetadataAddAttributeString(p, n_ame, v_alue);
      }

      public static void ResultMetadataGetAttributeValueInt(IntPtr p,StringBuilder n_ame,ref int v_alue) {
         vis_ResultMetadataGetAttributeValueInt(p, n_ame,ref v_alue);
      }

      public static void ResultMetadataGetAttributeValueFloat(IntPtr p,StringBuilder n_ame,ref float v_alue) {
         vis_ResultMetadataGetAttributeValueFloat(p, n_ame,ref v_alue);
      }

      public static void ResultMetadataGetAttributeValueDouble(IntPtr p,StringBuilder n_ame,ref double v_alue) {
         vis_ResultMetadataGetAttributeValueDouble(p, n_ame,ref v_alue);
      }

      public static void ResultMetadataGetAttributeValueString(IntPtr p,StringBuilder n_ame,StringBuilder v_alue) {
         vis_ResultMetadataGetAttributeValueString(p, n_ame, v_alue);
      }

      public static void ResultMetadataSetResultType(IntPtr p,int r_esultType) {
         vis_ResultMetadataSetResultType(p, r_esultType);
      }

      public static void ResultMetadataGetDimensions(IntPtr p,StringBuilder d_imensions) {
         vis_ResultMetadataGetDimensions(p, d_imensions);
      }

      public static void ResultMetadataEntType(IntPtr p,ref int e_nttype,ref int s_ubtype) {
         vis_ResultMetadataEntType(p,ref e_nttype,ref s_ubtype);
      }

      public static int ResultMetadataError(IntPtr p) {
         return vis_ResultMetadataError(p);
      }

      public static void ResultMetadataPrintAttributes(IntPtr p) {
         vis_ResultMetadataPrintAttributes(p);
      }

      public static void ResultMetadataGetAttributesNames(IntPtr p,out IntPtr a_ttributesNames) {
         vis_ResultMetadataGetAttributesNames(p,out a_ttributesNames);
      }

      public const int RPROP_UNDEFINED = 0;
      public const int RPROP_VALUE = 1;
      public const int RPROP_LOADFACTOR = 0;
      public const int RPROP_FREQUENCY = 1;
      public const int RPROP_EIGENVALUE = 2;
      public const int RPROP_TIME = 3;
      public const int RPROP_TIMESTEP = 4;
      public const int RPROP_AMPLITUDE = 5;
      public const int RPROP_PHASE = 6;
      public const int RPROP_GENERALIZEDMASS = 7;
      public const int RPROP_LOADCASE = 8;
      public const int RPROP_CONTENTS = 9;
      public const int RPROP_DATATYPE = 10;
      public const int RPROP_COMPLEX = 11;
      public const int RPROP_TITLE = 12;
      public const int RPROP_SUBTITLE = 13;
      public const int RPROP_SUBTITLE1 = 14;
      public const int RPROP_SUBTITLE2 = 15;
      public const int RPROP_SUBTITLE3 = 16;
      public const int RPROP_SUBTITLE4 = 17;
      public const int RPROP_LABEL = 18;
      public const int RPROP_SUBLABEL = 19;
      public const int RPROP_LINK_ROTANG = 20;
      public const int RPROP_LINK_CID = 21;
      public const int RPROP_LINK_COMPLEX = 22;
      public const int RPROP_LINK_SECTION = 23;
      public const int RPROP_LINK_LAYERS = 24;
      public const int RPROP_STRAINTYPE = 25;
      public const int RPROP_DATASOURCE = 26;
      public const int RPROP_CATEGORY = 27;
      public const int RPROP_LINK_ENTDOF = 28;
      public const int RPROP_LINK_INDEX = 29;
      public const int RPROP_LABEL1 = 30;
      public const int RPROP_ESSTEYR_NT11_EXCEPTION = 31;
      public const int RPROP_SCALAR1 = 32;
      public const int RPROP_SCALAR2 = 33;
      public const int RPROP_SCALAR3 = 34;
      public const int RPROP_CYCLICCSYSID = 35;
      public const int RPROP_NONLINEAR = 36;
      public const int RPROP_MAX = 37;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RPropBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RPropError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropDef(IntPtr p,int p_arenttype,int c_hildtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropInq(IntPtr p,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetType(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetType(IntPtr p,ref int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetIds(IntPtr p,int i_d1,int i_d2,int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetMode(IntPtr p,int m_ode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetMode(IntPtr p,ref int m_ode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetAnalysis(IntPtr p,int a_nalysis);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetAnalysis(IntPtr p,ref int a_nalysis);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetSolution(IntPtr p,int s_olution);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetSolution(IntPtr p,ref int s_olution);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetHist(IntPtr p,int h_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetHist(IntPtr p,ref int h_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetCplx(IntPtr p,int c_plx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetCplx(IntPtr p,ref int c_plx);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetQual(IntPtr p,int n_qua,int [] i_qua,StringBuilder c_qua);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetQual(IntPtr p,ref int n_qua,int [] i_qua,StringBuilder c_qua);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetDatasetName(IntPtr p,StringBuilder d_sname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetDatasetName(IntPtr p,StringBuilder d_sname);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetDatasetIndex(IntPtr p,int d_sindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetDatasetIndex(IntPtr p,ref int d_sindex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValueiv(IntPtr p,int t_ype,int [] i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValuef(IntPtr p,int t_ype,float r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValuefv(IntPtr p,int t_ype,float [] r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValuedv(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropUnSetValue(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueFloat(IntPtr p,int t_ype,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropPrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RPropCopy(IntPtr p,IntPtr q_);

      public static IntPtr RPropBegin() {
         return vis_RPropBegin();
      }

      public static void RPropEnd(IntPtr p) {
         vis_RPropEnd(p);
      }

      public static int RPropError(IntPtr p) {
         return vis_RPropError(p);
      }

      public static void RPropDef(IntPtr p,int p_arenttype,int c_hildtype) {
         vis_RPropDef(p, p_arenttype, c_hildtype);
      }

      public static void RPropInq(IntPtr p,ref int e_nttype,ref int s_ubtype) {
         vis_RPropInq(p,ref e_nttype,ref s_ubtype);
      }

      public static void RPropSetType(IntPtr p,int t_ype) {
         vis_RPropSetType(p, t_ype);
      }

      public static void RPropGetType(IntPtr p,ref int t_ype) {
         vis_RPropGetType(p,ref t_ype);
      }

      public static void RPropSetIds(IntPtr p,int i_d1,int i_d2,int i_d3) {
         vis_RPropSetIds(p, i_d1, i_d2, i_d3);
      }

      public static void RPropGetIds(IntPtr p,ref int i_d1,ref int i_d2,ref int i_d3) {
         vis_RPropGetIds(p,ref i_d1,ref i_d2,ref i_d3);
      }

      public static void RPropSetMode(IntPtr p,int m_ode) {
         vis_RPropSetMode(p, m_ode);
      }

      public static void RPropGetMode(IntPtr p,ref int m_ode) {
         vis_RPropGetMode(p,ref m_ode);
      }

      public static void RPropSetAnalysis(IntPtr p,int a_nalysis) {
         vis_RPropSetAnalysis(p, a_nalysis);
      }

      public static void RPropGetAnalysis(IntPtr p,ref int a_nalysis) {
         vis_RPropGetAnalysis(p,ref a_nalysis);
      }

      public static void RPropSetSolution(IntPtr p,int s_olution) {
         vis_RPropSetSolution(p, s_olution);
      }

      public static void RPropGetSolution(IntPtr p,ref int s_olution) {
         vis_RPropGetSolution(p,ref s_olution);
      }

      public static void RPropSetHist(IntPtr p,int h_ist) {
         vis_RPropSetHist(p, h_ist);
      }

      public static void RPropGetHist(IntPtr p,ref int h_ist) {
         vis_RPropGetHist(p,ref h_ist);
      }

      public static void RPropSetCplx(IntPtr p,int c_plx) {
         vis_RPropSetCplx(p, c_plx);
      }

      public static void RPropGetCplx(IntPtr p,ref int c_plx) {
         vis_RPropGetCplx(p,ref c_plx);
      }

      public static void RPropSetQual(IntPtr p,int n_qua,int [] i_qua,StringBuilder c_qua) {
         vis_RPropSetQual(p, n_qua, i_qua, c_qua);
      }

      public static void RPropGetQual(IntPtr p,ref int n_qua,int [] i_qua,StringBuilder c_qua) {
         vis_RPropGetQual(p,ref n_qua, i_qua, c_qua);
      }

      public static void RPropSetDatasetName(IntPtr p,StringBuilder d_sname) {
         vis_RPropSetDatasetName(p, d_sname);
      }

      public static void RPropGetDatasetName(IntPtr p,StringBuilder d_sname) {
         vis_RPropGetDatasetName(p, d_sname);
      }

      public static void RPropSetDatasetIndex(IntPtr p,int d_sindex) {
         vis_RPropSetDatasetIndex(p, d_sindex);
      }

      public static void RPropGetDatasetIndex(IntPtr p,ref int d_sindex) {
         vis_RPropGetDatasetIndex(p,ref d_sindex);
      }

      public static void RPropSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_RPropSetValuei(p, t_ype, i_value);
      }

      public static void RPropSetValueiv(IntPtr p,int t_ype,int [] i_value) {
         vis_RPropSetValueiv(p, t_ype, i_value);
      }

      public static void RPropSetValuef(IntPtr p,int t_ype,float r_value) {
         vis_RPropSetValuef(p, t_ype, r_value);
      }

      public static void RPropSetValuefv(IntPtr p,int t_ype,float [] r_value) {
         vis_RPropSetValuefv(p, t_ype, r_value);
      }

      public static void RPropSetValued(IntPtr p,int t_ype,double d_param) {
         vis_RPropSetValued(p, t_ype, d_param);
      }

      public static void RPropSetValuedv(IntPtr p,int t_ype,double [] d_param) {
         vis_RPropSetValuedv(p, t_ype, d_param);
      }

      public static void RPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value) {
         vis_RPropSetValuec(p, t_ype, c_value);
      }

      public static void RPropUnSetValue(IntPtr p,int t_ype) {
         vis_RPropUnSetValue(p, t_ype);
      }

      public static void RPropValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_RPropValueType(p,ref n_types, t_ype);
      }

      public static void RPropValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_RPropValueFlag(p, t_ype,ref f_lag);
      }

      public static void RPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_RPropValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void RPropValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_RPropValueName(p, t_ype, n_ame);
      }

      public static void RPropValueFloat(IntPtr p,int t_ype,float [] f_param) {
         vis_RPropValueFloat(p, t_ype, f_param);
      }

      public static void RPropValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_RPropValueDouble(p, t_ype, d_param);
      }

      public static void RPropValueString(IntPtr p,int t_ype,StringBuilder c_param) {
         vis_RPropValueString(p, t_ype, c_param);
      }

      public static void RPropValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_RPropValueInteger(p, t_ype, i_param);
      }

      public static void RPropSetName(IntPtr p,StringBuilder n_ame) {
         vis_RPropSetName(p, n_ame);
      }

      public static void RPropGetName(IntPtr p,StringBuilder n_ame) {
         vis_RPropGetName(p, n_ame);
      }

      public static void RPropPrint(IntPtr p) {
         vis_RPropPrint(p);
      }

      public static void RPropCopy(IntPtr p,IntPtr q_) {
         vis_RPropCopy(p, q_);
      }

      public const int SPACE_LINE_INFINITE = 2;
      public const int SPACE_PLANE_INFINITE = 6;
      public const int SPACE_DEPTH = 11;
      public const int SPACE_RESOLUTION = 12;
      public const int SPACE_RESOLUTION_ADAPT = 13;
      public const int SPACE_DECOMP_BLOCK = 31;
      public const int SPACE_DECOMP_ADAPT_BLOCK = 32;
      public const int SPACE_TOLERANCE = 50;
      public const int SPACE_REFINE = 51;
      public const int SPACE_NODE_SEARCH = 60;
      public const int SPACE_NODE_LOWEST = 61;
      public const int SPACE_NODE_CLOSEST = 62;
      public const int SPACE_NODE_ANY = 63;
      public const int SPACE_TREE = 70;
      public const int SPACE_TREE_OCTREE = 71;
      public const int SPACE_TREE_ADTREE = 72;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_SpaceBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_SpaceError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceSetParami(IntPtr p,int t_ype,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetParami(IntPtr p,int t_ype,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceSetParamf(IntPtr p,int p_type,float f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetParamf(IntPtr p,int t_ype,ref float v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceKernel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceElemRST(IntPtr p,float [] x_,IntPtr g_roup,ref int i_d,float [] r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceElemRSTdv(IntPtr p,double [] x_,IntPtr g_roup,ref int i_d,double [] r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceNodeKernel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpacePointIdTran(IntPtr p,int n_um_pts,float [] p_ts,IntPtr g_roup,IntPtr i_dtran,float [] r_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceLineGroup(IntPtr p,float [] l_ine_pts,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpacePlaneGroup(IntPtr p,float [] p_lane_pts,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpacePlaneGroupdv(IntPtr p,double [] p_ts,IntPtr s_ubset,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceBoxNodeGroup(IntPtr p,float [] b_ox_pts,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceBoxGroup(IntPtr p,float [] b_ox_pts,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetNumBlocks(IntPtr p,ref int n_um_blocks);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetElemList(IntPtr p,int b_lock,ref int n_um_elem,out int [] l_ist);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceSetMaxCount(IntPtr p,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetMaxCount(IntPtr p,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetStats(IntPtr p,ref int m_ax_elem,ref int m_in_elem,ref int a_vg_elem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceGetExtents(IntPtr p,ref int n_um_pts,float p_ts);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpaceDupNodeIdTran(IntPtr p,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpacePointNodeIdTran(IntPtr p,int n_um_pts,float [] p_ts,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SpacePrint(IntPtr p);

      public static IntPtr SpaceBegin() {
         return vis_SpaceBegin();
      }

      public static void SpaceEnd(IntPtr p) {
         vis_SpaceEnd(p);
      }

      public static int SpaceError(IntPtr p) {
         return vis_SpaceError(p);
      }

      public static void SpaceSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_SpaceSetObject(p, o_bjecttype, o_bject);
      }

      public static void SpaceSetParami(IntPtr p,int t_ype,int v_alue) {
         vis_SpaceSetParami(p, t_ype, v_alue);
      }

      public static void SpaceGetParami(IntPtr p,int t_ype,ref int v_alue) {
         vis_SpaceGetParami(p, t_ype,ref v_alue);
      }

      public static void SpaceSetParamf(IntPtr p,int p_type,float f_param) {
         vis_SpaceSetParamf(p, p_type, f_param);
      }

      public static void SpaceGetParamf(IntPtr p,int t_ype,ref float v_alue) {
         vis_SpaceGetParamf(p, t_ype,ref v_alue);
      }

      public static void SpaceKernel(IntPtr p) {
         vis_SpaceKernel(p);
      }

      public static void SpaceElemRST(IntPtr p,float [] x_,IntPtr g_roup,ref int i_d,float [] r_) {
         vis_SpaceElemRST(p, x_, g_roup,ref i_d, r_);
      }

      public static void SpaceElemRSTdv(IntPtr p,double [] x_,IntPtr g_roup,ref int i_d,double [] r_) {
         vis_SpaceElemRSTdv(p, x_, g_roup,ref i_d, r_);
      }

      public static void SpaceNodeKernel(IntPtr p) {
         vis_SpaceNodeKernel(p);
      }

      public static void SpacePointIdTran(IntPtr p,int n_um_pts,float [] p_ts,IntPtr g_roup,IntPtr i_dtran,float [] r_) {
         vis_SpacePointIdTran(p, n_um_pts, p_ts, g_roup, i_dtran, r_);
      }

      public static void SpaceLineGroup(IntPtr p,float [] l_ine_pts,IntPtr g_roup,IntPtr g_roupdst) {
         vis_SpaceLineGroup(p, l_ine_pts, g_roup, g_roupdst);
      }

      public static void SpacePlaneGroup(IntPtr p,float [] p_lane_pts,IntPtr g_roup,IntPtr g_roupdst) {
         vis_SpacePlaneGroup(p, p_lane_pts, g_roup, g_roupdst);
      }

      public static void SpacePlaneGroupdv(IntPtr p,double [] p_ts,IntPtr s_ubset,IntPtr g_roup) {
         vis_SpacePlaneGroupdv(p, p_ts, s_ubset, g_roup);
      }

      public static void SpaceBoxNodeGroup(IntPtr p,float [] b_ox_pts,IntPtr g_roup,IntPtr g_roupdst) {
         vis_SpaceBoxNodeGroup(p, b_ox_pts, g_roup, g_roupdst);
      }

      public static void SpaceBoxGroup(IntPtr p,float [] b_ox_pts,IntPtr g_roup,IntPtr g_roupdst) {
         vis_SpaceBoxGroup(p, b_ox_pts, g_roup, g_roupdst);
      }

      public static void SpaceGetNumBlocks(IntPtr p,ref int n_um_blocks) {
         vis_SpaceGetNumBlocks(p,ref n_um_blocks);
      }

      public static void SpaceGetElemList(IntPtr p,int b_lock,ref int n_um_elem,out int [] l_ist) {
         vis_SpaceGetElemList(p, b_lock,ref n_um_elem,out l_ist);
      }

      public static void SpaceSetMaxCount(IntPtr p,int v_alue) {
         vis_SpaceSetMaxCount(p, v_alue);
      }

      public static void SpaceGetMaxCount(IntPtr p,ref int v_alue) {
         vis_SpaceGetMaxCount(p,ref v_alue);
      }

      public static void SpaceGetStats(IntPtr p,ref int m_ax_elem,ref int m_in_elem,ref int a_vg_elem) {
         vis_SpaceGetStats(p,ref m_ax_elem,ref m_in_elem,ref a_vg_elem);
      }

      public static void SpaceGetExtents(IntPtr p,ref int n_um_pts,float p_ts) {
         vis_SpaceGetExtents(p,ref n_um_pts, p_ts);
      }

      public static void SpaceDupNodeIdTran(IntPtr p,IntPtr g_roup,IntPtr i_dtran) {
         vis_SpaceDupNodeIdTran(p, g_roup, i_dtran);
      }

      public static void SpacePointNodeIdTran(IntPtr p,int n_um_pts,float [] p_ts,IntPtr g_roup,IntPtr i_dtran) {
         vis_SpacePointNodeIdTran(p, n_um_pts, p_ts, g_roup, i_dtran);
      }

      public static void SpacePrint(IntPtr p) {
         vis_SpacePrint(p);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_SPropBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_SPropError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropDef(IntPtr p,int p_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropInq(IntPtr p,ref int s_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropReDef(IntPtr p,int s_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValuei(IntPtr p,int t_ype,int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValueiv(IntPtr p,int t_ype,int [] i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValuef(IntPtr p,int t_ype,float r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValuefv(IntPtr p,int t_ype,float [] r_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValued(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValuedv(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetValueId(IntPtr p,int t_ype,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropUnSetValue(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueTypeNum(IntPtr p,ref int n_types);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueType(IntPtr p,ref int n_types,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueFlag(IntPtr p,int t_ype,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueId(IntPtr p,int t_ype,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueName(IntPtr p,int t_ype,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueFloat(IntPtr p,int t_ype,float [] f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueDouble(IntPtr p,int t_ype,double [] d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueString(IntPtr p,int t_ype,StringBuilder c_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropValueInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropStreamNum(IntPtr p,int s_trmtype,ref int n_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SPropPrint(IntPtr p);

      public static IntPtr SPropBegin() {
         return vis_SPropBegin();
      }

      public static void SPropEnd(IntPtr p) {
         vis_SPropEnd(p);
      }

      public static int SPropError(IntPtr p) {
         return vis_SPropError(p);
      }

      public static void SPropDef(IntPtr p,int p_type) {
         vis_SPropDef(p, p_type);
      }

      public static void SPropInq(IntPtr p,ref int s_type) {
         vis_SPropInq(p,ref s_type);
      }

      public static void SPropReDef(IntPtr p,int s_type) {
         vis_SPropReDef(p, s_type);
      }

      public static void SPropSetParami(IntPtr p,int t_ype,int i_param) {
         vis_SPropSetParami(p, t_ype, i_param);
      }

      public static void SPropSetValuei(IntPtr p,int t_ype,int i_value) {
         vis_SPropSetValuei(p, t_ype, i_value);
      }

      public static void SPropSetValueiv(IntPtr p,int t_ype,int [] i_value) {
         vis_SPropSetValueiv(p, t_ype, i_value);
      }

      public static void SPropSetValuef(IntPtr p,int t_ype,float r_value) {
         vis_SPropSetValuef(p, t_ype, r_value);
      }

      public static void SPropSetValuefv(IntPtr p,int t_ype,float [] r_value) {
         vis_SPropSetValuefv(p, t_ype, r_value);
      }

      public static void SPropSetValued(IntPtr p,int t_ype,double d_param) {
         vis_SPropSetValued(p, t_ype, d_param);
      }

      public static void SPropSetValuedv(IntPtr p,int t_ype,double [] d_param) {
         vis_SPropSetValuedv(p, t_ype, d_param);
      }

      public static void SPropSetValuec(IntPtr p,int t_ype,StringBuilder c_value) {
         vis_SPropSetValuec(p, t_ype, c_value);
      }

      public static void SPropSetValueId(IntPtr p,int t_ype,int i_d) {
         vis_SPropSetValueId(p, t_ype, i_d);
      }

      public static void SPropUnSetValue(IntPtr p,int t_ype) {
         vis_SPropUnSetValue(p, t_ype);
      }

      public static void SPropAddUserValue(IntPtr p,int n_dim,StringBuilder n_ame,int [] d_im,int d_type,ref IntPtr d_at) {
         vis_SPropAddUserValue(p, n_dim, n_ame, d_im, d_type,ref d_at);
      }

      public static void SPropValueTypeNum(IntPtr p,ref int n_types) {
         vis_SPropValueTypeNum(p,ref n_types);
      }

      public static void SPropValueType(IntPtr p,ref int n_types,int [] t_ype) {
         vis_SPropValueType(p,ref n_types, t_ype);
      }

      public static void SPropValueFlag(IntPtr p,int t_ype,ref int f_lag) {
         vis_SPropValueFlag(p, t_ype,ref f_lag);
      }

      public static void SPropValueId(IntPtr p,int t_ype,ref int i_d) {
         vis_SPropValueId(p, t_ype,ref i_d);
      }

      public static void SPropValueParams(IntPtr p,int t_ype,ref int n_val,ref int d_typ) {
         vis_SPropValueParams(p, t_ype,ref n_val,ref d_typ);
      }

      public static void SPropValueName(IntPtr p,int t_ype,StringBuilder n_ame) {
         vis_SPropValueName(p, t_ype, n_ame);
      }

      public static void SPropValueFloat(IntPtr p,int t_ype,float [] f_param) {
         vis_SPropValueFloat(p, t_ype, f_param);
      }

      public static void SPropValueDouble(IntPtr p,int t_ype,double [] d_param) {
         vis_SPropValueDouble(p, t_ype, d_param);
      }

      public static void SPropValueString(IntPtr p,int t_ype,StringBuilder c_param) {
         vis_SPropValueString(p, t_ype, c_param);
      }

      public static void SPropValueInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_SPropValueInteger(p, t_ype, i_param);
      }

      public static void SPropStreamNum(IntPtr p,int s_trmtype,ref int n_um) {
         vis_SPropStreamNum(p, s_trmtype,ref n_um);
      }

      public static void SPropStreamSave(IntPtr p,int s_trmtype,ref IntPtr d_ata) {
         vis_SPropStreamSave(p, s_trmtype,ref d_ata);
      }

      public static void SPropStreamLoad(IntPtr p,int s_trmtype,int n_dat,ref IntPtr d_ata) {
         vis_SPropStreamLoad(p, s_trmtype, n_dat,ref d_ata);
      }

      public static void SPropSetId(IntPtr p,int i_d) {
         vis_SPropSetId(p, i_d);
      }

      public static void SPropGetId(IntPtr p,ref int i_d) {
         vis_SPropGetId(p,ref i_d);
      }

      public static void SPropSetName(IntPtr p,StringBuilder n_ame) {
         vis_SPropSetName(p, n_ame);
      }

      public static void SPropGetName(IntPtr p,StringBuilder n_ame) {
         vis_SPropGetName(p, n_ame);
      }

      public static void SPropCopy(IntPtr p,IntPtr f_romp) {
         vis_SPropCopy(p, f_romp);
      }

      public static void SPropPrint(IntPtr p) {
         vis_SPropPrint(p);
      }

      public const int SYS_SOL_NONE = 0;
      public const int SYS_SOL_STATIC = 1;
      public const int SYS_SOL_VIBRATION = 2;
      public const int SYS_SOL_BUCKLING = 3;
      public const int SYS_SOL_TRANSIENT = 4;
      public const int SYS_SOL_SUPERELEMENT = 5;
      public const int SYS_SOL_FREQRESPONSE = 6;
      public const int SYS_SOL_COMPLEXEIGEN = 7;
      public const int SYS_SOL_QUASISTATIC = 8;
      public const int SYS_SOL_OUTPUT = 9;
      public const int SYS_SOL_SINGULAR = 10;
      public const int SYS_SOL_MAX = 10;
      public const int SPROP_UNDEFINED = 0;
      public const int SPROP_VALUE = 1;
      public const int SPROP_IDENTIFIER = 2;
      public const int SPROP_ANALYSIS = 0;
      public const int SPROP_CASEID = 22;
      public const int SPROP_EIGEN_NUM = 1;
      public const int SPROP_EIGEN_TYPE = 34;
      public const int SPROP_EIGEN_SOLVER = 38;
      public const int SPROP_EIGEN_CASE = 83;
      public const int SPROP_LCASE_NUM = 2;
      public const int SPROP_LCASE = 3;
      public const int SPROP_LCASE_SENSORNODE = 62;
      public const int SPROP_LCASE_SENSORDOF = 63;
      public const int SPROP_EIGEN_NORM = 39;
      public const int SPROP_EIGEN_SIZE = 40;
      public const int SPROP_EIGEN_STEPS = 41;
      public const int SPROP_LCASE_TCURVE = 23;
      public const int SPROP_LCASE_TREF = 25;
      public const int SPROP_LCASE_MODE = 60;
      public const int SPROP_LCASE_UNIT = 76;
      public const int SPROP_LCASE_TINIT = 85;
      public const int SPROP_TIME_STEPFIXED = 56;
      public const int SPROP_RCASE = 8;
      public const int SPROP_MCASE = 18;
      public const int SPROP_ICASE = 10;
      public const int SPROP_THERMALSTRAIN = 14;
      public const int SPROP_LARGESTRAIN = 15;
      public const int SPROP_NONLINEAR = 16;
      public const int SPROP_MASSDIAG = 17;
      public const int SPROP_INERTIARELIEF = 24;
      public const int SPROP_PRESTRESS = 35;
      public const int SPROP_PERTURBATION = 36;
      public const int SPROP_SAVE_FREQ = 26;
      public const int SPROP_RESFILE_FREQ = 26;
      public const int SPROP_HISTFILE_FREQ = 27;
      public const int SPROP_COUPLED_NUM = 28;
      public const int SPROP_COUPLED = 29;
      public const int SPROP_RESFILE_NUM = 30;
      public const int SPROP_RESFILE = 31;
      public const int SPROP_RESFILE_QUA1 = 50;
      public const int SPROP_RESFILE_QUA2 = 51;
      public const int SPROP_RESFILE_NSET = 77;
      public const int SPROP_RESFILE_ESET = 78;
      public const int SPROP_RESPRINT_NUM = 32;
      public const int SPROP_RESPRINT = 33;
      public const int SPROP_RESPRINT_QUA1 = 53;
      public const int SPROP_RESPRINT_QUA2 = 54;
      public const int SPROP_LHSITER_FREQ = 46;
      public const int SPROP_LHSSTEP_FREQ = 47;
      public const int SPROP_LHSFORM = 81;
      public const int SPROP_ITERMAX = 48;
      public const int SPROP_ESET_DELETE = 61;
      public const int SPROP_HISTFILE_NUM = 64;
      public const int SPROP_HISTFILE = 65;
      public const int SPROP_HISTFILE_SET = 66;
      public const int SPROP_MODALDAMP_TCURVE = 67;
      public const int SPROP_MODALDAMP_TYPE = 68;
      public const int SPROP_FREQ_TYPE = 69;
      public const int SPROP_FREQ_NUM = 70;
      public const int SPROP_FREQ_NPNTS = 73;
      public const int SPROP_FREQRESPONSE_MODAL = 75;
      public const int SPROP_FOURIER_NUM = 79;
      public const int SPROP_FOURIER = 80;
      public const int SPROP_NSM_ID = 84;
      public const int SPROP_MAX_INCREMENT_STEP = 89;
      public const int SPROP_CONTACT_NUM = 90;
      public const int SPROP_CONTACT_CASE = 91;
      public const int SPROP_RESEXPORT_NUM = 92;
      public const int SPROP_RESEXPORT = 93;
      public const int SPROP_RESIMPORT_NUM = 95;
      public const int SPROP_RESIMPORT = 96;
      public const int SPROP_USER_NUM = 59;
      public const int SPROP_EIGEN_LOWER = 11;
      public const int SPROP_EIGEN_UPPER = 12;
      public const int SPROP_EIGEN_SHIFT = 13;
      public const int SPROP_LCASE_FACTOR = 4;
      public const int SPROP_TIME_INIT = 5;
      public const int SPROP_TIME_STEP = 6;
      public const int SPROP_TIME_TERM = 7;
      public const int SPROP_TIME_STEPMIN = 42;
      public const int SPROP_TIME_STEPMAX = 43;
      public const int SPROP_RCASE_FACTOR = 9;
      public const int SPROP_MASS_FACTOR = 37;
      public const int SPROP_DAMP_ALPHA = 57;
      public const int SPROP_DAMP_BETA = 58;
      public const int SPROP_FTOL = 44;
      public const int SPROP_UTOL = 45;
      public const int SPROP_ETOL = 87;
      public const int SPROP_FREQ_LOWER = 71;
      public const int SPROP_FREQ_UPPER = 72;
      public const int SPROP_FREQ_BIAS = 74;
      public const int SPROP_TEMPMAXVARIATION = 86;
      public const int SPROP_DRILLFACTOR = 88;
      public const int SPROP_TITLE = 19;
      public const int SPROP_SUBTITLE = 20;
      public const int SPROP_LABEL = 21;
      public const int SPROP_SUBLABEL = 49;
      public const int SPROP_RESFILE_CQUA = 52;
      public const int SPROP_RESPRINT_CQUA = 55;
      public const int SPROP_DESTINATIONFILE = 82;
      public const int SPROP_RESIMPORTFILE = 94;
      public const int SPROP_MAX = 97;
      public const int SPROP_USERDIMENUM = -1000000;
      public const int SPROP_USERDIME = -2000000;
      public const int SPROP_USERNAME = -3000000;
      public const int SPROP_USERDATATYPE = -4000000;
      public const int SPROP_USERDATA = -5000000;
      public const int SPROP_USERBASE = -5000000;
      public const int SPROP_360 = 1;
      public const int SPROP_FREQ_RANGE = 2;
      public const int SPROP_FREQ_EIGEN = 3;
      public const int SPROP_FREQ_SPREAD = 4;
      public const int SPROP_MODALDAMP_CRITFRAC = 5;
      public const int SPROP_MODALDAMP_RAYLEIGH = 6;
      public const int SPROP_FREQ_RANDOM = 7;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_StateBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_StateError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StatePre(IntPtr p,int p_re);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetPre(IntPtr p,ref int i_pre);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetComplexMode(IntPtr p,int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetComplexMode(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetComplex(IntPtr p,ref int c_omplexmode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_StateErr(IntPtr p,int n_ument,int e_nttype,int s_ubtype,int d_atatype,ref int i_err);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype,int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateNumber(IntPtr p,ref int c_ount);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetEngineeringStrain(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetEngineeringStrain(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetMagnitudePhase(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetMagnitudePhase(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetIntegerData(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetIntegerData(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetScaledDirCos(IntPtr p,int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetScaledDirCos(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateClear(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataStat(IntPtr p,int n_ix,int [] i_x,int [] s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataStatElemEnt(IntPtr p,int i_ndex,int n_o,ref int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataStatNum(IntPtr p,ref int n_umstat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataEnt(IntPtr p,int i_ndex,int n_umno,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataEnt(IntPtr p,int i_d,ref int n_umno,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataSect(IntPtr p,int i_ndex,int n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataSect(IntPtr p,int n_ix,int [] i_x,int [] n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateCheckSect(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataLayPos(IntPtr p,int i_ndex,int l_pos);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataLayPos(IntPtr p,int n_ix,int [] i_x,int [] l_pos);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataSectArray(IntPtr p,int [] p_sec,int [] p_lay);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateCheckLayers(IntPtr p,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateClearData(IntPtr p,int i_ndex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataElemEnt(IntPtr p,int i_ndex,int n_o,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataElemEntdv(IntPtr p,int i_d,int n_o,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetData(IntPtr p,int i_ndex,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDataArray(IntPtr p,int n_ind,int [] i_nd,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDatadv(IntPtr p,int i_d,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetDerive(IntPtr p,int d_erive);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetDerive(IntPtr p,ref int d_erive);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateNumDerive(IntPtr p,ref int n_cmp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateTypeDerive(IntPtr p,ref int t_ypederive);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetSection(IntPtr p,int s_ection);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetSection(IntPtr p,ref int s_ection);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetSystem(IntPtr p,int s_ystem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetSystem(IntPtr p,ref int s_ystem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetSystemType(IntPtr p,int s_ystemtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateGetSystemType(IntPtr p,ref int s_ystemtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateEntitySystemId(IntPtr p,int i_ndex,ref int c_sysid);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateTransform(IntPtr p,int s_ystem,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateConvertStrain(IntPtr p,int s_traintype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateConvertComplex(IntPtr p,int c_omplextype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDemo(IntPtr p,int o_per,float f_,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDeform(IntPtr p,float f_,IntPtr s_tated,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateData(IntPtr p,int n_ix,int [] i_x,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemNode(IntPtr p,int i_d,int n_ix,int [] i_x,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemNodedv(IntPtr p,int i_d,int n_ix,int [] i_x,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElem(IntPtr p,int i_ndex,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemdv(IntPtr p,int i_d,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemEnt(IntPtr p,int t_ype,int i_ndex,int n_o,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemEntdv(IntPtr p,int t_ype,int i_d,int n_o,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemRST(IntPtr p,int i_ndex,float [] r_,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataElemRSTdv(IntPtr p,int i_d,double [] r_,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDatadv(IntPtr p,int n_ids,int [] i_ds,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataArray(IntPtr p,int m_ode,int n_ids,int [] i_ds,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataArraydv(IntPtr p,int m_ode,int n_ids,int [] i_ds,double [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataNum(IntPtr p,int i_ndex,ref int n_dat,ref int n_loc,ref int n_sec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDataMax(IntPtr p,ref int m_axdat,ref int m_axloc,ref int m_axsec);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDirCos(IntPtr p,int i_ndex,float [] t_m);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateExtent(IntPtr p,IntPtr g_roup,float [] e_xtent);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateExtentLoc(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x,int [] n_o);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateExtentLocSect(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x,int [] n_o,int [] s_c);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSum(IntPtr p,IntPtr g_roup,float [] s_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSumdv(IntPtr p,IntPtr g_roup,double [] s_um);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateMap(IntPtr p,IntPtr s_tatesrc,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateMidside(IntPtr p,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateMapElemNode(IntPtr p,IntPtr s_tatesrc,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateOperateUnary(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateOperateUnarydv(IntPtr p,int o_per,double f_,int f_unct,IntPtr s_tatex,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateOperateBinary(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr s_tatey,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateOperateBinarydv(IntPtr p,int o_per,double f_,int f_unct,IntPtr s_tatex,IntPtr s_tatey,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateDerivative(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr g_roup);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateToFloat(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSetGroupParamfv(IntPtr p,int p_type,float [] v_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSortIdTran(IntPtr p,IntPtr g_roup,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateElemGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateNodeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateWrite(IntPtr p,IntPtr r_prop,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateList(IntPtr p,int t_ype,IntPtr g_roup,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateRead(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSaveFlag(IntPtr p,ref int s_aveflag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateSave(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateRestore(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StateCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_StatePrint(IntPtr p);

      public static IntPtr StateBegin() {
         return vis_StateBegin();
      }

      public static void StateEnd(IntPtr p) {
         vis_StateEnd(p);
      }

      public static int StateError(IntPtr p) {
         return vis_StateError(p);
      }

      public static void StatePre(IntPtr p,int p_re) {
         vis_StatePre(p, p_re);
      }

      public static void StateGetPre(IntPtr p,ref int i_pre) {
         vis_StateGetPre(p,ref i_pre);
      }

      public static void StateSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_StateSetObject(p, o_bjecttype, o_bject);
      }

      public static void StateGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_StateGetObject(p, o_bjecttype,out o_bject);
      }

      public static void StateSetHashTable(IntPtr p,int t_ype,IntPtr h_ashtable) {
         vis_StateSetHashTable(p, t_ype, h_ashtable);
      }

      public static void StateGetHashTable(IntPtr p,int t_ype,out IntPtr h_ashtable) {
         vis_StateGetHashTable(p, t_ype,out h_ashtable);
      }

      public static void StateSetParami(IntPtr p,int p_type,int i_param) {
         vis_StateSetParami(p, p_type, i_param);
      }

      public static void StateSetComplexMode(IntPtr p,int c_omplexmode) {
         vis_StateSetComplexMode(p, c_omplexmode);
      }

      public static void StateGetComplexMode(IntPtr p,ref int c_omplexmode) {
         vis_StateGetComplexMode(p,ref c_omplexmode);
      }

      public static void StateGetComplex(IntPtr p,ref int c_omplexmode) {
         vis_StateGetComplex(p,ref c_omplexmode);
      }

      public static int StateErr(IntPtr p,int n_ument,int e_nttype,int s_ubtype,int d_atatype,ref int i_err) {
         return vis_StateErr(p, n_ument, e_nttype, s_ubtype, d_atatype,ref i_err);
      }

      public static void StateDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype,int d_atatype) {
         vis_StateDef(p, n_ument, p_arenttype, c_hildtype, d_atatype);
      }

      public static void StateInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype,ref int d_atatype) {
         vis_StateInq(p,ref n_ument,ref e_nttype,ref s_ubtype,ref d_atatype);
      }

      public static void StateNumber(IntPtr p,ref int c_ount) {
         vis_StateNumber(p,ref c_ount);
      }

      public static void StateSetEngineeringStrain(IntPtr p,int f_lag) {
         vis_StateSetEngineeringStrain(p, f_lag);
      }

      public static void StateGetEngineeringStrain(IntPtr p,ref int f_lag) {
         vis_StateGetEngineeringStrain(p,ref f_lag);
      }

      public static void StateSetMagnitudePhase(IntPtr p,int f_lag) {
         vis_StateSetMagnitudePhase(p, f_lag);
      }

      public static void StateGetMagnitudePhase(IntPtr p,ref int f_lag) {
         vis_StateGetMagnitudePhase(p,ref f_lag);
      }

      public static void StateSetIntegerData(IntPtr p,int f_lag) {
         vis_StateSetIntegerData(p, f_lag);
      }

      public static void StateGetIntegerData(IntPtr p,ref int f_lag) {
         vis_StateGetIntegerData(p,ref f_lag);
      }

      public static void StateSetScaledDirCos(IntPtr p,int f_lag) {
         vis_StateSetScaledDirCos(p, f_lag);
      }

      public static void StateGetScaledDirCos(IntPtr p,ref int f_lag) {
         vis_StateGetScaledDirCos(p,ref f_lag);
      }

      public static void StateClear(IntPtr p) {
         vis_StateClear(p);
      }

      public static void StateDataStat(IntPtr p,int n_ix,int [] i_x,int [] s_tat) {
         vis_StateDataStat(p, n_ix, i_x, s_tat);
      }

      public static void StateDataStatElemEnt(IntPtr p,int i_ndex,int n_o,ref int s_tat) {
         vis_StateDataStatElemEnt(p, i_ndex, n_o,ref s_tat);
      }

      public static void StateDataStatNum(IntPtr p,ref int n_umstat) {
         vis_StateDataStatNum(p,ref n_umstat);
      }

      public static void StateSetDataEnt(IntPtr p,int i_ndex,int n_umno,int [] n_o) {
         vis_StateSetDataEnt(p, i_ndex, n_umno, n_o);
      }

      public static void StateDataEnt(IntPtr p,int i_d,ref int n_umno,int [] n_o) {
         vis_StateDataEnt(p, i_d,ref n_umno, n_o);
      }

      public static void StateSetDataSect(IntPtr p,int i_ndex,int n_sec) {
         vis_StateSetDataSect(p, i_ndex, n_sec);
      }

      public static void StateDataSect(IntPtr p,int n_ix,int [] i_x,int [] n_sec) {
         vis_StateDataSect(p, n_ix, i_x, n_sec);
      }

      public static void StateCheckSect(IntPtr p,ref int f_lag) {
         vis_StateCheckSect(p,ref f_lag);
      }

      public static void StateSetDataLayPos(IntPtr p,int i_ndex,int l_pos) {
         vis_StateSetDataLayPos(p, i_ndex, l_pos);
      }

      public static void StateDataLayPos(IntPtr p,int n_ix,int [] i_x,int [] l_pos) {
         vis_StateDataLayPos(p, n_ix, i_x, l_pos);
      }

      public static void StateSetDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay) {
         vis_StateSetDataLayers(p, i_ndex, p_os, l_ay);
      }

      public static void StateDataLayers(IntPtr p,int i_ndex,int [] p_os,int [] l_ay) {
         vis_StateDataLayers(p, i_ndex, p_os, l_ay);
      }

      public static void StateSetDataSectArray(IntPtr p,int [] p_sec,int [] p_lay) {
         vis_StateSetDataSectArray(p, p_sec, p_lay);
      }

      public static void StateCheckLayers(IntPtr p,ref int f_lag) {
         vis_StateCheckLayers(p,ref f_lag);
      }

      public static void StateClearData(IntPtr p,int i_ndex) {
         vis_StateClearData(p, i_ndex);
      }

      public static void StateSetDataElemEnt(IntPtr p,int i_ndex,int n_o,float [] s_) {
         vis_StateSetDataElemEnt(p, i_ndex, n_o, s_);
      }

      public static void StateSetDataElemEntdv(IntPtr p,int i_d,int n_o,double [] s_) {
         vis_StateSetDataElemEntdv(p, i_d, n_o, s_);
      }

      public static void StateSetData(IntPtr p,int i_ndex,float [] s_) {
         vis_StateSetData(p, i_ndex, s_);
      }

      public static void StateSetDataArray(IntPtr p,int n_ind,int [] i_nd,float [] s_) {
         vis_StateSetDataArray(p, n_ind, i_nd, s_);
      }

      public static void StateSetDatadv(IntPtr p,int i_d,double [] s_) {
         vis_StateSetDatadv(p, i_d, s_);
      }

      public static void StateSetDerive(IntPtr p,int d_erive) {
         vis_StateSetDerive(p, d_erive);
      }

      public static void StateGetDerive(IntPtr p,ref int d_erive) {
         vis_StateGetDerive(p,ref d_erive);
      }

      public static void StateNumDerive(IntPtr p,ref int n_cmp) {
         vis_StateNumDerive(p,ref n_cmp);
      }

      public static void StateTypeDerive(IntPtr p,ref int t_ypederive) {
         vis_StateTypeDerive(p,ref t_ypederive);
      }

      public static void StateSetSection(IntPtr p,int s_ection) {
         vis_StateSetSection(p, s_ection);
      }

      public static void StateGetSection(IntPtr p,ref int s_ection) {
         vis_StateGetSection(p,ref s_ection);
      }

      public static void StateSetSystem(IntPtr p,int s_ystem) {
         vis_StateSetSystem(p, s_ystem);
      }

      public static void StateGetSystem(IntPtr p,ref int s_ystem) {
         vis_StateGetSystem(p,ref s_ystem);
      }

      public static void StateSetSystemType(IntPtr p,int s_ystemtype) {
         vis_StateSetSystemType(p, s_ystemtype);
      }

      public static void StateGetSystemType(IntPtr p,ref int s_ystemtype) {
         vis_StateGetSystemType(p,ref s_ystemtype);
      }

      public static void StateEntitySystemId(IntPtr p,int i_ndex,ref int c_sysid) {
         vis_StateEntitySystemId(p, i_ndex,ref c_sysid);
      }

      public static void StateTransform(IntPtr p,int s_ystem,IntPtr g_roup) {
         vis_StateTransform(p, s_ystem, g_roup);
      }

      public static void StateConvertStrain(IntPtr p,int s_traintype) {
         vis_StateConvertStrain(p, s_traintype);
      }

      public static void StateConvertComplex(IntPtr p,int c_omplextype) {
         vis_StateConvertComplex(p, c_omplextype);
      }

      public static void StateDemo(IntPtr p,int o_per,float f_,IntPtr g_roup) {
         vis_StateDemo(p, o_per, f_, g_roup);
      }

      public static void StateDeform(IntPtr p,float f_,IntPtr s_tated,IntPtr g_roup) {
         vis_StateDeform(p, f_, s_tated, g_roup);
      }

      public static void StateData(IntPtr p,int n_ix,int [] i_x,float [] s_) {
         vis_StateData(p, n_ix, i_x, s_);
      }

      public static void StateDataElemNode(IntPtr p,int i_d,int n_ix,int [] i_x,float [] s_) {
         vis_StateDataElemNode(p, i_d, n_ix, i_x, s_);
      }

      public static void StateDataElemNodedv(IntPtr p,int i_d,int n_ix,int [] i_x,double [] s_) {
         vis_StateDataElemNodedv(p, i_d, n_ix, i_x, s_);
      }

      public static void StateDataElem(IntPtr p,int i_ndex,float [] s_) {
         vis_StateDataElem(p, i_ndex, s_);
      }

      public static void StateDataElemdv(IntPtr p,int i_d,double [] s_) {
         vis_StateDataElemdv(p, i_d, s_);
      }

      public static void StateDataElemEnt(IntPtr p,int t_ype,int i_ndex,int n_o,float [] s_) {
         vis_StateDataElemEnt(p, t_ype, i_ndex, n_o, s_);
      }

      public static void StateDataElemEntdv(IntPtr p,int t_ype,int i_d,int n_o,double [] s_) {
         vis_StateDataElemEntdv(p, t_ype, i_d, n_o, s_);
      }

      public static void StateDataElemRST(IntPtr p,int i_ndex,float [] r_,float [] s_) {
         vis_StateDataElemRST(p, i_ndex, r_, s_);
      }

      public static void StateDataElemRSTdv(IntPtr p,int i_d,double [] r_,double [] s_) {
         vis_StateDataElemRSTdv(p, i_d, r_, s_);
      }

      public static void StateDatadv(IntPtr p,int n_ids,int [] i_ds,double [] s_) {
         vis_StateDatadv(p, n_ids, i_ds, s_);
      }

      public static void StateDataArray(IntPtr p,int m_ode,int n_ids,int [] i_ds,float [] s_) {
         vis_StateDataArray(p, m_ode, n_ids, i_ds, s_);
      }

      public static void StateDataArraydv(IntPtr p,int m_ode,int n_ids,int [] i_ds,double [] s_) {
         vis_StateDataArraydv(p, m_ode, n_ids, i_ds, s_);
      }

      public static void StateDataNum(IntPtr p,int i_ndex,ref int n_dat,ref int n_loc,ref int n_sec) {
         vis_StateDataNum(p, i_ndex,ref n_dat,ref n_loc,ref n_sec);
      }

      public static void StateDataMax(IntPtr p,ref int m_axdat,ref int m_axloc,ref int m_axsec) {
         vis_StateDataMax(p,ref m_axdat,ref m_axloc,ref m_axsec);
      }

      public static void StateDirCos(IntPtr p,int i_ndex,float [] t_m) {
         vis_StateDirCos(p, i_ndex, t_m);
      }

      public static void StateExtent(IntPtr p,IntPtr g_roup,float [] e_xtent) {
         vis_StateExtent(p, g_roup, e_xtent);
      }

      public static void StateExtentLoc(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x,int [] n_o) {
         vis_StateExtentLoc(p, g_roup, e_xtent, i_x, n_o);
      }

      public static void StateExtentLocSect(IntPtr p,IntPtr g_roup,float [] e_xtent,int [] i_x,int [] n_o,int [] s_c) {
         vis_StateExtentLocSect(p, g_roup, e_xtent, i_x, n_o, s_c);
      }

      public static void StateSum(IntPtr p,IntPtr g_roup,float [] s_) {
         vis_StateSum(p, g_roup, s_);
      }

      public static void StateSumdv(IntPtr p,IntPtr g_roup,double [] s_um) {
         vis_StateSumdv(p, g_roup, s_um);
      }

      public static void StateMap(IntPtr p,IntPtr s_tatesrc,IntPtr g_roup) {
         vis_StateMap(p, s_tatesrc, g_roup);
      }

      public static void StateMidside(IntPtr p,IntPtr g_roup) {
         vis_StateMidside(p, g_roup);
      }

      public static void StateMapElemNode(IntPtr p,IntPtr s_tatesrc,IntPtr g_roup,IntPtr i_dtran) {
         vis_StateMapElemNode(p, s_tatesrc, g_roup, i_dtran);
      }

      public static void StateOperateUnary(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr g_roup) {
         vis_StateOperateUnary(p, o_per, f_, f_unc, s_tatex, g_roup);
      }

      public static void StateOperateUnarydv(IntPtr p,int o_per,double f_,int f_unct,IntPtr s_tatex,IntPtr g_roup) {
         vis_StateOperateUnarydv(p, o_per, f_, f_unct, s_tatex, g_roup);
      }

      public static void StateOperateBinary(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr s_tatey,IntPtr g_roup) {
         vis_StateOperateBinary(p, o_per, f_, f_unc, s_tatex, s_tatey, g_roup);
      }

      public static void StateOperateBinarydv(IntPtr p,int o_per,double f_,int f_unct,IntPtr s_tatex,IntPtr s_tatey,IntPtr g_roup) {
         vis_StateOperateBinarydv(p, o_per, f_, f_unct, s_tatex, s_tatey, g_roup);
      }

      public static void StateDerivative(IntPtr p,int o_per,float f_,int f_unc,IntPtr s_tatex,IntPtr g_roup) {
         vis_StateDerivative(p, o_per, f_, f_unc, s_tatex, g_roup);
      }

      public static void StateToFloat(IntPtr p) {
         vis_StateToFloat(p);
      }

      public static void StateSetGroupParamfv(IntPtr p,int p_type,float [] v_param) {
         vis_StateSetGroupParamfv(p, p_type, v_param);
      }

      public static void StateSortIdTran(IntPtr p,IntPtr g_roup,IntPtr i_dtran) {
         vis_StateSortIdTran(p, g_roup, i_dtran);
      }

      public static void StateElemGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_StateElemGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void StateNodeGroup(IntPtr p,int o_per,IntPtr g_roup,IntPtr g_roupdst) {
         vis_StateNodeGroup(p, o_per, g_roup, g_roupdst);
      }

      public static void StateWrite(IntPtr p,IntPtr r_prop,int t_ype,StringBuilder p_ath) {
         vis_StateWrite(p, r_prop, t_ype, p_ath);
      }

      public static void StateList(IntPtr p,int t_ype,IntPtr g_roup,StringBuilder p_ath) {
         vis_StateList(p, t_ype, g_roup, p_ath);
      }

      public static void StateRead(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_StateRead(p, t_ype, p_ath);
      }

      public static void StateSaveFlag(IntPtr p,ref int s_aveflag) {
         vis_StateSaveFlag(p,ref s_aveflag);
      }

      public static void StateSave(IntPtr p) {
         vis_StateSave(p);
      }

      public static void StateRestore(IntPtr p) {
         vis_StateRestore(p);
      }

      public static void StateCopy(IntPtr p,IntPtr f_romp) {
         vis_StateCopy(p, f_romp);
      }

      public static void StatePrint(IntPtr p) {
         vis_StatePrint(p);
      }

      public const int STATE_ELEMNODE = 0;
      public const int STATE_NODE = 1;
      public const int STATE_ELEM = 4;
      public const int STATE_SORTHIGHLOW = 2;
      public const int STATE_MAPNONZERO = 3;
      public const int STATE_SORTABSVALUE = 4;
      public const int STATE_SORTELEMNODEAVE = 5;
      public const int STATE_MAPELEM = 6;
      public const int STATE_MAPNODE = 7;
      public const int STATE_EXTENTNONZERO = 15;
      public const int STATE_LISTWIDTH = 16;
      public const int STATE_MAPDEFINED = 17;
      public const int STATE_MIDSIDE = 18;
      public const int STATE_MAPAVE = 8;
      public const int STATE_MAPMIN = 9;
      public const int STATE_MAPMAX = 10;
      public const int STATE_MAPABSMIN = 11;
      public const int STATE_MAPABSMAX = 12;
      public const int STATE_MAPCENT = 13;
      public const int STATE_MAPGEOM = 1;
      public const int STATE_NODE_MAPAVE = 8;
      public const int STATE_NODE_MAPMIN = 9;
      public const int STATE_NODE_MAPMAX = 10;
      public const int STATE_NODE_MAPABSMIN = 11;
      public const int STATE_NODE_MAPABSMAX = 12;
      public const int STATE_MAPDIFF = 14;
      public const int STATE_MIDSIDEAVE = 19;
      public const int STATE_MIDSIDECLAMP = 20;
      public const int STATE_PATRAN_NEUTRAL = -4;
      public const int STATE_TEXT_SUMMARY = -5;
      public const int STATE_TEXT_LISTING = -6;
      public const int STATE_TEXT_SUMMMAX = -7;
      public const int STATE_EXTENT = 7;
      public const int STATE_DEFINED = 8;
      public const int STATE_NONZERO = 9;
      public const int STATE_OUTBOUND = 10;
      public const int STATE_LOCALMIN = 11;
      public const int STATE_LOCALMAX = 12;
      public const int STATE_LOCALMINMAX = 13;
      public const int STATE_EQUAL = 0;
      public const int STATE_PLUSEQUAL = 1;
      public const int STATE_MINUSEQUAL = 2;
      public const int STATE_MULTIPLYEQUAL = 3;
      public const int STATE_DIVIDEEQUAL = 4;
      public const int STATE_GRAD = 0;
      public const int STATE_GRADNORM = 1;
      public const int STATE_DIV = 2;
      public const int STATE_CURL = 3;
      public const int STATE_STRAIN = 4;
      public const int STATE_VECTORGRAD = 5;
      public const int STATE_IDENTITY = 0;
      public const int STATE_SIN = 1;
      public const int STATE_COS = 2;
      public const int STATE_TAN = 3;
      public const int STATE_ASIN = 4;
      public const int STATE_ACOS = 5;
      public const int STATE_ATAN = 6;
      public const int STATE_SQRT = 7;
      public const int STATE_LOG = 8;
      public const int STATE_EXP = 9;
      public const int STATE_ABS = 10;
      public const int STATE_RECIPROCAL = 11;
      public const int STATE_UNITY = 12;
      public const int STATE_MIN = 1;
      public const int STATE_MAX = 2;
      public const int STATE_AVERAGE = 3;
      public const int STATE_CROSS = 4;
      public const int STATE_DOT = 5;
      public const int STATE_SUM = 6;
      public const int STATE_DEMO_BEAM = 1;
      public const int STATE_DEMO_PLATE = 2;
      public const int STATE_DEMO_COORDS = 3;
      public const int STATE_DEMO_X = 4;
      public const int STATE_DEMO_Y = 5;
      public const int STATE_DEMO_Z = 6;
      public const int STATE_GLOBAL = 0;
      public const int STATE_LOCAL = 1;
      public const int STATE_ROTANG = 2;
      public const int STATE_MATERIAL = 3;
      public const int STATE_ISINTEGERDATA = 0;
      public const int STATE_CYCLICSYSTEMID = 1;
      public const int STATE_MISSINGLINKCSYS = 2;
      public const int STATE_SYSTEMDEFAULTTOROTANG = 3;
      public const int STATE_AVOIDTRANSFORMATION = 4;
      public const int STATE_SCALEDDIRCOS = 5;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_TCurveBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_TCurveError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetId(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveGetId(IntPtr p,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveGetName(IntPtr p,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveDef(IntPtr p,int t_ype,int n_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveInq(IntPtr p,ref int t_ype,ref int n_val);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetFactor(IntPtr p,int p_type,float p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetFactord(IntPtr p,int t_ype,double f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveGetFactor(IntPtr p,int t_ype,ref float f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveGetFactord(IntPtr p,int t_ype,ref double f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetParamd(IntPtr p,int t_ype,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveGetParami(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetPWLinear(IntPtr p,int n_pts,float [] t_,float [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetPWLineardv(IntPtr p,int n_pts,double [] t_,double [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetCompPWLinear(IntPtr p,int n_pts,int i_val,float [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveNum(IntPtr p,ref int n_pts);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveIndep(IntPtr p,int n_pts,int [] p_ts,float [] t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveIndepdv(IntPtr p,int n_pts,int [] p_ts,double [] t_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveDep(IntPtr p,int n_pts,int [] p_ts,float [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveDepdv(IntPtr p,int n_pts,int [] p_ts,double [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetDep(IntPtr p,int n_pts,int [] p_ts,float [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveSetDepdv(IntPtr p,int n_pts,int [] p_ts,double [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveEval(IntPtr p,int n_pts,float [] t_,float [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveEvaldv(IntPtr p,int n_pts,double [] t_,double [] f_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveMerge(IntPtr p,int n_um,IntPtr t_curvex);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurveIndepMatch(IntPtr p,int n_pts,float [] t_,ref int f_lag);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TCurvePrint(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_TCurveIsEqualTo(IntPtr p,IntPtr q_);

      public static IntPtr TCurveBegin() {
         return vis_TCurveBegin();
      }

      public static void TCurveEnd(IntPtr p) {
         vis_TCurveEnd(p);
      }

      public static int TCurveError(IntPtr p) {
         return vis_TCurveError(p);
      }

      public static void TCurveSetId(IntPtr p,int i_d) {
         vis_TCurveSetId(p, i_d);
      }

      public static void TCurveGetId(IntPtr p,ref int i_d) {
         vis_TCurveGetId(p,ref i_d);
      }

      public static void TCurveSetName(IntPtr p,StringBuilder n_ame) {
         vis_TCurveSetName(p, n_ame);
      }

      public static void TCurveGetName(IntPtr p,StringBuilder n_ame) {
         vis_TCurveGetName(p, n_ame);
      }

      public static void TCurveDef(IntPtr p,int t_ype,int n_val) {
         vis_TCurveDef(p, t_ype, n_val);
      }

      public static void TCurveInq(IntPtr p,ref int t_ype,ref int n_val) {
         vis_TCurveInq(p,ref t_ype,ref n_val);
      }

      public static void TCurveSetFactor(IntPtr p,int p_type,float p_aram) {
         vis_TCurveSetFactor(p, p_type, p_aram);
      }

      public static void TCurveSetFactord(IntPtr p,int t_ype,double f_param) {
         vis_TCurveSetFactord(p, t_ype, f_param);
      }

      public static void TCurveGetFactor(IntPtr p,int t_ype,ref float f_param) {
         vis_TCurveGetFactor(p, t_ype,ref f_param);
      }

      public static void TCurveGetFactord(IntPtr p,int t_ype,ref double f_param) {
         vis_TCurveGetFactord(p, t_ype,ref f_param);
      }

      public static void TCurveSetParamd(IntPtr p,int t_ype,double d_param) {
         vis_TCurveSetParamd(p, t_ype, d_param);
      }

      public static void TCurveSetParami(IntPtr p,int p_type,int i_param) {
         vis_TCurveSetParami(p, p_type, i_param);
      }

      public static void TCurveGetParami(IntPtr p,int t_ype,ref int i_param) {
         vis_TCurveGetParami(p, t_ype,ref i_param);
      }

      public static void TCurveSetPWLinear(IntPtr p,int n_pts,float [] t_,float [] f_) {
         vis_TCurveSetPWLinear(p, n_pts, t_, f_);
      }

      public static void TCurveSetPWLineardv(IntPtr p,int n_pts,double [] t_,double [] f_) {
         vis_TCurveSetPWLineardv(p, n_pts, t_, f_);
      }

      public static void TCurveSetCompPWLinear(IntPtr p,int n_pts,int i_val,float [] f_) {
         vis_TCurveSetCompPWLinear(p, n_pts, i_val, f_);
      }

      public static void TCurveNum(IntPtr p,ref int n_pts) {
         vis_TCurveNum(p,ref n_pts);
      }

      public static void TCurveIndep(IntPtr p,int n_pts,int [] p_ts,float [] t_) {
         vis_TCurveIndep(p, n_pts, p_ts, t_);
      }

      public static void TCurveIndepdv(IntPtr p,int n_pts,int [] p_ts,double [] t_) {
         vis_TCurveIndepdv(p, n_pts, p_ts, t_);
      }

      public static void TCurveDep(IntPtr p,int n_pts,int [] p_ts,float [] f_) {
         vis_TCurveDep(p, n_pts, p_ts, f_);
      }

      public static void TCurveDepdv(IntPtr p,int n_pts,int [] p_ts,double [] f_) {
         vis_TCurveDepdv(p, n_pts, p_ts, f_);
      }

      public static void TCurveSetDep(IntPtr p,int n_pts,int [] p_ts,float [] f_) {
         vis_TCurveSetDep(p, n_pts, p_ts, f_);
      }

      public static void TCurveSetDepdv(IntPtr p,int n_pts,int [] p_ts,double [] f_) {
         vis_TCurveSetDepdv(p, n_pts, p_ts, f_);
      }

      public static void TCurveEval(IntPtr p,int n_pts,float [] t_,float [] f_) {
         vis_TCurveEval(p, n_pts, t_, f_);
      }

      public static void TCurveEvaldv(IntPtr p,int n_pts,double [] t_,double [] f_) {
         vis_TCurveEvaldv(p, n_pts, t_, f_);
      }

      public static void TCurveMerge(IntPtr p,int n_um,IntPtr t_curvex) {
         vis_TCurveMerge(p, n_um, t_curvex);
      }

      public static void TCurveIndepMatch(IntPtr p,int n_pts,float [] t_,ref int f_lag) {
         vis_TCurveIndepMatch(p, n_pts, t_,ref f_lag);
      }

      public static void TCurvePrint(IntPtr p) {
         vis_TCurvePrint(p);
      }

      public static int TCurveIsEqualTo(IntPtr p,IntPtr q_) {
         return vis_TCurveIsEqualTo(p, q_);
      }

      public const int TCURVE_PWLINEAR = 0;
      public const int TCURVE_EQUATION = 1;
      public const int TCURVE_EXPRESSION = 2;
      public const int TCURVE_SCALE = 1;
      public const int TCURVE_SHIFT = 2;
      public const int TCURVE_DIVISOR = 3;
      public const int TCURVE_OFFSET = 4;
      public const int TCURVE_TOLERANCE = 1;
      public const int TCURVE_EXTRAPOLATE = 2;
      public const int TCURVE_HINT = 3;
      public const int TCURVE_TABLEM1 = 1;
      public const int TCURVE_TABLEM2 = 2;
      public const int TCURVE_TABLEM3 = 3;
      public const int TCURVE_TABLES1 = 4;
      public const int TCURVE_TABLED2 = 6;
      public const int TCURVE_TABLED3 = 7;

      public const int TRIMESH_NUMNONMAN = 1;
      public const int TRIMESH_NONMAN = 2;
      public const int TRIMESH_NUMINCONS = 3;
      public const int TRIMESH_INCONS = 4;
      public const int TRIMESH_NUMNEGJAC = 5;
      public const int TRIMESH_NUMFREEEND = 6;
      public const int TRIMESH_FREEEND = 7;
      public const int TRIMESH_NUMNONQUAL = 8;
      public const int TRIMESH_NUMUNCONN = 9;
      public const int TRIMESH_UNCONN = 10;
      public const int TRIMESH_NUMEXNODE = 11;
      public const int TRIMESH_EXNODE = 12;
      public const int TRIMESH_NUMINTERSECT = 13;
      public const int TRIMESH_INTERSECT = 14;
      public const int TRIMESH_NUMREPEATEDNODE = 15;
      public const int TRIMESH_REPEATEDNODE = 16;
      public const int TRIMESH_NUMDUPLICATELINE = 17;
      public const int TRIMESH_DUPLICATELINE = 18;
      public const int TRIMESH_UNCONNECT = -2;
      public const int TRIMESH_LINEFLAG = -3;
      public const int TRIMESH_UNCONNECT_ERROR = 0;
      public const int TRIMESH_UNCONNECT_INCLUDE = 1;
      public const int TRIMESH_UNCONNECT_IGNORE = 2;
      public const int TRIMESH_ADVFRONT = -5;
      public const int TRIMESH_SMOOTH = -6;
      public const int TRIMESH_BOUNDCUT = -7;
      public const int TRIMESH_CUTFLAG = -8;
      public const int TRIMESH_CUTANGLE = -9;
      public const int TRIMESH_CUTMINEDGELENGTH = -10;
      public const int TRIMESH_NONOBTUSEMETHOD = -11;
      public const int TRIMESH_FUN_DEBUG = 1;
      public const int TRIMESH_FUN_MONITOR = 2;
      public const int TRIMESH_FUN_SIZING = 3;
      public const int TRIMESH_FUN_ASIZING = 4;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_TriangleGenerationBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_TriangleGenerationError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationDef(IntPtr p,int n_umnode,int n_umline,int m_axi);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationInq(IntPtr p,ref int n_umnode,ref int n_umline,ref int m_axi);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetDebugFunction(IntPtr p,VTriMeshDebugFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetMonitorFunction(IntPtr p,VTriMeshMonitorFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetSizingFunction(IntPtr p,VTriMeshSizingFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetASizingFunction(IntPtr p,VTriMeshASizingFunc f_unction,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetNode(IntPtr p,int i_d,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetNodeAssoc(IntPtr p,int t_ype,int i_d,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetNodeSizing(IntPtr p,int i_d,double h_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLine(IntPtr p,int i_d,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLineStat(IntPtr p,int i_d,int s_tat);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLineSizing(IntPtr p,int i_d,int e_nttype,double h_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLineDepthSizing(IntPtr p,int i_d,double d_,double h_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLineNorm(IntPtr p,int i_d,double [] v_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetLineAssoc(IntPtr p,int t_ype,int i_d,int e_nttype,int a_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetElem(IntPtr p,int i_d,int s_hape,int m_axi,int [] i_x);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetParami(IntPtr p,int p_type,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationGetParami(IntPtr p,int t_ype,ref int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetParamd(IntPtr p,int p_type,double d_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationGetParamd(IntPtr p,int t_ype,ref double p_aram);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationAbort(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationSetGeomSizing(IntPtr p,int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,double h_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationGetConnect(IntPtr p,out IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationWrite(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationRead(IntPtr p,int t_ype,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationGetInteger(IntPtr p,int t_ype,int [] i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationComputeArea(IntPtr p,ref double a_rea);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationGenerate(IntPtr p,IntPtr c_onnect);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_TriangleGenerationRefine(IntPtr p,IntPtr s_tate,IntPtr c_onnect);

      public static IntPtr TriangleGenerationBegin() {
         return vis_TriangleGenerationBegin();
      }

      public static void TriangleGenerationEnd(IntPtr p) {
         vis_TriangleGenerationEnd(p);
      }

      public static int TriangleGenerationError(IntPtr p) {
         return vis_TriangleGenerationError(p);
      }

      public static void TriangleGenerationDef(IntPtr p,int n_umnode,int n_umline,int m_axi) {
         vis_TriangleGenerationDef(p, n_umnode, n_umline, m_axi);
      }

      public static void TriangleGenerationInq(IntPtr p,ref int n_umnode,ref int n_umline,ref int m_axi) {
         vis_TriangleGenerationInq(p,ref n_umnode,ref n_umline,ref m_axi);
      }

      public static void TriangleGenerationSetFunction(IntPtr p,int f_untype,Vfunc f_unction,IntPtr o_bject) {
         vis_TriangleGenerationSetFunction(p, f_untype, f_unction, o_bject);
      }

      public static void TriangleGenerationSetDebugFunction(IntPtr p,VTriMeshDebugFunc f_unction,IntPtr o_bject) {
         vis_TriangleGenerationSetDebugFunction(p, f_unction, o_bject);
      }

      public static void TriangleGenerationSetMonitorFunction(IntPtr p,VTriMeshMonitorFunc f_unction,IntPtr o_bject) {
         vis_TriangleGenerationSetMonitorFunction(p, f_unction, o_bject);
      }

      public static void TriangleGenerationSetSizingFunction(IntPtr p,VTriMeshSizingFunc f_unction,IntPtr o_bject) {
         vis_TriangleGenerationSetSizingFunction(p, f_unction, o_bject);
      }

      public static void TriangleGenerationSetASizingFunction(IntPtr p,VTriMeshASizingFunc f_unction,IntPtr o_bject) {
         vis_TriangleGenerationSetASizingFunction(p, f_unction, o_bject);
      }

      public static void TriangleGenerationSetNode(IntPtr p,int i_d,double [] x_) {
         vis_TriangleGenerationSetNode(p, i_d, x_);
      }

      public static void TriangleGenerationSetNodeAssoc(IntPtr p,int t_ype,int i_d,int a_id) {
         vis_TriangleGenerationSetNodeAssoc(p, t_ype, i_d, a_id);
      }

      public static void TriangleGenerationSetNodeSizing(IntPtr p,int i_d,double h_) {
         vis_TriangleGenerationSetNodeSizing(p, i_d, h_);
      }

      public static void TriangleGenerationSetLine(IntPtr p,int i_d,int [] i_x) {
         vis_TriangleGenerationSetLine(p, i_d, i_x);
      }

      public static void TriangleGenerationSetLineStat(IntPtr p,int i_d,int s_tat) {
         vis_TriangleGenerationSetLineStat(p, i_d, s_tat);
      }

      public static void TriangleGenerationSetLineSizing(IntPtr p,int i_d,int e_nttype,double h_) {
         vis_TriangleGenerationSetLineSizing(p, i_d, e_nttype, h_);
      }

      public static void TriangleGenerationSetLineDepthSizing(IntPtr p,int i_d,double d_,double h_) {
         vis_TriangleGenerationSetLineDepthSizing(p, i_d, d_, h_);
      }

      public static void TriangleGenerationSetLineNorm(IntPtr p,int i_d,double [] v_) {
         vis_TriangleGenerationSetLineNorm(p, i_d, v_);
      }

      public static void TriangleGenerationSetLineAssoc(IntPtr p,int t_ype,int i_d,int e_nttype,int a_id) {
         vis_TriangleGenerationSetLineAssoc(p, t_ype, i_d, e_nttype, a_id);
      }

      public static void TriangleGenerationSetElem(IntPtr p,int i_d,int s_hape,int m_axi,int [] i_x) {
         vis_TriangleGenerationSetElem(p, i_d, s_hape, m_axi, i_x);
      }

      public static void TriangleGenerationSetParami(IntPtr p,int p_type,int i_param) {
         vis_TriangleGenerationSetParami(p, p_type, i_param);
      }

      public static void TriangleGenerationGetParami(IntPtr p,int t_ype,ref int i_param) {
         vis_TriangleGenerationGetParami(p, t_ype,ref i_param);
      }

      public static void TriangleGenerationSetParamd(IntPtr p,int p_type,double d_param) {
         vis_TriangleGenerationSetParamd(p, p_type, d_param);
      }

      public static void TriangleGenerationGetParamd(IntPtr p,int t_ype,ref double p_aram) {
         vis_TriangleGenerationGetParamd(p, t_ype,ref p_aram);
      }

      public static void TriangleGenerationAbort(IntPtr p) {
         vis_TriangleGenerationAbort(p);
      }

      public static void TriangleGenerationSetGeomSizing(IntPtr p,int t_ype,double [] x_o,double [] x_a,double [] x_b,double [] d_,double h_) {
         vis_TriangleGenerationSetGeomSizing(p, t_ype, x_o, x_a, x_b, d_, h_);
      }

      public static void TriangleGenerationGetConnect(IntPtr p,out IntPtr c_onnect) {
         vis_TriangleGenerationGetConnect(p,out c_onnect);
      }

      public static void TriangleGenerationWrite(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_TriangleGenerationWrite(p, t_ype, p_ath);
      }

      public static void TriangleGenerationRead(IntPtr p,int t_ype,StringBuilder p_ath) {
         vis_TriangleGenerationRead(p, t_ype, p_ath);
      }

      public static void TriangleGenerationGetInteger(IntPtr p,int t_ype,int [] i_param) {
         vis_TriangleGenerationGetInteger(p, t_ype, i_param);
      }

      public static void TriangleGenerationComputeArea(IntPtr p,ref double a_rea) {
         vis_TriangleGenerationComputeArea(p,ref a_rea);
      }

      public static void TriangleGenerationGenerate(IntPtr p,IntPtr c_onnect) {
         vis_TriangleGenerationGenerate(p, c_onnect);
      }

      public static void TriangleGenerationRefine(IntPtr p,IntPtr s_tate,IntPtr c_onnect) {
         vis_TriangleGenerationRefine(p, s_tate, c_onnect);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_UnitsBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_UnitsError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsSetBase(IntPtr p,int t_ype,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetBase(IntPtr p,int t_ype,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsSetConv(IntPtr p,int t_ype,int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetConv(IntPtr p,int t_ype,ref int v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetDesc(IntPtr p,int t_ype,int v_alue,StringBuilder s_tg);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsSetFactor(IntPtr p,int t_ype,double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetFactor(IntPtr p,int t_ype,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetBaseSIFactor(IntPtr p,int t_ype,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsGetSIFactor(IntPtr p,int t_ype,int u_nit,ref double v_alue);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsComputeFactors(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsCopy(IntPtr p,IntPtr f_romp);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_UnitsPrint(IntPtr p);

      public static IntPtr UnitsBegin() {
         return vis_UnitsBegin();
      }

      public static void UnitsEnd(IntPtr p) {
         vis_UnitsEnd(p);
      }

      public static int UnitsError(IntPtr p) {
         return vis_UnitsError(p);
      }

      public static void UnitsSetBase(IntPtr p,int t_ype,int v_alue) {
         vis_UnitsSetBase(p, t_ype, v_alue);
      }

      public static void UnitsGetBase(IntPtr p,int t_ype,ref int v_alue) {
         vis_UnitsGetBase(p, t_ype,ref v_alue);
      }

      public static void UnitsSetConv(IntPtr p,int t_ype,int v_alue) {
         vis_UnitsSetConv(p, t_ype, v_alue);
      }

      public static void UnitsGetConv(IntPtr p,int t_ype,ref int v_alue) {
         vis_UnitsGetConv(p, t_ype,ref v_alue);
      }

      public static void UnitsGetDesc(IntPtr p,int t_ype,int v_alue,StringBuilder s_tg) {
         vis_UnitsGetDesc(p, t_ype, v_alue, s_tg);
      }

      public static void UnitsSetFactor(IntPtr p,int t_ype,double v_alue) {
         vis_UnitsSetFactor(p, t_ype, v_alue);
      }

      public static void UnitsGetFactor(IntPtr p,int t_ype,ref double v_alue) {
         vis_UnitsGetFactor(p, t_ype,ref v_alue);
      }

      public static void UnitsGetBaseSIFactor(IntPtr p,int t_ype,ref double v_alue) {
         vis_UnitsGetBaseSIFactor(p, t_ype,ref v_alue);
      }

      public static void UnitsGetSIFactor(IntPtr p,int t_ype,int u_nit,ref double v_alue) {
         vis_UnitsGetSIFactor(p, t_ype, u_nit,ref v_alue);
      }

      public static void UnitsComputeFactors(IntPtr p) {
         vis_UnitsComputeFactors(p);
      }

      public static void UnitsCopy(IntPtr p,IntPtr f_romp) {
         vis_UnitsCopy(p, f_romp);
      }

      public static void UnitsPrint(IntPtr p) {
         vis_UnitsPrint(p);
      }

      public const int UNITS_LENGTH = 1;
      public const int UNITS_MASS = 2;
      public const int UNITS_TIME = 3;
      public const int UNITS_TEMP = 4;
      public const int UNITS_TEMP_OFFSET = 5;
      public const int UNITS_ANGLE = 6;
      public const int UNITS_CHARGE = 7;
      public const int UNITS_LENGTH_METER = 1;
      public const int UNITS_LENGTH_CENTIMETER = 2;
      public const int UNITS_LENGTH_MILLIMETER = 3;
      public const int UNITS_LENGTH_MICRON = 4;
      public const int UNITS_LENGTH_NANOMETER = 5;
      public const int UNITS_LENGTH_ANGSTROM = 6;
      public const int UNITS_LENGTH_KILOMETER = 7;
      public const int UNITS_LENGTH_INCH = 8;
      public const int UNITS_LENGTH_FOOT = 9;
      public const int UNITS_LENGTH_MILE = 10;
      public const int UNITS_LENGTH_USER = 11;
      public const int UNITS_MASS_KILOGRAM = 101;
      public const int UNITS_MASS_GRAM = 102;
      public const int UNITS_MASS_POUND = 103;
      public const int UNITS_MASS_SLUG = 104;
      public const int UNITS_MASS_METRICTON = 105;
      public const int UNITS_MASS_BLOB = 106;
      public const int UNITS_MASS_KILOGRAMFM = 107;
      public const int UNITS_MASS_KILOGRAMFMM = 108;
      public const int UNITS_MASS_USER = 109;
      public const int UNITS_MASS_NEWTONHOURSQUAREPERMM = 110;
      public const int UNITS_MASS_MILLIGRAM = 111;
      public const int UNITS_TIME_SECOND = 201;
      public const int UNITS_TIME_MINUTE = 202;
      public const int UNITS_TIME_HOUR = 203;
      public const int UNITS_TIME_USER = 204;
      public const int UNITS_TIME_MICROSECOND = 205;
      public const int UNITS_TIME_MILLISECOND = 206;
      public const int UNITS_TEMP_KELVIN = 301;
      public const int UNITS_TEMP_CELSIUS = 302;
      public const int UNITS_TEMP_RANKINE = 303;
      public const int UNITS_TEMP_FAHRENHEIT = 304;
      public const int UNITS_TEMP_USER = 305;
      public const int UNITS_ANGLE_RADIAN = 401;
      public const int UNITS_ANGLE_DEGREE = 402;
      public const int UNITS_ANGLE_CYCLE = 403;
      public const int UNITS_ANGLE_USER = 404;
      public const int UNITS_CHARGE_COULOMB = 501;
      public const int UNITS_CHARGE_USER = 502;
      public const int UNITS_DESCRIPTION_MAXCHAR = 12;

      public const int VIS_MAXISOCLIP = 6;
      public const int VIS_MAXPRIMLENGTH = 864;
      public const int VIS_MAXDATAROWS = 16;
      public const int VIS_MAXELEMIJK = 13;
      public const int VIS_MAXEDGENODE = 13;
      public const int VIS_MAXFACENODE = 1024;
      public const int VIS_MAXCELLNODE = 2197;
      public const int VIS_MAXELEMNODE = 4095;
      public const int VIS_MAXIJK = 4096;
      public const int VIS_MAX_MAXI = 32767;
      public const int VIS_MAX_MAXJ = 32767;
      public const int VIS_MAX_MAXK = 32767;
      public const int VIS_MAXNODEELEM = 1000;
      public const int VIS_MAXSECTION = 4096;
      public const int VIS_OFF = 0;
      public const int VIS_ON = 1;
      public const int VIS_ERROR_NONE = 0;
      public const int VIS_ERROR_VALUE = 1;
      public const int VIS_ERROR_ENUM = 2;
      public const int VIS_ERROR_OBJECTTYPE = 3;
      public const int VIS_ERROR_MEMORY = 4;
      public const int VIS_ERROR_NULLOBJECT = 5;
      public const int VIS_ERROR_FILE = 6;
      public const int VIS_ERROR_COMPUTE = 7;
      public const int VIS_ERROR_OPERATION = 8;
      public const int VIS_SHAPEUNDEFINED = -1;
      public const int VIS_SHAPEPOINT = 0;
      public const int VIS_SHAPELINE = 1;
      public const int VIS_SHAPETRI = 2;
      public const int VIS_SHAPEQUAD = 3;
      public const int VIS_SHAPETET = 4;
      public const int VIS_SHAPEPYR = 5;
      public const int VIS_SHAPEWED = 6;
      public const int VIS_SHAPEHEX = 7;
      public const int VIS_SHAPEPOLYGON = 8;
      public const int VIS_SHAPEPOLYHED = 9;
      public const int VIS_SPCFLAGS = 7;
      public const int VIS_CREFID = 9;
      public const int VIS_FEATYPE = 0;
      public const int VIS_MATLID = 1;
      public const int VIS_PROPID = 2;
      public const int VIS_PARTID = 3;
      public const int VIS_CSYSID = 4;
      public const int VIS_IBLANK = 6;
      public const int VIS_EXTTYPE = 8;
      public const int VIS_USERID = 10;
      public const int VIS_FEATECH = 11;
      public const int VIS_FEASPEC = 12;
      public const int VIS_CMATID = 13;
      public const int VIS_CMATFLAG = 14;
      public const int VIS_MISCID0 = 15;
      public const int VIS_MISCID1 = 16;
      public const int VIS_MISCID2 = 17;
      public const int VIS_MISCID3 = 18;
      public const int VIS_MISCID4 = 19;
      public const int VIS_MISCID5 = 20;
      public const int VIS_MISCID6 = 21;
      public const int VIS_MISCID7 = 22;
      public const int VIS_MISCID8 = 23;
      public const int VIS_FEATWOD = 25;
      public const int VIS_ENDATOPO = 26;
      public const int VIS_ENDBTOPO = 27;
      public const int VIS_ENDACON = 28;
      public const int VIS_ENDBCON = 29;
      public const int VIS_ORIENTINDEX = 30;
      public const int VIS_GEOVERT = 33;
      public const int VIS_GEOEDGE = 34;
      public const int VIS_GEOFACE = 35;
      public const int VIS_GEOBODY = 36;
      public const int VIS_PINFLAGS = 41;
      public const int VIS_DOMAIN = 42;
      public const int VIS_SEID = 43;
      public const int VIS_SYMMID = 44;
      public const int VIS_POLYUNIQUEFACE = 46;
      public const int VIS_NODE_FEATYPE = 0;
      public const int VIS_NODE_PARTID = 3;
      public const int VIS_NODE_CSYSID = 4;
      public const int VIS_NODE_IBLANK = 6;
      public const int VIS_NODE_SPCFLAGS = 7;
      public const int VIS_NODE_CREFID = 9;
      public const int VIS_NODE_USERID = 10;
      public const int VIS_NODE_MISCID0 = 15;
      public const int VIS_NODE_MISCID1 = 16;
      public const int VIS_NODE_MISCID2 = 17;
      public const int VIS_NODE_MISCID3 = 18;
      public const int VIS_NODE_MISCID4 = 19;
      public const int VIS_NODE_MISCID5 = 20;
      public const int VIS_NODE_MISCID6 = 21;
      public const int VIS_NODE_MISCID7 = 22;
      public const int VIS_NODE_MISCID8 = 23;
      public const int VIS_MAXNODEASSOC = 24;
      public const int VIS_COLORID = 5;
      public const int VIS_MISCID = 15;
      public const int VIS_EXTNAMEA = 31;
      public const int VIS_EXTNAMEB = 32;
      public const int VIS_INTERN = 37;
      public const int VIS_INTERN0 = 37;
      public const int VIS_INTERN1 = 38;
      public const int VIS_INTERN2 = 39;
      public const int VIS_INTERN3 = 40;
      public const int VIS_FEATECHMODIFIED = 45;
      public const int VIS_QUALFLAG = 24;
      public const int VIS_MAXASSOC = 47;
      public const int VIS_MAXASSOC_PER_ENTITY = 10000;
      public const int VIS_NODE_UNDEFINED = 0;
      public const int VIS_NODE_GRID = 1;
      public const int VIS_NODE_SCALAR = 2;
      public const int VIS_ELEM_UNDEFINED = 0;
      public const int VIS_ELEM_SOLID = 1;
      public const int VIS_ELEM_SHELL = 2;
      public const int VIS_ELEM_MEMBRANE = 3;
      public const int VIS_ELEM_BEAM = 4;
      public const int VIS_ELEM_TRUSS = 5;
      public const int VIS_ELEM_INFINITE = 6;
      public const int VIS_ELEM_GAP = 7;
      public const int VIS_ELEM_JOINT = 8;
      public const int VIS_ELEM_SPRINGDASHPOT = 9;
      public const int VIS_ELEM_RIGID = 10;
      public const int VIS_ELEM_CONSTRAINT = 11;
      public const int VIS_ELEM_PLOT = 12;
      public const int VIS_ELEM_MASS = 13;
      public const int VIS_ELEM_INTER = 14;
      public const int VIS_ELEM_SUPER = 15;
      public const int VIS_ELEM_REINFORCEMENT = 16;
      public const int VIS_ELEM_MAX = 17;
      public const int VIS_SCALAR = 0;
      public const int VIS_VECTOR = 1;
      public const int VIS_TENSOR = 2;
      public const int VIS_GENERALTENSOR = 3;
      public const int VIS_ELEMRES = 5;
      public const int VIS_SIXDOF = 9;
      public const int VIS_SCALARS = 10;
      public const int VIS_SCALARS1 = 11;
      public const int VIS_SCALARS2 = 12;
      public const int VIS_SCALARS3 = 13;
      public const int VIS_SCALARS4 = 14;
      public const int VIS_SCALARS5 = 15;
      public const int VIS_SCALARS6 = 16;
      public const int VIS_SCALARS7 = 17;
      public const int VIS_SCALARS8 = 18;
      public const int VIS_SCALARS9 = 19;
      public const int VIS_SCALARS10 = 20;
      public const int VIS_SCALARS11 = 21;
      public const int VIS_SCALARS12 = 22;
      public const int VIS_SCALARS13 = 23;
      public const int VIS_SCALARS14 = 24;
      public const int VIS_SCALARS15 = 25;
      public const int VIS_SCALARS16 = 26;
      public const int VIS_SCALARS17 = 27;
      public const int VIS_SCALARS18 = 28;
      public const int VIS_SCALARS19 = 29;
      public const int VIS_SCALARS20 = 30;
      public const int VIS_SCALARS21 = 31;
      public const int VIS_SCALARS22 = 32;
      public const int VIS_SCALARS23 = 33;
      public const int VIS_SCALARS24 = 34;
      public const int VIS_SCALARS25 = 35;
      public const int VIS_SCALARS26 = 36;
      public const int VIS_SCALARS27 = 37;
      public const int VIS_SCALARS28 = 38;
      public const int VIS_SCALARS29 = 39;
      public const int VIS_SCALARS30 = 40;
      public const int VIS_SCALARS31 = 41;
      public const int VIS_SCALARS32 = 42;
      public const int VIS_SCALARS33 = 43;
      public const int VIS_SCALARS34 = 44;
      public const int VIS_SCALARS35 = 45;
      public const int VIS_SCALARS36 = 46;
      public const int VIS_SCALARS37 = 47;
      public const int VIS_SCALARS38 = 48;
      public const int VIS_SCALARS39 = 49;
      public const int VIS_SCALARS40 = 50;
      public const int VIS_SCALARS41 = 51;
      public const int VIS_SCALARS42 = 52;
      public const int VIS_SCALARS43 = 53;
      public const int VIS_SCALARS44 = 54;
      public const int VIS_SCALARS45 = 55;
      public const int VIS_SCALARS46 = 56;
      public const int VIS_SCALARS47 = 57;
      public const int VIS_SCALARS48 = 58;
      public const int VIS_SCALARS49 = 59;
      public const int VIS_SCALARS50 = 60;
      public const int VIS_SCALARS51 = 61;
      public const int VIS_SCALARS52 = 62;
      public const int VIS_SCALARS53 = 63;
      public const int VIS_SCALARS54 = 64;
      public const int VIS_SCALARS55 = 65;
      public const int VIS_SCALARS56 = 66;
      public const int VIS_SCALARS57 = 67;
      public const int VIS_SCALARS58 = 68;
      public const int VIS_SCALARS59 = 69;
      public const int VIS_SCALARS60 = 70;
      public const int VIS_SCALARS61 = 71;
      public const int VIS_SCALARS62 = 72;
      public const int VIS_SCALARS63 = 73;
      public const int VIS_SCALARS64 = 74;
      public const int VIS_SCALARS65 = 75;
      public const int VIS_SCALARS66 = 76;
      public const int VIS_SCALARS67 = 77;
      public const int VIS_SCALARS68 = 78;
      public const int VIS_SCALARS69 = 79;
      public const int VIS_SCALARS70 = 80;
      public const int VIS_SCALARS71 = 81;
      public const int VIS_SCALARS72 = 82;
      public const int VIS_SCALARS73 = 83;
      public const int VIS_SCALARS74 = 84;
      public const int VIS_SCALARS75 = 85;
      public const int VIS_SCALARS76 = 86;
      public const int VIS_SCALARS77 = 87;
      public const int VIS_SCALARS78 = 88;
      public const int VIS_SCALARS79 = 89;
      public const int VIS_SCALARS80 = 90;
      public const int VIS_SCALARS81 = 91;
      public const int VIS_SCALARS82 = 92;
      public const int VIS_SCALARS83 = 93;
      public const int VIS_SCALARS84 = 94;
      public const int VIS_SCALARS85 = 95;
      public const int VIS_SCALARS86 = 96;
      public const int VIS_SCALARS87 = 97;
      public const int VIS_SCALARS88 = 98;
      public const int VIS_SCALARS89 = 99;
      public const int VIS_SCALARS90 = 100;
      public const int VIS_SCALARS91 = 101;
      public const int VIS_SCALARS92 = 102;
      public const int VIS_SCALARS93 = 103;
      public const int VIS_SCALARS94 = 104;
      public const int VIS_SCALARS95 = 105;
      public const int VIS_SCALARS96 = 106;
      public const int VIS_SCALARS97 = 107;
      public const int VIS_SCALARS98 = 108;
      public const int VIS_SCALARS99 = 109;
      public const int VIS_SCALARS100 = 110;
      public const int VIS_SCALARS101 = 111;
      public const int VIS_SCALARS102 = 112;
      public const int VIS_SCALARS103 = 113;
      public const int VIS_SCALARS104 = 114;
      public const int VIS_SCALARS105 = 115;
      public const int VIS_SCALARS106 = 116;
      public const int VIS_SCALARS107 = 117;
      public const int VIS_SCALARS108 = 118;
      public const int VIS_SCALARS109 = 119;
      public const int VIS_SCALARS110 = 120;
      public const int VIS_SCALARS111 = 121;
      public const int VIS_SCALARS112 = 122;
      public const int VIS_SCALARS113 = 123;
      public const int VIS_SCALARS114 = 124;
      public const int VIS_SCALARS115 = 125;
      public const int VIS_SCALARS116 = 126;
      public const int VIS_SCALARS117 = 127;
      public const int VIS_SCALARS118 = 128;
      public const int VIS_SCALARS119 = 129;
      public const int VIS_SCALARS120 = 130;
      public const int VIS_SCALARS121 = 131;
      public const int VIS_SCALARS122 = 132;
      public const int VIS_SCALARS123 = 133;
      public const int VIS_SCALARS124 = 134;
      public const int VIS_SCALARS125 = 135;
      public const int VIS_SCALARS126 = 136;
      public const int VIS_SCALARS127 = 137;
      public const int VIS_SCALARS128 = 138;
      public const int VIS_SCALARS129 = 139;
      public const int VIS_SCALARS130 = 140;
      public const int VIS_SCALARS131 = 141;
      public const int VIS_SCALARS132 = 142;
      public const int VIS_SCALARS133 = 143;
      public const int VIS_SCALARS134 = 144;
      public const int VIS_SCALARS135 = 145;
      public const int VIS_SCALARS136 = 146;
      public const int VIS_SCALARS137 = 147;
      public const int VIS_SCALARS138 = 148;
      public const int VIS_SCALARS139 = 149;
      public const int VIS_SCALARS140 = 150;
      public const int VIS_SCALARS141 = 151;
      public const int VIS_SCALARS142 = 152;
      public const int VIS_SCALARS143 = 153;
      public const int VIS_SCALARS144 = 154;
      public const int VIS_SCALARS145 = 155;
      public const int VIS_SCALARS146 = 156;
      public const int VIS_SCALARS147 = 157;
      public const int VIS_SCALARS148 = 158;
      public const int VIS_SCALARS149 = 159;
      public const int VIS_SCALARS150 = 160;
      public const int VIS_SCALARS151 = 161;
      public const int VIS_SCALARS152 = 162;
      public const int VIS_SCALARS153 = 163;
      public const int VIS_SCALARS154 = 164;
      public const int VIS_SCALARS155 = 165;
      public const int VIS_SCALARS156 = 166;
      public const int VIS_SCALARS157 = 167;
      public const int VIS_SCALARS158 = 168;
      public const int VIS_SCALARS159 = 169;
      public const int VIS_SCALARS160 = 170;
      public const int VIS_SCALARS161 = 171;
      public const int VIS_SCALARS162 = 172;
      public const int VIS_SCALARS163 = 173;
      public const int VIS_SCALARS164 = 174;
      public const int VIS_SCALARS165 = 175;
      public const int VIS_SCALARS166 = 176;
      public const int VIS_SCALARS167 = 177;
      public const int VIS_SCALARS168 = 178;
      public const int VIS_SCALARS169 = 179;
      public const int VIS_SCALARS170 = 180;
      public const int VIS_SCALARS171 = 181;
      public const int VIS_SCALARS172 = 182;
      public const int VIS_SCALARS173 = 183;
      public const int VIS_SCALARS174 = 184;
      public const int VIS_SCALARS175 = 185;
      public const int VIS_SCALARS176 = 186;
      public const int VIS_SCALARS177 = 187;
      public const int VIS_SCALARS178 = 188;
      public const int VIS_SCALARS179 = 189;
      public const int VIS_SCALARS180 = 190;
      public const int VIS_SCALARS181 = 191;
      public const int VIS_SCALARS182 = 192;
      public const int VIS_SCALARS183 = 193;
      public const int VIS_SCALARS184 = 194;
      public const int VIS_SCALARS185 = 195;
      public const int VIS_SCALARS186 = 196;
      public const int VIS_SCALARS187 = 197;
      public const int VIS_SCALARS188 = 198;
      public const int VIS_SCALARS189 = 199;
      public const int VIS_SCALARS190 = 200;
      public const int VIS_SCALARS191 = 201;
      public const int VIS_SCALARS192 = 202;
      public const int VIS_SCALARS193 = 203;
      public const int VIS_SCALARS194 = 204;
      public const int VIS_SCALARS195 = 205;
      public const int VIS_SCALARS196 = 206;
      public const int VIS_SCALARS197 = 207;
      public const int VIS_SCALARS198 = 208;
      public const int VIS_SCALARS199 = 209;
      public const int VIS_SCALARS200 = 210;
      public const int VIS_SCALARS201 = 211;
      public const int VIS_SCALARS202 = 212;
      public const int VIS_SCALARS203 = 213;
      public const int VIS_SCALARS204 = 214;
      public const int VIS_SCALARS205 = 215;
      public const int VIS_SCALARS206 = 216;
      public const int VIS_SCALARS207 = 217;
      public const int VIS_SCALARS208 = 218;
      public const int VIS_SCALARS209 = 219;
      public const int VIS_SCALARS210 = 220;
      public const int VIS_SCALARS211 = 221;
      public const int VIS_SCALARS212 = 222;
      public const int VIS_SCALARS213 = 223;
      public const int VIS_SCALARS214 = 224;
      public const int VIS_SCALARS215 = 225;
      public const int VIS_SCALARS216 = 226;
      public const int VIS_SCALARS217 = 227;
      public const int VIS_SCALARS218 = 228;
      public const int VIS_SCALARS219 = 229;
      public const int VIS_SCALARS220 = 230;
      public const int VIS_SCALARS221 = 231;
      public const int VIS_SCALARS222 = 232;
      public const int VIS_SCALARS223 = 233;
      public const int VIS_SCALARS224 = 234;
      public const int VIS_SCALARS225 = 235;
      public const int VIS_SCALARS226 = 236;
      public const int VIS_SCALARS227 = 237;
      public const int VIS_SCALARS228 = 238;
      public const int VIS_SCALARS229 = 239;
      public const int VIS_SCALARS230 = 240;
      public const int VIS_SCALARS231 = 241;
      public const int VIS_SCALARS232 = 242;
      public const int VIS_SCALARS233 = 243;
      public const int VIS_SCALARS234 = 244;
      public const int VIS_SCALARS235 = 245;
      public const int VIS_SCALARS236 = 246;
      public const int VIS_SCALARS237 = 247;
      public const int VIS_SCALARS238 = 248;
      public const int VIS_SCALARS239 = 249;
      public const int VIS_SCALARS240 = 250;
      public const int VIS_SCALARS241 = 251;
      public const int VIS_SCALARS242 = 252;
      public const int VIS_SCALARS243 = 253;
      public const int VIS_SCALARS244 = 254;
      public const int VIS_SCALARS245 = 255;
      public const int VIS_SCALARS246 = 256;
      public const int VIS_SCALARS247 = 257;
      public const int VIS_SCALARS248 = 258;
      public const int VIS_SCALARS249 = 259;
      public const int VIS_SCALARS250 = 260;
      public const int VIS_SCALARS251 = 261;
      public const int VIS_SCALARS252 = 262;
      public const int VIS_SCALARS253 = 263;
      public const int VIS_SCALARS254 = 264;
      public const int VIS_SCALARS255 = 265;
      public const int VIS_SCALARS256 = 266;
      public const int VIS_MAXDATATYPEROWS = 256;
      public const int VIS_VECTOR_X = 326;
      public const int VIS_VECTOR_Y = 327;
      public const int VIS_VECTOR_Z = 328;
      public const int VIS_VECTOR_MAG = 329;
      public const int VIS_VECTOR_VECTOR = 1;
      public const int VIS_TENSOR_XX = 331;
      public const int VIS_TENSOR_YY = 332;
      public const int VIS_TENSOR_ZZ = 333;
      public const int VIS_TENSOR_XY = 334;
      public const int VIS_TENSOR_YZ = 335;
      public const int VIS_TENSOR_ZX = 336;
      public const int VIS_TENSOR_MEAN = 337;
      public const int VIS_TENSOR_VONMISES = 338;
      public const int VIS_TENSOR_OCTAHEDRAL = 339;
      public const int VIS_TENSOR_DETERMINANT = 340;
      public const int VIS_TENSOR_MAXSHEAR = 341;
      public const int VIS_TENSOR_ANGSHEAR = 342;
      public const int VIS_TENSOR_MINPRINC = 343;
      public const int VIS_TENSOR_MIDPRINC = 344;
      public const int VIS_TENSOR_MAXPRINC = 345;
      public const int VIS_TENSOR_MINPRINCDEV = 346;
      public const int VIS_TENSOR_MIDPRINCDEV = 347;
      public const int VIS_TENSOR_MAXPRINCDEV = 348;
      public const int VIS_TENSOR_INTENSITY = 349;
      public const int VIS_TENSOR_EQUDIRECT = 350;
      public const int VIS_TENSOR_VONMISES_E = 351;
      public const int VIS_TENSOR_PRINC = 352;
      public const int VIS_TENSOR_PRINCDIRCOS = 353;
      public const int VIS_TENSOR_TENSOR = 2;
      public const int VIS_GENERALTENSOR_GENERALTENSOR = 3;
      public const int VIS_GENERALTENSOR_XX = 361;
      public const int VIS_GENERALTENSOR_XY = 362;
      public const int VIS_GENERALTENSOR_XZ = 363;
      public const int VIS_GENERALTENSOR_YX = 364;
      public const int VIS_GENERALTENSOR_YY = 365;
      public const int VIS_GENERALTENSOR_YZ = 366;
      public const int VIS_GENERALTENSOR_ZX = 367;
      public const int VIS_GENERALTENSOR_ZY = 368;
      public const int VIS_GENERALTENSOR_ZZ = 369;
      public const int VIS_GENERALTENSOR_SYM = 370;
      public const int VIS_GENERALTENSOR_XVEC = 371;
      public const int VIS_GENERALTENSOR_YVEC = 372;
      public const int VIS_GENERALTENSOR_ZVEC = 373;
      public const int VIS_ELEMRES_SHELL_NXX = 381;
      public const int VIS_ELEMRES_SHELL_NYY = 382;
      public const int VIS_ELEMRES_SHELL_NXY = 383;
      public const int VIS_ELEMRES_SHELL_MXX = 384;
      public const int VIS_ELEMRES_SHELL_MYY = 385;
      public const int VIS_ELEMRES_SHELL_MXY = 386;
      public const int VIS_ELEMRES_SHELL_QXZ = 387;
      public const int VIS_ELEMRES_SHELL_QYZ = 388;
      public const int VIS_ELEMRES_BEAM_NXX = 391;
      public const int VIS_ELEMRES_BEAM_MYY = 392;
      public const int VIS_ELEMRES_BEAM_MZZ = 393;
      public const int VIS_ELEMRES_BEAM_T = 394;
      public const int VIS_ELEMRES_BEAM_QXY = 395;
      public const int VIS_ELEMRES_BEAM_QZX = 396;
      public const int VIS_ELEMRES_BEAM_TB = 397;
      public const int VIS_ELEMRES_SPRINGDASHPOT_F = 400;
      public const int VIS_ELEMRES_SPRINGDASHPOT_FX = 400;
      public const int VIS_ELEMRES_SPRINGDASHPOT_FY = 401;
      public const int VIS_ELEMRES_SPRINGDASHPOT_FZ = 402;
      public const int VIS_ELEMRES_SPRINGDASHPOT_MX = 403;
      public const int VIS_ELEMRES_SPRINGDASHPOT_MY = 404;
      public const int VIS_ELEMRES_SPRINGDASHPOT_MZ = 405;
      public const int VIS_SIXDOF_SIXDOF = 9;
      public const int VIS_SIXDOF_TX = 411;
      public const int VIS_SIXDOF_TY = 412;
      public const int VIS_SIXDOF_TZ = 413;
      public const int VIS_SIXDOF_RX = 414;
      public const int VIS_SIXDOF_RY = 415;
      public const int VIS_SIXDOF_RZ = 416;
      public const int VIS_SIXDOF_TMAG = 417;
      public const int VIS_SIXDOF_RMAG = 418;
      public const int VIS_SIXDOF_TVEC = 419;
      public const int VIS_SIXDOF_RVEC = 420;
      public const int VIS_SCALARS_SCALAR = 0;
      public const int VIS_SCALARS_0 = 421;
      public const int VIS_SCALARS_1 = 422;
      public const int VIS_SCALARS_2 = 423;
      public const int VIS_SCALARS_3 = 424;
      public const int VIS_SCALARS_4 = 425;
      public const int VIS_SCALARS_5 = 426;
      public const int VIS_SCALARS_6 = 427;
      public const int VIS_SCALARS_7 = 428;
      public const int VIS_SCALARS_8 = 429;
      public const int VIS_SCALARS_9 = 430;
      public const int VIS_SCALARS_10 = 431;
      public const int VIS_SCALARS_11 = 432;
      public const int VIS_SCALARS_12 = 433;
      public const int VIS_DERIVE_MAX = 677;
      public const int VIS_ISOCLIP_NONE = 0;
      public const int VIS_ISOCLIP_FULL = 1;
      public const int VIS_ISOCLIP_PART = 2;
      public const int VIS_EFORMAT = 0;
      public const int VIS_FFORMAT = 1;
      public const int VIS_IFORMAT = 2;
      public const int VIS_GFORMAT = 3;
      public const int VIS_XFORMAT = 4;
      public const int VIS_E2FORMAT = 5;
      public const int VIS_E3FORMAT = 6;
      public const int VIS_GXFORMAT = 7;
      public const int VIS_FMFORMAT = 8;
      public const int VIS_LISTING = 1;
      public const int VIS_SUMMARY = 2;
      public const int VIS_VALUEBRACKET = 1024;
      public const int VIS_VALUEBACK = 2048;
      public const int VIS_DOFBACK = 4096;
      public const int VIS_ELEMREP_LINE = 0;
      public const int VIS_ELEMREP_SEMI = 1;
      public const int VIS_ELEMREP_SOLID = 2;
      public const int VIS_ELEMREP_BITMAP = 3;
      public const int VIS_ELEMREP_PIXMAP = 4;
      public const int VIS_ELEMREP_VALUE = 5;
      public const int VIS_ELEMAXES_NONE = 0;
      public const int VIS_ELEMAXES_XYZ = 7;
      public const int VIS_ELEMAXES_X = 1;
      public const int VIS_ELEMAXES_Y = 2;
      public const int VIS_ELEMAXES_Z = 4;
      public const int VIS_TRIANGLE = 0;
      public const int VIS_SQUARE = 1;
      public const int VIS_DIAMOND = 2;
      public const int VIS_HOURGLASS = 3;
      public const int VIS_PLUSSIGN = 4;
      public const int VIS_CIRCLE = 5;
      public const int VIS_DOT = 6;
      public const int VIS_POINT = 7;
      public const int VIS_DASH = 8;
      public const int VIS_SPHERE = 9;
      public const int VIS_BOX = 10;
      public const int VIS_TETRAHEDRON = 11;
      public const int VIS_OCTAHEDRON = 12;
      public const int VIS_POINT2 = 13;
      public const int VIS_POINT4 = 14;
      public const int VIS_CIRCLE3 = 15;
      public const int VIS_CIRCLE5 = 16;
      public const int VIS_CIRCLE7 = 17;
      public const int VIS_CIRCLE9 = 18;
      public const int VIS_METER = 19;
      public const int VIS_MARKERMAX = 19;
      public const int VIS_SOLID = 0;
      public const int VIS_DASHDASH = 1;
      public const int VIS_DOTDOT = 2;
      public const int VIS_DOTDASH = 3;
      public const int VIS_CYLINDER = 4;
      public const int VIS_VECTORDOUBLEHEAD = 2;
      public const int VIS_VECTORNOHEAD = 8;
      public const int VIS_VECTORTAIL = 16;
      public const int VIS_VECTORTAILREGISTER = 32;
      public const int VIS_VECTORPUSHHEAD = 128;
      public const int VIS_VECTORNOCAP = 256;
      public const int VIS_VECTORROUND = 512;
      public const int VIS_VECTORDOUBLEHEADPEN = 32768;
      public const int VIS_VECTORDOUBLEHEADADD = 65536;
      public const int VIS_VECTORLINE = 0;
      public const int VIS_VECTORCYLINDER = 1;
      public const int VIS_VECTORUMBRELLA = 2;
      public const int VIS_TENSORBOX = 1;
      public const int VIS_TENSORDIRECT = 4;
      public const int VIS_TENSORSHEAR = 64;
      public const int VIS_TENSORCUBE = 0;
      public const int VIS_TENSORELLIPSOID = 1;
      public const int VIS_TENSORCROWSFEET = 2;
      public const int VIS_SHRINKNONE = 0;
      public const int VIS_SHRINKENTITY = 1;
      public const int VIS_SHRINKELEMENT = 2;
      public const int VIS_MAPCOLOR_NONE = 0;
      public const int VIS_MAPCOLOR_CONSTANT = 1;
      public const int VIS_MAPCOLOR_SMOOTH = 2;
      public const int VIS_COMPONENT_PRINCIPAL = 0;
      public const int VIS_COMPONENT_BASIC = 1;
      public const int VIS_COMPONENT_MAXSHEAR = 2;
      public const int VIS_BACKPLANEFLIP = 8192;
      public const int VIS_CREATEPOLYHEDRON = 16384;
      public const int VIS_CYLINDERCAP = 131072;
      public const int VIS_ISOVALPOINT = 0;
      public const int VIS_ISOVALLINE = 1;
      public const int VIS_ISOVALSURFACE = 2;
      public const int VIS_ISOVALVOLUME = 3;
      public const int VIS_ISOVALFRINGE = 4;
      public const int VIS_ISOVALTONE = 5;
      public const int VIS_ISOVALGOURAUD = 6;
      public const int VIS_ISOVALTEXTURE = 7;
      public const int VIS_INTERP_SHAPE = 0;
      public const int VIS_INTERP_CLAMP = 1;
      public const int VIS_PRIM_POLY = 0;
      public const int VIS_PRIM_MULT = 1;
      public const int VIS_PRIM_ARRAY = 1;
      public const int VIS_PRIM_STRIP = 2;
      public const int VIS_ISOVALACCENT = 1;
      public const int VIS_TOPOCRITICALPOINT = 0;
      public const int VIS_TOPOVORTEXCORE = 1;
      public const int VIS_TOPODIVIDE = 2;
      public const int VIS_STREAMLINE = 0;
      public const int VIS_STREAMPOINT = 1;
      public const int VIS_STREAMRIBBON = 2;
      public const int VIS_STREAMTUBE = 3;
      public const int VIS_STREAMTWIST = 4;
      public const int VIS_STREAMBOX = 5;
      public const int VIS_STREAMELLIPSE = 6;
      public const int VIS_STREAMZERO = 0;
      public const int VIS_STREAMEXIT = 1;
      public const int VIS_STREAMBRANCH = 2;
      public const int VIS_STREAMMAXSTEPS = 3;
      public const int VIS_STREAMMAXEXCEEDED = 3;
      public const int VIS_STREAMCOMPUTE = 4;
      public const int VIS_TIMEREVERSE = 1048576;
      public const int VIS_NOSHADE = 0;
      public const int VIS_FLATSHADE = 1;
      public const int VIS_VERTEXSHADE = 2;
      public const int VIS_SIZEWORLD = 0;
      public const int VIS_SIZEDEVICE = 1;
      public const int VIS_RIGHT = 0;
      public const int VIS_LEFT = 1;
      public const int VIS_BOTTOM = 2;
      public const int VIS_TOP = 3;
      public const int VIS_CENTER = 4;
      public const int VIS_BOTTOMRIGHT = 5;
      public const int VIS_TOPRIGHT = 6;
      public const int VIS_BOTTOMLEFT = 7;
      public const int VIS_TOPLEFT = 8;
      public const int VIS_DRAG_INIT = 1;
      public const int VIS_DRAG_MOVE = 2;
      public const int VIS_DRAG_TERM = 3;
      public const int VIS_ACTION_NONE = 0;
      public const int VIS_ACTION_TRANSLATE = 1;
      public const int VIS_ACTION_SCALE = 2;
      public const int VIS_ACTION_ROTATE = 3;
      public const int VIS_NODATA = 0;
      public const int VIS_CELLDATA = 1;
      public const int VIS_VERTEXDATA = 2;
      public const int VIS_MAT_ISOTROPIC = 0;
      public const int VIS_MAT_LAMINA = 1;
      public const int VIS_MAT_ORTHOTROPIC = 2;
      public const int VIS_MAT_ANISOTROPIC = 3;
      public const int VIS_ELEMLOC_CENTROID = 0;
      public const int VIS_ELEMLOC_CORNERS = 1;
      public const int VIS_ELEMLOC_NODES = 2;
      public const int VIS_ELEMLOC_NATIVE = 3;
      public const int VIS_MESH_MAXI = 1;
      public const int VIS_MESH_SHAPE = 2;
      public const int VIS_MESH_NUMELEMENTS = 3;
      public const int VIS_MESH_INWARD = 4;
      public const int VIS_MESH_EDGELENGTH = 5;
      public const int VIS_MESH_MINEDGELENGTH = 6;
      public const int VIS_MESH_SPANANGLE = 7;
      public const int VIS_MESH_BOUNDREFINE = 8;
      public const int VIS_MESH_MINANGLE = 9;
      public const int VIS_MESH_LAGRANGE = 10;
      public const int VIS_MESH_GROWTHRATE = 11;
      public const int VIS_MESH_CHECK = 12;
      public const int VIS_MESH_MINFEATLENGTH = 13;
      public const int VIS_MESH_COARSEN = 14;
      public const int VIS_MESH_JACOBIANRATIO = 15;
      public const int VIS_MESH_MIDSIDEPROJ = 16;
      public const int VIS_MESH_MIDSIDEQUAL = 17;
      public const int VIS_MESH_MINFEATANGLE = 18;
      public const int VIS_MESH_REPAIRINCONS = 19;
      public const int VIS_MESH_QUALTARGET = 20;
      public const int VIS_MESH_QUALTYPE = 21;
      public const int VIS_MESH_INTERREFINE = 22;
      public const int VIS_MESH_CHORDHEIGHT = 23;
      public const int VIS_MESH_MINHEALLENGTH = 24;
      public const int VIS_MESH_MINHEALANGLE = 25;
      public const int VIS_MESH_COMPUTENORMAL = 26;
      public const int VIS_MESH_NUMLAYERS = 27;
      public const int VIS_MESH_LAYERINITLENGTH = 28;
      public const int VIS_MESH_LAYERGROWTHRATE = 29;
      public const int VIS_MESH_REFINESMOOTH = 30;
      public const int VIS_MESH_MAXEDGELENGTH = 31;
      public const int VIS_MESH_MAPDETECT = 32;
      public const int VIS_MESH_MAPANGLE = 33;
      public const int VIS_MESH_MAPRECTONLY = 34;
      public const int VIS_MESH_MAXRECTANGLE = 35;
      public const int VIS_MESH_MAXQUADANGLE = 35;
      public const int VIS_MESH_UNCONNECT = 36;
      public const int VIS_MESH_UNCONNECTLENGTH = 37;
      public const int VIS_MESH_UNCONNECTPROJECT = 38;
      public const int VIS_MESH_PROGRESS = 39;
      public const int VIS_MESH_MAXPROXRATIO = 40;
      public const int VIS_MESH_DELAUNAY = 42;
      public const int VIS_MESH_QUALMINANG = 43;
      public const int VIS_MESH_QUALEDGEALT = 44;
      public const int VIS_MESH_REFINETEMPLATE = 45;
      public const int VIS_MESH_MAXANGLE = 46;
      public const int VIS_MESH_NONOBTUSE = 47;
      public const int VIS_MESH_VERBOSE = 48;
      public const int VIS_MESH_MAXEDGEALT = 49;
      public const int VIS_MESH_GEOMBOX = 50;
      public const int VIS_MESH_GEOMSPHERE = 52;
      public const int VIS_MESH_GEOMCYLINDER = 53;
      public const int VIS_MESH_GEOMHEMISPHERE = 54;
      public const int VIS_MESH_REFINEFACTOR = 55;
      public const int VIS_MESH_MAXWARPANGLE = 56;
      public const int VIS_MESH_MAXSKEWANGLE = 57;
      public const int VIS_MESH_POINTSET = 58;
      public const int VIS_MESH_HARDMINEDGELENGTH = 59;
      public const int VIS_MESH_FUNSIZINGMIN = 60;
      public const int VIS_MESH_FUNSIZINGLEGACY = 61;
      public const int VIS_MESH_BIT_GENSPLIT = 1;
      public const int VIS_MESH_BIT_GENSWAP = 2;
      public const int VIS_MESH_BIT_REFSPLIT = 4;
      public const int VIS_MESH_BIT_REFSWAP = 8;
      public const int VIS_STREAM_FLAG = 0;
      public const int VIS_STREAM_INTEGER = 1;
      public const int VIS_STREAM_REAL = 2;
      public const int VIS_STREAM_HOLLERITH = 3;
      public const int VIS_STREAM_IDENTIFIER = 4;
      public const int VIS_LEVELS = 2010;
      public const int VIS_TRANSMAP = 2020;
      public const int VIS_COLORMAP = 2030;
      public const int VIS_VISCONTEXT = 2040;
      public const int VIS_VISCONTEXT_SCALAR = 2041;
      public const int VIS_VISCONTEXT_VECTOR = 2042;
      public const int VIS_VISCONTEXT_TENSOR = 2043;
      public const int VIS_VISCONTEXT_FONT = 2047;
      public const int VIS_VISCONTEXT_AXIS = 2048;
      public const int VIS_ISOCLIP = 2050;
      public const int VIS_DATAINT = 2060;
      public const int VIS_GRIDFUN = 2070;
      public const int VIS_CONNECT = 2080;
      public const int VIS_STATE = 2090;
      public const int VIS_STATE_ROTANG = 2091;
      public const int VIS_COORDSYS = 2100;
      public const int VIS_IDTRAN = 2110;
      public const int VIS_IDTRAN_COLOR = 2111;
      public const int VIS_IDTRAN_TRANS = 2112;
      public const int VIS_IDTRAN_NODE = 2113;
      public const int VIS_IDTRAN_ELEM = 2114;
      public const int VIS_IDTRAN_DATAINDEX = 2115;
      public const int VIS_IDTRAN_ELEMENT = 2116;
      public const int VIS_IDTRAN_NODESURF = 2117;
      public const int VIS_GROUP = 2120;
      public const int VIS_SPACE = 2140;
      public const int VIS_BEAM = 2150;
      public const int VIS_BEAMSECT = 2160;
      public const int VIS_SHELL = 2170;
      public const int VIS_SHELLWALL = 2180;
      public const int VIS_TRIAD = 2190;
      public const int VIS_LEGEND = 2200;
      public const int VIS_EDGE = 2210;
      public const int VIS_FACE = 2220;
      public const int VIS_SEGMENT = 2230;
      public const int VIS_CONTOUR = 2240;
      public const int VIS_THRESHOLD = 2250;
      public const int VIS_MARK = 2260;
      public const int VIS_VALUE = 2270;
      public const int VIS_SPROP = 2280;
      public const int VIS_EPROP = 2300;
      public const int VIS_MPROP = 2310;
      public const int VIS_LCASE = 2320;
      public const int VIS_RCASE = 2330;
      public const int VIS_ICASE = 2340;
      public const int VIS_MODEL = 2350;
      public const int VIS_TOPOCELL = 2360;
      public const int VIS_GAPELEM = 2370;
      public const int VIS_DISCELEM = 2380;
      public const int VIS_MASSELEM = 2390;
      public const int VIS_BILLBOARD = 2400;
      public const int VIS_RIGIDELEM = 2410;
      public const int VIS_INFELEM = 2420;
      public const int VIS_DIMENSION = 2430;
      public const int VIS_WORKPLANE = 2440;
      public const int VIS_MAPMESH = 2450;
      public const int VIS_TRIMESH = 2460;
      public const int VIS_TETMESH = 2470;
      public const int VIS_VOLMESH = 2471;
      public const int VIS_GEOMFUN = 2480;
      public const int VIS_ELEMCHK = 2490;
      public const int VIS_SURFMESH = 2500;
      public const int VIS_EXTMESH = 2510;
      public const int VIS_MASSPRP = 2520;
      public const int VIS_CURVMESH = 2530;
      public const int VIS_ELEMDAT = 2540;
      public const int VIS_MCASE = 2550;
      public const int VIS_TCURVE = 2560;
      public const int VIS_MESHQUAL = 2570;
      public const int VIS_RPROP = 2580;
      public const int VIS_MESHQUAD = 2590;
      public const int VIS_CPAIR = 2600;
      public const int VIS_HISTORY = 2610;
      public const int VIS_PRMCLP = 2620;
      public const int VIS_UNITS = 2640;
      public const int VIS_TESS = 2650;
      public const int VIS_ASURF = 2660;
      public const int VIS_REDMAT = 2670;
      public const int VIS_HANDLEBOX = 2671;
      public const int VIS_POLYBOX = 2672;
      public const int VIS_ZSTATE = 2673;
      public const int VIS_GPROP = 2674;
      public const int VIS_ISOLABEL = 2675;
      public const int VIS_RBODY = 2676;
      public const int VIS_WRITER = 2677;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_WriterFunBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetWriteStateFunction(IntPtr p,VFuncWriterWriteState f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetWriteRedMatFunction(IntPtr p,VFuncWriterWriteRedMat f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetWriteHistoryFunction(IntPtr p,VFuncWriterWriteHistory f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetWriteModelFunction(IntPtr p,VFuncWriterWriteModel f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetGetFilePathFunction(IntPtr p,VFuncWriterGetFilePath f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunSetGetFileTypeFunction(IntPtr p,VFuncWriterGetFileType f_unction);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunWriteRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunWriteHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunWriteModel(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunGetFilePath(IntPtr p,StringBuilder f_ilePath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_WriterFunGetFileType(IntPtr p,ref int f_ileType);

      public static IntPtr WriterFunBegin() {
         return vis_WriterFunBegin();
      }

      public static void WriterFunEnd(IntPtr p) {
         vis_WriterFunEnd(p);
      }

      public static void WriterFunSetWriteStateFunction(IntPtr p,VFuncWriterWriteState f_unction) {
         vis_WriterFunSetWriteStateFunction(p, f_unction);
      }

      public static void WriterFunSetWriteRedMatFunction(IntPtr p,VFuncWriterWriteRedMat f_unction) {
         vis_WriterFunSetWriteRedMatFunction(p, f_unction);
      }

      public static void WriterFunSetWriteHistoryFunction(IntPtr p,VFuncWriterWriteHistory f_unction) {
         vis_WriterFunSetWriteHistoryFunction(p, f_unction);
      }

      public static void WriterFunSetWriteModelFunction(IntPtr p,VFuncWriterWriteModel f_unction) {
         vis_WriterFunSetWriteModelFunction(p, f_unction);
      }

      public static void WriterFunSetGetFilePathFunction(IntPtr p,VFuncWriterGetFilePath f_unction) {
         vis_WriterFunSetGetFilePathFunction(p, f_unction);
      }

      public static void WriterFunSetGetFileTypeFunction(IntPtr p,VFuncWriterGetFileType f_unction) {
         vis_WriterFunSetGetFileTypeFunction(p, f_unction);
      }

      public static void WriterFunWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop) {
         vis_WriterFunWriteState(p, s_tate, r_prop);
      }

      public static void WriterFunWriteRedMat(IntPtr p,IntPtr r_edmat,IntPtr r_prop) {
         vis_WriterFunWriteRedMat(p, r_edmat, r_prop);
      }

      public static void WriterFunWriteHistory(IntPtr p,IntPtr h_istory,IntPtr r_prop) {
         vis_WriterFunWriteHistory(p, h_istory, r_prop);
      }

      public static void WriterFunWriteModel(IntPtr p,IntPtr m_odel) {
         vis_WriterFunWriteModel(p, m_odel);
      }

      public static void WriterFunGetFilePath(IntPtr p,StringBuilder f_ilePath) {
         vis_WriterFunGetFilePath(p, f_ilePath);
      }

      public static void WriterFunGetFileType(IntPtr p,ref int f_ileType) {
         vis_WriterFunGetFileType(p,ref f_ileType);
      }

      public const int ZSTATE_ELEMNODE = 0;
      public const int ZSTATE_NODE = 1;
      public const int ZSTATE_ELEM = 4;
      public const int ZSTATE_TOL = 1;
      public const int ZSTATE_NUMLEVELS = 2;
      public const int ZSTATE_NUMCOARSE = 3;
      public const int ZSTATE_NUMFINE = 4;
      public const int ZSTATE_WRITEMESH = 5;
      public const int ZSTATE_PRINTLEVEL = 6;
      public const int ZSTATE_ZEROTOL = 7;
      public const int ZSTATE_NUMZERO = 8;
      public const int ZSTATE_SPATIALCONTINUITY = 1;
      public const int ZSTATE_BUFSIZE = 2048;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ZStateBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ZStateError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetParamf(IntPtr p,int t_ype,float f_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetTemp(IntPtr p,int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateClearTemp(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetPerm(IntPtr p,int n_id);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateKernel(IntPtr p,IntPtr i_dtran);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateLngKernel(IntPtr p,ref long n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSaveKernel(IntPtr p,ref IntPtr b_uff,ref long n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateLoadKernel(IntPtr p,ref IntPtr b_uff);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateInterpolate(IntPtr p,int g_roup,int l_evel,int n_f,ref int i_fine,ref int n_ix,int [] i_x,double [] w_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateState(IntPtr p,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateLngState(IntPtr p,ref long n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSaveState(IntPtr p,IntPtr s_tate,ref IntPtr b_uff,ref long n_bytes);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateLoadState(IntPtr p,ref IntPtr b_uff,IntPtr s_tate);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateGetInteger(IntPtr p,int g_roup,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateGetLevelInteger(IntPtr p,int g_roup,int l_evel,int t_ype,ref int i_value);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateClearKernel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStatePrintKernel(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ZStateSetMode(IntPtr p,int t_ype,int v_alue);

      public static IntPtr ZStateBegin() {
         return vis_ZStateBegin();
      }

      public static void ZStateEnd(IntPtr p) {
         vis_ZStateEnd(p);
      }

      public static int ZStateError(IntPtr p) {
         return vis_ZStateError(p);
      }

      public static void ZStateSetObject(IntPtr p,int o_bjecttype,IntPtr o_bject) {
         vis_ZStateSetObject(p, o_bjecttype, o_bject);
      }

      public static void ZStateGetObject(IntPtr p,int o_bjecttype,out IntPtr o_bject) {
         vis_ZStateGetObject(p, o_bjecttype,out o_bject);
      }

      public static void ZStateSetParamf(IntPtr p,int t_ype,float f_param) {
         vis_ZStateSetParamf(p, t_ype, f_param);
      }

      public static void ZStateSetParami(IntPtr p,int t_ype,int i_param) {
         vis_ZStateSetParami(p, t_ype, i_param);
      }

      public static void ZStateDef(IntPtr p,int n_ument,int p_arenttype,int c_hildtype) {
         vis_ZStateDef(p, n_ument, p_arenttype, c_hildtype);
      }

      public static void ZStateInq(IntPtr p,ref int n_ument,ref int e_nttype,ref int s_ubtype) {
         vis_ZStateInq(p,ref n_ument,ref e_nttype,ref s_ubtype);
      }

      public static void ZStateSetTemp(IntPtr p,int i_d) {
         vis_ZStateSetTemp(p, i_d);
      }

      public static void ZStateClearTemp(IntPtr p) {
         vis_ZStateClearTemp(p);
      }

      public static void ZStateSetPerm(IntPtr p,int n_id) {
         vis_ZStateSetPerm(p, n_id);
      }

      public static void ZStateKernel(IntPtr p,IntPtr i_dtran) {
         vis_ZStateKernel(p, i_dtran);
      }

      public static void ZStateLngKernel(IntPtr p,ref long n_bytes) {
         vis_ZStateLngKernel(p,ref n_bytes);
      }

      public static void ZStateSaveKernel(IntPtr p,ref IntPtr b_uff,ref long n_bytes) {
         vis_ZStateSaveKernel(p,ref b_uff,ref n_bytes);
      }

      public static void ZStateLoadKernel(IntPtr p,ref IntPtr b_uff) {
         vis_ZStateLoadKernel(p,ref b_uff);
      }

      public static void ZStateInterpolate(IntPtr p,int g_roup,int l_evel,int n_f,ref int i_fine,ref int n_ix,int [] i_x,double [] w_) {
         vis_ZStateInterpolate(p, g_roup, l_evel, n_f,ref i_fine,ref n_ix, i_x, w_);
      }

      public static void ZStateState(IntPtr p,IntPtr s_tate) {
         vis_ZStateState(p, s_tate);
      }

      public static void ZStateLngState(IntPtr p,ref long n_bytes) {
         vis_ZStateLngState(p,ref n_bytes);
      }

      public static void ZStateSaveState(IntPtr p,IntPtr s_tate,ref IntPtr b_uff,ref long n_bytes) {
         vis_ZStateSaveState(p, s_tate,ref b_uff,ref n_bytes);
      }

      public static void ZStateLoadState(IntPtr p,ref IntPtr b_uff,IntPtr s_tate) {
         vis_ZStateLoadState(p,ref b_uff, s_tate);
      }

      public static void ZStateGetInteger(IntPtr p,int g_roup,int t_ype,ref int i_value) {
         vis_ZStateGetInteger(p, g_roup, t_ype,ref i_value);
      }

      public static void ZStateGetLevelInteger(IntPtr p,int g_roup,int l_evel,int t_ype,ref int i_value) {
         vis_ZStateGetLevelInteger(p, g_roup, l_evel, t_ype,ref i_value);
      }

      public static void ZStateClearKernel(IntPtr p) {
         vis_ZStateClearKernel(p);
      }

      public static void ZStatePrintKernel(IntPtr p) {
         vis_ZStatePrintKernel(p);
      }

      public static void ZStateSetMode(IntPtr p,int t_ype,int v_alue) {
         vis_ZStateSetMode(p, t_ype, v_alue);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ABAFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ABAFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ABAFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ABAFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr ABAFwtBegin() {
         return vis_ABAFwtBegin();
      }

      public static void ABAFwtEnd(IntPtr p) {
         vis_ABAFwtEnd(p);
      }

      public static int ABAFwtError(IntPtr p) {
         return vis_ABAFwtError(p);
      }

      public static void ABAFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_ABAFwtWriteModel(p, m_odel, p_ath);
      }

      public const int ANS_MAXELEMNODE = 32;
      public const int ANSFWT_CONTROLCARDS = 1;
      public const int ANS_ALIAS_LINE300 = 1;
      public const int ANS_ALIAS_TRI200 = 2;
      public const int ANS_ALIAS_TRI300 = 3;
      public const int ANS_ALIAS_TET200 = 4;
      public const int ANS_ALIAS_TET300 = 5;
      public const int ANS_ALIAS_PYR200 = 6;
      public const int ANS_ALIAS_PYR300 = 7;
      public const int ANS_ALIAS_WED200 = 8;
      public const int ANS_ALIAS_WED300 = 9;
      public const int ANS_ALIAS_QUAD320 = 10;
      public const int ANS_ALIAS_WED302 = 11;
      public const int ANS_ALIAS_HEX302 = 12;
      public const int ANS_ALIAS_MAX = 12;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_ANSFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ANSFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_ANSFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ANSFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_ANSFwtSetDimension(IntPtr p,int d_imensionCount);

      public static IntPtr ANSFwtBegin() {
         return vis_ANSFwtBegin();
      }

      public static void ANSFwtEnd(IntPtr p) {
         vis_ANSFwtEnd(p);
      }

      public static int ANSFwtError(IntPtr p) {
         return vis_ANSFwtError(p);
      }

      public static void ANSFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_ANSFwtWriteModel(p, m_odel, p_ath);
      }

      public static void ANSFwtSetDimension(IntPtr p,int d_imensionCount) {
         vis_ANSFwtSetDimension(p, d_imensionCount);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_D3DFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_D3DFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_D3DFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_D3DFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr D3DFwtBegin() {
         return vis_D3DFwtBegin();
      }

      public static void D3DFwtEnd(IntPtr p) {
         vis_D3DFwtEnd(p);
      }

      public static int D3DFwtError(IntPtr p) {
         return vis_D3DFwtError(p);
      }

      public static void D3DFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_D3DFwtWriteModel(p, m_odel, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_FLUENTLwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_FLUENTLwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtInit(IntPtr p,IntPtr m_odel);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtTerm(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtDimension(IntPtr p,ref int n_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtNumEntities(IntPtr p,ref int n_umcell,ref int n_umface,ref int n_umnode);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtNumCellZone(IntPtr p,ref int n_umcellzone);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtCellZoneParam(IntPtr p,int i_thcellzone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtCellZoneType(IntPtr p,int i_thcellzone,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtCellZoneElem(IntPtr p,int i_thcellzone,int [] e_lem);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtCellZoneName(IntPtr p,int i_thcellzone,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtCellZoneId(IntPtr p,int i_thcellzone,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtNumFaceZone(IntPtr p,ref int n_umfacezone);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtFaceZoneParam(IntPtr p,int i_thfacezone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtFaceZoneType(IntPtr p,int i_thfacezone,int [] t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtFaceZone(IntPtr p,int i_thfacezone,int [] i_xf,int [] c_r,int [] c_l);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtFaceZoneName(IntPtr p,int i_thfacezone,StringBuilder n_ame);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtFaceZoneId(IntPtr p,int i_thfacezone,ref int i_d);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtNode(IntPtr p,double [] x_);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtWriteModelAux(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_FLUENTLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr FLUENTLwtBegin() {
         return vis_FLUENTLwtBegin();
      }

      public static void FLUENTLwtEnd(IntPtr p) {
         vis_FLUENTLwtEnd(p);
      }

      public static int FLUENTLwtError(IntPtr p) {
         return vis_FLUENTLwtError(p);
      }

      public static void FLUENTLwtInit(IntPtr p,IntPtr m_odel) {
         vis_FLUENTLwtInit(p, m_odel);
      }

      public static void FLUENTLwtTerm(IntPtr p) {
         vis_FLUENTLwtTerm(p);
      }

      public static void FLUENTLwtDimension(IntPtr p,ref int n_d) {
         vis_FLUENTLwtDimension(p,ref n_d);
      }

      public static void FLUENTLwtNumEntities(IntPtr p,ref int n_umcell,ref int n_umface,ref int n_umnode) {
         vis_FLUENTLwtNumEntities(p,ref n_umcell,ref n_umface,ref n_umnode);
      }

      public static void FLUENTLwtNumCellZone(IntPtr p,ref int n_umcellzone) {
         vis_FLUENTLwtNumCellZone(p,ref n_umcellzone);
      }

      public static void FLUENTLwtCellZoneParam(IntPtr p,int i_thcellzone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type) {
         vis_FLUENTLwtCellZoneParam(p, i_thcellzone,ref i_first,ref i_last,ref t_ype,ref e_type);
      }

      public static void FLUENTLwtCellZoneType(IntPtr p,int i_thcellzone,int [] t_ype) {
         vis_FLUENTLwtCellZoneType(p, i_thcellzone, t_ype);
      }

      public static void FLUENTLwtCellZoneElem(IntPtr p,int i_thcellzone,int [] e_lem) {
         vis_FLUENTLwtCellZoneElem(p, i_thcellzone, e_lem);
      }

      public static void FLUENTLwtCellZoneName(IntPtr p,int i_thcellzone,StringBuilder n_ame) {
         vis_FLUENTLwtCellZoneName(p, i_thcellzone, n_ame);
      }

      public static void FLUENTLwtCellZoneId(IntPtr p,int i_thcellzone,ref int i_d) {
         vis_FLUENTLwtCellZoneId(p, i_thcellzone,ref i_d);
      }

      public static void FLUENTLwtNumFaceZone(IntPtr p,ref int n_umfacezone) {
         vis_FLUENTLwtNumFaceZone(p,ref n_umfacezone);
      }

      public static void FLUENTLwtFaceZoneParam(IntPtr p,int i_thfacezone,ref int i_first,ref int i_last,ref int t_ype,ref int e_type) {
         vis_FLUENTLwtFaceZoneParam(p, i_thfacezone,ref i_first,ref i_last,ref t_ype,ref e_type);
      }

      public static void FLUENTLwtFaceZoneType(IntPtr p,int i_thfacezone,int [] t_ype) {
         vis_FLUENTLwtFaceZoneType(p, i_thfacezone, t_ype);
      }

      public static void FLUENTLwtFaceZone(IntPtr p,int i_thfacezone,int [] i_xf,int [] c_r,int [] c_l) {
         vis_FLUENTLwtFaceZone(p, i_thfacezone, i_xf, c_r, c_l);
      }

      public static void FLUENTLwtFaceZoneName(IntPtr p,int i_thfacezone,StringBuilder n_ame) {
         vis_FLUENTLwtFaceZoneName(p, i_thfacezone, n_ame);
      }

      public static void FLUENTLwtFaceZoneId(IntPtr p,int i_thfacezone,ref int i_d) {
         vis_FLUENTLwtFaceZoneId(p, i_thfacezone,ref i_d);
      }

      public static void FLUENTLwtNode(IntPtr p,double [] x_) {
         vis_FLUENTLwtNode(p, x_);
      }

      public static void FLUENTLwtWriteModelAux(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_FLUENTLwtWriteModelAux(p, m_odel, p_ath);
      }

      public static void FLUENTLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_FLUENTLwtWriteModel(p, m_odel, p_ath);
      }

      public const int NASFWT_RELATIVEPATH = 1;

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_NASFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_NASFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_NASFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_NASFwtSetParami(IntPtr p,int t_ype,int i_param);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_NASFwt_GetExportVendor(IntPtr p,ref int v_endor);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_NASFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_NASFwtWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate,StringBuilder p_ath);

      public static IntPtr NASFwtBegin() {
         return vis_NASFwtBegin();
      }

      public static void NASFwtEnd(IntPtr p) {
         vis_NASFwtEnd(p);
      }

      public static int NASFwtError(IntPtr p) {
         return vis_NASFwtError(p);
      }

      public static void NASFwtSetParami(IntPtr p,int t_ype,int i_param) {
         vis_NASFwtSetParami(p, t_ype, i_param);
      }

      public static void NASFwt_GetExportVendor(IntPtr p,ref int v_endor) {
         vis_NASFwt_GetExportVendor(p,ref v_endor);
      }

      public static void NASFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_NASFwtWriteModel(p, m_odel, p_ath);
      }

      public static void NASFwtWriteState(IntPtr p,IntPtr r_prop,IntPtr s_tate,StringBuilder p_ath) {
         vis_NASFwtWriteState(p, r_prop, s_tate, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_OBJFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_OBJFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_OBJFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_OBJFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr OBJFwtBegin() {
         return vis_OBJFwtBegin();
      }

      public static void OBJFwtEnd(IntPtr p) {
         vis_OBJFwtEnd(p);
      }

      public static int OBJFwtError(IntPtr p) {
         return vis_OBJFwtError(p);
      }

      public static void OBJFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_OBJFwtWriteModel(p, m_odel, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_PatLwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_PatLwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_PatLwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_PatLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_PatLwtWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop,StringBuilder p_ath);

      public static IntPtr PatLwtBegin() {
         return vis_PatLwtBegin();
      }

      public static void PatLwtEnd(IntPtr p) {
         vis_PatLwtEnd(p);
      }

      public static int PatLwtError(IntPtr p) {
         return vis_PatLwtError(p);
      }

      public static void PatLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_PatLwtWriteModel(p, m_odel, p_ath);
      }

      public static void PatLwtWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop,StringBuilder p_ath) {
         vis_PatLwtWriteState(p, s_tate, r_prop, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_RASFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RASFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_RASFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_RASFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr RASFwtBegin() {
         return vis_RASFwtBegin();
      }

      public static void RASFwtEnd(IntPtr p) {
         vis_RASFwtEnd(p);
      }

      public static int RASFwtError(IntPtr p) {
         return vis_RASFwtError(p);
      }

      public static void RASFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_RASFwtWriteModel(p, m_odel, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_SDRCLwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SDRCLwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_SDRCLwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SDRCLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_SDRCLwtWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop,StringBuilder p_ath);

      public static IntPtr SDRCLwtBegin() {
         return vis_SDRCLwtBegin();
      }

      public static void SDRCLwtEnd(IntPtr p) {
         vis_SDRCLwtEnd(p);
      }

      public static int SDRCLwtError(IntPtr p) {
         return vis_SDRCLwtError(p);
      }

      public static void SDRCLwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_SDRCLwtWriteModel(p, m_odel, p_ath);
      }

      public static void SDRCLwtWriteState(IntPtr p,IntPtr s_tate,IntPtr r_prop,StringBuilder p_ath) {
         vis_SDRCLwtWriteState(p, s_tate, r_prop, p_ath);
      }

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern IntPtr vis_STLFwtBegin();

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_STLFwtEnd(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern int vis_STLFwtError(IntPtr p);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_STLFwtSetFileType(IntPtr p,int t_ype);

      [DllImport("HoopsSAM", CallingConvention = CallingConvention.Cdecl)]
      static extern void vis_STLFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath);

      public static IntPtr STLFwtBegin() {
         return vis_STLFwtBegin();
      }

      public static void STLFwtEnd(IntPtr p) {
         vis_STLFwtEnd(p);
      }

      public static int STLFwtError(IntPtr p) {
         return vis_STLFwtError(p);
      }

      public static void STLFwtSetFileType(IntPtr p,int t_ype) {
         vis_STLFwtSetFileType(p, t_ype);
      }

      public static void STLFwtWriteModel(IntPtr p,IntPtr m_odel,StringBuilder p_ath) {
         vis_STLFwtWriteModel(p, m_odel, p_ath);
      }

      public const int ANS_NUMELEMTYPES = 300;

      public const int D3D_NUMELEMTYPES = 13;
      public const int D3D_NUMELEMSETTYPES = 6;

      public const int NAS_NUMELEMTYPES = 152;

      public const int PAM_NUMELEMTYPES = 13;

   }
}
