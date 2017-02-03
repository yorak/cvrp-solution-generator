##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=vrp_gen
ConfigurationName      :=Release
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "./cvrp_gen_cpp"
ProjectPath            := "./cvrp_gen_cpp"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jussi Rasku
Date                   :=06/03/2013
CodeLitePath           :="/home/jussi/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             :=  $(Preprocessors)
LinkOptions            :=  -O2
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/bitbangM$(ObjectSuffix) $(IntermediateDirectory)/bigint_BigUnsigned$(ObjectSuffix) $(IntermediateDirectory)/bigint_BigIntegerUtils$(ObjectSuffix) $(IntermediateDirectory)/bigint_BigUnsignedInABase$(ObjectSuffix) $(IntermediateDirectory)/bigint_BigInteger$(ObjectSuffix) $(IntermediateDirectory)/GTGen$(ObjectSuffix) $(IntermediateDirectory)/MatrixGen$(ObjectSuffix) $(IntermediateDirectory)/PermutationsGen$(ObjectSuffix) $(IntermediateDirectory)/gen_main$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/bitbangM$(ObjectSuffix): bitbangM.cpp $(IntermediateDirectory)/bitbangM$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./bitbangM.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bitbangM$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitbangM$(DependSuffix): bitbangM.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bitbangM$(ObjectSuffix) -MF$(IntermediateDirectory)/bitbangM$(DependSuffix) -MM "./bitbangM.cpp"

$(IntermediateDirectory)/bitbangM$(PreprocessSuffix): bitbangM.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitbangM$(PreprocessSuffix) "./bitbangM.cpp"

$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(ObjectSuffix): PermutationAndConmbinationHelpers.cpp $(IntermediateDirectory)/PermutationAndConmbinationHelpers$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./PermutationAndConmbinationHelpers.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(DependSuffix): PermutationAndConmbinationHelpers.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(ObjectSuffix) -MF$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(DependSuffix) -MM "./PermutationAndConmbinationHelpers.cpp"

$(IntermediateDirectory)/PermutationAndConmbinationHelpers$(PreprocessSuffix): PermutationAndConmbinationHelpers.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PermutationAndConmbinationHelpers$(PreprocessSuffix) "./PermutationAndConmbinationHelpers.cpp"
	
$(IntermediateDirectory)/bigint_BigUnsigned$(ObjectSuffix): bigint/BigUnsigned.cc $(IntermediateDirectory)/bigint_BigUnsigned$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./bigint/BigUnsigned.cc" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bigint_BigUnsigned$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bigint_BigUnsigned$(DependSuffix): bigint/BigUnsigned.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bigint_BigUnsigned$(ObjectSuffix) -MF$(IntermediateDirectory)/bigint_BigUnsigned$(DependSuffix) -MM "./bigint/BigUnsigned.cc"

$(IntermediateDirectory)/bigint_BigUnsigned$(PreprocessSuffix): bigint/BigUnsigned.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bigint_BigUnsigned$(PreprocessSuffix) "./bigint/BigUnsigned.cc"

$(IntermediateDirectory)/bigint_BigIntegerUtils$(ObjectSuffix): bigint/BigIntegerUtils.cc $(IntermediateDirectory)/bigint_BigIntegerUtils$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./bigint/BigIntegerUtils.cc" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bigint_BigIntegerUtils$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bigint_BigIntegerUtils$(DependSuffix): bigint/BigIntegerUtils.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bigint_BigIntegerUtils$(ObjectSuffix) -MF$(IntermediateDirectory)/bigint_BigIntegerUtils$(DependSuffix) -MM "./bigint/BigIntegerUtils.cc"

$(IntermediateDirectory)/bigint_BigIntegerUtils$(PreprocessSuffix): bigint/BigIntegerUtils.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bigint_BigIntegerUtils$(PreprocessSuffix) "./bigint/BigIntegerUtils.cc"

$(IntermediateDirectory)/bigint_BigUnsignedInABase$(ObjectSuffix): bigint/BigUnsignedInABase.cc $(IntermediateDirectory)/bigint_BigUnsignedInABase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./bigint/BigUnsignedInABase.cc" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bigint_BigUnsignedInABase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bigint_BigUnsignedInABase$(DependSuffix): bigint/BigUnsignedInABase.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bigint_BigUnsignedInABase$(ObjectSuffix) -MF$(IntermediateDirectory)/bigint_BigUnsignedInABase$(DependSuffix) -MM "./bigint/BigUnsignedInABase.cc"

$(IntermediateDirectory)/bigint_BigUnsignedInABase$(PreprocessSuffix): bigint/BigUnsignedInABase.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bigint_BigUnsignedInABase$(PreprocessSuffix) "./bigint/BigUnsignedInABase.cc"

$(IntermediateDirectory)/bigint_BigInteger$(ObjectSuffix): bigint/BigInteger.cc $(IntermediateDirectory)/bigint_BigInteger$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./bigint/BigInteger.cc" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bigint_BigInteger$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bigint_BigInteger$(DependSuffix): bigint/BigInteger.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bigint_BigInteger$(ObjectSuffix) -MF$(IntermediateDirectory)/bigint_BigInteger$(DependSuffix) -MM "./bigint/BigInteger.cc"

$(IntermediateDirectory)/bigint_BigInteger$(PreprocessSuffix): bigint/BigInteger.cc
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bigint_BigInteger$(PreprocessSuffix) "./bigint/BigInteger.cc"

$(IntermediateDirectory)/GTGen$(ObjectSuffix): GTGen.cpp $(IntermediateDirectory)/GTGen$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./GTGen.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/GTGen$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GTGen$(DependSuffix): GTGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/GTGen$(ObjectSuffix) -MF$(IntermediateDirectory)/GTGen$(DependSuffix) -MM "./GTGen.cpp"

$(IntermediateDirectory)/GTGen$(PreprocessSuffix): GTGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GTGen$(PreprocessSuffix) "./GTGen.cpp"

$(IntermediateDirectory)/MatrixGen$(ObjectSuffix): MatrixGen.cpp $(IntermediateDirectory)/MatrixGen$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./MatrixGen.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MatrixGen$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MatrixGen$(DependSuffix): MatrixGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/MatrixGen$(ObjectSuffix) -MF$(IntermediateDirectory)/MatrixGen$(DependSuffix) -MM "./MatrixGen.cpp"

$(IntermediateDirectory)/MatrixGen$(PreprocessSuffix): MatrixGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MatrixGen$(PreprocessSuffix) "./MatrixGen.cpp"

$(IntermediateDirectory)/PermutationsGen$(ObjectSuffix): PermutationsGen.cpp $(IntermediateDirectory)/PermutationsGen$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./PermutationsGen.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/PermutationsGen$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PermutationsGen$(DependSuffix): PermutationsGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/PermutationsGen$(ObjectSuffix) -MF$(IntermediateDirectory)/PermutationsGen$(DependSuffix) -MM "./PermutationsGen.cpp"

$(IntermediateDirectory)/PermutationsGen$(PreprocessSuffix): PermutationsGen.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PermutationsGen$(PreprocessSuffix) "./PermutationsGen.cpp"

$(IntermediateDirectory)/gen_main$(ObjectSuffix): gen_main.cpp $(IntermediateDirectory)/gen_main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "./gen_main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gen_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gen_main$(DependSuffix): gen_main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gen_main$(ObjectSuffix) -MF$(IntermediateDirectory)/gen_main$(DependSuffix) -MM "./gen_main.cpp"

$(IntermediateDirectory)/gen_main$(PreprocessSuffix): gen_main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gen_main$(PreprocessSuffix) "./gen_main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/bitbangM$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bitbangM$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bitbangM$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PermutationAndConmbinationHelpers$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PermutationAndConmbinationHelpers$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PermutationAndConmbinationHelpers$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsigned$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsigned$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsigned$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigIntegerUtils$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigIntegerUtils$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigIntegerUtils$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsignedInABase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsignedInABase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigUnsignedInABase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigInteger$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigInteger$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bigint_BigInteger$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/GTGen$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/GTGen$(DependSuffix)
	$(RM) $(IntermediateDirectory)/GTGen$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MatrixGen$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MatrixGen$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MatrixGen$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PermutationsGen$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PermutationsGen$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PermutationsGen$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gen_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gen_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gen_main$(PreprocessSuffix)
	$(RM) $(OutputFile)


