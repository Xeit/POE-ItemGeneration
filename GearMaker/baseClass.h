#pragma once
#include <iostream>
#include <string>

namespace Bases
{
	class BaseClass
	{
	public:
		std::string name;
		short minPD;
		short maxPD;
		double critChance; // In %
		double APS; //Attacks Per Seconds
		short range; //Weapon range
		short reqLvl;
		short reqStr;
		short reqDex;
		short reqInt;
		std::string modifier = "";


		BaseClass(std::string name, short minPD, short maxPD, double critChance, double APS, short range, short reqLvl, short reqStr, short reqDex, short reqInt, std::string modifier)
		{
			this->name = name;
			this->minPD = minPD;
			this->maxPD = maxPD;
			this->critChance = critChance;
			this->APS = APS;
			this->range = range;
			this->reqLvl = reqLvl;
			this->reqStr = reqStr;
			this->reqDex = reqDex;
			this->reqInt = reqInt;
			this->modifier = modifier;
		}

		BaseClass()
		{}
	};
}

namespace Base
{
	//Sceptres
	static Bases::BaseClass Driftwood_Sceptre("Driftwood Sceptre", 5, 8, 6, 1.55, 11, 1, 8, 0, 8, "10% increased elemental damage");
	static Bases::BaseClass Darkwood_Sceptre("Darkwood Sceptre", 8, 12, 6, 1.5, 11, 5, 14, 0, 14, "12% increased elemental damage");
	static Bases::BaseClass Bronze_Sceptre("Bronze Sceptre", 10, 19, 6, 1.4, 11, 10, 22, 0, 22, "12% increased elemental damage");
	static Bases::BaseClass Quartz_Sceptre("Quartz Sceptre", 14, 22, 6.5, 1.4, 11, 15, 25, 0, 35, "20% increased elemental damage");
	static Bases::BaseClass Iron_Sceptre("Iron Sceptre", 18, 27, 6, 1.4, 11, 20, 38, 0, 38, "14% increased elemental damage");
	static Bases::BaseClass Ochre_Sceptre("Ochre Sceptre", 17, 31, 6, 1.45, 11, 24, 44, 0, 44, "16% increased elemental damage");
	static Bases::BaseClass Ritual_Sceptre("Ritual Sceptre", 21, 50, 6, 1.2, 11, 28, 51, 0, 51, "16% increased elemental damage");
	static Bases::BaseClass Shadow_Sceptre("Shadow Sceptre", 29, 44, 6.2, 1.25, 11, 32, 52, 0, 62, "22% increased elemental damage");
	static Bases::BaseClass Grinning_Fetish("Grinning Fetish", 24, 36, 6, 1.5, 11, 35, 62, 0, 62, "15% increased elemental damage");
	static Bases::BaseClass Horned_Sceptre("Horned Sceptre", 27, 50, 6, 1.3, 11, 36, 66, 0, 66, "damage penetrates 4% elemental resistances");
	static Bases::BaseClass Sekhem("Sekhem", 30, 55, 6, 1.25, 11, 38, 67, 0, 67, "18% increased elemental damage");
	static Bases::BaseClass Crystal_Sceptre("Crystal Sceptre", 35, 52, 6.5, 1.25, 11, 41, 59, 0, 85, "30% increased elemental damage");
	static Bases::BaseClass Lead_Sceptre("Lead Sceptre", 38, 57, 6, 1.25, 11, 44, 77, 0, 77, "22% increased elemental damage");
	static Bases::BaseClass Blood_Sceptre("Blood Sceptre", 30, 55, 6, 1.4, 11, 47, 81, 0, 81, "24% increased elemental damage");
	static Bases::BaseClass Royal_Sceptre("Royal Sceptre", 34, 80, 6, 1.2, 11, 50, 86, 0, 86, "24% increased elemental damage");
	static Bases::BaseClass Abyssal_Sceptre("Abyssal Sceptre", 45, 67, 6.2, 1.25, 11, 53, 83, 0, 99, "30% increased elemental damage");
	static Bases::BaseClass Stag_Sceptre("Stag Sceptre", 39, 72, 6, 1.3, 11, 55, 98, 0, 98, "damage penetrates 4% elemental resistances");
	static Bases::BaseClass Karui_Sceptre("Karui Sceptre", 37, 55, 6, 1.5, 11, 56, 96, 0, 96, "26% increased elemental damage");
	static Bases::BaseClass Tyrants_Sekhem("Tyrant's Sekhem", 43, 80, 6, 1.24, 11, 58, 99, 0, 99, "26% increased elemental damage");
	static Bases::BaseClass Opal_Sceptre("Opal Sceptre", 49, 73, 6.5, 1.25, 11, 60, 95, 0, 131, "40% increased elemental damage");
	static Bases::BaseClass Platinum_Sceptre("Platinum Sceptre", 51, 76, 6, 1.25, 11, 62, 113, 0, 113, "30% increased elemental damage");
	static Bases::BaseClass Vaal_Sceptre("Vaal Sceptre", 37, 70, 6, 1.4, 11, 64, 113, 0, 113, "32% increased elemental damage");
	static Bases::BaseClass Carnal_Sceptre("Carnal Sceptre", 41, 95, 6, 1.2, 11, 66, 113, 0, 113, "32% increased elemental damage");
	static Bases::BaseClass Void_Sceptre("Void Sceptre", 50, 76, 6.2, 1.25, 11, 68, 104, 0, 122, "40% increased elemental damage");
	static Bases::BaseClass Sambar_Sceptre("Sambar Sceptre", 42, 78, 6, 1.3, 11, 70, 121, 0, 113, "Damage penetrates 6% elemental resistances");
	//One Handed Maces
	static Bases::BaseClass Driftwood_Club("Driftwood Club", 6, 8, 5, 1.45, 11, 1, 14, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Tribal_Club("Tribal Club", 8, 13, 5, 1.4, 11, 5, 26, 0, 0, "10% reduced enemy stun threashold");
	static Bases::BaseClass Spiked_Club("Spiked Club", 13, 16, 5, 1.45, 11, 10, 41, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Stone_Hammer("Stone Hammer", 15, 27, 5, 1.3, 11, 15, 56, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass War_Hammer("War Hammer", 13, 31, 5, 1.45, 11, 20, 71, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Bladed_Mace("Bladed Mace", 19, 32, 5, 1.4, 11, 24, 83, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Ceremonial_Mace("Ceremonial Mace", 32, 40, 5, 1.2, 11, 28, 95, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Dream_Mace("Dream Mace", 21, 43, 5, 1.4, 11, 32, 107, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Wyrm_Mace("Wyrm Mace", 28, 42, 5, 1.35, 11, 34, 118, 0, 0, "4% increased attack speed");
	static Bases::BaseClass Petrified_Club("Petrified Club", 31, 51, 5, 1.25, 11, 35, 116, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Barbed_Club("Barbed Club", 33, 42, 5, 1.4, 11, 38, 125, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Rock_Breaker("Rock Breaker", 37, 69, 5, 1.15, 11, 41, 134, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Battle_Hammer("Battle Hammer", 25, 59, 5, 1.4, 11, 44, 143, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Flanged_Mace("Flanged Mace", 38, 63, 5, 1.3, 11, 47, 152, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Ornate_Mace("Ornate Mace", 53, 67, 5, 1.2, 11, 50, 161, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Phantom_Mace("Phantom Mace", 33, 69, 5, 1.4, 11, 53, 170, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Dragon_Mace("Dragon Mace", 44, 66, 5, 1.35, 11, 55, 184, 0, 0, "4% incresed attack speed");
	static Bases::BaseClass Ancestral_Club("Ancestral Club", 48, 80, 5, 1.25, 11, 56, 179, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Tenderizer("Tenderizer", 49, 62, 5, 1.4, 11, 58, 185, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Gavel("Gavel", 54, 101, 5, 1.15, 11, 60, 212, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Legion_Hammer("Legion Hammer", 35, 81, 5, 1.4, 11, 62, 212, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Pernach("Pernach", 49, 82, 5, 1.3, 11, 64, 212, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Auric_Mace("Auric Mace", 65, 82, 5, 1.2, 11, 66, 212, 0, 0, "15% reduced enemy stun threshold");
	static Bases::BaseClass Nightmare_Mace("Nightmare mace", 38, 80, 5, 1.4, 11, 68, 212, 0, 0, "10% reduced enemy stun threshold");
	static Bases::BaseClass Behemoth_Mace("Behemot Mace", 49, 74, 5, 1.35, 11, 70, 220, 0, 0, "6% increased attack speed");
	//Two Handed Maces
	static Bases::BaseClass Driftwood_Maul("Driftwood Maul", 10, 16, 5, 1.3, 11, 3, 20, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Tribal_Maul("Tribal Maul", 17, 25, 5, 1.25, 13, 8, 35, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Mallet("Mallet", 16, 33, 5, 1.3, 13, 12, 47, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Sledgehammer("Sledgehammer", 25, 38, 5, 1.3, 13, 17, 62, 0, 0, "45% increased stun duration on enemies");
	static Bases::BaseClass Jagged_Maul("Jagged Maul", 27, 49, 5, 1.3, 13, 22, 77, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Brass_Maul("Brass Maul", 40, 60, 5, 1.2, 13, 27, 92, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Fright_Maul("Fright Maul", 46, 62, 5, 1.25, 13, 32, 107, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Morning_Star("Morning Star", 45, 68, 5, 1.25, 13, 34, 118, 0, 0, "15% increased area of effect");
	static Bases::BaseClass Totemic_Maul("Totemic Maul", 57, 85, 5, 1.1, 13, 36, 119, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Great_Mallet("Great Mallet", 43, 88, 5, 1.25, 13, 40, 131, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Steelhead("Steelhead", 54, 81, 5, 1.3, 13, 44, 143, 0, 0, "45% increased stun duration on enemies");
	static Bases::BaseClass Spiny_Maul("Spiny Maul", 55, 103, 5, 1.25, 13, 48, 155, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Plated_Maul("Plated Maul", 72, 108, 5, 1.2, 13, 51, 164, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Dread_Maul("Dread Maul", 77, 104, 5, 1.25, 13, 54, 173, 0, 0, "30% increased stun duration on enemies");
	static Bases::BaseClass Solar_Maul("Solar Maul", 75, 113, 5, 1.25, 13, 56, 187, 0, 0, "%15% increased area of effect");
	static Bases::BaseClass Karui_Maul("Karui Maul", 112, 168, 5, 1, 13, 57, 182, 0, 0, "45% increased stun duration on enemies");
	static Bases::BaseClass Colossus_Mallet("Colossus Mallet", 65, 135, 5.5, 1.3, 13, 59, 188, 0, 0, "30% increased area damage");
	static Bases::BaseClass Piledriver("Piledriver", 77, 115, 5, 1.35, 13, 61, 212, 0, 0, "20% reduced enemy stun threshld");
	static Bases::BaseClass Meatgrinder("Meatgrinder", 74, 138, 5, 1.25, 13, 63, 212, 0, 0, "5% chance to deal double damage");
	static Bases::BaseClass Imperial_Maul("Imperial Maul", 102, 153, 5, 1.1, 13, 65, 212, 0, 0, "10% increased strength");
	static Bases::BaseClass Terror_Maul("Terror Maul", 101, 137, 6, 1.15, 13, 67, 212, 0, 0, "25% chance to double stun duration");
	static Bases::BaseClass Coronal_Maul("Coronal Maul", 91, 136, 5, 1.2, 13, 69, 220, 0, 0, "20% increased area of effect");
	//One Handed Axes
	static Bases::BaseClass Rusted_Hatchet("Rusted Hatchet", 6, 11, 5, 1.5, 11, 2, 12, 6, 0, "");
	static Bases::BaseClass Jade_Hatchet("Jade Hatchet", 10, 15, 5, 1.45, 11, 6, 21, 10, 0, "");
	static Bases::BaseClass Boarding_Axe("Boarding Axe", 11, 21, 5, 1.5, 11, 11, 28, 19, 0, "");
	static Bases::BaseClass Cleaver("Cleaver", 12, 35, 5, 1.3, 11, 16, 48, 14, 0, "");
	static Bases::BaseClass Broad_Axe("Broad Axe", 19, 34, 5, 1.35, 11, 21, 54, 25, 0, "");
	static Bases::BaseClass Arming_Axe("Arming Axe", 14, 42, 5, 1.4, 11, 25, 58, 33, 0, "");
	static Bases::BaseClass Decorative_Axe("Decorative Axe", 27, 50, 5, 1.2, 11, 29, 80, 23, 0, "");
	static Bases::BaseClass Spectral_Axe("Spectral Axe", 29, 46, 5, 1.35, 11, 35, 93, 43, 0, "");
	static Bases::BaseClass Etched_Hatchet("Etched Hatchet", 26, 46, 5, 1.35, 11, 35, 93, 43, 0, "8% increased global physical damage");
	static Bases::BaseClass Jasper_Axe("Jasper Axe", 32, 50, 5, 1.3, 11, 36, 86, 40, 0, "");
	static Bases::BaseClass Tomahawk("Tomahawk", 25, 46, 5, 1.5, 11, 39, 81, 56, 0, "");
	static Bases::BaseClass Wrist_Chopper("Wrist Chopper", 26, 79, 5, 1.2, 11, 42, 112, 32, 0, "");
	static Bases::BaseClass War_Axe("War Axe", 35, 65, 5, 1.3, 11, 45, 106, 49, 0, "");
	static Bases::BaseClass Chest_Splitter("Chest Splitter", 24, 71, 5, 1.4, 11, 48, 105, 60, 0, "");
	static Bases::BaseClass Ceremonial_Axe("Ceremonial Axe", 45, 83, 5, 1.2, 11, 51, 134, 39, 0, "");
	static Bases::BaseClass Wraith_Axe("Wraith Axe", 45, 75, 5, 1.3, 11, 54, 134, 59, 0, "");
	static Bases::BaseClass Engraved_Hatchet("Engraved Hatchet", 40, 71, 5, 1.35, 11, 56, 143, 66, 0, "6% increased global physical damage");
	static Bases::BaseClass Karui_Axe("Karui Axe", 49, 77, 5, 1.3, 11, 57, 132, 62, 0, "");
	static Bases::BaseClass Siege_Axe("Siege Axe", 38, 70, 5, 1.5, 11, 59, 119, 82, 0, "");
	static Bases::BaseClass Reaver_Axe("Reaver Axe", 38, 114, 5, 1.2, 11, 61, 167, 57, 0, "");
	static Bases::BaseClass Butcher_Axe("Butcher Axe", 47, 87, 5, 1.3, 11, 63, 149, 76, 0, "");
	static Bases::BaseClass Vaal_Hatchet("Vaal Hatchet", 30, 90, 5, 1.4, 11, 65, 140, 86, 0, "");
	static Bases::BaseClass Royal_Axe("Royal Axe", 54, 100, 5, 1.2, 11, 67, 167, 57, 0, "");
	static Bases::BaseClass Infernal_Axe("Infernal Axe", 51, 85, 5, 1.3, 11, 69, 158, 76, 0, "");
	static Bases::BaseClass Runic_Hatchet("Runic Hatchet", 44, 79, 5, 1.35, 11, 71, 163, 82, 0, "15% increased global physical damage");
	//Two Handed Axes
	static Bases::BaseClass Stone_Axe("Stone Axe", 12, 20, 5, 1.3, 13, 4, 17, 8, 0, "");
	static Bases::BaseClass Jade_Chopper("Jade Chopper", 19, 30, 5, 1.25, 13, 9, 31, 9, 0, "");
	static Bases::BaseClass Woodsplitter("Woodsplitter", 19, 39, 5, 1.25, 13, 9, 31, 9, 0, "");
	static Bases::BaseClass Poleaxe("Poleaxe", 29, 43, 5, 1.3, 13, 18, 44, 25, 0, "");
	static Bases::BaseClass Double_Axe("Double Axe", 36, 60, 5, 1.25, 13, 23, 62, 27, 0, "");
	static Bases::BaseClass Gilded_Axe("Gilded Axe", 43, 58, 5, 1.3, 13, 28, 64, 37, 0, "");
	static Bases::BaseClass Shadow_Axe("Shadow Axe", 49, 73, 5, 1.25, 13, 33, 80, 37, 0, "");
	static Bases::BaseClass Dagger_Axe("Dagger Axe", 53, 83, 5, 1.2, 13, 36, 89, 43, 0, "50% increased critical strike chance");
	static Bases::BaseClass Jasper_Chopper("Jade Chopper", 58, 91, 5, 1.15, 13, 37, 100, 29, 0, "");
	static Bases::BaseClass Timber_Axe("Timber Axe", 48, 99, 5, 1.25, 13, 41, 97, 45, 0, "");
	static Bases::BaseClass Headsman_Axe("Headsman Axe", 61, 92, 5, 1.3, 13, 45, 99, 57, 0, "");
	static Bases::BaseClass Labrys("Labrys", 74, 123, 5, 1.2, 13, 79, 122, 53, 0, "");
	static Bases::BaseClass Noble_Axe("Noble Axe", 76, 103, 5, 1.3, 13, 52, 113, 65, 0, "");
	static Bases::BaseClass Abyssal_Axe("Abyssal Axe", 81, 121, 5, 1.25, 13, 55, 128, 60, 0, "");
	static Bases::BaseClass Talon_Axe("Talon Axe", 88, 138, 5, 1.2, 13, 59, 140, 67, 0, "50% increased critical strike chance");
	static Bases::BaseClass Karui_Chopper("Karui Chopper", 121, 189, 5, 1.05, 13, 58, 151, 43, 0, "");
	static Bases::BaseClass Sundering_Axe("Sundering Axe", 87, 131, 5.7, 1.35, 13, 62, 140, 86, 0, "+20% to damage over time multiplier for bleeding");
	static Bases::BaseClass Ezomyte_Axe("Ezomyte Axe", 87, 131, 5.7, 1.35, 13, 62, 140, 86, 0, "");
	static Bases::BaseClass Vaal_Axe("Vaal Axe", 104, 174, 5, 1.15, 13, 64, 158, 76, 0, "25% chance to maim on hit");
	static Bases::BaseClass Despot_Axe("Despot Axe", 90, 122, 5, 1.4, 13, 66, 140, 86, 0, "");
	static Bases::BaseClass Void_Axe("Void Axe", 96, 144, 6, 1.25, 13, 68, 149, 76, 0, "");
	static Bases::BaseClass Fleshripper("Fleshripper", 97, 152, 5, 1.2, 13, 70, 156, 84, 0, "50% increased critical strike chance");
	//One Handed Sword
	static Bases::BaseClass Rusted_Sword("Rusted Sword", 4, 9, 5, 1.55, 11, 1, 8, 8, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Copper_Sword("Copper Sword", 6, 14, 5, 1.5, 11, 5, 14, 14, 0, "+45 to accuracy rating");
	static Bases::BaseClass Sabre("Sabre", 5, 22, 5, 1.55, 11, 10, 18, 26, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Broad_Sword("Broad Sword", 15, 21, 5, 1.45, 11, 15, 30, 30, 0, "40% increased global accuracy rating");
	static Bases::BaseClass War_Sword("War Sword", 16, 30, 5, 1.4, 11, 20, 41, 35, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Ancient_Sword("Ancient Sword", 18, 33, 5, 1.45, 11, 24, 4, 44, 0, "+165 to accuracy rating");
	static Bases::BaseClass Elegant_Sword("Elegant Sword", 20, 33, 5, 1.5, 11, 28, 46, 55, 0, "+190 to accuracy rating");
	static Bases::BaseClass Dusk_Blade("Dusk Blade", 19, 54, 5, 1.3, 11, 32, 57, 57, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Hook_Sword("Hook Sword", 28, 60, 5, 1.15, 11, 34, 64, 64, 0, "4% chance to dodge attack hits");
	static Bases::BaseClass Variscite_Blade("Variscite Blade", 25, 53, 5, 1.3, 11, 35, 62, 62, 0, "+240 to accuracy rating");
	static Bases::BaseClass Cutlass("Cutlass", 13, 53, 5, 1.55, 11, 38, 55, 79, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Baselard("Baselard", 37, 53, 5, 1.3, 11, 41, 72, 72, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Battle_Sword("Battle Sword", 38, 70, 5, 1.2, 11, 44, 83, 70, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Elder_Sword("Elder Sword", 36, 66, 5, 1.3, 11, 47, 81, 81, 0, "+330 to accuracy rating");
	static Bases::BaseClass Graceful_Sword("Graceful Sword", 34, 55, 5, 1.5, 11, 50, 78, 94, 0, "+350 to accuracy rating");
	static Bases::BaseClass Twilight_Blade("Twilight Blade", 30, 86, 5, 1.3, 11, 53, 91, 91, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Grappler("Grappler", 44, 94, 5, 1.15, 11, 55, 99, 99, 0, "4% chance to dodage attack hits");
	static Bases::BaseClass Gemstone_Sword("Gemstone Sword", 39, 83, 5, 1.3, 11, 56, 96, 96, 0, "+400 to accuracy rating");
	static Bases::BaseClass Corsair_Sword("Corsair Sword", 20, 80, 5, 1.55, 11, 58, 81, 117, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Gladius("Gladius", 54, 78, 5, 1.3, 11, 60, 113, 113, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Legion_Sword("Legion Sword", 53, 98, 5, 1.2, 11, 62, 122, 104, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Vaal_Blade("Vaal Blade", 46, 86, 5, 1.3, 11, 64, 113, 113, 0, "+460 to accuracy rating");
	static Bases::BaseClass Eternal_Sword("Eternal Sword", 41, 68, 5, 1.5, 11, 66, 104, 122, 0, "+475 to accuracy rating");
	static Bases::BaseClass Midnight_Blade("Midnight Blade", 35, 99, 5, 1.3, 11, 68, 113, 113, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Tiger_Hook("Tiger Hook", 37, 80, 5, 1.4, 11, 70, 119, 119, 0, "6% chance to dodge attack hits");
	//Thrusting One Handed Sword
	static Bases::BaseClass Rusted_Spike("Rusted Spike", 5, 11, 5.5, 1.55, 14, 3, 0, 20, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Whalebone_Rapier("WhaleBone Rapier", 4, 17, 5.5, 1.6, 14, 7, 0, 32, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Battered_Foil("Battered Foid", 11, 20, 6, 1.5, 14, 12, 0, 47, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Basket_Rapier("Basket Rapier", 11, 25, 5.5, 1.55, 14, 17, 0, 62, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Jagged_Foil("Jagged Foid", 12, 29, 5.5, 1.6, 14, 22, 0, 77, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Antique_Rapier("Antique Rapier", 12, 46, 6.5, 1.3, 14, 26, 0, 89, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Elegant_Foil("Elegant Foil", 18, 33, 5.5, 1.6, 14, 30, 0, 101, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Thorn_Rapier("Thorn Rapier", 19, 44, 5.7, 1.4, 14, 34, 0, 113, 0, "+35% to global critical strike multiplayer");
	static Bases::BaseClass Smallsword("Smallsword", 19, 40, 6, 1.55, 14, 36, 0, 124, 0, "15% chance to cause bleeding on hit");
	static Bases::BaseClass Wyrmbone_Rapier("Wyrmbone Rapier", 13, 51, 5.5, 1.5, 14, 37, 0, 122, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Burnished_Foil("Burnished Foil", 25, 46, 6, 1.4, 14, 40, 0, 131, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Estoc("Estoc", 21, 50, 5.5, 1.5, 14, 43, 0, 140, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Serrated_Foil("Serrated Foil", 21, 49, 5.5, 1.6, 14, 46, 0, 149, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Primeval_Rapier("Primeval Rapier", 18, 73, 6.5, 1.3, 14, 49, 0, 158, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Fancy_Foil("Fancy Foil", 28, 51, 5.5, 1.6, 14, 52, 0, 167, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Apex_Rapier("Apex Rapier", 29, 67, 5.7, 1.4, 14, 55, 0, 176, 0, "+35% to global critical strike multiplayer");
	static Bases::BaseClass Courtesan_Sword("Courtesan Sword", 29, 60, 6, 1.55, 14, 57, 0, 190, 0, "15% chance to cause bleeding on hit");
	static Bases::BaseClass Dragonbone_Rapier("Dragonbone Rapier", 19, 75, 5.5, 1.5, 14, 58, 0, 185, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Tempered_Foil("Tempered Foil", 35, 65, 6, 1.4, 14, 60, 0, 212, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Pecoraro("Pecoraro", 29, 69, 5.5, 1.5, 14, 62, 0, 212, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Spiraled_Foil("Spiraled Foil", 27, 64, 5.5, 1.6, 14, 64, 0, 212, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Vaal_Rapier("Vaal Rapier", 22, 87, 6.5, 1.3, 14, 66, 0, 212, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Jewelled_Foil("Jewelled Foil", 32, 60, 5.5, 1.6, 14, 68, 0, 212, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Harpy_Rapier("Harpy Rapier", 31, 72, 5.7, 1.4, 14, 70, 0, 212, 0, "+35% to global critical strike multiplayer");
	static Bases::BaseClass Dragoon_Sword("Dragoon Sword", 32, 66, 6, 1.5, 14, 72, 0, 220, 0, "20% chance to cause bleeding on hit");
	//Two Handed Sword
	static Bases::BaseClass Corroded_Blade("Corroded Blade", 8, 16, 5, 1.45, 13, 3, 11, 11, 0, "40% increased global accuracy rating");
	static Bases::BaseClass Longsword("Longsword", 11, 26, 5, 1.4, 13, 8, 20, 17, 0, "+60 to accuracy rating");
	static Bases::BaseClass Bastard_Sword("Bastard Sword", 17, 29, 5, 1.45, 13, 12, 21, 30, 0, "60% increased global accuracy rating");
	static Bases::BaseClass TwoHanded_Sword("Two-Handed Sword", 20, 38, 5, 1.4, 13, 17, 33, 33, 0, "+120 to accuracy rating");
	static Bases::BaseClass Etched_Greatsword("Etched Greatsword", 23, 48, 5, 1.4, 13, 22, 45, 38, 0, "60% increased global accuracy rating");
	static Bases::BaseClass Ornate_Sword("Ornate Sword", 30, 50, 5, 1.4, 13, 27, 45, 54, 0, "+185 to accuracy rating");
	static Bases::BaseClass Spectral_Sword("Spectral Sword", 31, 65, 5, 1.35, 13, 32, 57, 57, 0, "45% increased global accuracy rating");
	static Bases::BaseClass Curved_Blade("Curved Blade", 41, 68, 6, 1.35, 13, 35, 62, 73, 0, "+40% to global critical strike multiplayer");
	static Bases::BaseClass Butcher_Sword("Butcher Sword", 34, 79, 5, 1.3, 13, 36, 69, 58, 0, "+250 to accuracy rating");
	static Bases::BaseClass Footman_Sword("Footman Sword", 39, 65, 5, 1.45, 13, 40, 57, 83, 0, "60% increased global accuracy rating");
	static Bases::BaseClass Highland_Blade("Highland Blade", 45, 84, 5, 1.35, 13, 44, 77, 77, 0, "+305 to accuracy rating");
	static Bases::BaseClass Engraved_Greatsword("Engraved Greatsword", 49, 102, 5, 1.3, 13, 48, 91, 76, 0, "60% increased global accuracy rating");
	static Bases::BaseClass Tiger_Sword("Tiger Sword", 54, 89, 5, 1.4, 13, 51, 80, 96, 0, "+360 to accuracy rating");
	static Bases::BaseClass Wraith_Sword("Wraith Sword", 52, 109, 5, 1.35, 13, 56, 96, 113, 0, "45% increased global accuracy rating");
	static Bases::BaseClass Lithe_Blade("Lithe Blade", 63, 104, 6, 1.35, 13, 56, 96, 113, 0, "+40% to global critical strike multiplayer");
	static Bases::BaseClass Headmans_Sword("Headman's Sword", 55, 128, 5, 1.3, 13, 57, 106, 89, 0, "+400 to accuracy rating");
	static Bases::BaseClass Reaver_Sword("Reaver Sword", 62, 104, 5, 1.5, 13, 59, 82, 119, 0, "60% increased global accuracy rating");
	static Bases::BaseClass Ezomyte_Blade("Ezomyte Blade", 62, 115, 6.5, 1.4, 13, 61, 113, 113, 0, "+25% to global critical strike multiplayer");
	static Bases::BaseClass Vaal_Greatsword("Vaal Greatsword", 68, 142, 5, 1.3, 13, 63, 122, 104, 0, "+470 to accuracy rating");
	static Bases::BaseClass Lion_Sword("Lion Sword", 69, 129, 5, 1.45, 13, 65, 104, 122, 0, "+50 to strength and dextrity");
	static Bases::BaseClass Infernal_Sword("Infernal Sword", 62, 129, 5, 1.35, 13, 67, 113, 113, 0, "30% increased elemental damage with attack skills");
	static Bases::BaseClass Exquisite_Blade("Exquisite Blade", 67, 112, 5.7, 1.35, 13, 70, 119, 131, 0, "+50% to global critical strike multiplayer");
	//Bows
	static Bases::BaseClass Crude_Bow("Crude Bow", 5, 13, 5, 1.4, 0, 1, 0, 14, 0, "");
	static Bases::BaseClass Short_Bow("Short Bow", 6, 16, 5, 1.5, 0, 5, 0, 26, 0, "");
	static Bases::BaseClass Long_Bow("Long Bow", 6, 25, 6, 1.3, 0, 9, 0, 38, 0, "");
	static Bases::BaseClass Composite_Bow("Composite Bow", 12, 26, 6, 1.3, 0, 14, 0, 53, 0, "");
	static Bases::BaseClass Recurve_Bow("Recurve Bow", 11, 34, 6.7, 1.25, 0, 18, 0, 65, 0, "+(15-25)% to global critical strike multipler");
	static Bases::BaseClass Bone_Bow("Bone Bow", 11, 34, 6.5, 1.4, 0, 23, 0, 80, 0, "");
	static Bases::BaseClass Royal_Bow("Royal Bow", 10, 41, 5, 1.45, 0, 28, 0, 95, 0, "(20-24)% increased elemental damage with attack skills");
	static Bases::BaseClass Death_Bow("Death Bow", 20, 53, 5, 1.2, 0, 32, 0, 107, 0, "(30-50)% increased critical strike chance");
	static Bases::BaseClass Reflex_Bow("Reflex Bow", 27, 40, 5.5, 1.4, 0, 36, 0, 124, 0, "6% increased movement speed");
	static Bases::BaseClass Grove_Bow("Grove Bow", 15, 44, 5, 1.5, 0, 35, 0, 116, 0, "");
	static Bases::BaseClass Decurve_Bow("Decurve Bow", 17, 69, 6, 1.25, 0, 38, 0, 125, 0, "");
	static Bases::BaseClass Compound_Bow("Compound Bow", 26, 55, 6, 1.3, 0, 41, 0, 134, 0, "");
	static Bases::BaseClass Sniper_Bow("Sniper Bow", 23, 68, 6.7, 1.25, 0, 44, 0, 143, 0, "+(15-25)% to global critical strike multiplier");
	static Bases::BaseClass Ivory_Bow("Ivory Bow", 20, 61, 6.5, 1.4, 0, 47, 0, 152, 0, "");
	static Bases::BaseClass Highborn_Bow("Highborn Bow", 17, 67, 5, 1.45, 0, 50, 0, 161, 0, "(20-24)% increased elemental damage with attack skills");
	static Bases::BaseClass Decimation_Bow("Decimation Bow", 31, 81, 5, 1.2, 0, 53, 0, 170, 0, "(30-50)% increased critical strike chance");
	static Bases::BaseClass Steelwood_Bow("Steelwood Bow", 40, 60, 5.5, 1.4, 0, 57, 0, 190, 0, "6% increased movement speed");
	static Bases::BaseClass Thicket_Bow("Thicket Bow", 22, 67, 5, 1.5, 0, 56, 0, 179, 0, "");
	static Bases::BaseClass Citadel_Bow("Citadel Bow", 25, 100, 6, 1.25, 0, 58, 0, 185, 0, "");
	static Bases::BaseClass Ranger_Bow("Ranger Bow", 39, 81, 6, 1.3, 0, 60, 0, 212, 0, "");
	static Bases::BaseClass Assassin_Bow("Assassin Bow", 30, 89, 6.7, 1.25, 0, 62, 0, 212, 0, "+(15-25)% to global critical strike multiplier");
	static Bases::BaseClass Spine_Bow("Spine Bow", 26, 78, 6.5, 1.4, 0, 64, 0, 212, 0, "");
	static Bases::BaseClass Imperial_Bow("Imperial Bow", 20, 78, 5, 1.45, 0, 66, 0, 212, 0, "(20-24)% increased elemental damage with attack skills");
	static Bases::BaseClass Harbinger_Bow("Harbringer Bow", 35, 92, 5, 1.2, 0, 68, 0, 212, 0, "(30-50)% increased critical strike chance");
	static Bases::BaseClass Maraketh_Bow("Maraketh Bow", 44, 66, 5.5, 1.4, 0, 71, 0, 222, 0, "10% increased movement speed");
	//Claws
	static Bases::BaseClass Nailed_Fist("Nailed Fist", 4, 11, 6.2, 1.6, 11, 3, 0, 11, 11, "+3 life gained for each enemy hit by attacks");
	static Bases::BaseClass Sharktooth_Claw("Sharktooth Claw", 6, 17, 6.5, 1.5, 11, 7, 0, 14, 20, "+6 life gained for each enemy hit by attacks");
	static Bases::BaseClass Awl("Awl", 7, 23, 6.3, 1.55, 11, 12, 0, 25, 25, "+7 life gained for each enemy hit by attacks");
	static Bases::BaseClass Cats_Paw("Cat's Paw", 12, 22, 6, 1.6, 11, 17, 0, 39, 27, "+8 life gained for each enemy hit by attacks");
	static Bases::BaseClass Blinder("Blinder", 12, 31, 6.3, 1.55, 11, 22, 0, 41, 41, "+12 life gained for each enemy hit by attacks");
	static Bases::BaseClass Timeworn_Claw("Timeworn Claw", 16, 43, 6.5, 1.3, 11, 26, 0, 39, 56, "+19 life gained for each enemy hit by attacks");
	static Bases::BaseClass Sparkling_Claw("Sparkling Claw", 14, 38, 6, 1.6, 11, 30, 0, 64, 44, "+15 life gained for each enemy hit by attacks");
	static Bases::BaseClass Fright_Claw("Fright Claw", 12, 46, 6.3, 1.5, 11, 34, 0, 61, 61, "+20 life gained for each enemy hit by attacks");
	static Bases::BaseClass Double_Claw("Double Claw", 15, 44, 6.3, 1.5, 11, 36, 0, 67, 67, "+6 mana gained for each enemy hit by attacks\n+15 life gained for each enemy hit by attacks");
	static Bases::BaseClass Thresher_Claw("Thresher Claw", 20, 53, 6.5, 1.3, 11, 37, 0, 53, 77, "+25 life gained for each enemy hit by attacks");
	static Bases::BaseClass Gouger("Gouger", 15, 51, 6.3, 1.5, 11, 40, 0, 70, 70, "+24 life gained for each enemy hit by attacks");
	static Bases::BaseClass Tigers_Paw("Tiger's Paw", 23, 43, 6, 1.6, 11, 43, 0, 88, 61, "1.6% of physical attack damage leeched as life");
	static Bases::BaseClass Gut_Ripper("Gut Ripper", 20, 53, 6.3, 1.5, 11, 46, 0, 80, 80, "+44 life gained for each enemy hit by attacks");
	static Bases::BaseClass Prehistoric_Claw("Prehistoric Claw", 26, 68, 6.5, 1.3, 11, 49, 0, 69, 100, "2% of physical attack damage leeched as life");
	static Bases::BaseClass Noble_Claw("Noble Claw", 21, 56, 6, 1.6, 11, 52, 0, 105, 73, "+40 life gained for each enemy hit by attacks");
	static Bases::BaseClass Eagle_Claw("Eagle Claw", 17, 69, 6.3, 1.5, 11, 55, 0, 94, 94, "2% of physical attack damage leeched as life");
	static Bases::BaseClass Twin_Claw("Twin Claw", 21, 64, 6.3, 1.5, 11, 57, 0, 103, 103, "+10 mana gained for each enemy hit by attacks\n+28 life gained for each enemy hit by attacks");
	static Bases::BaseClass Great_White_Claw("Great White Claw", 30, 78, 6.5, 1.3, 11, 58, 0, 81, 117, "+46 life gained for each enemy hit by attacks");
	static Bases::BaseClass Throat_Stabber("Throat Stabber", 21, 73, 6.3, 1.5, 11, 60, 0, 113, 113, "+40 life gained for each enemy hit by attacks");
	static Bases::BaseClass Hellions_Paw("Hellion's Paw", 29, 55, 6, 1.6, 11, 62, 0, 131, 95, "1.6% of physical attacks damage leeched as life");
	static Bases::BaseClass Eye_Gouger("Eye Gouger", 26, 68, 6.3, 1.5, 11, 64, 0, 113, 113, "+50 life gained for each enemy hit by attacks");
	static Bases::BaseClass Vaal_Claw("Vaal Claw", 29, 76, 6.5, 1.3, 11, 66, 0, 95, 131, "2% of physical attack damage leeched as life");
	static Bases::BaseClass Imperial_Claw("Imperial Claw", 25, 65, 6, 1.6, 11, 68, 0, 131, 95, "+46 life gained for each enemy hit by attacks");
	static Bases::BaseClass Terror_Claw("Terror Claw", 18, 71, 6.3, 1.5, 11, 70, 0, 113, 113, "2% of physical attack damage leeched as life");
	static Bases::BaseClass Gemini_Claw("Gemini Claw", 23, 68, 6.3, 1.5, 11, 72, 0, 121, 121, "+14 mana gained for each enemy hit by attacks\n+ life gained for each enemy hit by attacks");
	//Daggers
	static Bases::BaseClass Glass_Shank("Glass Shank", 6, 10, 6, 1.5, 10, 1, 0, 9, 6, "30% increased global critical strike chance");
	static Bases::BaseClass Skinning_Knife("Skinning Knife", 4, 17, 6, 1.45, 10, 5, 0, 16, 11, "30% increased global critical strike chance");
	static Bases::BaseClass Stiletto("Stiletto", 7, 27, 6.1, 1.5, 10, 15, 0, 30, 30, "30% increased global critical strike chance");
	static Bases::BaseClass Flaying_Knife("Flaying Knife", 11, 45, 6, 1.4, 10, 30, 0, 64, 44, "30% increased global critical strike chance");
	static Bases::BaseClass Prong_Dagger("Prong Dagger", 14, 54, 6.2, 1.35, 10, 36, 0, 55, 77, "4% chance to block attack damage");
	static Bases::BaseClass Poignard("Poignard", 13, 52, 6.1, 1.5, 10, 41, 0, 72, 72, "30% increased global critical strike chance");
	static Bases::BaseClass Trisula("Trisula", 19, 74, 6.5, 1.35, 10, 51, 0, 83, 99, "4% chance to block attack damage");
	static Bases::BaseClass Gutting_Knife("Gutting Knife", 19, 76, 6.5, 1.4, 10, 56, 0, 113, 78, "30% increased global critical strike chance");
	static Bases::BaseClass Ambusher("Ambusher", 19, 74, 6.1, 1.5, 10, 60, 0, 113, 113, "30% increased global critical strike chance");
	static Bases::BaseClass Sai("Sai", 22, 88, 6.2, 1.35, 10, 70, 0, 121, 121, "6% chance to block attack damage");
	//Rune Daggers
	static Bases::BaseClass Carving_Knife("Carving Knife", 3, 26, 6.3, 1.45, 10, 10, 0, 18, 26, "30% increased global critical strike chance");
	static Bases::BaseClass Boot_Knife("Boot Knife", 8, 34, 6.3, 1.45, 10, 20, 0, 31, 45, "30% increased global critical strike chance");
	static Bases::BaseClass Copper_Kris("Copper Kris", 10, 41, 6.5, 1.3, 10, 24, 0, 28, 60, "50% increased global critical strike chance");
	static Bases::BaseClass Skean("Skan", 11, 43, 6.3, 1.45, 10, 28, 0, 42, 60, "30% increased global critical strike chance");
	static Bases::BaseClass Imp_Dagger("Imp Dagger", 15, 59, 6.5, 1.2, 10, 32, 0, 36, 78, "40% increased global critical strike chance");
	static Bases::BaseClass Butcher_Knife("Butcher Knife", 7, 62, 6.3, 1.4, 10, 38, 0, 55, 79, "30% increased global critical strike chance");
	static Bases::BaseClass Boot_Blade("Boot Knife", 15, 59, 6.3, 1.4, 10, 44, 0, 63, 90, "30% increased global critical strike chance");
	static Bases::BaseClass Golden_Kris("Golden Kris", 19, 75, 6.5, 1.2, 10, 47, 0, 51, 110, "50% increased global critical strike chance");
	static Bases::BaseClass Royal_Skean("Royal Sekan", 16, 64, 6.3, 1.45, 10, 50, 0, 71, 102, "30% increased global critical strike chance");
	static Bases::BaseClass Fiend_Dagger("Fiend Dagger", 22, 87, 6.5, 1.2, 10, 53, 0, 58, 123, "40% increased global critical strike chance");
	static Bases::BaseClass Slaughter_Knife("Slaughter Knife", 10, 86, 6.3, 1.4, 10, 58, 0, 81, 117, "30% increased global critical strike chance");
	static Bases::BaseClass Ezomyte_Dagger("Ezomyte Dagger", 20, 79, 6.3, 1.4, 10, 62, 0, 95, 131, "30% increased global critical strike chance");
	static Bases::BaseClass Platinum_Kris("Platinum Kris", 24, 95, 6.5, 1.2, 10, 64, 0, 76, 149, "50% increased global critical strike chance");
	static Bases::BaseClass Imperial_Skean("Imperial Skean", 18, 73, 6.3, 1.5, 10, 66, 0, 95, 131, "30% increased global critical strike chance");
	static Bases::BaseClass Demon_Dagger("Demon Dagger", 24, 97, 6.5, 1.2, 10, 68, 0, 76, 149, "40% increased global critical strike chance");
	//Staves
	static Bases::BaseClass Gnarled_Branch("Gnarled Branch", 9, 19, 6, 1.3, 13, 4, 12, 0, 12, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Primitive_Staff("Primitive Staff", 10, 31, 6.2, 1.3, 13, 9, 20, 0, 20, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Long_Staff("Long Staff", 24, 41, 6, 1.3, 13, 18, 35, 0, 35, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Royal_Staff("Royal Staff", 27, 81, 6.5, 1.15, 13, 28, 51, 0, 51, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Crescent_Staff("Crescent Staff", 41, 85, 6, 1.2, 13, 36, 66, 0, 66, "80% increased global critical strike chance");
	static Bases::BaseClass Woodful_Staff("Woodful Staff", 34, 102, 6.2, 1.15, 13, 37, 65, 0, 65, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Quarterstaff("Quarterstaff", 51, 86, 6, 1.3, 13, 45, 78, 0, 78, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Highborn_Staff("Highborn Staff", 48, 145, 6.5, 1.15, 13, 52, 89, 0, 89, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Moon_Staff("Moon Staff", 66, 138, 6, 1.2, 13, 57, 101, 0, 101, "80% increased global critical strike chance");
	static Bases::BaseClass Primordial_Staff("Primordial Staff", 55, 165, 6.2, 1.15, 13, 58, 99, 0, 99, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Lathi("Lathi", 72, 120, 6, 1.3, 13, 62, 113, 0, 113, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Imperial_Staff("Imperial Staff", 57, 171, 7, 1.15, 13, 66, 113, 0, 113, "+18% chance to block attack damage while wielding a staff");
	static Bases::BaseClass Eclipse_Staff("Eclipse Staff", 70, 145, 6, 1.2, 13, 70, 117, 0, 117, "100% increased global critica strike chance");
	//Wands
	static Bases::BaseClass Driftwood_Wand("Driftwood Wand", 5, 9, 7, 1.4, 0, 1, 0, 0, 14, "(8-12)% increased spell damage");
	static Bases::BaseClass Goats_Horn("Goat's Horn", 9, 16, 7, 1.2, 0, 6, 0, 0, 29, "(10-14)% increased spell damage");
	static Bases::BaseClass Carved_Wand("Carved Wand", 9, 17, 7, 1.5, 0, 12, 0, 0, 47, "(11-15)% increased spell damage");
	static Bases::BaseClass Quartz_Wand("Quartz Wand", 14, 27, 7, 1.3, 0, 18, 0, 0, 65, "(18-22)% increased spell damage");
	static Bases::BaseClass Spiraled_Wand("Spiraled Wand", 12, 37, 7, 1.3, 0, 24, 0, 0, 83, "(15-19)% increased spell damage");
	static Bases::BaseClass Sage_Wand("Sage Wand", 23, 42, 8, 1.2, 0, 30, 0, 0, 119, "(17-21)% increased spell damage");
	static Bases::BaseClass Pagan_Wand("Pagan Wand", 22, 40, 7, 1.35, 0, 34, 0, 0, 118, "10% increased case speed");
	static Bases::BaseClass Fauns_Horn("Faun's Horn", 26, 48, 7, 1.2, 0, 35, 0, 0, 116, "(20-24)% increased spell damage");
	static Bases::BaseClass Engraved_Wand("Engraved Wand", 21, 38, 7, 1.5, 0, 40, 0, 0, 131, "(22-26)% increased spell damage");
	static Bases::BaseClass Crystal_Wand("Crystal Wand", 28, 52, 7, 1.3, 0, 45, 0, 0, 146, "(29-33)% increased spell damage");
	static Bases::BaseClass Serpent_Wand("Serpent Wand", 21, 64, 7, 1.3, 0, 49, 0, 0, 158, "(26-30)% increased spell damage");
	static Bases::BaseClass Omen_Wand("Omen Wand", 33, 61, 8, 1.2, 0, 53, 0, 0, 200, "(27-31)% increased spell damage");
	static Bases::BaseClass Heathen_Wand("Heathen Wand", 31, 57, 7, 1.35, 0, 55, 0, 0, 184, "10% increased cast speed");
	static Bases::BaseClass Demons_Horn("Demon's Horn", 38, 71, 7, 1.2, 0, 56, 0, 0, 179, "(31-35)% increased spell damage");
	static Bases::BaseClass Imbued_Wand("Imbued Wand", 29, 53, 7, 1.5, 0, 59, 0, 0, 188, "(33-37)% increased spell damage");
	static Bases::BaseClass Opal_Wand("Opal Wand", 35, 65, 7, 1.3, 0, 62, 0, 0, 212, "(38-42)% increased spell damage");
	static Bases::BaseClass Tornado_Wand("Tornado Wand", 25, 75, 7, 1.3, 0, 65, 0, 0, 212, "(35-39)% increased spell damage");
	static Bases::BaseClass Prophecy_Wand("Prophecy Wand", 35, 64, 8, 1.2, 0, 68, 0, 0, 245, "(36-40)% increased spell damage");
	static Bases::BaseClass Profane_Wand("Profane Wand", 33, 61, 7, 1.35, 0, 70, 0, 0, 245, "14% increased cast speed");
	static Bases::BaseClass Convoking_Wand("Convoking Wand", 30, 55, 7, 1.4, 0, 72, 0, 0, 242, "Can roll minion modifiers");
}