// Copyright 2024 Rogerio Gasi

using System.IO;
using UnrealBuildTool;

public class CPP23 : ModuleRules
{
	public CPP23(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;	
	        IWYUSupport = IWYUSupport.Full;
	        bLegacyPublicIncludePaths = false;

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        	PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

	        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"CPP11",
				"CPP17",
				"CPP20"
			});
	}
}
