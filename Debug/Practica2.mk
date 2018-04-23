##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Practica2
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Marc\Desktop\2ºLaSalle\Programació\P2_ls29307_ls28717\LS-PACMAN\Debug"
ProjectPath            := "C:\Users\Marc\Desktop\2ºLaSalle\Programació\P2_ls29307_ls28717\LS-PACMAN\Debug"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Marc
Date                   :=11/16/15
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Practica2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro-5.0.10-monolith-mt-debug 
ArLibs                 :=  "liballegro-5.0.10-monolith-mt-debug.a" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IntermediateDirectory)/Logica.c$(ObjectSuffix) $(IntermediateDirectory)/Tipus.c$(ObjectSuffix) $(IntermediateDirectory)/Grafics.c$(ObjectSuffix) $(IntermediateDirectory)/Menu.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix): LS_allegro.c $(IntermediateDirectory)/LS_allegro.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/LS_allegro.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LS_allegro.c$(DependSuffix): LS_allegro.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) -MF$(IntermediateDirectory)/LS_allegro.c$(DependSuffix) -MM "LS_allegro.c"

$(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix): LS_allegro.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix) "LS_allegro.c"

$(IntermediateDirectory)/Logica.c$(ObjectSuffix): Logica.c $(IntermediateDirectory)/Logica.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/Logica.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Logica.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Logica.c$(DependSuffix): Logica.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Logica.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Logica.c$(DependSuffix) -MM "Logica.c"

$(IntermediateDirectory)/Logica.c$(PreprocessSuffix): Logica.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Logica.c$(PreprocessSuffix) "Logica.c"

$(IntermediateDirectory)/Tipus.c$(ObjectSuffix): Tipus.c $(IntermediateDirectory)/Tipus.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/Tipus.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tipus.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tipus.c$(DependSuffix): Tipus.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tipus.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Tipus.c$(DependSuffix) -MM "Tipus.c"

$(IntermediateDirectory)/Tipus.c$(PreprocessSuffix): Tipus.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tipus.c$(PreprocessSuffix) "Tipus.c"

$(IntermediateDirectory)/Grafics.c$(ObjectSuffix): Grafics.c $(IntermediateDirectory)/Grafics.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/Grafics.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Grafics.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Grafics.c$(DependSuffix): Grafics.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Grafics.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Grafics.c$(DependSuffix) -MM "Grafics.c"

$(IntermediateDirectory)/Grafics.c$(PreprocessSuffix): Grafics.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Grafics.c$(PreprocessSuffix) "Grafics.c"

$(IntermediateDirectory)/Menu.c$(ObjectSuffix): Menu.c $(IntermediateDirectory)/Menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Marc/Desktop/2ºLaSalle/Programació/P2_ls29307_ls28717/LS-PACMAN/Debug/Menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Menu.c$(DependSuffix): Menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Menu.c$(DependSuffix) -MM "Menu.c"

$(IntermediateDirectory)/Menu.c$(PreprocessSuffix): Menu.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Menu.c$(PreprocessSuffix) "Menu.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/Practica2"


