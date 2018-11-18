#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/MissionScript.c"
#endif

#ifndef MISSION_Script_WORKER
#define MISSION_Script_WORKER



static TStringArray WorkingZombieClasses()
{
    return { "ZmbM_HermitSkinny_Base","ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green",
             "ZmbM_HermitSkinny_Red","ZmbM_FarmerFat_Base","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown",
             "ZmbM_FarmerFat_Green","ZmbF_CitizenANormal_Base","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Brown",
             "ZmbF_CitizenANormal_Blue","ZmbM_CitizenASkinny_Base","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown",
             "ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Base","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Red",
             "ZmbM_CitizenBFat_Green","ZmbF_CitizenBSkinny_Base","ZmbF_CitizenBSkinny","ZmbM_PrisonerSkinny_Base","ZmbM_PrisonerSkinny",
             "ZmbM_FirefighterNormal_Base","ZmbM_FirefighterNormal","ZmbM_FishermanOld_Base","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green",
             "ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_JournalistSkinny_Base","ZmbM_JournalistSkinny","ZmbF_JournalistNormal_Base",
             "ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White",
             "ZmbM_ParamedicNormal_Base","ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red",
             "ZmbM_ParamedicNormal_Black","ZmbF_ParamedicNormal_Base","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green",
             "ZmbF_ParamedicNormal_Red","ZmbM_HikerSkinny_Base","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow",
             "ZmbF_HikerSkinny_Base","ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Red",
             "ZmbM_HunterOld_Base","ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter",
             "ZmbF_SurvivorNormal_Base","ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red",
             "ZmbF_SurvivorNormal_White","ZmbM_SurvivorDean_Base","ZmbM_SurvivorDean_Black","ZmbM_SurvivorDean_Blue","ZmbM_SurvivorDean_Grey",
             "ZmbM_PolicemanFat_Base","ZmbM_PolicemanFat","ZmbF_PoliceWomanNormal_Base","ZmbF_PoliceWomanNormal","ZmbM_PolicemanSpecForce_Base",
             "ZmbM_PolicemanSpecForce","ZmbM_SoldierNormal_Base","ZmbM_SoldierNormal","ZmbM_usSoldier_normal_Base",
             "ZmbM_usSoldier_normal_Woodland","ZmbM_usSoldier_normal_Desert","ZmbM_CommercialPilotOld_Base","ZmbM_CommercialPilotOld_Blue",
             "ZmbM_CommercialPilotOld_Olive","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey","ZmbM_PatrolNormal_Base",
             "ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_Summer","ZmbM_JoggerSkinny_Base",
             "ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbF_JoggerSkinny_Base","ZmbF_JoggerSkinny_Blue",
             "ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbM_MotobikerFat_Base","ZmbM_MotobikerFat_Beige",
             "ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_VillagerOld_Base","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green",
             "ZmbM_VillagerOld_White","ZmbM_SkaterYoung_Base","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green",
             "ZmbM_SkaterYoung_Grey","ZmbF_SkaterYoung_Base","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet",
             "ZmbF_DoctorSkinny_Base","ZmbF_DoctorSkinny","ZmbF_BlueCollarFat_Base","ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green",
             "ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_MechanicNormal_Base","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green",
             "ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbM_MechanicSkinny_Base","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Grey",
             "ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Red","ZmbM_ConstrWorkerNormal_Base","ZmbM_ConstrWorkerNormal_Beige",
             "ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey","ZmbM_HeavyIndustryWorker_Base",
             "ZmbM_HeavyIndustryWorker","ZmbM_OffshoreWorker_Base","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red",
             "ZmbM_OffshoreWorker_Yellow","ZmbF_NurseFat_Base","ZmbF_NurseFat","ZmbM_HandymanNormal_Base","ZmbM_HandymanNormal_Beige",
             "ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White","ZmbM_DoctorFat_Base",
             "ZmbM_DoctorFat","ZmbM_Jacket_Base","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks",
             "ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes",
             "ZmbF_PatientOld_Base","ZmbF_PatientOld","ZmbM_PatientSkinny_Base","ZmbM_PatientSkinny","ZmbF_ShortSkirt_Base","ZmbF_ShortSkirt_beige",
             "ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_checks",
             "ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow","ZmbF_VillagerOld_Base",
             "ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_Soldier","ZmbM_SoldierAlice",
             "ZmbM_SoldierHelmet","ZmbM_SoldierVest","ZmbM_SoldierAliceHelmet","ZmbM_SoldierVestHelmet","ZmbF_MilkMaidOld_Base",
             "ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey","ZmbM_priestPopSkinny_Base",
             "ZmbM_priestPopSkinny","ZmbM_ClerkFat_Base","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White",
             "ZmbF_Clerk_Normal_Base","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_White","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red" };
}
static TStringArray BuildingClasses()
{
    return { "Land_BusStation_wall_bench"};
}
class ControlMissionScriptThread : MissionScriptThread
{
	Building building;
	int number = 0 ;

	override void Tick() {
		super.Tick();
		//Print("Check Zombies");
		CheckZombies();
		//Print("Where The Magic Happens");
	}
	void CheckZombies()
	{
		/*
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		foreach (EntityAI zombie : this.GetMissionShared().zombies)
		{
			if (zombie&&!zombie.IsAlive())
			{
				this.GetMissionShared().counter.zombieKills++;

				this.GetMissionShared().zombies.RemoveItem(zombie);

				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 60000, false, zombie); // adds call 'obj.Hello(65, "world")' into queue, and it will be executed once after 5s
																														//	GetGame().ObjectDelete(zombie);
				if (this.GetMissionShared().counter.zombieKills % (10 * players.Count()) == 0)
				{
					this.GetMissionShared().counter.zombieKills = 0;
					HealAllPlayers();
				}
			}
		}
		
			//Print("Spawn Zombies");
		SpawnZombies();
		*/
	}
	void AddLoot(EntityAI zed) {
		int number = Math.RandomIntInclusive(0,4);
		switch(number) {
			case 1: 
			GameInventory inventory = zed.GetInventory();
			inventory.CreateEntityInCargo( "Mag_STANAGCoupled_30Rnd" );
			break;
		}
	}
	void SpawnZombies()
	{
		/*while(this.GetMissionShared().zombies.Count()<1) {
			//Print("Spawning Zombie");
			//Print(this.GetMissionShared().zombies.Count());
			float randX = Math.RandomFloatInclusive(-250,250);
			float randZ = Math.RandomFloatInclusive(-250,250);
			vector pos =  "13406 6 6172";
			pos[0]=pos[0]+randX;
			pos[2]=pos[2]+randZ;
			EntityAI zed = EntityAI.Cast(GetGame().CreateObject( WorkingZombieClasses().GetRandomElement(), pos, false, true ));
			
			if(zed) {
				zed.CreateAndInitInventory();
				AddLoot(zed);
				this.GetMissionShared().zombies.Insert(zed);
			}
			Sleep(10);
		}*/
	}
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		return;
		switch(rpc_type)
			{
				case MRPCs.RPC_CLIENT_INTERACT:
				PlayerBase pTarget = PlayerBase.Cast(target);
				//pTarget.SetPosition("1800 128 3000");
				Print("[RPC] Mission Script Called");
				Print("BUILD");
				//Print(GetGame().GetPlayer());
				if(building) {
					building.Explode();
				}
				
				int count = BuildingClasses().Count();
				Print("BUILDING COUNT");
				Print(count);
				while (number < count) {
					vector last_location ="0 0 0";
					vector lastBoundsMin, lastBoundsMax;
					for(int i = 0; i < 10; i++) {
						
						vector forward_vec = pTarget.GetDirection()* (35.5 * (number+i));
						building = Building.Cast(GetGame().CreateObject( BuildingClasses().Get(number), pTarget.GetPosition() , false, true ));
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 30000, false,building);
						
						vector v = pTarget.GetOrientation();
						//v[0]=v[0]+ 45;
						v[1]= v[1]+10;
						v[2]= v[2] + 90;
						vector boundsMin,boundsMax;
						building.SetOrientation(v);
						building.GetWorldBounds(boundsMin,boundsMax);
						if(i != 0) {
							Print(lastBoundsMax);
							Print(last_location);
							Print( (lastBoundsMax-last_location));
							building.SetPosition(last_location+ (building.GetDirection()*1.5));
							//building.AddChild(target, 1);
							target.SetPosition("13253 8 6304");
							
						} else {
						}
						vector orientation  =building.GetOrientation();
							building.SetOrientation("0 0 0");
						building.SetOrientation(orientation);
						last_location = building.GetPosition();
						lastBoundsMin = boundsMin;
						lastBoundsMax = boundsMax;
					} 
					number = number+1;
				}
				number = 0;

			}
	}
	void HealAllPlayers()
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);

		for (int i = 0; i < players.Count(); ++i)
		{

			PlayerBase player = PlayerBase.Cast(players.Get(i));
			if (player && player.IsAlive() && !player.IsUnconscious())
			{
				player.SetStamina(1000, 1000);
				player.GetStatStamina().Set(1000);
				player.GetStatEnergy().Set(1000);
				player.GetStatWater().Set(1000);
				player.GetStatStomachVolume().Set(300);
                player.GetStatStomachWater().Set(300);
                player.GetStatStomachEnergy().Set(300);
				player.GetStatHeatComfort().Set(0);
				int maxShock = player.GetMaxHealth("GlobalHealth", "Shock");
				int maxBlood = player.GetMaxHealth("GlobalHealth", "Blood");
				int maxHealth = player.GetMaxHealth("GlobalHealth", "Health");
				player.AddHealth("GlobalHealth", "Shock", maxShock / 4);
				player.AddHealth("GlobalHealth", "Blood", maxBlood / 4);
				player.AddHealth("GlobalHealth", "Health", maxHealth / 4);
				if (player.GetBleedingManagerServer())
				{
					player.GetBleedingManagerServer().RemoveAnyBleedingSource();
				}
				player.AddHealth(25);
				player.MessageStatus("Magic Happend");
				EntityAI oWeapon = player.GetHumanInventory().GetEntityInHands();

				if (oWeapon)
				{
					Weapon_Base weapon = Weapon_Base.Cast(oWeapon);

					Magazine oMag = (Magazine)oWeapon.GetAttachmentByConfigTypeName("DefaultMagazine");

					if (oMag && oMag.IsMagazine())
					{
						oMag.ServerSetAmmoMax();
					}

					Object oSupressor = (Object)oWeapon.GetAttachmentByConfigTypeName("SuppressorBase");

					if (oSupressor)
					{
						oSupressor.SetHealth(oSupressor.GetMaxHealth("", ""));
					}
				}
			}
		}
	}
}
;
static ref MissionScriptThread mod_missionScript;
void  CreateMissionScript(Param2<ScriptModule,string> data)
{
	mod_missionScript = new ControlMissionScriptThread;
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