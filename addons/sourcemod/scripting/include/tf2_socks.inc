/*
 Fixed version of "TF2_RemoveWeaponSlot"
 By: fiagram & Powerlord

*/

new Handle:hRemoveWearable = INVALID_HANDLE; 
new Handle:hEquipWearable = INVALID_HANDLE; 
new Handle:hIsWearable = INVALID_HANDLE; 

stock TF2_RemoveWearable(client, wearable) 
{ 
   if(hRemoveWearable == INVALID_HANDLE) 
   { 
       new Handle:hGameConfigtemp = LoadGameConfigFile("equipwearable"); 
       if(hGameConfigtemp == INVALID_HANDLE) 
       { 
           LogError("Equipwearable Gamedata could not be found"); 
           return; 
       } 
       StartPrepSDKCall(SDKCall_Player); 
       PrepSDKCall_SetFromConf(hGameConfigtemp, SDKConf_Virtual, "RemoveWearable"); 
       CloseHandle(hGameConfigtemp); 
       PrepSDKCall_AddParameter(SDKType_CBaseEntity, SDKPass_Pointer); 
       if ((hRemoveWearable = EndPrepSDKCall()) == INVALID_HANDLE) 
       { 
           LogError("Couldn't load SDK functions (CTFPlayer::RemoveWearable). SDK call failed."); 
           return; 
       } 
   } 

   SDKCall(hRemoveWearable, client, wearable); 
} 

stock TF2_EquipWearable(client, wearable) 
{ 
   if(hEquipWearable == INVALID_HANDLE) 
   { 
       new Handle:hGameConfigtemp = LoadGameConfigFile("equipwearable"); 
       if(hGameConfigtemp == INVALID_HANDLE) 
       { 
           LogError("Equipwearable Gamedata could not be found"); 
           return; 
       } 
       StartPrepSDKCall(SDKCall_Player); 
       PrepSDKCall_SetFromConf(hGameConfigtemp, SDKConf_Virtual, "EquipWearable"); 
       CloseHandle(hGameConfigtemp); 
       PrepSDKCall_AddParameter(SDKType_CBaseEntity, SDKPass_Pointer); 
       if ((hEquipWearable = EndPrepSDKCall()) == INVALID_HANDLE) 
       { 
           LogError("Couldn't load SDK functions (CTFPlayer::EquipWearable). SDK call failed."); 
           return; 
       } 
   } 

   SDKCall(hEquipWearable, client, wearable); 
} 

stock TF2_IsWearable(wearable) 
{ 
   if(hIsWearable == INVALID_HANDLE) 
   { 
       new Handle:hGameConfigtemp = LoadGameConfigFile("equipwearable"); 
       if(hGameConfigtemp == INVALID_HANDLE) 
       { 
           LogError("Equipwearable Gamedata could not be found"); 
           return false; 
       } 
       StartPrepSDKCall(SDKCall_Entity); 
       PrepSDKCall_SetFromConf(hGameConfigtemp, SDKConf_Virtual, "IsWearable"); 
       CloseHandle(hGameConfigtemp); 
       PrepSDKCall_SetReturnInfo(SDKType_Bool, SDKPass_Plain); 
       if ((hIsWearable = EndPrepSDKCall()) == INVALID_HANDLE) 
       { 
           LogError("Couldn't load SDK functions (CTFPlayer::IsWearable). SDK call failed."); 
           return false; 
       } 
   } 

   return SDKCall(hIsWearable, wearable); 
} 

/* Removes all weapons from a client's weapon slot 
* 
* @param client        Player's index. 
* @param slot          Slot index (0-5) 
* @noreturn 
* @error               Invalid client, invalid slot or lack of mod support 
*/ 
stock TF2_RemoveWeaponSlot2(client, slot) 
{ 
   decl ew; 
   new weaponIndex; 
   while ((weaponIndex = GetPlayerWeaponSlot(client, slot)) != -1) 
   { 
       ew = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearable"); 
       if(IsValidEntity(ew)) 
       { 
           TF2_RemoveWearable(client, ew); 
       } 
       ew = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearableViewModel"); 
       if(IsValidEntity(ew)) 
       { 
           TF2_RemoveWearable(client, ew); 
       } 
       RemovePlayerItem(client, weaponIndex); 
       AcceptEntityInput(weaponIndex, "Kill"); 
   } 
}

/**
 * Removes all weapons from a client
 *
 * @param client		Player's index.
 * @noreturn
 */
stock TF2_RemoveAllWeapons2(client)
{
	for (new i = 0; i <= 5; i++)
	{
		TF2_RemoveWeaponSlot2(client, i);
	}
}