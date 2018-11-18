#ifdef SERVER
#include "$CurrentDir:/mpmissions/mine.chernarusplus/scripts/CommandScript.c"
#endif

#ifndef COMMAND_Vehicle
#define COMMAND_Vehicle

class VehicleCommandScriptThread : CommandScriptThread
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

        if(ctx.params[0] == "/veh" && canExec(ctx)) {
           SpawnVehicle(ctx,"OffroadHatchback",{
		"HatchbackWheel","HatchbackWheel","HatchbackWheel","HatchbackWheel",
		"CarBattery","CarRadiator","EngineBelt","SparkPlug","HatchbackHood",
		"HatchbackTrunk","HatchbackDoors_Driver","HatchbackDoors_CoDriver",
		});
      		
        }
		if(ctx.params[0] == "/truck" && canExec(ctx)) {
            
      		SpawnVehicle(ctx,"V3S_Cargo_Blue",{
				"V3SWheel","V3SWheel", "V3SWheel","V3SWheel", "V3SWheelDouble","V3SWheelDouble", "V3SWheelDouble","V3SWheelDouble",
				"TruckBattery","TruckRadiator","EngineBelt","GlowPlug","V3SHood",
				"V3SDoors_Driver_Orange","V3SDoors_CoDriver_Orange",
			});
        }
    }
	
	void SpawnVehicle(CommandContext ctx, string vehicle, TStringArray parts) {
		vector NewPosition;
        vector OldPosition;	
        OldPosition = ctx.executor.admin.GetPosition();
        NewPosition[0] = OldPosition[0] + 1.5;
        NewPosition[1] = OldPosition[1] + 0.2;
        NewPosition[2] = OldPosition[2] + 1.5;
		Car oCar = Car.Cast( GetGame().CreateObject( vehicle, NewPosition, false, false ) );

		for (int j = 0; j < parts.Count(); j++) { oCar.GetInventory().CreateAttachment( parts.Get(j) ); }

		oCar.SwitchLights();
		
		oCar.Fill( CarFluid.FUEL, 100 );
		oCar.Fill( CarFluid.OIL, 100 );
		oCar.Fill( CarFluid.BRAKE, 100 );
		oCar.Fill( CarFluid.COOLANT, 100 );
	}
	

}
;
static ref CommandScriptThread mod_commandScript;
void  CreateCommandScript(Param2<ScriptModule,string> data)
{
    mod_commandScript = new VehicleCommandScriptThread;
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