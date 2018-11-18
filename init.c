
#ifdef HAS_FUN
proto native static string  HelloDayz(string test);

proto native static void RustTest(string test);
#endif

#ifdef SERVER
	#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/MissionScript.c"
	
	#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif

#ifndef MISSION_INIT
#define MISSION_INIT

void main()
{

    Hive ce = CreateHive();
    if ( ce )
        ce.InitOffline();

    Weather weather = g_Game.GetWeather();

    /*weather.GetOvercast().SetLimits( 0.0 , 2.0 );
    weather.GetRain().SetLimits( 0.0 , 2.0 );
    weather.GetFog().SetLimits( 0.0 , 2.0 );

    weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetRain().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetFog().SetForecastChangeLimits( 0.0, 0.0 );

    weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
    weather.GetRain().SetForecastTimeLimits( 600 , 600 );
    weather.GetFog().SetForecastTimeLimits( 600 , 600 );

    weather.GetOvercast().Set( 1.0, 10, 360) ;
    weather.GetRain().Set( 1.0, 10, 360 );
    weather.GetFog().Set( 1.0, 10, 360 );

    weather.SetWindMaximumSpeed( 50 );
    weather.SetWindFunctionParams( 0, 0, 1 );
    Weather weather = g_Game.GetWeather();*/

    weather.GetOvercast().SetLimits( 0.0 , 1.0 );
    weather.GetRain().SetLimits( 0.0 , 1.0 );
    weather.GetFog().SetLimits( 0.0 , 0.25 );

    weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
    weather.GetRain().SetForecastChangeLimits( 0.0, 0.1 );
    weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

    weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
    weather.GetRain().SetForecastTimeLimits( 600 , 600 );
    weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

    weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
    weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
    weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);

    weather.SetWindMaximumSpeed(15);
    weather.SetWindFunctionParams(0.1, 0.3, 50);
}
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
class TickHandler : Managed {
    CustomMission m_mission;
    void TickHandler(CustomMission mission) {
        m_mission = mission;
    }
    void SlowTick() {
        
    }
}
class CustomMission: MissionServer
{
    ref Timer						m_SlowTickTimer;
    ref TickHandler					m_TickHandler;
    ref array<ScriptModule> MissionScripts = new array<ScriptModule>;
    

    ref array<ScriptModule> CommandScripts = new array<ScriptModule>;
    int zedKillCount = 0;

    void CustomMission() {
        m_TickHandler = new TickHandler(this);
        m_SlowTickTimer = new Timer();
        m_SlowTickTimer.Run(2, m_TickHandler, "SlowTick",null, true);

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
        Print("CALL LATERT START");
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.StartMissionScripts, 1000, false,NULL);
        
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.StartCommandScripts, 1000, false,NULL);
        Print("Construct Called");
        //StartMissionScripts();

    }
    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch(rpc_type)
        {
        case MRPCs.RPC_CLIENT_INTERACT:
#ifdef HAS_FUN
            Print(HelloDayz("HELLO RUST HOW ARE YOU"));
            RustTest("HELLO RUST HOW ARE YOU");
#endif      
                                ReloadCommandScripts();
            ReloadMissionScripts();
            break;
        }
        foreach(ScriptModule missionScript: MissionScripts) {

            missionScript.Call(NULL,"OnRPC",new Param4<PlayerIdentity,Object,int,ParamsReadContext>(sender,target,rpc_type,ctx));

        }
    }
    TStringArray GetMissions() {
        string	file_name;
        int 	file_attr;
        int		flags;
        TStringArray  missionList = new TStringArray;

        string m_PathToMissions = "$CurrentDir:/mpmissions";

        string path_find_pattern = m_PathToMissions+"\\*"; //*/
        FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);

        bool found = true;
        while ( found )
        {
            if ( file_attr & FileAttr.DIRECTORY )
            {
                missionList.Insert(file_name);
            }

            found = FindNextFile(file_handler, file_name, file_attr);
        }
        return missionList;
    }
    TStringArray GetMissionScripts(string mission) {
        string	file_name;
        int 	file_attr;
        int		flags;
        TStringArray  scriptsList = new TStringArray;

        string m_PathToMissionsScripts = "$CurrentDir:/mpmissions\\"+mission+"\\scripts\\MissionScripts";

        string path_find_pattern = m_PathToMissionsScripts+"\\*.c"; //*/
        FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);

        bool found = true;
        while ( found )
        {
            if ( file_attr  )
            {
                Print("Found MissionScript: "+ file_name);
                scriptsList.Insert("$CurrentDir:/mpmissions\\"+mission+"\\scripts\\MissionScripts\\"+file_name);
            }

            found = FindNextFile(file_handler, file_name, file_attr);
        }
        return scriptsList;
    }
    TStringArray GetCommandScripts(string mission) {
        string	file_name;
        int 	file_attr;
        int		flags;
        TStringArray  scriptsList = new TStringArray;

        string m_PathToMissionsScripts = "$CurrentDir:/mpmissions\\"+mission+"\\scripts\\CommandScripts";

        string path_find_pattern = m_PathToMissionsScripts+"\\*.c"; //*/
        FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);

        bool found = true;
        while ( found )
        {
            if ( file_attr  )
            {
                Print("Found CommandScript: "+ file_name);
                scriptsList.Insert("$CurrentDir:/mpmissions\\"+mission+"\\scripts\\CommandScripts\\"+file_name);
            }

            found = FindNextFile(file_handler, file_name, file_attr);
        }
        return scriptsList;
    }
    void ReloadMissionScripts() {
        
         Print("Reloading MissionScripts");
        StopMissionScripts();
        StartMissionScripts();
         Print("Reloaded MissionScripts");
    }
  
    void StartMissionScripts() {
        
        Print("Starting MissionScripts");
        auto missions = GetMissions();
        foreach( string mission: missions ) {
            auto scripts = GetMissionScripts(mission);
            foreach(string missionScriptPath: scripts) {
                ScriptModule mod = ScriptModule.LoadScript(MissionScript,missionScriptPath,false);
                mod.CallFunction(NULL,"CreateMissionScript",NULL,new Param2<ScriptModule,string>(mod,missionScriptPath));
                MissionScripts.Insert(mod);
            }
        }
        
        Print("Started MissionScripts");
    }
    void StopMissionScripts() {
        
        Print("Stopping MissionScripts");
        foreach(ScriptModule missionScript: MissionScripts) {
            Print("Stopping MissionScript"+ missionScript);
            MissionScripts.RemoveItem(missionScript);

            missionScript.Call(NULL,"StopMissionScript",NULL);
            missionScript.Release();
        }
        
         Print("Stopped MissionScripts");
    }
    void ReloadCommandScripts() {
        
        Print("Reloading CommandScripts");
        StopCommandScripts();
        StartCommandScripts();
        
        Print("Reloaded CommandScripts");
    }
     void StartCommandScripts() {
         
        Print("Starting CommandScripts");
        auto missions = GetMissions();
        foreach( string mission: missions ) {
            auto scripts = GetCommandScripts(mission);
            foreach(string commandScriptPath: scripts) {
                ScriptModule mod = ScriptModule.LoadScript(MissionScript,commandScriptPath,false);
                mod.CallFunction(NULL,"CreateCommandScript",NULL,new Param2<ScriptModule,string>(mod,commandScriptPath));
                CommandScripts.Insert(mod);
            }
        }
        
        Print("Started CommandScripts");
    }
    void StopCommandScripts() {
        
        Print("Stopping commandScripts");
        foreach(ScriptModule commandScript: CommandScripts) {
            Print("Stopping commandScript"+ commandScript);
            CommandScripts.RemoveItem(commandScript);

            commandScript.Call(NULL,"StopCommandScript",NULL);
            commandScript.Release();
        }
        
        Print("Stopped COmmandScripts");
    }

    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt;
        playerEnt = GetGame().CreatePlayer(identity, characterName, "13406 6 6172", 250, "NONE");//Creates random player
        Class.CastTo(m_player, playerEnt);

        GetGame().SelectPlayer(identity, m_player);

        return m_player;
    }
    void CreateDefaultCharacter(PlayerBase oPlayer)
    {




    }

    static Weapon_Base CreateWeapon(PlayerBase oPlayer)
    {
        Weapon_Base oWpn = Weapon_Base.Cast(oPlayer.GetHumanInventory().CreateInHands( "M4A1_Black" ));
        oWpn.GetInventory().CreateAttachment( "M4_Suppressor" );
        oWpn.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" );
        oWpn.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
        oWpn.GetInventory().CreateAttachment( "ACOGOptic" );

        Magazine oMag = Magazine.Cast(oPlayer.GetHumanInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" ));


        return oWpn;
    }
    void HealAllPlayers() {
        ref array<Man> players = new array<Man>;
        GetGame().GetPlayers( players );


        for ( int i = 0; i < players.Count(); ++i )
        {

            PlayerBase player = PlayerBase.Cast(players.Get(i));
            if(player) {
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
                player.AddHealth("GlobalHealth","Shock",maxShock/4);
                player.AddHealth("GlobalHealth","Blood",maxBlood/4);
                player.AddHealth("GlobalHealth","Health",maxHealth/4);
                if (player.GetBleedingManagerServer() )
                {
                    player.GetBleedingManagerServer().RemoveAnyBleedingSource();
                }
                player.AddHealth(25);
                player.MessageStatus("Magic Happend");
                EntityAI oWeapon = player.GetHumanInventory().GetEntityInHands();

                if( oWeapon )
                {
                    Weapon_Base weapon = Weapon_Base.Cast(oWeapon);


                    Magazine oMag = ( Magazine ) oWeapon.GetAttachmentByConfigTypeName( "DefaultMagazine" );

                    if( oMag && oMag.IsMagazine() )
                    {
                        oMag.ServerSetAmmoMax();
                    }

                    Object oSupressor = ( Object ) oWeapon.GetAttachmentByConfigTypeName( "SuppressorBase" );

                    if( oSupressor )
                    {
                        oSupressor.SetHealth( oSupressor.GetMaxHealth( "", "" ) );
                    }
                }
            }

        }
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
    }
    override void EquipCharacter()
    {
        EntityAI item = m_player.GetInventory().CreateInInventory( "AviatorGlasses" );
        item = m_player.GetInventory().CreateInInventory( "MilitaryBeret_UN" );
        item = m_player.GetInventory().CreateInInventory( "M65Jacket_Black" );
        item = m_player.GetInventory().CreateInInventory( "PlateCarrierHolster" );
        item = m_player.GetInventory().CreateInInventory( "TacticalGloves_Black" );
        item = m_player.GetInventory().CreateInInventory( "HunterPants_Autumn" );
        item = m_player.GetInventory().CreateInInventory( "MilitaryBoots_Black" );
        item = m_player.GetInventory().CreateInInventory( "AliceBag_Camo" );

        Magazine oMag1 =  m_player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" );
        Magazine oMag2 = m_player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" );

        Magazine oMag3 = m_player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" );
        m_player.SetQuickBarEntityShortcut( oMag1, 1, true );
        m_player.SetQuickBarEntityShortcut( oMag2, 2, true );

        m_player.SetQuickBarEntityShortcut( oMag3, 3, true );


        Weapon_Base oWpn = CreateWeapon(m_player);
        m_player.SetQuickBarEntityShortcut( oWpn, 0, true );


    }
    // void AddLoot(EntityAI zed) {
    // 	// int number = Math.RandomIntInclusive(0,4);
    // 	// switch(number) {
    // 	// 	case 1:
    // 	// 	GameInventory inventory = zed.GetInventory();
    // 	// 	inventory.CreateEntityInCargo( "Mag_STANAGCoupled_30Rnd" );
    // 	// 	break;
    // 	// }
    // }
    void SpawnZombies() {


        // foreach(EntityAI zombie : m_SharedData.zombies)
        // {
        // 	zombie.SetHealth( 0);
        // 	m_SharedData.zombies.RemoveItem(zombie);
        // 	GetGame().ObjectDelete(zombie);
        // }

        // while(m_SharedData.zombies.Count() < 750)
        // {
        // 	float randX = Math.RandomFloatInclusive(-250,250);
        // 	float randZ = Math.RandomFloatInclusive(-250,250);
        // 	vector pos =  "13406 6 6172";
        // 	pos[0]=pos[0]+randX;
        // 	pos[2]=pos[2]+randZ;
        // 	EntityAI zed = EntityAI.Cast(GetGame().CreateObject( WorkingZombieClasses().GetRandomElement(), pos, false, true ));
        // 	if(zed) {

        // 		zed.CreateAndInitInventory();
        // 		AddLoot(zed);
        // 		m_SharedData.zombies.Insert(zed);
        // 	}
        // }

    }

    
    override void OnEvent(EventType eventTypeId, Param params)
    {

        JsonSerializer js = new JsonSerializer();
        switch(eventTypeId)
        {
        case ChatMessageEventTypeID:
            string textOut;
            js.WriteToString( this, true, textOut);
            Print(textOut);
            textOut = "";
            ChatMessageEventParams chat_params = ChatMessageEventParams.Cast( params );
            if(!chat_params.param3.Contains("/")) {
                return;
            }
            Print("Channel: "+chat_params.param1+" From: "+chat_params.param2+ " Message: "+chat_params.param3+ " Color: "+chat_params.param4);
            ref array<Man> players = new array<Man>;
            GetGame().GetPlayers( players );

            
            for ( int i = 0; i < players.Count(); ++i )
            {

                Man player = players.Get(i);
                PlayerIdentity identity = player.GetIdentity();

                if( identity )
                {
                    if( player )
                    {  
                        
                        Print("Player: "+identity.GetName());
                        if(identity.GetName() == chat_params.param2) {
                            Print("Player Found: "+identity.GetName());
                            Print("Command: "+chat_params.param3);

                            switch(chat_params.param3) {
                            case "/suicide":
                                Print("SUICIDE");
                                player.SetHealth( 0);
                                break;
                            case "/zeds":
                                //GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call();
                                this.SpawnZombies();
                            case "/teleportall":
                                TeleportAllPlayersTo(player);
                                break;
                            case "/healall":
                                HealAllPlayers();
                                break;
                            case "/r":
                                ReloadMissionScripts();                                
                                ReloadCommandScripts();
                                break;
                            }

                        };
                        array<string> strs = new array<string>;
			            chat_params.param3.Split(" ", strs );

                        auto ctx = new CommandContext(new CommandExecutor(player),strs);

                        foreach(ScriptModule commandScript: CommandScripts) {

                            commandScript.Call(NULL,"OnCommand",new Param1<CommandContext>(ctx));

                        }
                    }
                }
            }
            break;
        }
        super.OnEvent(eventTypeId,params);
        switch(eventTypeId) {
        case StartupEventTypeID:
            Print("StartupEventTypeID");
            break;

        case WorldCleaupEventTypeID:
            Print("WorldCleaupEventTypeID");
            break;

        //-----------------------------------------------------------------------------

        case MPSessionStartEventTypeID:
            Print("MPSessionStartEventTypeID");
            break;

        case MPSessionEndEventTypeID:
            Print("MPSessionEndEventTypeID");
            break;

        case MPSessionFailEventTypeID:
            Print("MPSessionFailEventTypeID");
            break;

        case MPSessionPlayerReadyEventTypeID:
            Print("MPSessionPlayerReadyEventTypeID");
            break;

        //-----------------------------------------------------------------------------
        case ProgressEventTypeID:
            Print("ProgressEventTypeID");
            break;

        case NetworkManagerClientEventTypeID:
            Print("NetworkManagerClientEventTypeID");
            break;

        case NetworkManagerServerEventTypeID:
            Print("NetworkManagerServerEventTypeID");
            break;

        case DialogQueuedEventTypeID:
            Print("DialogQueuedEventTypeID");
            break;
        case ChatMessageEventTypeID:
            Print("ChatMessageEventTypeID");
            break;
        case ChatChannelEventTypeID:
            Print("ChatChannelEventTypeID");
            break;
        case PreloadEventTypeID:
            Print("PreloadEventTypeID");
            break;
        case ClientNewEventTypeID:
            Print("ClientNewEventTypeID");
            break;
        case ClientRespawnEventTypeID:
            Print("ClientRespawnEventTypeID");
            break;
        case ClientReadyEventTypeID:
            Print("ClientReadyEventTypeID");
            break;
        case ClientDisconnectedEventTypeID:
            Print("ClientDisconnectedEventTypeID");
            break;
        case LogoutCancelEventTypeID:
            Print("LogoutCancelEventTypeID");
            break;
        case ClientSpawningEventTypeID:
            Print("ClientSpawningEventTypeID");
            break;
        case LogoutEventTypeID:
            Print("LogoutEventTypeID");
            break;
        case DatabaseErrorEventTypeID:
            Print("DatabaseErrorEventTypeID");
            break;
        case ScriptLogEventTypeID:
            //Print("ScriptLogEventTypeID");
            break;
        case VONStateEventTypeID:
            Print("VONStateEventTypeID");
            break;
        case SetFreeCameraEventTypeID:
            Print("SetFreeCameraEventTypeID");
            break;
        case MPConnectionLostEventTypeID:
            Print("MPConnectionLostEventTypeID");
            break;

        case ConnectingAbortEventTypeID:
            Print("ConnectingAbortEventTypeID");
            break;
        //possible in engine events not accessable from script
        default:
            Print("Unknown");
            Print(eventTypeId);
            break;
        }
    }
    
    

	int TeleportAllPlayersTo(PlayerBase PlayerAdmin)
	{
		array<Man> players = new array<Man>;
	    GetGame().GetPlayers( players );

	    vector AdminPos;
	    AdminPos = PlayerAdmin.GetPosition();

	    for ( int i = 0; i < players.Count(); ++i )
		{
			PlayerBase Target = players.Get(i);
			Target.SetPosition( AdminPos );
		}
		return i;
	}

	

};


Mission CreateCustomMission(string path)
{
    return new CustomMission();
}

#endif /* MISSION_INIT */