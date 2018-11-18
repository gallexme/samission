#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif

#ifndef COMMAND_Horde
#define COMMAND_Horde

class HordeCommandScriptThread : CommandScriptThread
{
    static TStringArray WorkingZombieClasses()
{
       return { "ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green",
             "ZmbM_HermitSkinny_Red","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown",
             "ZmbM_FarmerFat_Green","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Brown",
             "ZmbF_CitizenANormal_Blue","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown",
             "ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Red",
             "ZmbM_CitizenBFat_Green","ZmbF_CitizenBSkinny","ZmbM_PrisonerSkinny",
             "ZmbM_FirefighterNormal","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green",
             "ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_JournalistSkinny",
             "ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White",
             "ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red",
             "ZmbM_ParamedicNormal_Black","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green",
             "ZmbF_ParamedicNormal_Red","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow",
             "ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Red",
             "ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter",
             "ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red",
             "ZmbF_SurvivorNormal_White","ZmbM_SurvivorDean_Black","ZmbM_SurvivorDean_Blue","ZmbM_SurvivorDean_Grey",
             "ZmbM_PolicemanFat","ZmbF_PoliceWomanNormal",
             "ZmbM_PolicemanSpecForce","ZmbM_SoldierNormal",
             "ZmbM_usSoldier_normal_Woodland","ZmbM_usSoldier_normal_Desert","ZmbM_CommercialPilotOld_Blue",
             "ZmbM_CommercialPilotOld_Olive","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey",
             "ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_Summer",
             "ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbF_JoggerSkinny_Blue",
             "ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbM_MotobikerFat_Beige",
             "ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green",
             "ZmbM_VillagerOld_White","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green",
             "ZmbM_SkaterYoung_Grey","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet",
             "ZmbF_DoctorSkinny","ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green",
             "ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green",
             "ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Grey",
             "ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Red","ZmbM_ConstrWorkerNormal_Beige",
             "ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey",
             "ZmbM_HeavyIndustryWorker","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red",
             "ZmbM_OffshoreWorker_Yellow","ZmbF_NurseFat","ZmbM_HandymanNormal_Beige",
             "ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White",
             "ZmbM_DoctorFat","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks",
             "ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes",
             "ZmbF_PatientOld","ZmbM_PatientSkinny","ZmbF_ShortSkirt_beige",
             "ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_checks",
             "ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow",
             "ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_Soldier","ZmbM_SoldierAlice",
             "ZmbM_SoldierHelmet","ZmbM_SoldierVest","ZmbM_SoldierAliceHelmet","ZmbM_SoldierVestHelmet",
             "ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey",
             "ZmbM_priestPopSkinny","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White",
             "ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_White","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red" };
}
	
    override void OnCommand(CommandContext ctx) {
        switch(ctx.params[0]) {
            case "/horde":
                HordeCommand(ctx);          
            break;
        }
       
    }

    void HordeCommand(CommandContext ctx) {
      
			
        if (canExec(ctx,{"Admin"})) {
            for(int i = 0; i <  ctx.params[3].ToInt(); i++) {
                vector pos;
                pos[0] = ctx.params[1].ToFloat();
                pos[2] = ctx.params[2].ToFloat();
                    Print(pos);
                float randX = Math.RandomFloatInclusive(-7,7);
                float randZ = Math.RandomFloatInclusive(-7,7);
                pos[0]=pos[0]+randX;
                pos[2]=pos[2]+randZ;
                Print(pos);
                EntityAI zed = EntityAI.Cast(GetGame().CreateObject( WorkingZombieClasses().GetRandomElement(), pos, false, true ));
		
            }
        }
    }

}
;
static ref CommandScriptThread mod_commandScript;
void  CreateCommandScript(Param2<ScriptModule,string> data)
{
    mod_commandScript = new HordeCommandScriptThread;
    mod_commandScript.Init(data.param1);
    mod_commandScript.SetName(data.param2);
    mod_commandScript.StartScript();
}
void StopCommandScript()
{
    mod_commandScript.StopScript();
}
void OnCommand(Param1<CommandContext> commandCtx)
{
    mod_commandScript.OnCommand(commandCtx.param1);
}
#endif