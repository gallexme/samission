#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif

#ifndef COMMAND_Player
#define COMMAND_Player

class PlayerCommandScriptThread : CommandScriptThread
{

    override void OnCommand(CommandContext ctx) {
        switch(ctx.params[0])
        {
            case "/killall":
            CommandKillAll(ctx);
            break;
        }
       
    }

    void CommandKillAll(CommandContext ctx) {
        if(!canExec(ctx,{"Admin"})) {
            return;
        }
        array<Man> players = new array<Man>;
			GetGame().GetPlayers( players );
            for ( int ig = 0; ig < players.Count(); ++ig )
            {
                PlayerBase Target = players.Get(ig);
                if ( Target.GetIdentity() != ctx.executor.admin.GetIdentity() )
                {
                    Target.SetHealth(0);						
                }
            }
    }
}
;
static ref CommandScriptThread mod_commandScript;
void  CreateCommandScript(Param2<ScriptModule,string> data)
{
    mod_commandScript = new PlayerCommandScriptThread;
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