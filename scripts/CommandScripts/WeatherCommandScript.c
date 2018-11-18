#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif

#ifndef COMMAND_Weather
#define COMMAND_Weather

class WeatherCommandScriptThread : CommandScriptThread
{

    override void OnCommand(CommandContext ctx) {
        switch(ctx.params[0]) {
            case "/daytime":
            Print("Daytime");
                DayTimeCommand(ctx);
            break;
             case "/nighttime":
            Print("nighttime");
                NightTimeCommand(ctx);
            break;
             case "/fog":
            Print("fog");
                FogCommand(ctx);
            break;
        }
       
    }
    void DayTimeCommand(CommandContext ctx) {
        if(canExec(ctx,{"Admin","Moderator"})) {
            GetGame().GetWorld().SetDate( 1988, 5, 23, 12, 0 );
        }
    }
    void NightTimeCommand(CommandContext ctx) {
        if(canExec(ctx,{"Admin","Moderator"})) {
            GetGame().GetWorld().SetDate( 1988, 5, 23, 22, 0 );
         }
    }
    void FogCommand(CommandContext ctx) {
        Weather weather = GetGame().GetWeather();
        if(canExec(ctx,{"Admin","Moderator"})) {
            Print("DO FOG NOW");
            weather.GetOvercast().SetLimits( 0.0 , 2.0 );
            weather.GetFog().SetLimits( 0.0 , 2.0 );

            weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.0 );
            weather.GetFog().SetForecastChangeLimits( 0.0, 0.0 );

            weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
            weather.GetFog().SetForecastTimeLimits( 600 , 600 );

            weather.GetOvercast().Set( 1.0, 2, 60*5) ;
            weather.GetFog().Set( 1.0, 2, 60*5 );

         }
    }

}
;
static ref CommandScriptThread mod_commandScript;
void  CreateCommandScript(Param2<ScriptModule,string> data)
{
    mod_commandScript = new WeatherCommandScriptThread;
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