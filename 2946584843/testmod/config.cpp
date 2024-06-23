class CfgPatches
{
	class testmod
	{		
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
    class testmod
    {
    	type="mod";
		dir="testmod";
    	name = "test mod and example code";		
		author = "lankycraig";
		action = "https://steamcommunity.com/sharedfiles/filedetails/?id=2946584843";
    	dependencies[]={"Core","Game","World","Mission","smoptions"};
        class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"testmod/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"testmod/Scripts/5_Mission"};
			};
			
		};
	};
};