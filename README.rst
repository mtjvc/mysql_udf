AIP MySQL UDF collection
========================

This is a collection of usefull UDFs that we use at the Leibniz Institute
for Astrophysics Potsdam (AIP). 

- UDF for angular distance using the Vincenty formula
- UDF for up to 10-dim hilbert curve key generation
- UDF for distributed STDDEV calculation (using Welford 1962, Chan et al. 1979)
- UDF for doing nothing for a given number of seconds (sleep)
- UDF for strrpos implementation
- UDFs for work with Gaia mission data
- UDFs for special functions such as erf


Installation
------------

1) Download the mysql source corresponding to your installed
   version. Building mysql from scratch is recommended.

   Note: ONLY MYSQL VERSION 5.5 AND ABOVE ARE CURRENTLY SUPPORTED

2) edit CMakeList.txt accordingly to point to the directory 
   where mysql is installed.

3) edit CMakeList.txt accordingly to point to the directory
   of the mysql sources

4) mkdir build
   cd build

5) cmake ..

6) make

7) make install

8) log into mysql server as root and execute the commands in 
   install_udfs.sql. This will setup the neccessary tables, install the plugin
   and create all the UDFs needed to administer the queue.

Uasge
-----

udf_angdist: 

- ``angdist(pointA RA (degree), pointA DEC (degree), pointB RA (degree), pointB DEC (degree))``


udf_gaia_healpix:

- ``gaia_healpix(healpix level, source_id)``


udf_hilbert:

- ``hilbertKey(hilbert order, box size, num dim, x, y, z, ... )``
- ``coordFromHilbertKey(hilbert order, box size, num dim, hilbert key, current dimension (separate call for each dimension))``


udf_partitAdd_sum_of_squares:

- ``partitadd_sum_of_sqares(PART_M2, PART_MEAN, PART_COUNT)``
 * - ``PART_M2:	the sum of squares for a given partition``
 * - ``PART_MEAN:	the mean for a given partition``
 * - ``PART_COUNT:	the number of elements in the partition``


udf_sleep:

- ``idle(num seconds)``


udf_special_functions:

- ``aip_erf(x)``


udf_sum_of_squares:

- ``sum_of_squares(number)``


udf_strrpos:

- ``strrpos(haystack, needle)``
