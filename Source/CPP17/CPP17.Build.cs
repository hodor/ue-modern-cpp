// Copyright 2024 Rogerio Gasi

using System.IO;
using UnrealBuildTool;

public class CPP17 : ModuleRules
{
	public CPP17(ReadOnlyTargetRules Target) : base(Target)
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
				"CPP11"
            }
			);
	}
}
