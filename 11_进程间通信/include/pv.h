/*
 * 文件名: pv.h
 * 描述: 对信号量进行PV 操作
 * 完成日期: 2018年2月26日 10:40
 * */

#ifndef __PV_H__
#define __PV_H__

/* 初始化 semnums 个信号灯/信号量的值(value) */
extern int I(int semnums, int value);

/* 对信号量集(semid)中的某个信号灯(semnum)做P(value)操作 */
extern void P(int semid, int semnum, int value);

/* 对信号量集(semid)中的某个信号灯(semnum)做V(value)操作 */
extern void V(int semid, int semnum, int value);

/* 销毁信号量集 */
extern void D(int semid);

#endif
