AIP MySQL UDF collection
========================

This is a collection of usefull UDFs that we use at the Leibniz Institute
for Astrophysics Potsdam (AIP). 


Installation
------------

1) Download the MySQL/MariaDB source corresponding to your installed
   version. Building from scratch is recommended.

2) Edit ``CMakeList.txt`` accordingly to point to the directory 
   where mysql is installed.

3) Edit ``CMakeList.txt`` accordingly to point to the directory
   of the mysql sources

4) Execute the following commands:

.. code-block:: shell

    mkdir build
    cd build
    cmake ..
    make
    make install

5) Log into MySQL/MariaDB server as root and execute the commands in 
   ``install_udfs.sql``. This will setup the neccessary tables, install
   the plugin and create all the UDFs needed to administer the queue.

Usage
-----

udf_angdist - for angular distance using the Vincenty formula:

- ``angdist(pointA RA (degree), pointA DEC (degree), pointB RA (degree), pointB DEC (degree))``


udf_gaia_healpix - Gaia mission source_id to HEALPix value conversion:

- ``gaia_healpix(healpix level, source_id)``


udf_hilbert - up to 10-dim hilbert curve key generation:

- ``hilbertKey(hilbert order, box size, num dim, x, y, z, ... )``
- ``coordFromHilbertKey(hilbert order, box size, num dim, hilbert key, current dimension (separate call for each dimension))``


udf_partitAdd_sum_of_squares:

- ``partitadd_sum_of_sqares(PART_M2, PART_MEAN, PART_COUNT)``
 * - ``PART_M2:	the sum of squares for a given partition``
 * - ``PART_MEAN:	the mean for a given partition``
 * - ``PART_COUNT:	the number of elements in the partition``


udf_sleep - UDF for doing nothing for a given number of seconds (sleep):

- ``idle(num seconds)``


udf_special_functions - special functions:

- ``aip_erf(x)``


udf_sum_of_squares:

- ``sum_of_squares(number)``


udf_strrpos - UDF for strrpos implementation:

- ``strrpos(haystack, needle)``
