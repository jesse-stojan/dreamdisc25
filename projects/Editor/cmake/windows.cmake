#================================================================
# [Dream Disk 25] - Editor
# ~/projects/Editor/cmake/windows.cmake
#================================================================

if		(TARGET_WINDOWS_XP)
	#--------------------------------
	# Windows XP
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0501
	)
	add_link_options(
		/SUBSYSTEM:CONSOLE,5.01
	)
elseif	(TARGET_WINDOWS_VISTA)
	#--------------------------------
	# Windows Vista
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0600
	)
	add_link_options(
		/SUBSYSTEM:CONSOLE,6.00
	)
elseif	(TARGET_WINDOWS_7)
	#--------------------------------
	# Windows 7
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0601
	)
	add_link_options(
		/SUBSYSTEM:CONSOLE,6.01
	)
elseif	(TARGET_WINDOWS_8)
	#--------------------------------
	# Windows 8
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0602
	)
	add_link_options(
		/SUBSYSTEM:CONSOLE,6.02
	)
elseif	(TARGET_WINDOWS_8_1)
	#--------------------------------
	# Windows 8.1
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0603
	)
	add_link_options(
		/SUBSYSTEM:CONSOLE,6.03
	)
elseif	(TARGET_WINDOWS_10)
	#--------------------------------
	# Windows 10
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0A00
	)
	#TODO: Fill in for Win10 Target
elseif	(TARGET_WINDOWS_11)
	#--------------------------------
	# Windows 11
	#--------------------------------
	add_compile_definitions(
		_WIN32_WINNT=0x0A00
	)
	#TODO: Fill in for Win11 Target
else()
	#--------------------------------
	# (Unsupported)
	#--------------------------------
	# Do Nothing?
	#--------------------------------
endif()
