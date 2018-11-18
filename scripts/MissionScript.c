
#ifndef MISSION_SCRIPT
#define MISSION_SCRIPT
enum MRPCs
{
	RPC_CLIENT_REQUEST_AUTOWALK = 2000,
	RPC_CLIENT_INCREASE_STATS,
	RPC_CLIENT_REQUEST_SUICIDE,
	RPC_SERVER_ASK_SPAWN_LOCATION,
	RPC_CLIENT_SEND_SPAWN_LOCATION,
	RPC_CLIENT_ACTION_SPECTATOR,
	RPC_BR_SEND_CLIENT_MSG,
	RPC_BR_SEND_GLOBAL_MSG,
	RPC_BR_SET_INPUT,
	RPC_BR_FADE_IN,
	RPC_BR_FADE_OUT,
	RPC_CLIENT_INTERACT,
	// Ignore, though BattleRoyale class was also ran client side.
	// RPC_BR_SET_GAME_DATA
}


class Counter {
	int zombieKills =0;
}
class MissionScriptThread
{
	bool m_Running = false;
	ScriptModule m_Self;
	
	string m_Name;
	void Init(ScriptModule self)
	{
		m_Self = self;
		
	}
	void SetName(string newName)
	{
		m_Name = newName;
	}
	string GetName()
	{
		return m_Name;
	}
	void StartScript()
	{
		m_Running = true;
		m_Self.Call(this, "ScriptThread", NULL);
	}
	void ScriptThread()
	{
		while (this.CanRun())
		{
			Tick();
		}
	}
	void Tick() {
			Sleep(100);
	}
	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		
	}
	void StopScript()
	{
		m_Running = false;
		m_Self.Release();
		delete this;
	}
	void OnInteract() {

	}
	bool CanRun()
	{
		return m_Running;
	}
	void ~MissionScriptThread()
	{
		m_Running = false;
	}
};
#endif