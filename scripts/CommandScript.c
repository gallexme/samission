
#ifndef COMMAND_SCRIPT
#define COMMAND_SCRIPT

class CommandContext  {
	ref CommandExecutor executor;
	ref array<string> params;
	void CommandContext(CommandExecutor executor, ref array<string> params) {
		this.executor = executor;
		this.params = params;
	}
}
class CommandExecutor  {
	PlayerBase admin;
	ref array<string> permissions;
	void CommandExecutor(PlayerBase admin) {
		this.admin = admin;
		LoadPermissions();
	}
	void LoadPermissions() {
		permissions = new array<string>();
		FileHandle AdminUIDSFile = OpenFile("$CurrentDir:/mpmissions/mine.chernarusplus/Admins.txt", FileMode.READ);
		if (AdminUIDSFile != 0)
		{
			string line_content = "";
			while ( FGets(AdminUIDSFile,line_content) > 0 )
			{
				if(line_content.Contains(admin.GetIdentity().GetPlainId())) {
					array<string> strs = new array<string>;
					line_content.Split("|", strs );

					permissions.InsertAll(strs); 
				}
			}
			CloseFile(AdminUIDSFile);
		}
	}
}


class CommandScriptThread  {
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

	void StopScript()
	{
		m_Running = false;
		m_Self.Release();
		delete this;
	}
	void OnCommand(CommandContext ctx) {
		Print(ctx);
	}
	bool CanRun()
	{
		return m_Running;
	}
	void ~CommandScriptThread()
	{
		m_Running = false;
	}
	bool canExec(CommandContext ctx, array<string>Roles) {
		foreach(string perm : ctx.executor.permissions) {
			foreach(string role: Roles) {
                if(perm.Contains(role)) {
				    return true;
			    }
            }
            
		}
		return false;
	}
};
#endif