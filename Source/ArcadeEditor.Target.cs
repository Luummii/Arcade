using UnrealBuildTool;
using System.Collections.Generic;

public class ArcadeEditorTarget : TargetRules
{
	public ArcadeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Arcade" } );
	}
}
