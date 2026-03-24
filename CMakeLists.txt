cmake_minimum_required(VERSION 3.14)
project(StraightSkel VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

if(MSVC)
    add_compile_definitions(_USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS)
endif()

# create config.h
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(DEBUG ON)
endif()
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in
               ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h)


# util
add_library(skelutil STATIC
        src/util/StringFactory.cpp
        src/util/StringFuncs.cpp
        src/util/StackTrace.cpp
        src/util/Configuration.cpp
        src/util/Timer.cpp)
target_include_directories(skelutil PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)


# kernel
add_library(skelkernel STATIC
        src/kernel/Point2.cpp
        src/kernel/Vector2.cpp
        src/kernel/Line2.cpp
        src/kernel/Segment2.cpp
        src/kernel/Ray2.cpp
        src/kernel/Point3.cpp
        src/kernel/Vector3.cpp
        src/kernel/Line3.cpp
        src/kernel/Segment3.cpp
        src/kernel/Plane3.cpp
        src/kernel/Sphere3.cpp
        src/kernel/intersection.cpp
        src/kernel/distance.cpp
        src/kernel/bisector.cpp
        src/kernel/projection.cpp)
target_include_directories(skelkernel PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
if(UNIX)
    target_link_libraries(skelkernel PRIVATE m)
endif()


# data 2d
add_library(skeldata2d STATIC
        src/data/2d/KernelFactory.cpp
        src/data/2d/Vertex.cpp
        src/data/2d/VertexData.cpp
        src/data/2d/Edge.cpp
        src/data/2d/EdgeData.cpp
        src/data/2d/Polygon.cpp
        src/data/2d/skel/StraightSkeleton.cpp
        src/data/2d/skel/Node.cpp
        src/data/2d/skel/Arc.cpp
        src/data/2d/skel/AbstractEvent.cpp
        src/data/2d/skel/ConstOffsetEvent.cpp
        src/data/2d/skel/EdgeEvent.cpp
        src/data/2d/skel/SplitEvent.cpp
        src/data/2d/skel/TriangleEvent.cpp
        src/data/2d/skel/SkelVertexData.cpp
        src/data/2d/skel/SkelEdgeData.cpp
        src/data/2d/mesh/Mesh.cpp
        src/data/2d/mesh/MeshVertex.cpp
        src/data/2d/mesh/MeshCell.cpp
        src/data/2d/mesh/MeshRay.cpp
        src/data/2d/mesh/MeshEdgeData.cpp)
target_link_libraries(skeldata2d PUBLIC skelutil skelkernel)


# data 3d
add_library(skeldata3d STATIC
        src/data/3d/KernelFactory.cpp
        src/data/3d/Vertex.cpp
        src/data/3d/VertexData.cpp
        src/data/3d/Edge.cpp
        src/data/3d/EdgeData.cpp
        src/data/3d/Facet.cpp
        src/data/3d/FacetData.cpp
        src/data/3d/Triangle.cpp
        src/data/3d/Polyhedron.cpp
        src/data/3d/CircularVertex.cpp
        src/data/3d/CircularVertexData.cpp
        src/data/3d/CircularEdge.cpp
        src/data/3d/CircularEdgeData.cpp
        src/data/3d/SphericalPolygon.cpp
        src/data/3d/skel/StraightSkeleton.cpp
        src/data/3d/skel/Node.cpp
        src/data/3d/skel/Arc.cpp
        src/data/3d/skel/Sheet.cpp
        src/data/3d/skel/AbstractEvent.cpp
        src/data/3d/skel/ConstOffsetEvent.cpp
        src/data/3d/skel/SaveOffsetEvent.cpp
        src/data/3d/skel/EdgeEvent.cpp
        src/data/3d/skel/EdgeMergeEvent.cpp
        src/data/3d/skel/TriangleEvent.cpp
        src/data/3d/skel/DblEdgeMergeEvent.cpp
        src/data/3d/skel/DblTriangleEvent.cpp
        src/data/3d/skel/TetrahedronEvent.cpp
        src/data/3d/skel/VertexEvent.cpp
        src/data/3d/skel/FlipVertexEvent.cpp
        src/data/3d/skel/SurfaceEvent.cpp
        src/data/3d/skel/PolyhedronSplitEvent.cpp
        src/data/3d/skel/SplitMergeEvent.cpp
        src/data/3d/skel/EdgeSplitEvent.cpp
        src/data/3d/skel/PierceEvent.cpp
        src/data/3d/skel/SkelVertexData.cpp
        src/data/3d/skel/SkelEdgeData.cpp
        src/data/3d/skel/SkelFacetData.cpp
        src/data/3d/skel/SphericalSkeleton.cpp
        src/data/3d/skel/CircularNode.cpp
        src/data/3d/skel/CircularArc.cpp
        src/data/3d/skel/SphericalAbstractEvent.cpp
        src/data/3d/skel/SphericalConstOffsetEvent.cpp
        src/data/3d/skel/SphericalEdgeEvent.cpp
        src/data/3d/skel/SphericalSplitEvent.cpp
        src/data/3d/skel/SphericalTriangleEvent.cpp
        src/data/3d/skel/SphericalDblEdgeEvent.cpp
        src/data/3d/skel/SphericalLeaveEvent.cpp
        src/data/3d/skel/SphericalReturnEvent.cpp
        src/data/3d/skel/SphericalDblLeaveEvent.cpp
        src/data/3d/skel/SphericalDblReturnEvent.cpp
        src/data/3d/skel/SphericalVertexEvent.cpp
        src/data/3d/skel/SphericalEdgeMergeEvent.cpp
        src/data/3d/skel/SphericalInversionEvent.cpp
        src/data/3d/skel/SphericalSkelVertexData.cpp
        src/data/3d/skel/SphericalSkelEdgeData.cpp
        src/data/3d/skel/SphericalOffset.cpp)
target_link_libraries(skeldata3d PUBLIC skeldata2d)


# algo 2d
add_library(skelalgo2d STATIC
        src/algo/Controller.cpp
        src/algo/2d/KernelWrapper.cpp
        src/algo/2d/PolygonTransformation.cpp
        src/algo/2d/SimpleStraightSkel.cpp
        src/algo/2d/FastStraightSkel.cpp
        src/algo/2d/MeshModifier.cpp
        src/algo/2d/SkelMeshGenerator.cpp)
target_link_libraries(skelalgo2d PUBLIC skeldata2d)


# algo 3d
add_library(skelalgo3d STATIC
        src/algo/3d/KernelWrapper.cpp
        src/algo/3d/SimpleStraightSkel.cpp
        src/algo/3d/PolyhedronBuilder.cpp
        src/algo/3d/LineInFacet.cpp
        src/algo/3d/SelfIntersection.cpp
        src/algo/3d/AbstractVertexSplitter.cpp
        src/algo/3d/AngleVertexSplitter.cpp
        src/algo/3d/CombiVertexSplitter.cpp
        src/algo/3d/ConvexVertexSplitter.cpp
        src/algo/3d/VolumeVertexSplitter.cpp
        src/algo/3d/WeightVertexSplitter.cpp
        src/algo/3d/SphereVertexSplitter.cpp
        src/algo/3d/PolyhedronTransformation.cpp
        src/algo/3d/PolyhedronIntersection.cpp
        src/algo/3d/AbstractSimpleSphericalSkel.cpp
        src/algo/3d/ProjSimpleSphericalSkel.cpp
        src/algo/3d/RotSimpleSphericalSkel.cpp
        src/algo/3d/TransSimpleSphericalSkel.cpp
        src/algo/3d/SpeedSimpleSphericalSkel.cpp
        src/algo/3d/GraphChecker.cpp)
target_link_libraries(skelalgo3d PUBLIC skelalgo2d skeldata3d)


# convenience target for CPM consumers
add_library(StraightSkel INTERFACE)
target_link_libraries(StraightSkel INTERFACE skelalgo2d skelalgo3d)
add_library(StraightSkel::StraightSkel ALIAS StraightSkel)


# tests (optional, requires Boost)
option(BUILD_TESTS "Build unit tests (requires Boost.Test)" OFF)
if(BUILD_TESTS)
    enable_testing()
    find_package(Boost REQUIRED unit_test_framework)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(test)

    add_executable(UtilTestRunner
            test/util/UtilTestRunner.cpp
            test/util/StringFuncsTest.cpp)
    target_link_libraries(UtilTestRunner skelutil ${Boost_LIBRARIES})
    add_test(UtilTestRunner UtilTestRunner)

    add_executable(KernelTestRunner
            test/kernel/KernelTestRunner.cpp
            test/kernel/Vector2Test.cpp
            test/kernel/Point2Test.cpp
            test/kernel/Line2Test.cpp
            test/kernel/Segment2Test.cpp
            test/kernel/Vector3Test.cpp
            test/kernel/Point3Test.cpp
            test/kernel/Line3Test.cpp
            test/kernel/Segment3Test.cpp
            test/kernel/Plane3Test.cpp
            test/kernel/IntersectionTest.cpp
            test/kernel/DistanceTest.cpp
            test/kernel/BisectorTest.cpp)
    target_link_libraries(KernelTestRunner skelkernel ${Boost_LIBRARIES})
    add_test(KernelTestRunner KernelTestRunner)

    add_executable(Data2DTestRunner
            test/data/2d/Data2DTestRunner.cpp
            test/data/2d/KernelFactoryTest.cpp
            test/data/2d/VertexTest.cpp
            test/data/2d/EdgeTest.cpp
            test/data/2d/PolygonTest.cpp)
    target_link_libraries(Data2DTestRunner skeldata2d ${Boost_LIBRARIES})
    add_test(Data2DTestRunner Data2DTestRunner)

    add_executable(Data3DTestRunner
            test/data/3d/Data3DTestRunner.cpp
            test/data/3d/EdgeTest.cpp
            test/data/3d/FacetTest.cpp
            test/data/3d/PolyhedronTest.cpp)
    target_link_libraries(Data3DTestRunner skeldata3d ${Boost_LIBRARIES})
    add_test(Data3DTestRunner Data3DTestRunner)

    add_executable(Algo2DTestRunner
            test/algo/2d/Algo2DTestRunner.cpp
            test/algo/2d/KernelWrapperTest.cpp)
    target_link_libraries(Algo2DTestRunner skelalgo2d ${Boost_LIBRARIES})
    add_test(Algo2DTestRunner Algo2DTestRunner)

    add_executable(Algo3DTestRunner
            test/algo/3d/Algo3DTestRunner.cpp
            test/algo/3d/KernelWrapperTest.cpp
            test/algo/3d/PolyhedronBuilderTest.cpp
            test/algo/3d/LineInFacetTest.cpp
            test/algo/3d/CombiVertexSplitterTest.cpp
            test/algo/3d/VolumeVertexSplitterTest.cpp)
    target_link_libraries(Algo3DTestRunner skelalgo3d ${Boost_LIBRARIES})
    add_test(Algo3DTestRunner Algo3DTestRunner)
endif()
