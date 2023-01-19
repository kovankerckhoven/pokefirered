@ After each successfull Elite Four cycle:
@ 	* Reset flags for the postgame gossipers, Elite Four, and Champion
@	* Call Script_UpdateTrainerFanClubGameClear
@	* If the National Dex hasn't been enabled yet, try to enable it (in the Pallet Town scene) 
@	* If the National Dex has been enabled already, but Johto hasn't been unlocked yet, try to unlock it (in the Pallet Town scene)
@	* Reset Legendaries
@	* TODO: Also reset Roamers etc.?
EventScript_SetDefeatedEliteFourFlagsVars::
	clearflag FLAG_HIDE_POSTGAME_GOSSIPERS
	call EventScript_ResetEliteFour
	special Script_UpdateTrainerFanClubGameClear
	call_if_unset FLAG_SYS_NATIONAL_DEX, EventScript_SetReadyTryGiveNationalDexScene
	call_if_set FLAG_SYS_NATIONAL_DEX, EventScript_FlagCheck_SetReadyTryUnlockJohto
	call EventScript_ResetLegendaries
	return

@ Attempt to enable the National Dex in the Pallet Town scene
EventScript_SetReadyTryGiveNationalDexScene::
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	return

@ If the National Dex has been enabled, check if Johto has been unlocked already or not
EventScript_FlagCheck_SetReadyTryUnlockJohto::
	call_if_unset FLAG_SYS_JOHTO_UNLOCKED, EventScript_SetReadyTryUnlockJohto
	return

@ Johto not unlocked yet, attempt to unlock it in the Pallet Town scene
EventScript_SetReadyTryUnlockJohto::
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 4
	return

EventScript_ResetLegendaries::
	clearflag FLAG_LUGIA_FLEW_AWAY
	clearflag FLAG_HO_OH_FLEW_AWAY
	clearflag FLAG_DEOXYS_FLEW_AWAY
	return

@ TODO: Is this actually referenced anywhere instead of "EventScript_ResetEliteFour"?
EventScript_ResetEliteFourEnd::
	call EventScript_ResetEliteFour
	end

EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_CHAMP
	cleartrainerflag TRAINER_CHAMPION_FIRST_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_FIRST_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_FIRST_CHARMANDER
	cleartrainerflag TRAINER_CHAMPION_REMATCH_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_REMATCH_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_REMATCH_CHARMANDER
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 0
	return
