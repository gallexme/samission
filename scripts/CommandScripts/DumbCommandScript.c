#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif
#ifndef COMMAND_DUMB
#define COMMAND_DUMB

class DumbCommandScriptThread : CommandScriptThread
{
	bool canExec(CommandContext ctx) {
		foreach(string perm : ctx.executor.permissions) {
			if(perm.Contains("Admin")) {
				return true;
			}
		}
		return false;
	}
    override void OnCommand(CommandContext ctx) {

        if(ctx.params[0] == "/dumb" && canExec(ctx)) {
            Print("Test DUMB");
        }
    }


}
;
static ref CommandScriptThread mod_commandScript;
void  CreateCommandScript(Param2<ScriptModule,string> data)
{
    mod_commandScript = new DumbCommandScriptThread;
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