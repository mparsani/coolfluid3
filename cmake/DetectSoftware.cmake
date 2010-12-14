##############################################################################
# finding MPI (essential) must be after the GlobalOptions

coolfluid_log( "\n +++ Searching for MPI ..." )
include( DetectMPI )

##############################################################################
# finding boost (essential)

coolfluid_log( "\n +++ Searching for Boost ..." )
include( DetectBoost )

##############################################################################
# Find Qt - defines QT_USE_FILE and QT_LIBRARIES used below

#  set( QT_USE_QTXML TRUE     )
#  set( QT_USE_QTNETWORK TRUE )

if(APPLE)
  set(QT_USE_FRAMEWORKS TRUE)
endif()

find_package( Qt4 4.6.0 COMPONENTS QtCore QtGui QtXml QtNetwork QtTest )

coolfluid_log("QT_FOUND: [${QT_FOUND}]")
if(${QT_FOUND})
  coolfluid_log("QT Libraries: [${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTNETWORK_LIBRARY} ${QT_QTTEST_LIBRARY}]")
endif()

##############################################################################
# find non essential packages

# using our find macros

coolfluid_log( "" )
find_package(CMath)           # find the math library
find_package(BlasLapack)      # search for Blas Lapack support
find_package(PTScotch)        # parallel domain decomposition
find_package(Metis)           # serial domain decomposition
find_package(Parmetis)        # parallel domain decomposition
find_package(Zoltan)          # parallel and serial domain decomposition using parmetis or pt-scotch
find_package(Curl)            # curl downloads files on the fly
find_package(Valgrind)        # valgrind for profiling and memmory leak detection
find_package(GooglePerftools) # dynamic profiler and memory checker
find_package(CGNS)            # CGNS library
find_package(PythonInterp)    # Python interpreter
find_package(Realtime)        # POSIX Realtime library

if( CF_ENAGLE_OPENCL AND CF_ENABLE_GPU )
  find_package(OpenCL)          # opencl support
endif()

# using cmake find macros

if( CF_ENAGLE_CUDA AND CF_ENABLE_GPU )
  find_package(CUDA)            # cuda support
  coolfluid_log( "CUDA_FOUND: [${CUDA_FOUND}]" )
endif()

find_package(ZLIB)            # file compression support

coolfluid_log( "ZLIB_FOUND: [${ZLIB_FOUND}]" )
if( ZLIB_FOUND )
  coolfluid_log_file( "  ZLIB_INCLUDE_DIRS: [${ZLIB_INCLUDE_DIRS}]" )
  coolfluid_log_file( "  ZLIB_LIBRARIES:    [${ZLIB_LIBRARIES}]" )
endif()

# find_package(BZip2)        # file compression support

#coolfluid_log( "BZIP2_FOUND: [${BZIP2_FOUND}]" )
#if( BZIP2_FOUND )
#  coolfluid_log_file( "  BZIP2_INCLUDE_DIR:  [${BZIP2_INCLUDE_DIR}]" )
#  coolfluid_log_file( "  BZIP2_LIBRARIES:    [${BZIP2_LIBRARIES}]" )
#  coolfluid_log_file( "  BZIP2_DEFINITIONS:  [${BZIP2_DEFINITIONS}]" )
#  coolfluid_log_file( "  BZIP2_NEED_PREFIX:  [${BZIP2_NEED_PREFIX}]" )
#endif()
