///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Behavior Server
//  Subsystem:       
//  Workfile:        types.h
//  Revision:        1.0 - 6 Apr, 2006
//                   1.1 - 2 July, 2007 : Modified for use on the cell phone
//                                        assembly configuration
//                   2.0 - 1 Sep, 2008  : Generalized for multiple projects
//                   2.1 - 24 May, 2010 : Moved common data types from GA
//                                        library to here
//  Author:          J. Marvel
//
//  Description
//  ===========
//  System-wide type & structure definitions
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <math.h>
#include <io.h>
#include "portable.h"

///////////////////////////////////////////////////////////////////////////////
/**************************** data structures ********************************/
///////////////////////////////////////////////////////////////////////////////

//! @brief Application configuration options
//!
//! @note This is the only structure that should be populated by application
//!       options or configuration values, and should be ammended whenever
//!       new applications/options are added to the workspace rather than new
//!       structures being defined.  Not all options will be used, but it's
//!       better than having a million and one configuration structures.
//!
struct settingsAggregate
{
  /////////////////////////////////////////////////////////////////////////////
  /*                 GENETIC ALGORITHM APPLICATION OPTIONS                   */
  /////////////////////////////////////////////////////////////////////////////

  //! @brief The number of children per clan
  //!
  int numChildren;

  //! @brief The number of clans to maintain
  //!
  int numClans;

  //! @brief The ETA- value to use in our custom GA implementation
  //!
  double etaMinus;

  //! @brief The ETA+ value to use in our custom GA implementation
  //!
  double etaPlus;

  //! @brief The number of iterations to run per child test
  //!
  int numIterations;

  //! @brief The amount of importance we are placing on the time element
  //!        of the GA result vector
  //!
  double timeWeight;

  //! @brief The amount of importance we are placing on the force element
  //!        of the GA result vector
  //!
  double forceWeight;

  //! @brief The maximum amount of force we are allowing in any given
  //!        direction before we mark an assembly attempt as failed and
  //!        abort
  //!
  double maxForce;

  //! @brief The maximum amount of time we are allowing before we mark an
  //!        assembly attempt as failed and abort
  //!
  double maxTime;

  //! @brief Whether or not we should add a random perturbation once the
  //!        GA has finished executing a gene sequence
  //!
  bool randomOffset;

  //! @brief Whether or not we should dump a raw log file to disk
  //!
  bool logDump;

  //! @brief Default constructor
  //!
  settingsAggregate ()
  {
    timeWeight = defaultTimeWeight;
    forceWeight = defaultForceWeight;
    maxTime = defaultMaxTime;
    maxForce = defaultMaxForce;
    numChildren = defaultPopulationSize;
    numClans = defaultClanCount;
    etaMinus = defaultEtaMinus;
    etaPlus = defaultEtaPlus;
    randomOffset = false;
    logDump = false;
  }
};

//! @brief Cartesian pose information
//!
struct robotPose
{
  //! @brief Cartesian X axis coordinate
  //!
  double x;

  //! @brief Cartesian Y axis coordinate
  //!
  double y;

  //! @brief Cartesian Z axis coordinate
  //!
  double z;

  //! @brief Cartesian X axis rotation value
  //!
  double xrot;

  //! @brief Cartesian Y axis rotation value
  //!
  double yrot;

  //! @brief Cartesian Z axis rotation value
  //!
  double zrot;

  //! @brief Default constructor
  //!
  robotPose()
  {
    clear ();
  }

  //! @brief Set all values to 0
  //!
  void clear ()
  {
    x = y = z = xrot = yrot = zrot = 0.0;
  }

  //! @brief Pose assignment function
  //!
  //! @param source An existing pose that will be used to populate this pose
  //!               instance
  //!
  robotPose & operator=(const robotPose &source)
  {
    if (this != &source)
    {
      x = source.x;
      y = source.y;
      z = source.z;
      xrot = source.xrot;
      yrot = source.yrot;
      zrot = source.zrot;
    }
    return *this;
  }

};


//! @brief Robot axis information
//!
struct robotAxes
{
  //! @brief Robot axis values
  //!
  double *axis;

  //! @brief The number of axes defined for the robot
  //!
  int axes;

  //! @brief Constructor
  //!
  robotAxes (int numAxes)
  {
    axes = numAxes;
    axis = new double[axes];
  }

  //! @brief Destructor
  //!
  ~robotAxes ()
  {
    delete [] axis;
  }
};


//! @brief Image-space coordinates of the cell phone components
//!
struct point
{
  //! @brief Cartesian X axis coordinate
  //!
  double x;

  //! @brief Cartesian Y axis coordinate
  //!
  double y;

  //! @brief Cartesian Z axis coordinate
  //!
  double z;

  //! @brief Default constructor
  //!
  point ()
  {
    x = y = z = 0.0;
  }

  //! @brief Assignmet constructor
  point (double px, double py, double pz) :
    x(px),
    y(py),
    z(pz)
  {
  }

  //! @brief Point assignment function
  //!
  //! @param source An existing point that will be used to populate this point
  //!               instance
  //!
  point & operator=(const point &source)
  {
    if (this != &source)
    {
      x = source.x;
      y = source.y;
      z = source.z;
    }
    return *this;
  }


  //! @brief Point adjustment function
  //!
  //! @param pB
  //!
  //! @return
  //!
  point operator+(const point &pB)
  {
    point pC;
    pC.x = x + pB.x;
    pC.y = y + pB.y;
    pC.z = z + pB.z;
    return pC;
  }

  //! @brief Compute the Cartesian distance to another point
  //!
  //! @param dest The comparitive point to which we are finding the distance
  //! @param root Whether or not to take the square root (false makes the
  //!             equation faster--useful when only doing nearest-neighbor
  //!             comparisons)
  //!
  //! @return The Cartesian distance between this point and a destination
  //!         point
  //!
  double distance (const point &dest, bool root = false)
  {
    static double temp;
    temp = (dest.x - x) * (dest.x - x);
    temp += (dest.y - y) * (dest.y - y);
    temp += (dest.z - z) * (dest.z - z);
    return (root ? sqrt (temp) : temp);
  }
};

//! @brief Robot configuration data for virtual sensor output
//!
struct robotStruct
{

  double x;
  double y;
  double z;
  double rx;
  double ry;
  double rz;
  double fx;
  double fy;
  double fz;
  double frx;
  double fry;
  double frz;
  double ts;
  int flag;
  int intflag;
  statusFlag status;
  methodFlag method;

  //! @brief Packet sequence number
  //!
  int seq;

  //! @brief Image grab flag
  //!
  int grabImg;

  //! @brief Move ready flag
  //!
  int moveFlag;

  //! @brief Mutex for protecting against access violations
  //!
  HANDLE robotMutex;

  //! @breif Default constructor
  //!
  robotStruct ()
  {
    seq = grabImg = moveFlag = 0;
    flag = intflag = 0;
  }

  //! @brief RobotStruct assignment function
  //!
  //! @param source An existing robot struct that will be used to populate this
  //!               structure instance
  //!
  robotStruct & operator=(const robotStruct &source)
  {
    if (this != &source)
    {
      x = source.x;
      y = source.y;
      z = source.z;
      rx = source.rx;
      ry = source.ry;
      rz = source.rz;
      fx = source.fx;
      fy = source.fy;
      fz = source.fz;
      frx = source.frx;
      fry = source.fry;
      frz = source.frz;
      flag = source.flag;
      intflag = source.intflag;
      seq = source.seq;
      grabImg = source.grabImg;
      moveFlag = source.moveFlag;
    }
    return *this;
  }
};


//! @brief State setting variables for the server
//!
struct networkSettings
{
  //! @brief Whether we are currently connected
  //!
  bool connected;

  //! @brief Whether the server is currently running
  //!
  bool globalRunServer;

  //! @brief Whether a disconnect request has been issued
  //!
  bool disconnectRequest;

  //! @brief Internal debugging string
  //!
  char globalString[1024];

  //! @brief Internal debugging socket string
  //!
  char sockString[1024];

  //! @brief Run process flag
  //!
  unsigned short runFlag;

  //! @brief Whether or not to commit the GSI logs to disk
  //!
  bool log;

  //! @brief Default settings constructor
  //!
  networkSettings  () : 
    connected(false),
    globalRunServer(false),
    log(false),
    disconnectRequest(false)
  {
  }
};


//! @brief Genetic heritage data of a given gene vector
//!
struct GenData
{
  //! @brief The epoch number for which a given gene or result value belongs
  //!
  int generation;

  //! @brief The parent/clan identifier specifying which clan a given gene
  //!        belongs to
  //!
  int parent;

  //! @brief The child number (identity) within a clan
  //!
  int identity;

  //! @brief The score assigned to a given child/result value
  //!
  double score;

  //! @brief Default constructor
  //!
  GenData () :
    generation(0),
    parent(0),
    identity(0),
    score(0.0)
  {
  }
};


struct matrix
{
  double **data;
  
  int rows;

  int cols;

  matrix ()
  {
    rows = cols = 0;
    data = NULL;
  }

  ~matrix ()
  {
    int y;
    if (data != NULL)
    {
      for (y = 0; y < rows; ++y)
      {
        delete [] data[y];
      }
      delete [] data;
    }
  }

  matrix (int r, int c)
  {
    int y, x;
    rows = r;
    cols = c;

    data = new double*[rows];
    for (y = 0; y < rows; ++y)
    {
      data[y] = new double[cols];
      for (x = 0; x < cols; ++x)
      {
        data[y][x] = 0.0f;
      }
    }
  }

  void resize (int r, int c)
  {
    int x, y;
    if (data != NULL)
    {
      for (y = 0; y < rows; ++y) 
      {
        delete [] data[y];
      }
      delete [] data;
    }

    rows = r;
    cols = c;
    data = new double*[rows];
    for (y = 0; y < rows; ++y)
    {
      data[y] = new double[cols];
      for (x = 0; x < cols; ++x)
      {
        data[y][x] = 0.0f;
      }
    }
  }

  double& at(int row, int col)
  {
    return data[row][col];
  }
};


//! @brief Gene definition for the Genetic Algorithms implementation
//!
struct GAGene
{
  //! @brief Whether or not this gene is COMPLETELY immune to mutation
  //!
  bool readOnly;

  //! @brief The number of elements in the search parameter vector
  //!
  const int params;

  //! @brief The search parameter vector that is mutated and optimized
  //!
  double searchParam[GAPARAMCOUNT];

  //! @brief Parameter vector version number.  Versions are not forwards- or
  //!        backwards-compatible due to the RAPID code having to be modified
  //!        to accommodate more or fewer elements being sent in the GSI XML
  //!        strings.
  //!
  int version;

  //! @brief TODO
  //!
  double score;

  //! @brief Generic constructor
  //!
  GAGene () :
    params(GAPARAMCOUNT),
    version(GAGENEVERSION)
  {
    score = 0.0;
    readOnly = false;
  };

  //! @brief Copy constructor
  //!
  //! @param g An existing gene value that will be used to initialize the
  //!          new gene.
  //!
  GAGene (const GAGene &g) :
    params(g.params),
    readOnly(g.readOnly),
    version(g.version)
  {
    int i;
    for (i = 0; i < params; ++i)
    {
      searchParam[i] = g.searchParam[i];
    }
  };

  //! @brief Default destructor
  //!
  ~GAGene ()
  {
  }

  //! @brief Gene assignment function
  //!
  //! @param source An existing gene value that will be used to 
  //!               populate this gene instance
  //!
  GAGene & operator=(const GAGene &source)
  {
    if (this != &source)
    {
      version = source.version;
      readOnly = source.readOnly;
      score = source.score;
      for (int x = 0; x < params; ++x)
      {
        searchParam[x] = source.searchParam[x];
      }
    }
    return *this;
  }
};


//! @brief Results of the application process
//!
struct LIBRARY_API GAResult
{
  //! @brief Generalized functional output (for simulators and
  //!        undefined/generalized outputs)
  //!
  double output;

  //! @brief The actual output of the function (without noise)
  //!
  double actual;

  //! @brief How much weight the output should have in the fitness function
  //!
  double outWeight;

  //! @brief The standard deviation of multiple iterations of a single gene
  //!        being executed
  //!
  double outStdev;

  //! @brief The length of time a given stage took to complete
  //!
  double time;

  //! @brief The force value associated with the stage
  //!
  double force;

  //! @brief The distance traveled by the robot during the attempt
  //!        (Intermediate scoring metric)
  double distance;

  //! @brief How much weight the time should have in the fitness function
  //!
  double timeWeight;

  //! @brief How much weight the force value should have in the fitness
  //!        function
  //!
  double forceWeight;

  //! @brief The standard deviation of multiple iterations of a single gene
  //!        being executed
  //!
  double timeStdev;

  //! @brief Generic constructor
  //!
  GAResult ()
  {
    time = 0.0f;
    force = 0.0f;
    timeStdev = 0.0f;
    distance = 0.0f;
    output = 0.0f;
    actual = 0.0f;
    outStdev = 0.0f;

    outWeight = defaultOutWeight;
    timeWeight = defaultTimeWeight;
    forceWeight = defaultForceWeight;
  };

  //! @brief Assignment constructor
  //!
  //! @param t Recorded time value to be assigned to the results
  //! @param f Recorded force value to be assigned to the results
  //!
  GAResult (double t, double f)
  {
    time = t;
    force = f;

    timeWeight = defaultTimeWeight;
    forceWeight = defaultForceWeight;
  }

  //! @brief Assignment constructor
  //!
  //! @param t Recorded output value to be assigned to the results
  //!
  GAResult (double o)
  {
    output = o;
    outWeight = 1.0f;
  }

  //! @brief Generic destructor
  //!
  ~GAResult ()
  {
  }

  //! @brief Assignment operator
  //!
  //! @param source An existing result structure that will be used to
  //!               populate this structure instance
  //!
  GAResult & operator=(const GAResult &source)
  {
    if (this != &source)
    {
      time = source.time;
      force = source.force;
      output = source.output;
      distance = source.distance;
      outStdev = source.outStdev;
      timeStdev = source.timeStdev;
      outWeight = source.outWeight;
      timeWeight = source.timeWeight;
      forceWeight = source.forceWeight;
    }
    return *this;
  }

  //! @brief Addition operator used to combine two result values
  //!
  //! @param source An existing result structure that will be added to
  //!               the current results for analysis
  //!
  GAResult & operator+=(const GAResult &source)
  {
    if (this != &source)
    {
      time += source.time;
      force += source.force;
      output += source.output;
      distance += source.distance;
    }
    return *this;
  }

  //! @brief Division-gets operator used to scale this result value
  //!
  //! @param div The divisor by which the time and force values are modified
  //!
  //! @note Currently used for averaging data
  //!
  GAResult & operator/=(const double div)
  {
    time /= div;
    force /= div;
    output /= div;
    distance /= div;

    return *this;
  }
};


//! @brief Inter-process shared communicator structure
//!
//! @note In the context of the ABB genetic algorithm assembly optimization
//!       project, we have to communicate with the robot via the GSI.  The
//!       communication process is threaded since the GSI is constantly
//!       polling the PC for new updates.  As such, we must have the GA
//!       running in its own thread and must therefore have a means of
//!       passing messages between the two threads via a common interface.
//!
struct GAComm
{
  //! @brief TODO
  //!
  bool readyFlag;

  //! @brief TODO
  //!
  bool reset;

  //! @brief Connection status
  //!
  //! 0 = disconnected
  //! 1 = connected (idle)
  //! 2 = connected (active)
  //!
  int connStatus;

  //! @brief Status indicator value specifying the current average assembly
  //!        time for a given gene sequence
  //!
  double curTimeAvg;

  //! @brief Status indicator value specifying the current standard deviation
  //!        of the gene sequence's sample assembly times
  //!
  double curTimeStdev;

  //! @brief Status indicator value specifying the current average output for
  //!        a given gene sequence
  //!
  double curOutAvg;

  //! @brief Status indicator value specifying the current standard deviation
  //!        of the gene sequence's sample outputs
  //!
  double curOutStdev;

  //! @brief Status indicator for the current iteration number
  //!
  int curIter;

  //! @brief TODO
  //!
  HANDLE commMutex;

  //! @brief Handle pointer to the current gene sequence that is to be run
  //!        by the robot controller
  //!
  GAGene *genePtr;

  //! @brief Handle pointer to the result structure that is used by the main
  //!        application to populate the interface's learning vectors
  //!
  GAResult *resultPtr;

  //! @brief Default cosntructor
  //!
  GAComm ()
  {
    readyFlag = false;
    reset = false;
    genePtr = NULL;
    resultPtr = NULL;
    curIter = 0;
    curTimeAvg = 0.0f;
    curTimeStdev = 0.0f;
    curOutAvg = 0.0f;
    curOutStdev = 0.0f;

    commMutex = CreateMutex (NULL, false, NULL);
  };

  //! @brief Default destructor
  //!
  ~GAComm ()
  {
    readyFlag = false;
    reset = false;
    genePtr = NULL;
    resultPtr = NULL;
  };
};


//! @brief CRCL parameter space
//!
struct CRCLProgramParams
{
  //! TODO:  Populate with CRCL program parameters

};


#endif