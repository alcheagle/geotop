PROJECT(utest)

IF(COMMAND CMAKE_POLICY)
	CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

ADD_EXECUTABLE(utest
	maintest.cpp
	test_input_keywords.cpp
	)

TARGET_LINK_LIBRARIES(utest
	${Boost_SYSTEM_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	${INPUT_KEYWORDS_LIBRARIES}
	)
