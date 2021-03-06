/* Turtle_NetCdf CONTAINS FUNCTIONS TO INPORT/EXPORT FUIDTURLE STRUCT OF DATA IN NETcdf FILES AS VARIABLES
Turtle_NetCdf Version 0.9375 KMackenzie

file turtle2netcdf.c

Copyright, 2009 Stefano Endrizzi, Emanuele Cordano, Matteo Dall'Amico 

This file is part of numerioc_solver.
	 Turtle_NetCdf is free software: you can redistribute it and/or modify
    it under the terms of the GNU  General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

     Turtle_NetCdf is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU  General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 *
 * \file turtle2netcdf.c
 * \data 11 September 2009
 * \author Emanuele Cordano
 */

#ifdef USE_NETCDF
#ifndef NCGT_TURTLE2NETCDF_H
#define NCGT_TURTLE2NETCDF_H


#include "../libraries/fluidturtle/turtle.h"
//#include <netcdf.h>
#include "gt_utilities.h"
#include "gt_symbols.h"
#include "ncgt_utilities.h"


//DEFINE/UNDEFINE this symbol in Project.Properties.C++ Build.Settings.Gcc C compiler.Defined Symbol
//to write netcdf in standard 3 or 4
#ifdef USE_NETCDF4
	#define NEW_EMPTY_FILE NC_CLOBBER|NC_NETCDF4
#else
	#define NEW_EMPTY_FILE NC_CLOBBER
#endif
/* file: turtle2netcdf.c
 * all C commands for NetCDF file management
 * http://www.unidata.ucar.edu/software/netcdf/docs/netcdf-c/index.html#Top
 */
/*
 * Handle errors by printing an error message and exiting with a
 * non-zero status.
 */
#define ERRCODE 2

#define ERROR_MESSAGE(e,n_function,n_ncfunction) {printf("Error in %s() function: %s",n_function,n_ncfunction); printf("\nError: %s\n", nc_strerror(e)); exit(ERRCODE);}
#define GLOBAL_ATTRIBUTE "global_attribute"



//int ncgt_newemptyfile(int ncid);

int ncgt_put_doublevector(DOUBLEVECTOR *v, int ncid, const char *dimension);

int ncgt_put_doublematrix(DOUBLEMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);

int ncgt_put_var_textattributes(int ncid,const char *varname, const char *attribute_name, const char *attribute_text);

//EV_S
int ncgt_put_floatvector(FLOATVECTOR *v, int ncid, const char *dimension);

int ncgt_put_intvector(INTVECTOR *v, int ncid, const char *dimension);

int ncgt_put_longvector(LONGVECTOR *v, int ncid, const char *dimension);

int ncgt_put_shortvector(SHORTVECTOR *v, int ncid, const char *dimension);

//CHARVECTOR TBC (unused in Geotop)

int ncgt_put_floatmatrix(FLOATMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);

int ncgt_put_shortmatrix(SHORTMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);

int ncgt_put_intmatrix(INTMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);

int ncgt_put_longmatrix(LONGMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);

int ncgt_put_doubletensor(DOUBLETENSOR *dt, int ncid, const char *dimension_x, const char *dimension_y, const char *dimension_z);

//EV_E

/* added by Emanuele Cordano on October 13 , 2009 */


int ncgt_put_doublematrix_vs_time(DOUBLEMATRIX *m, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y);
/* end added by Emanuele Cordano on October 13 , 2009 */
int ncgt_put_doublematrix_vs_time(GeoMatrix<double>& m, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y);


//221009_s
int ncgt_put_doublevector_vs_time(DOUBLEVECTOR *v, long k, int ncid, const char *dimension_t,  const char *dimension_x);

int ncgt_put_doubletensor_vs_time(DOUBLETENSOR *t, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y, const char *dimension_z);
int ncgt_put_doubletensor_vs_time(GeoTensor<double>&t, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y, const char *dimension_z);
//201009_s
//SCALAR TYPES
//NC_BYTE
int nc_put_byte(signed char bval, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);


// NC_INT
int nc_put_int(int ival, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);


// NC_SHORT
int nc_put_short(short sval, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);


// NC_FLOAT
int nc_put_float(float fval, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);


// NC_DOUBLE
int nc_put_double(double dval, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);

// NC_LONG
int nc_put_long(long lval, int ncid,const char *varname, const char *units, const char *description,const char *standard_name,const char *long_name);


//201009_e

/* Emanuele Cordano on October 26 October */

int ncgt_put_rotate180_y_doublematrix(DOUBLEMATRIX *m, int ncid, const char *dimension_x, const char *dimension_y);
int ncgt_put_rotate180_y_doublematrix_vs_time(GeoMatrix<double>& m, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y);
int ncgt_put_rotate180_y_doubletensor(DOUBLETENSOR *m, int ncid, const char *dimension_x, const char *dimension_y, const char *dimension_z);

int ncgt_put_rotate180_y_doublematrix_vs_time(DOUBLEMATRIX *m, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y);

int ncgt_put_rotate180_y_doubletensor_vs_time(DOUBLETENSOR *t, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y, const char *dimension_z);
int ncgt_put_rotate180_y_doubletensor_vs_time(GeoTensor<double>& t, long k, int ncid, const char *dimension_t,  const char *dimension_x, const char *dimension_y, const char *dimension_z);

//void nc_add_global_attr_lat_lon_min_max(int ncid,double long_min,double long_max,double lat_min,double lat_max);

void nc_add_variable_attr_missing_value(int ncid,const char *varname,double missing_value);

void nc_add_global_attr_missing_value(int ncid,double missing_value);

//void nc_add_global_attr_resolution(int ncid,double map_resolution);

void nc_add_global_attr_double(int ncid,char *attr_name,double attr_value);

int ncgt_put_double_vs_time(double v, const char *var_name, long k, int ncid, const char *dimension_t);

//int ncgt_put_doublematrix_from_doubletensor_vs_time(DOUBLETENSOR *dt,long k, int ncid, const char *dimension_t, const char *suffix, const char *dimension_id, const char *dimension_z,LONGMATRIX *rc);
//int ncgt_put_doublematrix_from_doubletensor_vs_time(DOUBLETENSOR *dt,long k, int ncid, const char *dimension_t, char *suffix,const char *dimension_id, const char *dimension_z, LONGMATRIX *rc);
int ncgt_put_doublematrix_from_doubletensor_vs_time(DOUBLETENSOR *dt,long k, int ncid, const char *dimension_t, char *suffix,const char *dimension_id, const char *dimension_z, GeoMatrix<long>* rc);
int ncgt_put_doublematrix_from_doubletensor_vs_time(const GeoTensor<double>& dt, long k, int ncid, const char *dimension_t, char *suffix, 
                                                    const char *dimension_id, const char *dimension_z, GeoMatrix<long>* rc);

//int ncgt_put_doublevector_from_doublematrix_vs_time(DOUBLEMATRIX *dt,long k, int ncid, const char *dimension_t, const char *suffix,const char *dimension_id, LONGMATRIX *rc);
//int ncgt_put_doublevector_from_doublematrix_vs_time(DOUBLEMATRIX *dt,long k, int ncid, const char *dimension_t,  char *suffix,const char *dimension_id, LONGMATRIX *rc);
int ncgt_put_doublevector_from_doublematrix_vs_time(DOUBLEMATRIX *dt,long k, int ncid, const char *dimension_t,  char *suffix,const char *dimension_id, GeoMatrix<long>* rc);

#endif
#endif
