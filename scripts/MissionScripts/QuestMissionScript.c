#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/MissionScript.c"
#endif


#ifndef MISSION_Script_QUEST
#define MISSION_Script_QUEST

static EntityAI SpawnZombie(vector pos)
{
    //Print("Spawning Zombie");
    //Print(this.GetMissionShared().zombies.Count());
    float randX = Math.RandomFloatInclusive(-50,50);
    float randZ = Math.RandomFloatInclusive(-50,50);
    pos[0]=pos[0]+randX;
    pos[2]=pos[2]+randZ;
    EntityAI zed = EntityAI.Cast(GetGame().CreateObject( WorkingZombieClasses().GetRandomElement(), pos, false, true ));

    return zed;

}
static TStringArray WorkingZombieClasses() {
    return {"ZmbM_HermitSkinny_Base", "ZmbM_HermitSkinny_Beige", "ZmbM_HermitSkinny_Black", "ZmbM_HermitSkinny_Green",
            "ZmbM_HermitSkinny_Red", "ZmbM_FarmerFat_Base", "ZmbM_FarmerFat_Beige", "ZmbM_FarmerFat_Blue", "ZmbM_FarmerFat_Brown",
            "ZmbM_FarmerFat_Green", "ZmbF_CitizenANormal_Base", "ZmbF_CitizenANormal_Beige", "ZmbF_CitizenANormal_Brown",
            "ZmbF_CitizenANormal_Blue", "ZmbM_CitizenASkinny_Base", "ZmbM_CitizenASkinny_Blue", "ZmbM_CitizenASkinny_Brown",
            "ZmbM_CitizenASkinny_Grey", "ZmbM_CitizenASkinny_Red", "ZmbM_CitizenBFat_Base", "ZmbM_CitizenBFat_Blue", "ZmbM_CitizenBFat_Red",
            "ZmbM_CitizenBFat_Green", "ZmbF_CitizenBSkinny_Base", "ZmbF_CitizenBSkinny", "ZmbM_PrisonerSkinny_Base", "ZmbM_PrisonerSkinny",
            "ZmbM_FirefighterNormal_Base", "ZmbM_FirefighterNormal", "ZmbM_FishermanOld_Base", "ZmbM_FishermanOld_Blue", "ZmbM_FishermanOld_Green",
            "ZmbM_FishermanOld_Grey", "ZmbM_FishermanOld_Red", "ZmbM_JournalistSkinny_Base", "ZmbM_JournalistSkinny", "ZmbF_JournalistNormal_Base",
            "ZmbF_JournalistNormal_Blue", "ZmbF_JournalistNormal_Green", "ZmbF_JournalistNormal_Red", "ZmbF_JournalistNormal_White",
            "ZmbM_ParamedicNormal_Base", "ZmbM_ParamedicNormal_Blue", "ZmbM_ParamedicNormal_Green", "ZmbM_ParamedicNormal_Red",
            "ZmbM_ParamedicNormal_Black", "ZmbF_ParamedicNormal_Base", "ZmbF_ParamedicNormal_Blue", "ZmbF_ParamedicNormal_Green",
            "ZmbF_ParamedicNormal_Red", "ZmbM_HikerSkinny_Base", "ZmbM_HikerSkinny_Blue", "ZmbM_HikerSkinny_Green", "ZmbM_HikerSkinny_Yellow",
            "ZmbF_HikerSkinny_Base", "ZmbF_HikerSkinny_Blue", "ZmbF_HikerSkinny_Grey", "ZmbF_HikerSkinny_Green", "ZmbF_HikerSkinny_Red",
            "ZmbM_HunterOld_Base", "ZmbM_HunterOld_Autumn", "ZmbM_HunterOld_Spring", "ZmbM_HunterOld_Summer", "ZmbM_HunterOld_Winter",
            "ZmbF_SurvivorNormal_Base", "ZmbF_SurvivorNormal_Blue", "ZmbF_SurvivorNormal_Orange", "ZmbF_SurvivorNormal_Red",
            "ZmbF_SurvivorNormal_White", "ZmbM_SurvivorDean_Base", "ZmbM_SurvivorDean_Black", "ZmbM_SurvivorDean_Blue", "ZmbM_SurvivorDean_Grey",
            "ZmbM_PolicemanFat_Base", "ZmbM_PolicemanFat", "ZmbF_PoliceWomanNormal_Base", "ZmbF_PoliceWomanNormal", "ZmbM_PolicemanSpecForce_Base",
            "ZmbM_PolicemanSpecForce", "ZmbM_SoldierNormal_Base", "ZmbM_SoldierNormal", "ZmbM_usSoldier_normal_Base",
            "ZmbM_usSoldier_normal_Woodland", "ZmbM_usSoldier_normal_Desert", "ZmbM_CommercialPilotOld_Base", "ZmbM_CommercialPilotOld_Blue",
            "ZmbM_CommercialPilotOld_Olive", "ZmbM_CommercialPilotOld_Brown", "ZmbM_CommercialPilotOld_Grey", "ZmbM_PatrolNormal_Base",
            "ZmbM_PatrolNormal_PautRev", "ZmbM_PatrolNormal_Autumn", "ZmbM_PatrolNormal_Flat", "ZmbM_PatrolNormal_Summer", "ZmbM_JoggerSkinny_Base",
            "ZmbM_JoggerSkinny_Blue", "ZmbM_JoggerSkinny_Green", "ZmbM_JoggerSkinny_Red", "ZmbF_JoggerSkinny_Base", "ZmbF_JoggerSkinny_Blue",
            "ZmbF_JoggerSkinny_Brown", "ZmbF_JoggerSkinny_Green", "ZmbF_JoggerSkinny_Red", "ZmbM_MotobikerFat_Base", "ZmbM_MotobikerFat_Beige",
            "ZmbM_MotobikerFat_Black", "ZmbM_MotobikerFat_Blue", "ZmbM_VillagerOld_Base", "ZmbM_VillagerOld_Blue", "ZmbM_VillagerOld_Green",
            "ZmbM_VillagerOld_White", "ZmbM_SkaterYoung_Base", "ZmbM_SkaterYoung_Blue", "ZmbM_SkaterYoung_Brown", "ZmbM_SkaterYoung_Green",
            "ZmbM_SkaterYoung_Grey", "ZmbF_SkaterYoung_Base", "ZmbF_SkaterYoung_Brown", "ZmbF_SkaterYoung_Striped", "ZmbF_SkaterYoung_Violet",
            "ZmbF_DoctorSkinny_Base", "ZmbF_DoctorSkinny", "ZmbF_BlueCollarFat_Base", "ZmbF_BlueCollarFat_Blue", "ZmbF_BlueCollarFat_Green",
            "ZmbF_BlueCollarFat_Red", "ZmbF_BlueCollarFat_White", "ZmbF_MechanicNormal_Base", "ZmbF_MechanicNormal_Beige", "ZmbF_MechanicNormal_Green",
            "ZmbF_MechanicNormal_Grey", "ZmbF_MechanicNormal_Orange", "ZmbM_MechanicSkinny_Base", "ZmbM_MechanicSkinny_Blue", "ZmbM_MechanicSkinny_Grey",
            "ZmbM_MechanicSkinny_Green", "ZmbM_MechanicSkinny_Red", "ZmbM_ConstrWorkerNormal_Base", "ZmbM_ConstrWorkerNormal_Beige",
            "ZmbM_ConstrWorkerNormal_Black", "ZmbM_ConstrWorkerNormal_Green", "ZmbM_ConstrWorkerNormal_Grey", "ZmbM_HeavyIndustryWorker_Base",
            "ZmbM_HeavyIndustryWorker", "ZmbM_OffshoreWorker_Base", "ZmbM_OffshoreWorker_Green", "ZmbM_OffshoreWorker_Orange", "ZmbM_OffshoreWorker_Red",
            "ZmbM_OffshoreWorker_Yellow", "ZmbF_NurseFat_Base", "ZmbF_NurseFat", "ZmbM_HandymanNormal_Base", "ZmbM_HandymanNormal_Beige",
            "ZmbM_HandymanNormal_Blue", "ZmbM_HandymanNormal_Green", "ZmbM_HandymanNormal_Grey", "ZmbM_HandymanNormal_White", "ZmbM_DoctorFat_Base",
            "ZmbM_DoctorFat", "ZmbM_Jacket_Base", "ZmbM_Jacket_beige", "ZmbM_Jacket_black", "ZmbM_Jacket_blue", "ZmbM_Jacket_bluechecks",
            "ZmbM_Jacket_brown", "ZmbM_Jacket_greenchecks", "ZmbM_Jacket_grey", "ZmbM_Jacket_khaki", "ZmbM_Jacket_magenta", "ZmbM_Jacket_stripes",
            "ZmbF_PatientOld_Base", "ZmbF_PatientOld", "ZmbM_PatientSkinny_Base", "ZmbM_PatientSkinny", "ZmbF_ShortSkirt_Base", "ZmbF_ShortSkirt_beige",
            "ZmbF_ShortSkirt_black", "ZmbF_ShortSkirt_brown", "ZmbF_ShortSkirt_green", "ZmbF_ShortSkirt_grey", "ZmbF_ShortSkirt_checks",
            "ZmbF_ShortSkirt_red", "ZmbF_ShortSkirt_stripes", "ZmbF_ShortSkirt_white", "ZmbF_ShortSkirt_yellow", "ZmbF_VillagerOld_Base",
            "ZmbF_VillagerOld_Blue", "ZmbF_VillagerOld_Green", "ZmbF_VillagerOld_Red", "ZmbF_VillagerOld_White", "ZmbM_Soldier", "ZmbM_SoldierAlice",
            "ZmbM_SoldierHelmet", "ZmbM_SoldierVest", "ZmbM_SoldierAliceHelmet", "ZmbM_SoldierVestHelmet", "ZmbF_MilkMaidOld_Base",
            "ZmbF_MilkMaidOld_Beige", "ZmbF_MilkMaidOld_Black", "ZmbF_MilkMaidOld_Green", "ZmbF_MilkMaidOld_Grey", "ZmbM_priestPopSkinny_Base",
            "ZmbM_priestPopSkinny", "ZmbM_ClerkFat_Base", "ZmbM_ClerkFat_Brown", "ZmbM_ClerkFat_Grey", "ZmbM_ClerkFat_Khaki", "ZmbM_ClerkFat_White",
            "ZmbF_Clerk_Normal_Base", "ZmbF_Clerk_Normal_Blue", "ZmbF_Clerk_Normal_White", "ZmbF_Clerk_Normal_Green", "ZmbF_Clerk_Normal_Red"};
}
void SendMessageToClient(PlayerBase reciever, string message )//sends given string to client, don't use if not nescessary
{

    ref Param1<string> 	m_MessageParam= new Param1<string>(message);
    if( GetGame().IsServer()   && reciever.IsAlive()  )
    {
        GetGame().RPCSingleParam(reciever, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, reciever.GetIdentity());
    }
}
enum QuestStatus {
    InProgress,
    Completed,
    Aborted
}
class Quest {
    private string Name;
    private string Description;
    private ref array<ref QuestReward> Rewards = new array<ref QuestReward>();
    private ref array<ref QuestObjective> Objectives = new array<ref QuestObjective>();
    private ref array<ref QuestRequirement> Requirements = new array<ref QuestRequirement>();
    private ref array<ref QuestParticipant> Participants = new array<ref QuestParticipant>();
    private QuestStatus status;

    array<ref QuestParticipant> GetParticipants() {
        return Participants;
    }
    void Quest(string name, string description, array<PlayerBase> participants) {
        Name = name;
        Description = description;
        foreach(auto participant : participants) {
            Participants.Insert(new QuestParticipant(participant));
        }
    }
    void AddObjective(QuestObjective objective) {
        this.Objectives.Insert(objective);
    }
    void AddReward(QuestRewardType type, QuestRewardProbability probability, string reward) {
        auto questReward = new QuestReward(type,probability);
        questReward.SetReward(reward);
        Rewards.Insert(questReward);
    }
    void AddReward(QuestRewardType type, QuestRewardProbability probability, int reward) {
        auto questReward = new QuestReward(type,probability);
        questReward.SetReward(reward);
        Rewards.Insert(questReward);
    }
    void MessageAllParticipants(string message) {
        message =string.Format("[QuestSystem] %1 %2",Name, message);
        foreach(auto participant: Participants) {
              participant.Message(message);
        }
    }
    bool Check() {
        string todoObjectiveList = "";
        foreach(auto objective: Objectives) {
            if (objective.MadeProgress()) {
                if (objective.IsCompleted()) {
                    Objectives.RemoveItem(objective);
                    ObjectiveCompleted(objective);
                } else {

                    todoObjectiveList = todoObjectiveList + objective.GetObjectiveString();
                    ObjectiveProgress(objective);
                }

            } else {
                todoObjectiveList = todoObjectiveList + objective.GetObjectiveString();
            }
        }
        if (status != QuestStatus.Completed) {
            foreach(auto requirement: Requirements) {
                requirement.Check();
            }
            foreach(auto participant: Participants) {
                if(!participant.IsValid()) {
                    Participants.RemoveItem(participant);
                }

            }
            if(Participants.Count() == 0) {
                status = QuestStatus.Aborted;
            }
            MessageAllParticipants(string.Format("Objectives Left: %1",todoObjectiveList));
        }

        return status == QuestStatus.Completed || status == QuestStatus.Aborted;
    }
    void ObjectiveProgress(QuestObjective objective) {
        MessageAllParticipants("U've made progress!");
    }
    void ObjectiveCompleted(QuestObjective objective) {
        MessageAllParticipants(string.Format("Objective [%1] is Done", objective.GetName()));

        if(Objectives.Count() == 0 ) {
            QuestCompleted();
        }
        objective.Delete();
    }
    void RewardParticipants() {
        foreach (auto participant: Participants) {
            foreach (auto reward: Rewards) {
                reward.RewardPlayer(participant);
            }
        }
    }

    void QuestCompleted() {
        MessageAllParticipants("Quest has been Completed!");
        RewardParticipants();
        status = QuestStatus.Completed;

    }
}
class QuestObjective {

    Quest quest;
    void QuestObjective(Quest quest) {
        this.quest = quest;
    }
    string GetName() {}
    string GetObjectiveString() {}
    bool MadeProgress() {}
    bool IsCompleted() {}
    void Delete() {
        quest = NULL;

    }
}
class KillZombiesQuestObjective extends QuestObjective {
    ref array<ref EntityAI>zombies = new array<ref EntityAI>;
    void KillZombiesQuestObjective(Quest quest, int howMany = 10) {
        this.quest = quest;
        while (zombies.Count() < howMany) {
            vector pos = quest.GetParticipants().GetRandomElement().GetPlayer().GetPosition();
            auto zombie = SpawnZombie(pos);
            if (zombie) {

                zombies.Insert(zombie);
            }
        }
    }
    override void Delete() {
        super.Delete();
        delete this;
    }
    void ~KillZombiesQuestObjective() {
        foreach(auto zed: zombies) {
            zed.Delete();
            zombies.RemoveItem(zed);
        }
        zombies = NULL;
        delete zombies;
    }
   override string GetName() {
        return "Kill Those Zombies";
    }
   override string GetObjectiveString() {
        return string.Format("Kill: %1 Zombies Infront of ya", zombies.Count());
    }
	override bool MadeProgress() {
        bool progress = false;
        foreach(auto z : zombies) {
            if(z && !z.IsAlive()) {
                progress = true;
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(z.Explode, 60000, false,NULL);
                zombies.RemoveItem(z);
            }
        }
        return progress;
    };

	override bool IsCompleted() {
        return zombies.Count() == 0;
    };
}
class GOTOQuestObjective extends QuestObjective {
    vector gotoPos;
    bool completed = false;
    void GOTOQuestObjective(Quest quest, vector pos) {
        this.quest = quest;
        gotoPos = pos;

    }
    override void Delete() {
        super.Delete();
        delete this;
    }
    void ~GOTOQuestObjective() {
    }
    override string GetName() {
        return "Goto";
    }
    override string GetObjectiveString() {
        return string.Format("Goto Position : %1", gotoPos);
    }
   override bool MadeProgress() {
        bool progress = false;
        auto participants = quest.GetParticipants();
        foreach(auto participant : participants) {
            if(participant.IsValid()) {
                if (vector.Distance(participant.GetPlayer().GetPosition(),gotoPos) < 2.5)  {
                    progress = true;
                    completed = true;
                }
            }
        }
        return progress;
    };

   override  bool IsCompleted() {
        return completed;
    };
}
enum QuestRequirementType  {
    Level,
    Name,
    Money,
    Item
}
class QuestRequirement {
    QuestRequirementType type;
    string requiredString;
    int requiredNumber;
    bool Check() {
        return true;
    }
}
enum QuestRewardType  {
    Level,
    Money,
    Health,
    Item
}
enum QuestRewardProbability  {
    Always,
    Sometimes
}
class QuestReward {
    QuestRewardType type;
    QuestRewardProbability probability;

    string rewardName;
    int rewardNumber;
    void QuestReward(QuestRewardType type, QuestRewardProbability probability) {
        this.type = type;
        this.probability = probability;
    }

    void SetReward(string reward) {
        this.rewardName = reward;
    }
    void SetReward(int reward) {
        this.rewardNumber = reward;
    }
    void RewardPlayer(QuestParticipant participant) {

        if (!participant.IsValid()) {

            return
        }
        switch(type) {
        case QuestRewardType.Health:
            PlayerBase player = participant.GetPlayer();
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
            player.AddHealth("GlobalHealth","Shock",(maxShock/100)*rewardNumber);
            player.AddHealth("GlobalHealth","Blood",(maxBlood/100)*rewardNumber);
            player.AddHealth("GlobalHealth","Health",(maxHealth/100)*rewardNumber);
            if (player.GetBleedingManagerServer() )
            {
                player.GetBleedingManagerServer().RemoveAnyBleedingSource();
            }
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
            participant.Message(string.Format("You've been %1 PERCENT Healed",rewardNumber));

            break;
        case QuestRewardType.Item:
            switch(probability) {
            case QuestRewardProbability.Always:

                participant.Message(string.Format("For Your work u Got: %1",rewardName));
                participant.GetPlayer().GetInventory().CreateInInventory( rewardName );
                break;
            case QuestRewardProbability.Sometimes:
                if (Math.RandomIntInclusive(0,1) == 1) {

                    participant.Message(string.Format("For Your work u Got: %1",rewardName));
                    participant.GetPlayer().GetInventory().CreateInInventory( rewardName );
                }
                break;

            }

            break;
        default:
            participant.Message("UnImplemented RewardType");
            break;
        }
    }

}
class QuestParticipant {
    PlayerBase player;
    void QuestParticipant(PlayerBase playerBase) {
        player = playerBase;
    }
    PlayerBase GetPlayer() {
        return player;
    }
    void Message(string text) {
        Print(text);
        SendMessageToClient(player,text);
    }
    //TODO: Reattach Respawned Player maybe?
    bool IsValid() {
        return GetPlayer() && GetPlayer().IsAlive();
    }

}
class QuestMissionScriptThread : MissionScriptThread
{
    Building building;
    int number = 0 ;
    ref array<ref Quest> runningQuests;
    void QuestMissionScriptThread()  {
        //return;
  /*      runningQuests = new array<ref Quest>();
        for(int i = 0; i < 1; i++ ) {
            Quest quest = NewKillZombieQuest();
            if(quest != NULL) {
                runningQuests.Insert(quest);

            }
*/
            /*Quest gotoQuest = NewGotoQuest();
            if(gotoQuest != NULL) {
                runningQuests.Insert(gotoQuest);

            }*/
    //    }
        
//		JsonFileLoader<array<ref Quest>>.JsonSaveFile( g_Game.GetMissionFolderPath() + "/quests.json", runningQuests );

    }
    override void Tick() {
        super.Tick();
        //Print("Check Zombies");
        CheckQuests();
        //Print("Where The Magic Happens");
        Sleep(2500);
    }
    Quest NewKillZombieQuest() {
        ref array<Man> mans = new array<Man>;
        ref array<PlayerBase> players = new array<PlayerBase>;
        GetGame().GetPlayers(mans);

        foreach(auto man : mans)
        {
            PlayerBase player = PlayerBase.Cast(man);
            if (player && player.IsAlive() && !player.IsUnconscious())
            {
                players.Insert(player);
            }
        }
        if(players.Count() > 0 ) {
            Quest quest = new Quest("ZombieKiller", "Kill 5 Zombies",players);
            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");
            quest.AddReward(QuestRewardType.Health, QuestRewardProbability.Always,10);
            quest.AddObjective(new KillZombiesQuestObjective(quest,20));
            return quest;
        } else {
            return NULL;
        }
    }
    Quest NewGotoQuest() {
        ref array<Man> mans = new array<Man>;
        ref array<PlayerBase> players = new array<PlayerBase>;
        GetGame().GetPlayers(mans);

        foreach(auto man : mans)
        {
            PlayerBase player = PlayerBase.Cast(man);
            if (player && player.IsAlive() && !player.IsUnconscious())
            {
                players.Insert(player);
            }
        }
        if(players.Count() > 0 ) {
            Quest quest = new Quest("Goto This Position", "DO IT",players);
            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");

            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");
            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");
            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");
            quest.AddReward(QuestRewardType.Item,QuestRewardProbability.Sometimes,"Mag_STANAGCoupled_30Rnd");
            quest.AddObjective(new GOTOQuestObjective(quest,"13253 5 6304"));
            return quest;
        } else {
            return NULL;
        }
    }
    void CheckQuests() {
        if(runningQuests&&runningQuests.Count() > 0 ) {

            foreach(Quest quest : runningQuests)
            {
                if (quest.Check()) {
                    runningQuests.RemoveItem(quest);
                    delete quest;
                }
            }
        } else {

            runningQuests = new array<ref Quest>();
        }
        //Print("Checking Quest Status");
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
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch(rpc_type)
        {
        case MRPCs.RPC_CLIENT_INTERACT:
            PlayerBase pTarget = PlayerBase.Cast(target);
            //pTarget.SetPosition("1800 128 3000");
            Print("[RPC] Questing Mission Script Called");


        }
    }

}
;
static ref MissionScriptThread mod_missionScript;
void  CreateMissionScript(Param2<ScriptModule,string> data)
{
    mod_missionScript = new QuestMissionScriptThread;
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