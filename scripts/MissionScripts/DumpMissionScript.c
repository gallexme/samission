#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/MissionScript.c"
#endif


#ifndef MISSION_Script_DUMP
#define MISSION_Script_DUMP

class DumpMissionScriptThread : MissionScriptThread
{
    static  void	SaveLog(string log_message)
	{
		FileHandle file_index = OpenFile("$profile:classes.txt", FileMode.APPEND);
		
		if ( file_index == 0 )
		{
			return;
		}
			
		FPrintln(file_index, log_message);
		
		CloseFile(file_index);
	}
	
    /*void DumpMissionScriptThread()  {
        string cfg_name = "CfgVehicles";
		int cfg_class_count = GetGame().ConfigGetChildrenCount( cfg_name );
		
		int i, j, k, l, m;
		for ( i = 0; i < cfg_class_count; i++ )
		{
			string cfg_class_name = "";
			Print(i);
			GetGame().ConfigGetChildName( cfg_name, i, cfg_class_name );
			SaveLog(cfg_class_name);
			
		}
    }*/	
	override void Tick() {
		super.Tick();
	}
	
	

}
;
static ref MissionScriptThread mod_missionScript;
void  CreateMissionScript(Param2<ScriptModule,string> data)
{
	mod_missionScript = new DumpMissionScriptThread;
	mod_missionScript.Init(data.param1);
	mod_missionScript.SetName(data.param2);
	mod_missionScript.StartScript();
}
void StopMissionScript()
{
	mod_missionScript.StopScript();
}
void OnRPC(Param4<PlayerIdentity,Object,int,ParamsReadContext> rpc)
{
	mod_missionScript.OnRPC(rpc.param1,rpc.param2,rpc.param3,rpc.param4);
}
#endif