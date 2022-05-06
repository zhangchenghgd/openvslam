
if(MSVC)
    add_definitions(-DOPENVSLAM_TEST_HELPER_DLL_EXPORT)
endif()

# Create test helper library
add_library(test_helper
            helper_exports.h
            bearing_vector.h
            keypoint.h
            landmark.h
            bearing_vector.cc
            keypoint.cc
            landmark.cc)

# Add include directory as PUBLIC (because the headers are included in test codes)
target_include_directories(test_helper
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/test
                           ${PROJECT_SOURCE_DIR}/src)

# Link to required libraries
target_link_libraries(test_helper
                      PUBLIC
                      Eigen3::Eigen
                      opencv_core)

set_target_properties(test_helper PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/output/bin
                      ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/output/lib
                      LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/output/lib)