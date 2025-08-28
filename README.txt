========================================================================
			FIRST OPTION
========================================================================
Configuration process for running SFML
In all generated x64, intermediate -> debug,releases -> necessary to add
it all by hand. Files are named as below. 
- sfml-system-d-3.dll
- sfml-graphics-d-3.dll
- sfml-window-d-3.dll

for debug -> input in that order (also to be set in the properties vs):
(in properties -> Linker -> input file):
- sfml-system-d-3.dll
- sfml-graphics-d-3.dll
- sfml-window-d-3.dll

for releases -> input in that order(also to be set in the properties vs)
(in properties -> Linker -> input file):
- sfml-system-3.dll
- sfml-graphics-3.dll
- sfml-window-3.dll

Files can be found in BIN, downloaded from official SFML page.
lib and include directories should be added to the following:

Project -> Properties -> C/C++ -> Additional headers: 
$(SolutionDir)\External\SFML_3_0_0\include

Project -> Properties -> Linker -> Additional lib files:
$(SolutionDir)\External\SFML_3_0_0\lib

========================================================================


========================================================================
			SECOND OPTION
========================================================================

Configuration process for running SFML
To make vs automatically copy the necessary dll for debug and releases
follow the instruction:

Project -> Properties -> Build events -> Post-build events -> command line
Switch to debug config only and paste:
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-system-d-3.dll" "$(TargetDir)"
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-graphics-d-3.dll" "$(TargetDir)"
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-window-d-3.dll" "$(TargetDir)"

Switch to release config only and paste:
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-system-3.dll" "$(TargetDir)"
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-graphics-3.dll" "$(TargetDir)"
xcopy /y /d "$(SolutionDir)External\SFML_3_0_0\bin\sfml-window-3.dll" "$(TargetDir)"


for debug -> input in that order
(in properties -> Linker -> input file):
- sfml-system-d-3.dll
- sfml-graphics-d-3.dll
- sfml-window-d-3.dll

for releases -> input in that order 
(in properties -> Linker -> input file):
- sfml-system-3.dll
- sfml-graphics-3.dll
- sfml-window-3.dll

Files can be found in BIN, downloaded from official SFML page.
In the project they are located in 
External
- SFML_3_0_0
 - bin

lib and include directories should be added to the following:

Project -> Properties -> C/C++ -> Additional headers: 
$(SolutionDir)\External\SFML_3_0_0\include

Project -> Properties -> Linker -> Additional lib files:
$(SolutionDir)\External\SFML_3_0_0\lib



========================================================================




Lower part was generated automatically by vs studio. (v. 2022).


========================================================================
    C++/WinRT AutonomousMiniSim_Project Project Overview
========================================================================

This project demonstrates how to get started consuming Windows Runtime 
classes directly from standard C++, using platform projection headers
generated from Windows SDK metadata files.

Steps to generate and consume SDK platform projection:
1. Build project initially to generate platform projection headers into
    your Generated Files folder.
2. Include a projection namespace header in your pch.h, such as 
    <winrt/Windows.Foundation.h>.
3. Consume winrt namespace and any Windows Runtime namespaces, such as 
    winrt::Windows::Foundation, from source code.
4. Initialize apartment via init_apartment() and consume winrt classes.

Steps to generate and consume a projection from third party metadata:
1. Add a WinMD reference by right-clicking the References project node
    and selecting "Add Reference...".  In the Add References dialog, 
    browse to the component WinMD you want to consume and add it.
2. Build the project once to generate projection headers for the 
    referenced WinMD file under the "Generated Files" subfolder.
3. As above, include projection headers in pch or source code 
    to consume projected Windows Runtime classes.

========================================================================
Learn more about C++/WinRT here:
http://aka.ms/cppwinrt/
========================================================================



