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
	static Bases::BaseClass Driftwood_Club("Driftwood Club", 6, 8,  5, 1.45, 11, 14, 0, 0, "10% reduced enemy stun threshold")
		static Bases::BaseClass Tribal_Club
		static Bases::BaseClass Spiked_Club
		static Bases::BaseClass Stone_Hammer
		static Bases::BaseClass War_Hammer
		static Bases::BaseClass Bladed_Mace
		static Bases::BaseClass Ceremonial_Mace
		static Bases::BaseClass Dream_Mace
		static Bases::BaseClass Wyrm_Mace
		static Bases::BaseClass Petrified_Club
		static Bases::BaseClass Barbed_Club
		static Bases::BaseClass Rock_Breaker
		static Bases::BaseClass Battle_Hammer
		static Bases::BaseClass Flanged_Mace
		static Bases::BaseClass Ornate_Mace
		static Bases::BaseClass Phantom_Mace
		static Bases::BaseClass Dragon_Mace
		static Bases::BaseClass Ancestral_Club
		static Bases::BaseClass Tenderizer
		static Bases::BaseClass Gavel
		static Bases::BaseClass Legion_Hammer
		static Bases::BaseClass Pernach
		static Bases::BaseClass Auric_Mace
		static Bases::BaseClass Nightmare_Mace
		static Bases::BaseClass Behemoth_Mace
}