#include <iostream>
#include <thread>
#include <random>
#include <ctime>
#include <string>
#include <map>
#include <chrono>


#include "baseClass.h"

std::mt19937 mtGen;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 1);
std::uniform_int_distribution<int> oneToHundred_distribution(0,100);
std::uniform_int_distribution<int> type_distribution(0, 13);
std::uniform_int_distribution<int> twoSockets_distribution(1, 120);
std::uniform_int_distribution<int> threeSockets_distribution(1, 270);
std::uniform_int_distribution<int> fourSockets_distribution(1, 300);
std::uniform_int_distribution<int> fiveSockets_distribution(1, 305);
std::uniform_int_distribution<int> sixSockets_distribution(1, 306);

enum itemType
{
	Sceptre, OneHandedMace, TwoHandedMace, OneHandedAxe, TwoHandedAxe, OneHandedSword, ThrustingOneHandedSword, TwoHandedSword, Bow, Claw, Dagger, RuneDagger, Stave, Wand
};

enum itemRarity
{
	Normal, Magic, Rare, Unique //TODO: Add unique types, currently it's just part of enum
};

enum socketColors
{
	Blue, Green, Red // Color of sockets item can have
};

enum baseTypeSceptre
{
	Driftwood_Sceptre, Darkwood_Sceptre, Bronze_Sceptre, Quartz_Sceptre, Iron_Sceptre, Ochre_Sceptre, Ritual_Sceptre, 
	Shadow_Sceptre, Grinning_Fetish, Horned_Sceptre, Sekhem, Crystal_Sceptre, Lead_Sceptre, Blood_Sceptre, 
	Royal_Sceptre, Abyssal_Sceptre, Stag_Sceptre, Karui_Sceptre, Tyrants_Sekhem, Opal_Sceptre,
	Platinum_Sceptre, Vaal_Sceptre, Carnal_Sceptre, Void_Sceptre, Sambar_Sceptre 
	//Oscillating, Stabilising, Alternating,
};
enum baseTypeOneHandedMace
{
	Driftwood_Club, Tribal_Club, Spiked_Club, Stone_Hammer, War_Hammer, Bladed_Mace, Ceremonial_Mace,
	Dream_Mace, Wyrm_Mace, Petrified_Club, Barbed_Club, Rock_Breaker, Battle_Hammer,
	Flanged_Mace, Ornate_Mace, Phantom_Mace, Dragon_Mace, Ancestral_Club, Tenderizer,
	Gavel, Legion_Hammer, Pernach, Auric_Mace, Nightmare_Mace, Behemoth_Mace
	//Flare_Mace, Crack_Mace, Boom_Mace 
};
enum baseTypeTwoHandedMace
{
	Driftwood_Maul, Tribal_Maul, Mallet, Sledgehammer, Jagged_Maul, Brass_Maul, Fright_Maul,
	Morning_Star, Totemic_Maul, Great_Mallet, Steelhead, Spiny_Maul, Plated_Maul, Dread_Maul,
	Solar_Maul, Karui_Maul, Colossus_Mallet, Piledriver, Meatgrinder, Imperial_Maul, Terror_Maul, Coronal_Maul
	//Blunt_Force_Condenser, Crushing_Force_Magnifier, Impact_Force_Propagator 
};
enum baseTypeOneHandedAxe
{
	Rusted_Hatchet, Jade_Hatchet, Boarding_Axe, Cleaver, Broad_Axe, Arming_Axe, Decorative_Axe, Spectral_Axe,
	Etched_Hatchet, Jasper_Axe, Tomahawk, Wrist_Chopper, War_Axe, Chest_Splitter, Ceremonial_Axe, Wraith_Axe, 
	Engraved_Hatchet, Karui_Axe, Siege_Axe, Reaver_Axe, Butcher_Axe, Vaal_Hatchet, Royal_Axe, Infernal_Axe, Runic_Hatchet
	//,Maltreatment_Axe, Disapprobation_Axe, Psychotic_Axe
};
enum baseTypeTwoHandedAxe
{
	Stone_Axe, Jade_Chopper, Woodsplitter, Poleaxe, Double_Axe, Gilded_Axe, Shadow_Axe, Dagger_Axe, Jasper_Chopper,
	Timber_Axe, Headsman_Axe, Labrys, Noble_Axe, Abyssal_Axe, Talon_Axe, Karui_Chopper, Sundering_Axe, Ezomyte_Axe, 
	Vaal_Axe, Despot_Axe, Void_Axe, Fleshripper
	//,Prime_Cleaver, Honed_Cleaver, Apex_Cleaver
};
enum baseTypeOneHandedSword
{
	Rusted_Sword, Copper_Sword, Sabre, Broad_Sword, War_Sword, Ancient_Sword, Elegant_Sword, Dusk_Blade,Hook_Sword,
	Variscite_Blade, Cutlass, Baselard, Battle_Sword, Elder_Sword, Graceful_Sword, Twilight_Blade, Grappler,
	Gemstone_Sword, Corsair_Sword, Gladius, Legion_Sword, Vaal_Blade, Eternal_Sword, Midnight_Blade, Tiger_Hook
	//,Fickle_Spiritblade, Capricious_Spiritblade, Anarchic_Spiritblade
};
enum baseTypeThrustingOneHandedSword
{
	Rusted_Spike, Whalebone_Rapier, Battered_Foil, Basket_Rapier, Jagged_Foil, Antique_Rapier, Elegant_Foil, Thorn_Rapier,
	Smallsword, Wyrmbone_Rapier, Burnished_Foil, Estoc, Serrated_Foil, Primeval_Rapier, Fancy_Foil, Apex_Rapier,
	Courtesan_Sword, Dragonbone_Rapier, Tempered_Foil, Pecoraro, Spiraled_Foil, Vaal_Rapier, Jewelled_Foil, Harpy_Rapier, Dragoon_Sword
};
enum baseTypeTwoHandedSword
{
	Corroded_Blade, Longsword, Bastard_Sword, TwoHanded_Sword, Etched_Greatsword, Ornate_Sword, Spectral_Sword, Curved_Blade,
	Butcher_Sword, Footman_Sword, Highland_Blade, Engraved_Greatsword, Tiger_Sword, Wraith_Sword, Lithe_Blade, Headmans_Sword,
	Reaver_Sword, Ezomyte_Blade, Vaal_Greatsword, Lion_Sword, Infernal_Sword, Exquisite_Blade
	//,Rebuking_Blade, Blasting_Blade, Banishing_Blade
};
enum baseTypeBow
{
	Crude_Bow, Short_Bow, Long_Bow, Composite_Bow, Recurve_Bow, Bone_Bow, Royal_Bow, Death_Bow, Reflex_Bow, Grove_Bow, Decurve_Bow,
	Compound_Bow, Sniper_Bow, Ivory_Bow, Highborn_Bow, Decimation_Bow, Steelwood_Bow, Thicket_Bow, Citadel_Bow, Ranger_Bow, 
	Assassin_Bow, Spine_Bow, Imperial_Bow, Harbinger_Bow, Maraketh_Bow
	//,Hedron_Bow, Foundry_Bow, Solarine_Bow, 
};
enum baseTypeClaw
{
	Nailed_Fist, Sharktooth_Claw, Awl, Cats_Paw, Blinder, Timeworn_Claw, Sparkling_Claw, Fright_Claw, Double_Claw, Thresher_Claw,
	Gouger, Tigers_Paw, Gut_Ripper, Prehistoric_Claw, Noble_Claw, Eagle_Claw, Twin_Claw, Great_White_Claw, Throat_Stabber, Hellions_Paw,
	Eye_Gouger, Vaal_Claw, Imperial_Claw, Terror_Claw, Gemini_Claw
	//Shadow_Fangs, Malign_Fangs, Void_Fangs
};
enum baseTypeDagger
{
	Glass_Shank, Skinning_Knife, Stiletto, Flaying_Knife, Prong_Dagger, Poignard, Trisula,
	Gutting_Knife, Ambusher, Sai
	//, Hollowpoint_Dagger, Pressurised_Dagger, Pneumatic_Dagger, Ethereal_Blade
};
enum baseTypeRuneDagger
{
	Carving_Knife, Boot_Knife, Copper_Kris, Skean, Imp_Dagger, Butcher_Knife, Boot_Blade, Golden_Kris, Royal_Skean, Fiend_Dagger, 
	Slaughter_Knife, Ezomyte_Dagger, Platinum_Kris, Imperial_Skean, Demon_Dagger
	//,Flickerflame_Blade, Flashfire_Blade, Infernal_Blade
};
enum baseTypeStave
{
	Gnarled_Branch, Primitive_Staff, Long_Staff, Royal_Staff, Crescent_Staff, Woodful_Staff, Quarterstaff, Highborn_Staff, Moon_Staff, 
	Primordial_Staff, Lathi, Imperial_Staff, Eclipse_Staff
	//,Transformer_Staff, Reciprocation_Staff, Battery_Staff
};
enum baseTypeWand
{
	Driftwood_Wand, Goats_Horn, Carved_Wand, Quartz_Wand, Spiraled_Wand, Sage_Wand, Pagan_Wand, Fauns_Horn, Engraved_Wand,
	Crystal_Wand, Serpent_Wand, Omen_Wand, Heathen_Wand, Demons_Horn, Imbued_Wand, Opal_Wand, Tornado_Wand, Prophecy_Wand,
	Profane_Wand, Convoking_Wand
	//,Assembler_Wand, Congregator_Wand, Accumulator_Wand
};


//------------------------------------------------------------------------------------------------------
//
//				ITEM CLASS
//
//------------------------------------------------------------------------------------------------------
class Item
{
public:
	int ilvl; //Item itemLvL
	itemType type; //Type of weapon (like staff, sceptre, bow etc)
	int base; //Nr from enums of item base
	Bases::BaseClass baseClass; //Item base
	itemRarity rarity; // Rarity of the item
	int maxSockets; // Max sockets item can have
	int nrOfSockets; // Nr of sockets item have
	socketColors socket[6]; //socket[ID_OF_SOCKET]=COLOR
	bool link[5]; //Links between socket (TRUE = exist | FALSE = don't exist) ([0] link between socket 0 and 1, [3] link between socket 3 and 4)


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE ITEM BASE (holy fck it was boring and tedious)
	//
	//------------------------------------------------------------------------------------------------------
	void generateBaseType()
	{
		switch (type)
		{
			case itemType::Sceptre: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 24;
					else if (ilvl >= 68)
						maxRolledBaseID = 23;
					else if (ilvl >= 66)
						maxRolledBaseID = 22;
					else if (ilvl >= 64)
						maxRolledBaseID = 21;
					else if (ilvl >= 62)
						maxRolledBaseID = 20;
					else if (ilvl >= 60)
						maxRolledBaseID = 19;
					else if (ilvl >= 58)
						maxRolledBaseID = 18;
					else if (ilvl >= 56)
						maxRolledBaseID = 17;
					else if (ilvl >= 55)
						maxRolledBaseID = 16;
					else if (ilvl >= 53)
						maxRolledBaseID = 15;
					else if (ilvl >= 50)
						maxRolledBaseID = 14;
					else if (ilvl >= 47)
						maxRolledBaseID = 13;
					else if (ilvl >= 44)
						maxRolledBaseID = 12;
					else if (ilvl >= 41)
						maxRolledBaseID = 11;
					else if (ilvl >= 38)
						maxRolledBaseID = 10;
					else if (ilvl >= 36)
						maxRolledBaseID = 9;
					else if (ilvl >= 35)
						maxRolledBaseID = 8;
					else if (ilvl >= 32)
						maxRolledBaseID = 7;
					else if (ilvl >= 28)
						maxRolledBaseID = 6;
					else if (ilvl >= 24)
						maxRolledBaseID = 5;
					else if (ilvl >= 20)
						maxRolledBaseID = 4;
					else if (ilvl >= 15)
						maxRolledBaseID = 3;
					else if (ilvl >= 10)
						maxRolledBaseID = 2;
					else if (ilvl >= 5)
						maxRolledBaseID = 1;
				} //Set what item bases can roll



				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeSceptre(distribution(mtGen));
				switch(base)
				{
				case 0:
					baseClass = Base::Driftwood_Sceptre;
					break;
				case 1:
					baseClass = Base::Darkwood_Sceptre;
					break;
				case 2:
					baseClass = Base::Bronze_Sceptre;
					break;
				case 3:
					baseClass = Base::Quartz_Sceptre;
					break;
				case 4:
					baseClass = Base::Iron_Sceptre;
					break;
				case 5:
					baseClass = Base::Ochre_Sceptre;
					break;
				case 6:
					baseClass = Base::Ritual_Sceptre;
					break;
				case 7:
					baseClass = Base::Shadow_Sceptre;
					break;
				case 8:
					baseClass = Base::Grinning_Fetish;
					break;
				case 9:
					baseClass = Base::Horned_Sceptre;
					break;
				case 10:
					baseClass = Base::Sekhem;
					break;
				case 11:
					baseClass = Base::Crystal_Sceptre;
					break;
				case 12:
					baseClass = Base::Lead_Sceptre;
					break;
				case 13:
					baseClass = Base::Blood_Sceptre;
					break;
				case 14:
					baseClass = Base::Royal_Sceptre;
					break;
				case 15:
					baseClass = Base::Abyssal_Sceptre;
					break;
				case 16:
					baseClass = Base::Stag_Sceptre;
					break;
				case 17:
					baseClass = Base::Karui_Sceptre;
					break;
				case 18:
					baseClass = Base::Tyrants_Sekhem;
					break;
				case 19:
					baseClass = Base::Opal_Sceptre;
					break;
				case 20:
					baseClass = Base::Platinum_Sceptre;
					break;
				case 21:
					baseClass = Base::Vaal_Sceptre;
					break;
				case 22:
					baseClass = Base::Carnal_Sceptre;
					break;
				case 23:
					baseClass = Base::Void_Sceptre;
					break;
				case 24:
					baseClass = Base::Sambar_Sceptre;
					break; 
				}
				break;
			} 
			case itemType::OneHandedMace: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 24;
					else if (ilvl >= 68)
						maxRolledBaseID = 23;
					else if (ilvl >= 66)
						maxRolledBaseID = 22;
					else if (ilvl >= 64)
						maxRolledBaseID = 21;
					else if (ilvl >= 62)
						maxRolledBaseID = 20;
					else if (ilvl >= 60)
						maxRolledBaseID = 19;
					else if (ilvl >= 58)
						maxRolledBaseID = 18;
					else if (ilvl >= 56)
						maxRolledBaseID = 17;
					else if (ilvl >= 55)
						maxRolledBaseID = 16;
					else if (ilvl >= 53)
						maxRolledBaseID = 15;
					else if (ilvl >= 50)
						maxRolledBaseID = 14;
					else if (ilvl >= 47)
						maxRolledBaseID = 13;
					else if (ilvl >= 44)
						maxRolledBaseID = 12;
					else if (ilvl >= 41)
						maxRolledBaseID = 11;
					else if (ilvl >= 38)
						maxRolledBaseID = 10;
					else if (ilvl >= 35)
						maxRolledBaseID = 9;
					else if (ilvl >= 34)
						maxRolledBaseID = 8;
					else if (ilvl >= 32)
						maxRolledBaseID = 7;
					else if (ilvl >= 28)
						maxRolledBaseID = 6;
					else if (ilvl >= 24)
						maxRolledBaseID = 5;
					else if (ilvl >= 20)
						maxRolledBaseID = 4;
					else if (ilvl >= 15)
						maxRolledBaseID = 3;
					else if (ilvl >= 10)
						maxRolledBaseID = 2;
					else if (ilvl >= 5)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeOneHandedMace(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Driftwood_Club;
					break;
				case 1:
					baseClass = Base::Tribal_Club;
					break;
				case 2:
					baseClass = Base::Spiked_Club;
					break;
				case 3:
					baseClass = Base::Stone_Hammer;
					break;
				case 4:
					baseClass = Base::War_Hammer;
					break;
				case 5:

					baseClass = Base::Bladed_Mace;
					break;
				case 6:
					baseClass = Base::Ceremonial_Mace;
					break;
				case 7:
					baseClass = Base::Dream_Mace;
					break;
				case 8:
					baseClass = Base::Wyrm_Mace;
					break;
				case 9:
					baseClass = Base::Petrified_Club;
					break;
				case 10:
					baseClass = Base::Barbed_Club;
					break;
				case 11:
					baseClass = Base::Rock_Breaker;
					break;
				case 12:
					baseClass = Base::Battle_Hammer;
					break;
				case 13:
					baseClass = Base::Flanged_Mace;
					break;
				case 14:
					baseClass = Base::Ornate_Mace;
					break;
				case 15:
					baseClass = Base::Phantom_Mace;
					break;
				case 16:
					baseClass = Base::Dragon_Mace;
					break;
				case 17:
					baseClass = Base::Ancestral_Club;
					break;
				case 18:
					baseClass = Base::Tenderizer;
					break;
				case 19:
					baseClass = Base::Gavel;
					break;
				case 20:
					baseClass = Base::Legion_Hammer;
					break;
				case 21:
					baseClass = Base::Pernach;
					break;
				case 22:
					baseClass = Base::Auric_Mace;
					break;
				case 23:
					baseClass = Base::Nightmare_Mace;
					break;
				case 24:
					baseClass = Base::Behemoth_Mace;
					break;
				}
				break;
			}
			case itemType::TwoHandedMace: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 69)
						maxRolledBaseID = 21;
					else if (ilvl >= 67)
						maxRolledBaseID = 20;
					else if (ilvl >= 65)
						maxRolledBaseID = 19;
					else if (ilvl >= 63)
						maxRolledBaseID = 18;
					else if (ilvl >= 61)
						maxRolledBaseID = 17;
					else if (ilvl >= 59)
						maxRolledBaseID = 16;
					else if (ilvl >= 57)
						maxRolledBaseID = 15;
					else if (ilvl >= 56)
						maxRolledBaseID = 14;
					else if (ilvl >= 54)
						maxRolledBaseID = 13;
					else if (ilvl >= 51)
						maxRolledBaseID = 12;
					else if (ilvl >= 48)
						maxRolledBaseID = 11;
					else if (ilvl >= 44)
						maxRolledBaseID = 10;
					else if (ilvl >= 40)
						maxRolledBaseID = 9;
					else if (ilvl >= 36)
						maxRolledBaseID = 8;
					else if (ilvl >= 34)
						maxRolledBaseID = 7;
					else if (ilvl >= 32)
						maxRolledBaseID = 6;
					else if (ilvl >= 27)
						maxRolledBaseID = 5;
					else if (ilvl >= 22)
						maxRolledBaseID = 4;
					else if (ilvl >= 17)
						maxRolledBaseID = 3;
					else if (ilvl >= 12)
						maxRolledBaseID = 2;
					else if (ilvl >= 8)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeTwoHandedMace(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Driftwood_Maul;
					break;
				case 1:
					baseClass = Base::Tribal_Maul;
					break;
				case 2:
					baseClass = Base::Mallet;
					break;
				case 3:
					baseClass = Base::Sledgehammer;
					break;
				case 4:
					baseClass = Base::Jagged_Maul;
					break;
				case 5:
					baseClass = Base::Brass_Maul;
					break;
				case 6:
					baseClass = Base::Fright_Maul;
					break;
				case 7:
					baseClass = Base::Morning_Star;
					break;
				case 8:
					baseClass = Base::Totemic_Maul;
					break;
				case 9:
					baseClass = Base::Great_Mallet;
					break;
				case 10:
					baseClass = Base::Steelhead;
					break;
				case 11:
					baseClass = Base::Spiny_Maul;
					break;
				case 12:
					baseClass = Base::Plated_Maul;
					break;
				case 13:
					baseClass = Base::Dread_Maul;
					break;
				case 14:
					baseClass = Base::Solar_Maul;
					break;
				case 15:
					baseClass = Base::Karui_Maul;
					break;
				case 16:
					baseClass = Base::Colossus_Mallet;
					break;
				case 17:
					baseClass = Base::Piledriver;
					break;
				case 18:
					baseClass = Base::Meatgrinder;
					break;
				case 19:
					baseClass = Base::Imperial_Maul;
					break;
				case 20:
					baseClass = Base::Terror_Maul;
					break;
				case 21:
					baseClass = Base::Coronal_Maul;
					break;
				}
				break;
			}
			case itemType::OneHandedAxe: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 71)
						maxRolledBaseID = 24;
					else if (ilvl >= 69)
						maxRolledBaseID = 23;
					else if (ilvl >= 67)
						maxRolledBaseID = 22;
					else if (ilvl >= 65)
						maxRolledBaseID = 21;
					else if (ilvl >= 63)
						maxRolledBaseID = 20;
					else if (ilvl >= 61)
						maxRolledBaseID = 19;
					else if (ilvl >= 59)
						maxRolledBaseID = 18;
					else if (ilvl >= 57)
						maxRolledBaseID = 17;
					else if (ilvl >= 56)
						maxRolledBaseID = 16;
					else if (ilvl >= 54)
						maxRolledBaseID = 15;
					else if (ilvl >= 51)
						maxRolledBaseID = 14;
					else if (ilvl >= 48)
						maxRolledBaseID = 13;
					else if (ilvl >= 45)
						maxRolledBaseID = 12;
					else if (ilvl >= 42)
						maxRolledBaseID = 11;
					else if (ilvl >= 39)
						maxRolledBaseID = 10;
					else if (ilvl >= 36)
						maxRolledBaseID = 9;
					else if (ilvl >= 35)
						maxRolledBaseID = 8;
					else if (ilvl >= 33)
						maxRolledBaseID = 7;
					else if (ilvl >= 29)
						maxRolledBaseID = 6;
					else if (ilvl >= 25)
						maxRolledBaseID = 5;
					else if (ilvl >= 21)
						maxRolledBaseID = 4;
					else if (ilvl >= 16)
						maxRolledBaseID = 3;
					else if (ilvl >= 11)
						maxRolledBaseID = 2;
					else if (ilvl >= 6)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeOneHandedAxe(distribution(mtGen));
				switch(base)
				{
				case 0:
					baseClass = Base::Rusted_Hatchet;
					break;
				case 1:
					baseClass = Base::Jade_Hatchet;
					break;
				case 2:
					baseClass = Base::Boarding_Axe;
					break;
				case 3:
					baseClass = Base::Cleaver;
					break;
				case 4:
					baseClass = Base::Broad_Axe;
					break;
				case 5:
					baseClass = Base::Arming_Axe;
					break;
				case 6:
					baseClass = Base::Decorative_Axe;
					break;
				case 7:
					baseClass = Base::Spectral_Axe;
					break;
				case 8:
					baseClass = Base::Etched_Hatchet;
					break;
				case 9:
					baseClass = Base::Jasper_Axe;
					break;
				case 10:
					baseClass = Base::Tomahawk;
					break;
				case 11:
					baseClass = Base::Wrist_Chopper;
					break;
				case 12:
					baseClass = Base::War_Axe;
					break;
				case 13:
					baseClass = Base::Chest_Splitter;
					break;
				case 14:
					baseClass = Base::Ceremonial_Axe;
					break;
				case 15:
					baseClass = Base::Wraith_Axe;
					break;
				case 16:
					baseClass = Base::Engraved_Hatchet;
					break;
				case 17:
					baseClass = Base::Karui_Axe;
					break;
				case 18:
					baseClass = Base::Siege_Axe;
					break;
				case 19:
					baseClass = Base::Reaver_Axe;
					break;
				case 20:
					baseClass = Base::Butcher_Axe;
					break;
				case 21:
					baseClass = Base::Vaal_Hatchet;
					break;
				case 22:
					baseClass = Base::Royal_Axe;
					break;
				case 23:
					baseClass = Base::Infernal_Axe;
					break;
				case 24:
					baseClass = Base::Runic_Hatchet;
					break;
				}
				break;
			}
			case itemType::TwoHandedAxe: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 21;
					else if (ilvl >= 68)
						maxRolledBaseID = 20;
					else if (ilvl >= 66)
						maxRolledBaseID = 19;
					else if (ilvl >= 64)
						maxRolledBaseID = 18;
					else if (ilvl >= 62)
						maxRolledBaseID = 17;
					else if (ilvl >= 60)
						maxRolledBaseID = 16;
					else if (ilvl >= 59)
						maxRolledBaseID = 15;
					else if (ilvl >= 58)
						maxRolledBaseID = 14;
					else if (ilvl >= 55)
						maxRolledBaseID = 13;
					else if (ilvl >= 52)
						maxRolledBaseID = 12;
					else if (ilvl >= 49)
						maxRolledBaseID = 11;
					else if (ilvl >= 45)
						maxRolledBaseID = 10;
					else if (ilvl >= 41)
						maxRolledBaseID = 9;
					else if (ilvl >= 37)
						maxRolledBaseID = 8;
					else if (ilvl >= 36)
						maxRolledBaseID = 7;
					else if (ilvl >= 33)
						maxRolledBaseID = 6;
					else if (ilvl >= 28)
						maxRolledBaseID = 5;
					else if (ilvl >= 23)
						maxRolledBaseID = 4;
					else if (ilvl >= 18)
						maxRolledBaseID = 3;
					else if (ilvl >= 13)
						maxRolledBaseID = 2;
					else if (ilvl >= 9)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeTwoHandedAxe(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Stone_Axe;
					break;
				case 1:
					baseClass = Base::Jade_Chopper;
					break;
				case 2:
					baseClass = Base::Woodsplitter;
					break;
				case 3:
					baseClass = Base::Poleaxe;
					break;
				case 4:
					baseClass = Base::Double_Axe;
					break;
				case 5:
					baseClass = Base::Gilded_Axe;
					break;
				case 6:
					baseClass = Base::Shadow_Axe;
					break;
				case 7:
					baseClass = Base::Dagger_Axe;
					break;
				case 8:
					baseClass = Base::Jasper_Chopper;
					break;
				case 9:
					baseClass = Base::Timber_Axe;
					break;
				case 10:
					baseClass = Base::Headsman_Axe;
					break;
				case 11:
					baseClass = Base::Labrys;
					break;
				case 12:
					baseClass = Base::Noble_Axe;
					break;
				case 13:
					baseClass = Base::Abyssal_Axe;
					break;
				case 14:
					baseClass = Base::Talon_Axe;
					break;
				case 15:
					baseClass = Base::Karui_Chopper;
					break;
				case 16:
					baseClass = Base::Sundering_Axe;
					break;
				case 17:
					baseClass = Base::Ezomyte_Axe;
					break;
				case 18:
					baseClass = Base::Vaal_Axe;
					break;
				case 19:
					baseClass = Base::Despot_Axe;
					break;
				case 20:
					baseClass = Base::Void_Axe;
					break;
				case 21:
					baseClass = Base::Fleshripper;
					break;
				}
				break;
			}
			case itemType::OneHandedSword: //DONE & ILVL <I'm bored...>
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 24;
					else if (ilvl >= 68)
						maxRolledBaseID = 23;
					else if (ilvl >= 66)
						maxRolledBaseID = 22;
					else if (ilvl >= 64)
						maxRolledBaseID = 21;
					else if (ilvl >= 62)
						maxRolledBaseID = 20;
					else if (ilvl >= 60)
						maxRolledBaseID = 19;
					else if (ilvl >= 58)
						maxRolledBaseID = 18;
					else if (ilvl >= 56)
						maxRolledBaseID = 17;
					else if (ilvl >= 55)
						maxRolledBaseID = 16;
					else if (ilvl >= 53)
						maxRolledBaseID = 15;
					else if (ilvl >= 50)
						maxRolledBaseID = 14;
					else if (ilvl >= 47)
						maxRolledBaseID = 13;
					else if (ilvl >= 44)
						maxRolledBaseID = 12;
					else if (ilvl >= 41)
						maxRolledBaseID = 11;
					else if (ilvl >= 38)
						maxRolledBaseID = 10;
					else if (ilvl >= 35)
						maxRolledBaseID = 9;
					else if (ilvl >= 34)
						maxRolledBaseID = 8;
					else if (ilvl >= 32)
						maxRolledBaseID = 7;
					else if (ilvl >= 28)
						maxRolledBaseID = 6;
					else if (ilvl >= 24)
						maxRolledBaseID = 5;
					else if (ilvl >= 20)
						maxRolledBaseID = 4;
					else if (ilvl >= 15)
						maxRolledBaseID = 3;
					else if (ilvl >= 10)
						maxRolledBaseID = 2;
					else if (ilvl >= 5)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeOneHandedSword(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Rusted_Sword;
					break;
				case 1:
					baseClass = Base::Copper_Sword;
					break;
				case 2:
					baseClass = Base::Sabre;
					break;
				case 3:
					baseClass = Base::Broad_Sword;
					break;
				case 4:
					baseClass = Base::War_Sword;
					break;
				case 5:
					baseClass = Base::Ancient_Sword;
					break;
				case 6:
					baseClass = Base::Elegant_Sword;
					break;
				case 7:
					baseClass = Base::Dusk_Blade;
					break;
				case 8:
					baseClass = Base::Hook_Sword;
					break;
				case 9:
					baseClass = Base::Variscite_Blade;
					break;
				case 10:
					baseClass = Base::Cutlass;
					break;
				case 11:
					baseClass = Base::Baselard;
					break;
				case 12:
					baseClass = Base::Battle_Sword;
					break;
				case 13:
					baseClass = Base::Elder_Sword;
					break;
				case 14:
					baseClass = Base::Graceful_Sword;
					break;
				case 15:
					baseClass = Base::Twilight_Blade;
					break;
				case 16:
					baseClass = Base::Grappler;
					break;
				case 17:
					baseClass = Base::Gemstone_Sword;
					break;
				case 18:
					baseClass = Base::Corsair_Sword;
					break;
				case 19:
					baseClass = Base::Gladius;
					break;
				case 20:
					baseClass = Base::Legion_Sword;
					break;
				case 21:
					baseClass = Base::Vaal_Blade;
					break;
				case 22:
					baseClass = Base::Eternal_Sword;
					break;
				case 23:
					baseClass = Base::Midnight_Blade;
					break;
				case 24:
					baseClass = Base::Tiger_Hook;
					break;
				}
				break;
			}
			case itemType::ThrustingOneHandedSword: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 72)
						maxRolledBaseID = 24;
					else if (ilvl >= 70)
						maxRolledBaseID = 23;
					else if (ilvl >= 68)
						maxRolledBaseID = 22;
					else if (ilvl >= 66)
						maxRolledBaseID = 21;
					else if (ilvl >= 64)
						maxRolledBaseID = 20;
					else if (ilvl >= 62)
						maxRolledBaseID = 19;
					else if (ilvl >= 60)
						maxRolledBaseID = 18;
					else if (ilvl >= 58)
						maxRolledBaseID = 17;
					else if (ilvl >= 57)
						maxRolledBaseID = 16;
					else if (ilvl >= 55)
						maxRolledBaseID = 15;
					else if (ilvl >= 52)
						maxRolledBaseID = 14;
					else if (ilvl >= 49)
						maxRolledBaseID = 13;
					else if (ilvl >= 46)
						maxRolledBaseID = 12;
					else if (ilvl >= 43)
						maxRolledBaseID = 11;
					else if (ilvl >= 40)
						maxRolledBaseID = 10;
					else if (ilvl >= 37)
						maxRolledBaseID = 9;
					else if (ilvl >= 36)
						maxRolledBaseID = 8;
					else if (ilvl >= 34)
						maxRolledBaseID = 7;
					else if (ilvl >= 30)
						maxRolledBaseID = 6;
					else if (ilvl >= 26)
						maxRolledBaseID = 5;
					else if (ilvl >= 22)
						maxRolledBaseID = 4;
					else if (ilvl >= 17)
						maxRolledBaseID = 3;
					else if (ilvl >= 12)
						maxRolledBaseID = 2;
					else if (ilvl >= 7)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeThrustingOneHandedSword(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Rusted_Spike;
					break;
				case 1:
					baseClass = Base::Whalebone_Rapier;
					break;
				case 2:
					baseClass = Base::Battered_Foil;
					break;
				case 3:
					baseClass = Base::Basket_Rapier;
					break;
				case 4:
					baseClass = Base::Jagged_Foil;
					break;
				case 5:
					baseClass = Base::Antique_Rapier;
					break;
				case 6:
					baseClass = Base::Elegant_Foil;
					break;
				case 7:
					baseClass = Base::Thorn_Rapier;
					break;
				case 8:
					baseClass = Base::Smallsword;
					break;
				case 9:
					baseClass = Base::Wyrmbone_Rapier;
					break;
				case 10:
					baseClass = Base::Burnished_Foil;
					break;
				case 11:
					baseClass = Base::Estoc;
					break;
				case 12:
					baseClass = Base::Serrated_Foil;
					break;
				case 13:
					baseClass = Base::Primeval_Rapier;
					break;
				case 14:
					baseClass = Base::Fancy_Foil;
					break;
				case 15:
					baseClass = Base::Apex_Rapier;
					break;
				case 16:
					baseClass = Base::Courtesan_Sword;
					break;
				case 17:
					baseClass = Base::Dragonbone_Rapier;
					break;
				case 18:
					baseClass = Base::Tempered_Foil;
					break;
				case 19:
					baseClass = Base::Pecoraro;
					break;
				case 20:
					baseClass = Base::Spiraled_Foil;
					break;
				case 21:
					baseClass = Base::Vaal_Rapier;
					break;
				case 22:
					baseClass = Base::Jewelled_Foil;
					break;
				case 23:
					baseClass = Base::Harpy_Rapier;
					break;
				case 24:
					baseClass = Base::Dragoon_Sword;
					break;
				}
				break;
			}
			case itemType::TwoHandedSword: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 21;
					else if (ilvl >= 67)
						maxRolledBaseID = 20;
					else if (ilvl >= 65)
						maxRolledBaseID = 19;
					else if (ilvl >= 63)
						maxRolledBaseID = 18;
					else if (ilvl >= 61)
						maxRolledBaseID = 17;
					else if (ilvl >= 59)
						maxRolledBaseID = 16;
					else if (ilvl >= 57)
						maxRolledBaseID = 15;
					else if (ilvl >= 56)
						maxRolledBaseID = 14;
					else if (ilvl >= 54)
						maxRolledBaseID = 13;
					else if (ilvl >= 51)
						maxRolledBaseID = 12;
					else if (ilvl >= 48)
						maxRolledBaseID = 11;
					else if (ilvl >= 44)
						maxRolledBaseID = 10;
					else if (ilvl >= 40)
						maxRolledBaseID = 9;
					else if (ilvl >= 36)
						maxRolledBaseID = 8;
					else if (ilvl >= 35)
						maxRolledBaseID = 7;
					else if (ilvl >= 32)
						maxRolledBaseID = 6;
					else if (ilvl >= 27)
						maxRolledBaseID = 5;
					else if (ilvl >= 22)
						maxRolledBaseID = 4;
					else if (ilvl >= 17)
						maxRolledBaseID = 3;
					else if (ilvl >= 12)
						maxRolledBaseID = 2;
					else if (ilvl >= 8)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeTwoHandedSword(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Corroded_Blade;
					break;
				case 1:
					baseClass = Base::Longsword;
					break;
				case 2:
					baseClass = Base::Bastard_Sword;
					break;
				case 3:
					baseClass = Base::TwoHanded_Sword;
					break;
				case 4:
					baseClass = Base::Etched_Greatsword;
					break;
				case 5:
					baseClass = Base::Ornate_Sword;
					break;
				case 6:
					baseClass = Base::Spectral_Sword;
					break;
				case 7:
					baseClass = Base::Curved_Blade;
					break;
				case 8:
					baseClass = Base::Butcher_Sword;
					break;
				case 9:
					baseClass = Base::Footman_Sword;
					break;
				case 10:
					baseClass = Base::Highland_Blade;
					break;
				case 11:
					baseClass = Base::Engraved_Greatsword;
					break;
				case 12:
					baseClass = Base::Tiger_Sword;
					break;
				case 13:
					baseClass = Base::Wraith_Sword;
					break;
				case 14:
					baseClass = Base::Lithe_Blade;
					break;
				case 15:
					baseClass = Base::Headmans_Sword;
					break;
				case 16:
					baseClass = Base::Reaver_Sword;
					break;
				case 17:
					baseClass = Base::Ezomyte_Blade;
					break;
				case 18:
					baseClass = Base::Vaal_Greatsword;
					break;
				case 19:
					baseClass = Base::Lion_Sword;
					break;
				case 20:
					baseClass = Base::Infernal_Sword;
					break;
				case 21:
					baseClass = Base::Exquisite_Blade;
					break;
				}
				break;
			}
			case itemType::Bow: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 71)
						maxRolledBaseID = 24;
					else if (ilvl >= 68)
						maxRolledBaseID = 23;
					else if (ilvl >= 66)
						maxRolledBaseID = 22;
					else if (ilvl >= 64)
						maxRolledBaseID = 21;
					else if (ilvl >= 62)
						maxRolledBaseID = 20;
					else if (ilvl >= 60)
						maxRolledBaseID = 19;
					else if (ilvl >= 58)
						maxRolledBaseID = 18;
					else if (ilvl >= 57)
						maxRolledBaseID = 17;
					else if (ilvl >= 56)
						maxRolledBaseID = 16;
					else if (ilvl >= 53)
						maxRolledBaseID = 15;
					else if (ilvl >= 50)
						maxRolledBaseID = 14;
					else if (ilvl >= 47)
						maxRolledBaseID = 13;
					else if (ilvl >= 44)
						maxRolledBaseID = 12;
					else if (ilvl >= 41)
						maxRolledBaseID = 11;
					else if (ilvl >= 38)
						maxRolledBaseID = 10;
					else if (ilvl >= 36)
						maxRolledBaseID = 9;
					else if (ilvl >= 35)
						maxRolledBaseID = 8;
					else if (ilvl >= 32)
						maxRolledBaseID = 7;
					else if (ilvl >= 28)
						maxRolledBaseID = 6;
					else if (ilvl >= 23)
						maxRolledBaseID = 5;
					else if (ilvl >= 18)
						maxRolledBaseID = 4;
					else if (ilvl >= 14)
						maxRolledBaseID = 3;
					else if (ilvl >= 9)
						maxRolledBaseID = 2;
					else if (ilvl >= 5)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeBow(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Crude_Bow;
					break;
				case 1:
					baseClass = Base::Short_Bow;
					break;
				case 2:
					baseClass = Base::Long_Bow;
					break;
				case 3:
					baseClass = Base::Composite_Bow;
					break;
				case 4:
					baseClass = Base::Recurve_Bow;
					break;
				case 5:
					baseClass = Base::Bone_Bow;
					break;
				case 6:
					baseClass = Base::Royal_Bow;
					break;
				case 7:
					baseClass = Base::Death_Bow;
					break;
				case 8:
					baseClass = Base::Reflex_Bow;
					break;
				case 9:
					baseClass = Base::Grove_Bow;
					break;
				case 10:
					baseClass = Base::Decurve_Bow;
					break;
				case 11:
					baseClass = Base::Compound_Bow;
					break;
				case 12:
					baseClass = Base::Sniper_Bow;
					break;
				case 13:
					baseClass = Base::Ivory_Bow;
					break;
				case 14:
					baseClass = Base::Highborn_Bow;
					break;
				case 15:
					baseClass = Base::Decimation_Bow;
					break;
				case 16:
					baseClass = Base::Steelwood_Bow;
					break;
				case 17:
					baseClass = Base::Thicket_Bow;
					break;
				case 18:
					baseClass = Base::Citadel_Bow;
					break;
				case 19:
					baseClass = Base::Ranger_Bow;
					break;
				case 20:
					baseClass = Base::Assassin_Bow;
					break;
				case 21:
					baseClass = Base::Spine_Bow;
					break;
				case 22:
					baseClass = Base::Imperial_Bow;
					break;
				case 23:
					baseClass = Base::Harbinger_Bow;
					break;
				case 24:
					baseClass = Base::Maraketh_Bow;
					break;
				}
				break;
			}
			case itemType::Claw: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 72)
						maxRolledBaseID = 24;
					else if (ilvl >= 70)
						maxRolledBaseID = 23;
					else if (ilvl >= 68)
						maxRolledBaseID = 22;
					else if (ilvl >= 66)
						maxRolledBaseID = 21;
					else if (ilvl >= 64)
						maxRolledBaseID = 20;
					else if (ilvl >= 62)
						maxRolledBaseID = 19;
					else if (ilvl >= 60)
						maxRolledBaseID = 18;
					else if (ilvl >= 58)
						maxRolledBaseID = 17;
					else if (ilvl >= 57)
						maxRolledBaseID = 16;
					else if (ilvl >= 55)
						maxRolledBaseID = 15;
					else if (ilvl >= 52)
						maxRolledBaseID = 14;
					else if (ilvl >= 49)
						maxRolledBaseID = 13;
					else if (ilvl >= 46)
						maxRolledBaseID = 12;
					else if (ilvl >= 43)
						maxRolledBaseID = 11;
					else if (ilvl >= 40)
						maxRolledBaseID = 10;
					else if (ilvl >= 37)
						maxRolledBaseID = 9;
					else if (ilvl >= 36)
						maxRolledBaseID = 8;
					else if (ilvl >= 34)
						maxRolledBaseID = 7;
					else if (ilvl >= 30)
						maxRolledBaseID = 6;
					else if (ilvl >= 26)
						maxRolledBaseID = 5;
					else if (ilvl >= 22)
						maxRolledBaseID = 4;
					else if (ilvl >= 17)
						maxRolledBaseID = 3;
					else if (ilvl >= 12)
						maxRolledBaseID = 2;
					else if (ilvl >= 7)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeClaw(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Nailed_Fist;
					break;
				case 1:
					baseClass = Base::Sharktooth_Claw;
					break;
				case 2:
					baseClass = Base::Awl;
					break;
				case 3:
					baseClass = Base::Cats_Paw;
					break;
				case 4:
					baseClass = Base::Blinder;
					break;
				case 5:
					baseClass = Base::Timeworn_Claw;
					break;
				case 6:
					baseClass = Base::Sparkling_Claw;
					break;
				case 7:
					baseClass = Base::Fright_Claw;
					break;
				case 8:
					baseClass = Base::Double_Claw;
					break;
				case 9:
					baseClass = Base::Thresher_Claw;
					break;
				case 10:
					baseClass = Base::Gouger;
					break;
				case 11:
					baseClass = Base::Tigers_Paw;
					break;
				case 12:
					baseClass = Base::Gut_Ripper;
					break;
				case 13:
					baseClass = Base::Prehistoric_Claw;
					break;
				case 14:
					baseClass = Base::Noble_Claw;
					break;
				case 15:
					baseClass = Base::Eagle_Claw;
					break;
				case 16:
					baseClass = Base::Twin_Claw;
					break;
				case 17:
					baseClass = Base::Great_White_Claw;
					break;
				case 18:
					baseClass = Base::Throat_Stabber;
					break;
				case 19:
					baseClass = Base::Hellions_Paw;
					break;
				case 20:
					baseClass = Base::Eye_Gouger;
					break;
				case 21:
					baseClass = Base::Vaal_Claw;
					break;
				case 22:
					baseClass = Base::Imperial_Claw;
					break;
				case 23:
					baseClass = Base::Terror_Claw;
					break;
				case 24:
					baseClass = Base::Gemini_Claw;
					break;
				}
				break;
			}
			case itemType::Dagger: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 9;
					else if (ilvl >= 60)
						maxRolledBaseID = 8;
					else if (ilvl >= 56)
						maxRolledBaseID = 7;
					else if (ilvl >= 51)
						maxRolledBaseID = 6;
					else if (ilvl >= 41)
						maxRolledBaseID = 5;
					else if (ilvl >= 36)
						maxRolledBaseID = 4;
					else if (ilvl >= 30)
						maxRolledBaseID = 3;
					else if (ilvl >= 15)
						maxRolledBaseID = 2;
					else if (ilvl >= 5)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeDagger(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Glass_Shank;
					break;
				case 1:
					baseClass = Base::Skinning_Knife;
					break;
				case 2:
					baseClass = Base::Stiletto;
					break;
				case 3:
					baseClass = Base::Flaying_Knife;
					break;
				case 4:
					baseClass = Base::Prong_Dagger;
					break;
				case 5:
					baseClass = Base::Poignard;
					break;
				case 6:
					baseClass = Base::Trisula;
					break;
				case 7:
					baseClass = Base::Gutting_Knife;
					break;
				case 8:
					baseClass = Base::Ambusher;
					break;
				case 9:
					baseClass = Base::Sai;
					break;
				}
				break;
			}
			case itemType::RuneDagger: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 68)
						maxRolledBaseID = 14;
					else if (ilvl >= 66)
						maxRolledBaseID = 13;
					else if (ilvl >= 64)
						maxRolledBaseID = 12;
					else if (ilvl >= 62)
						maxRolledBaseID = 11;
					else if (ilvl >= 58)
						maxRolledBaseID = 10;
					else if (ilvl >= 53)
						maxRolledBaseID = 9;
					else if (ilvl >= 50)
						maxRolledBaseID = 8;
					else if (ilvl >= 47)
						maxRolledBaseID = 7;
					else if (ilvl >= 44)
						maxRolledBaseID = 6;
					else if (ilvl >= 38)
						maxRolledBaseID = 5;
					else if (ilvl >= 32)
						maxRolledBaseID = 4;
					else if (ilvl >= 28)
						maxRolledBaseID = 3;
					else if (ilvl >= 24)
						maxRolledBaseID = 2;
					else if (ilvl >= 20)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeRuneDagger(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Carving_Knife;
					break;
				case 1:
					baseClass = Base::Boot_Knife;
					break;
				case 2:
					baseClass = Base::Copper_Kris;
					break;
				case 3:
					baseClass = Base::Skean;
					break;
				case 4:
					baseClass = Base::Imp_Dagger;
					break;
				case 5:
					baseClass = Base::Butcher_Knife;
					break;
				case 6:
					baseClass = Base::Boot_Blade;
					break;
				case 7:
					baseClass = Base::Golden_Kris;
					break;
				case 8:
					baseClass = Base::Royal_Skean;
					break;
				case 9:
					baseClass = Base::Fiend_Dagger;
					break;
				case 10:
					baseClass = Base::Slaughter_Knife;
					break;
				case 11:
					baseClass = Base::Ezomyte_Dagger;
					break;
				case 12:
					baseClass = Base::Platinum_Kris;
					break;
				case 13:
					baseClass = Base::Imperial_Skean;
					break;
				case 14:
					baseClass = Base::Demon_Dagger;
					break;
				}
				break;
			}
			case itemType::Stave: //DONE & ILVL
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 70)
						maxRolledBaseID = 12;
					else if (ilvl >= 66)
						maxRolledBaseID = 11;
					else if (ilvl >= 62)
						maxRolledBaseID = 10;
					else if (ilvl >= 58)
						maxRolledBaseID = 9;
					else if (ilvl >= 57)
						maxRolledBaseID = 8;
					else if (ilvl >= 52)
						maxRolledBaseID = 7;
					else if (ilvl >= 45)
						maxRolledBaseID = 6;
					else if (ilvl >= 37)
						maxRolledBaseID = 5;
					else if (ilvl >= 36)
						maxRolledBaseID = 4;
					else if (ilvl >= 28)
						maxRolledBaseID = 3;
					else if (ilvl >= 18)
						maxRolledBaseID = 2;
					else if (ilvl >= 9)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeStave(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Gnarled_Branch;
					break;
				case 1:
					baseClass = Base::Primitive_Staff;
					break;
				case 2:
					baseClass = Base::Long_Staff;
					break;
				case 3:
					baseClass = Base::Royal_Staff;
					break;
				case 4:
					baseClass = Base::Crescent_Staff;
					break;
				case 5:
					baseClass = Base::Woodful_Staff;
					break;
				case 6:
					baseClass = Base::Quarterstaff;
					break;
				case 7:
					baseClass = Base::Highborn_Staff;
					break;
				case 8:
					baseClass = Base::Moon_Staff;
					break;
				case 9:
					baseClass = Base::Primordial_Staff;
					break;
				case 10:
					baseClass = Base::Lathi;
					break;
				case 11:
					baseClass = Base::Imperial_Staff;
					break;
				case 12:
					baseClass = Base::Eclipse_Staff;
					break;
				}
				break;
			}
			case itemType::Wand: //MF DOOOOONE & ILVL. It was so boring.
			{
				int maxRolledBaseID = 0; //Max base that is possible to roll with ilvl of the item.
				//Set what item bases can roll
				{
					if (ilvl >= 72)
						maxRolledBaseID = 19;
					else if (ilvl >= 70)
						maxRolledBaseID = 18;
					else if (ilvl >= 68)
						maxRolledBaseID = 17;
					else if (ilvl >= 65)
						maxRolledBaseID = 16;
					else if (ilvl >= 62)
						maxRolledBaseID = 15;
					else if (ilvl >= 59)
						maxRolledBaseID = 14;
					else if (ilvl >= 56)
						maxRolledBaseID = 13;
					else if (ilvl >= 55)
						maxRolledBaseID = 12;
					else if (ilvl >= 53)
						maxRolledBaseID = 11;
					else if (ilvl >= 49)
						maxRolledBaseID = 10;
					else if (ilvl >= 45)
						maxRolledBaseID = 9;
					else if (ilvl >= 40)
						maxRolledBaseID = 8;
					else if (ilvl >= 35)
						maxRolledBaseID = 7;
					else if (ilvl >= 34)
						maxRolledBaseID = 6;
					else if (ilvl >= 30)
						maxRolledBaseID = 5;
					else if (ilvl >= 24)
						maxRolledBaseID = 4;
					else if (ilvl >= 18)
						maxRolledBaseID = 3;
					else if (ilvl >= 12)
						maxRolledBaseID = 2;
					else if (ilvl >= 6)
						maxRolledBaseID = 1;
				}
				distribution = std::uniform_int_distribution<int>(0, maxRolledBaseID);
				base = baseTypeWand(distribution(mtGen));
				switch (base)
				{
				case 0:
					baseClass = Base::Driftwood_Wand;
					break;
				case 1:
					baseClass = Base::Goats_Horn;
					break;
				case 2:
					baseClass = Base::Carved_Wand;
					break;
				case 3:
					baseClass = Base::Quartz_Wand;
					break;
				case 4:
					baseClass = Base::Spiraled_Wand;
					break;
				case 5:
					baseClass = Base::Sage_Wand;
					break;
				case 6:
					baseClass = Base::Pagan_Wand;
					break;
				case 7:
					baseClass = Base::Fauns_Horn;
					break;
				case 8:
					baseClass = Base::Engraved_Wand;
					break;
				case 9:
					baseClass = Base::Crystal_Wand;
					break;
				case 10:
					baseClass = Base::Serpent_Wand;
					break;
				case 11:
					baseClass = Base::Omen_Wand;
					break;
				case 12:
					baseClass = Base::Heathen_Wand;
					break;
				case 13:
					baseClass = Base::Demons_Horn;
					break;
				case 14:
					baseClass = Base::Imbued_Wand;
					break;
				case 15:
					baseClass = Base::Opal_Wand;
					break;
				case 16:
					baseClass = Base::Tornado_Wand;
					break;
				case 17:
					baseClass = Base::Prophecy_Wand;
					break;
				case 18:
					baseClass = Base::Profane_Wand;
					break;
				case 19:
					baseClass = Base::Convoking_Wand;
					break;
				}
				break;
			}
		}
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE WHAT THIS ITEM IS (Stave, mace, sword etc)
	//
	//------------------------------------------------------------------------------------------------------
	void generateType()
	{
		//distribution = std::uniform_int_distribution<int>(0, 13);
		type = itemType(type_distribution(mtGen));
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE Ilvl OF THE ITEM (CURRENTLY RANDOM FROM 1 TO 100)
	//
	//------------------------------------------------------------------------------------------------------
	void generateILVL()
	{
		//distribution = std::uniform_int_distribution<int>(1, 100);
		ilvl = oneToHundred_distribution(mtGen);
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE ITEM RARITY (From normal to rare as unique items are not supported yet)
	//
	//------------------------------------------------------------------------------------------------------
	void generateRarity()
	{
		//distribution = std::uniform_int_distribution<int>(1, 100);
		int percentageRoll = 0;
		percentageRoll = itemType(oneToHundred_distribution(mtGen));

		if (percentageRoll > 90)
			rarity = itemRarity::Rare;
		else if (percentageRoll > 60)
			rarity = itemRarity::Magic;
		else
			rarity = itemRarity::Normal;
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE HOW MANY SOCKETS ITEM HAVE THEN GENERATE SOCKET COLORS
	//
	//------------------------------------------------------------------------------------------------------
	void generateSockets()
	{
		//Generate how much sockets item can have
		if (type == itemType::Sceptre || type == itemType::OneHandedMace || type == itemType::OneHandedAxe || type == itemType::OneHandedSword || type == itemType::ThrustingOneHandedSword ||
			type == itemType::Claw || type == itemType::Dagger || type == itemType::RuneDagger || type == itemType::Wand)
		{
			if (ilvl > 1)
				maxSockets = 3;
			else
				maxSockets = 2;
		}
		else
		{
			if (ilvl >= 50)
				maxSockets = 6;
			else if (ilvl >= 35)
				maxSockets = 5;
			else if (ilvl >= 25)
				maxSockets = 4;
			else if (ilvl >= 2)
				maxSockets = 3;
			else
				maxSockets = 2;
		}


		//Generate sockets for item.
		switch (maxSockets)
		{
		case 2:
		{
			//distribution = std::uniform_int_distribution<int>(1, 120);
			int roll = twoSockets_distribution(mtGen);
			if (roll > 50)
				nrOfSockets = 2;
			else
				nrOfSockets = 1;
			break;
		}
		case 3:
		{
			//distribution = std::uniform_int_distribution<int>(1, 270);
			int roll = threeSockets_distribution(mtGen);
			if (roll > 170)
				nrOfSockets = 3;
			else if (roll > 50)
				nrOfSockets = 2;
			else
				nrOfSockets = 1;
			break;
		}
		case 4:
		{
			//distribution = std::uniform_int_distribution<int>(1, 300);
			int roll = fourSockets_distribution(mtGen);
			if (roll > 270)
				nrOfSockets = 4;
			else if (roll > 170)
				nrOfSockets = 3;
			else if (roll > 50)
				nrOfSockets = 2;
			else
				nrOfSockets = 1;
			break;
		}
		case 5:
		{
			//distribution = std::uniform_int_distribution<int>(1, 305);
			int roll = fiveSockets_distribution(mtGen);
			if (roll > 300)
				nrOfSockets = 5;
			else if (roll > 270)
				nrOfSockets = 4;
			else if (roll > 170)
				nrOfSockets = 3;
			else if (roll > 50)
				nrOfSockets = 2;
			else
				nrOfSockets = 1;
			break;
		}
		case 6:
			{
			//distribution = std::uniform_int_distribution<int>(1, 306);
			int roll = sixSockets_distribution(mtGen);
			if (roll > 305)
				nrOfSockets = 6;
			else if (roll > 300)
				nrOfSockets = 5;
			else if (roll > 270)
				nrOfSockets = 4;
			else if (roll > 170)
				nrOfSockets = 3;
			else if (roll > 50)
				nrOfSockets = 2;
			else
				nrOfSockets = 1;
			break;
			}
		}//End of switch statement

		//Generate colors for sockets.
		int strWeight = 12 + baseClass.reqStr;
		int dexWeight = 12 + baseClass.reqDex;
		int intWeight = 12 + baseClass.reqInt;
		int fullWeight = strWeight + dexWeight + intWeight;
		distribution = std::uniform_int_distribution<int>(1, fullWeight);
		//For every socket generate color.
		for (int i = 0; i < nrOfSockets; i++)
		{
			int roll = distribution(mtGen);
			if (roll > (strWeight + dexWeight))
				socket[i] = socketColors::Blue;
			else if (roll > strWeight)
				socket[i] = socketColors::Green;
			else
				socket[i] = socketColors::Red;
		}
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE LINKS BETWEN SOCKETS
	//
	//------------------------------------------------------------------------------------------------------
	void generateLinks()
	{
		//Prepare links (every link is set to be not existant
		for (int i = 0; i < 5; i++)
			link[i] = false;


		int currentSocket = 0;
		int linksLeft = (nrOfSockets - 1) - currentSocket;
		//weights
		int noneWeight = 17826;
		int singleWeight = 35118;
		int doubleWeight = 26717;
		int tripleWeight = 19418;
		int quadWeight = 821;
		int pentaWeight = 100;
		//--------------------
		int fullWeight = 0;

		while (linksLeft > 0)
		{
			switch (linksLeft)
			{
			case 5:
			{
				fullWeight = noneWeight + singleWeight + doubleWeight + tripleWeight + quadWeight + pentaWeight;
				distribution = std::uniform_int_distribution<int>(1, fullWeight);
				int roll = distribution(mtGen);
				if (roll > (noneWeight + singleWeight + doubleWeight + tripleWeight + quadWeight)) //5 LINKS
				{
					//TODO: --BUG--: This will not count from current socket but from start.
					for (int i = 0; i < 5; i++)
						link[i] = true;

					currentSocket = 5;
				}
				else if (roll > (noneWeight + singleWeight + doubleWeight + tripleWeight)) //4 LINKS
				{
					for (int i = 0; i < 4; i++)
						link[i] = true;

					currentSocket = 5;
				}
				else if (roll > (noneWeight + singleWeight + doubleWeight)) //3 LINKS
				{
					for (int i = 0; i < 3; i++)
						link[i] = true;

					currentSocket = 4;
				}
				else if (roll > (noneWeight + singleWeight)) //2 LINKS
				{
					for (int i = 0; i < 2; i++)
						link[i] = true;

					currentSocket = 3;
				}
				else if (roll > noneWeight) //1 LINK
				{
					link[0] = true;

					currentSocket = 2;
				}
				break;
			}//End of Case 5
			case 4:
			{
				fullWeight = noneWeight + singleWeight + doubleWeight + tripleWeight + quadWeight;
				distribution = std::uniform_int_distribution<int>(1, fullWeight);
				int roll = distribution(mtGen);
				if (roll > (noneWeight + singleWeight + doubleWeight + tripleWeight))
				{
					for (int i = 0; i < 4; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > (noneWeight + singleWeight + doubleWeight))
				{
					for (int i = 0; i < 3; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > (noneWeight + singleWeight))
				{
					for (int i = 0; i < 2; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > noneWeight)
				{
					link[currentSocket] = true;
					currentSocket += 2;
				}
				break;
			}//End of case 4
			case 3:
			{
				fullWeight = noneWeight + singleWeight + doubleWeight + tripleWeight;
				distribution = std::uniform_int_distribution<int>(1, fullWeight);
				int roll = distribution(mtGen);
				if (roll > (noneWeight + singleWeight + doubleWeight))
				{
					for (int i = 0; i < 3; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > (noneWeight + singleWeight))
				{
					for (int i = 0; i < 2; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > noneWeight)
				{
					link[currentSocket] = true;
					currentSocket += 2;
				}
				break;
			}//End of case 3
			case 2:
			{
				fullWeight = noneWeight + singleWeight + doubleWeight;
				distribution = std::uniform_int_distribution<int>(1, fullWeight);
				int roll = distribution(mtGen);
				if (roll > (noneWeight + singleWeight))
				{
					for (int i = 0; i < 2; i++)
					{
						link[currentSocket] = true;
						currentSocket++;
					}
					currentSocket++;
				}
				else if (roll > noneWeight)
				{
					link[currentSocket] = true;
					currentSocket += 2;
				}
				break;
			}//End of case 2
			case 1:
			{
				fullWeight = noneWeight + singleWeight;
				distribution = std::uniform_int_distribution<int>(1, fullWeight);
				int roll = distribution(mtGen);
				if (roll > noneWeight) //LINKED
				{
					link[currentSocket] = true;
	
					currentSocket += 2;
				}
				break;
			}
			default:
			{
				std::cout << "\n\n!!!Something went wrong with generating links!!!\n\n" << std::flush;
			}
			}//END OF SWITCH
			linksLeft = (nrOfSockets - 1) - currentSocket;
		}
	}


public:
	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE ITEM
	//
	//------------------------------------------------------------------------------------------------------
	void generateItem()
	{
		generateILVL();
		generateType();
		generateBaseType();
		generateRarity();
		generateSockets();
		generateLinks();
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				RETURN LETTER FOR SOCKET COLOR IN RENDERING ITEM
	//
	//------------------------------------------------------------------------------------------------------
	char colorOfSocket(socketColors color)
	{
		if (color == socketColors::Blue)
			return 'B';
		else if (color == socketColors::Green)
			return 'G';
		else if (color == socketColors::Red)
			return 'R';
		else
			std::cout << "Error while creating socket color." << std::endl;
		return 'B';

	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE TEXT DISPLAYED IN CONSOLE
	//
	//------------------------------------------------------------------------------------------------------
	std::string toString()
	{
		std::string returningText = "Item Class: ";

		//Adding item class to String
		switch (type)
		{
			case itemType::Sceptre: returningText += "Sceptre"; break;
			case itemType::OneHandedMace: returningText += "One Handed Mace"; break;
			case itemType::TwoHandedMace: returningText += "Two Handed Mace"; break;
			case itemType::OneHandedAxe: returningText += "One Handed Axe"; break;
			case itemType::TwoHandedAxe: returningText += "Two Handed Axe"; break;
			case itemType::OneHandedSword: returningText += "One Handed Sword"; break;
			case itemType::ThrustingOneHandedSword: returningText += "Thrusting One Handed Sword"; break;
			case itemType::TwoHandedSword: returningText += "Two Handed Sword"; break;
			case itemType::Bow: returningText += "Bow"; break;
			case itemType::Claw: returningText += "Claw"; break;
			case itemType::Dagger: returningText += "Dagger"; break;
			case itemType::RuneDagger: returningText += "Rune Dagger"; break;
			case itemType::Stave: returningText += "Stave"; break;
			case itemType::Wand: returningText += "Wand"; break;
		}

		returningText += "\nBase: ";

			returningText += baseClass.name;
			returningText += "\nPhysical Damage: ";
			returningText += std::to_string(baseClass.minPD);
			returningText += "-";
			returningText += std::to_string(baseClass.maxPD);
			returningText += "\nCritical Strike Chance: ";
			returningText += std::to_string(baseClass.critChance);
			returningText += "%\nAttacks per Second: ";
			returningText += std::to_string(baseClass.APS);
			returningText += "\nWeapon Range: ";
			returningText += std::to_string(baseClass.range);
			returningText += "\n\nItem Level: ";
			returningText += std::to_string(ilvl);
			returningText += "\nRequires level:";
			returningText += std::to_string(baseClass.reqLvl);
			returningText += ",";
			if (baseClass.reqStr > 0)
			{
				returningText += " ";
				returningText += std::to_string(baseClass.reqStr);
				returningText += " Str";
			}
			if (baseClass.reqDex > 0)
			{
				returningText += " ";
				returningText += std::to_string(baseClass.reqDex);
				returningText += " Dex";
			}
			if (baseClass.reqInt > 0)
			{
				returningText += " ";
				returningText += std::to_string(baseClass.reqInt);
				returningText += " Int";
			}
			if (baseClass.modifier.compare("") != 0)
			{
				returningText += "\n\n";
				returningText += baseClass.modifier;
			}
			returningText += "\n\n\n";
			returningText += "Sockets:\n";

			//Print Sockets
			switch (nrOfSockets)
			{
			case 1:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				break;
			}
			case 2:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				returningText += "\n";
				if (link[0] == true)
				{
					returningText += "\t";
					returningText += '|';
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[1]);
				break;
			}
			case 3:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				if (link[0] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[1]);
				returningText += "\n";
				if (link[1] == true)
				{
					returningText += "\t  |";
				}
				returningText += "\n\t  ";
				returningText += colorOfSocket(socket[2]);
				break;
			}
			case 4:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				if (link[0] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[1]);
				returningText += "\n";
				if (link[1] == true)
				{
					returningText += "\t  |";
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[2]);
				if (link[2] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[3]);
				break;
			}
			case 5:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				if (link[0] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[1]);
				returningText += "\n";
				if (link[1] == true)
				{
					returningText += "\t  |";
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[2]);
				if (link[2] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[3]);
				returningText += "\n";
				if (link[3] == true)
				{
					returningText += "\t|";
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[4]);
				break;
			}
			case 6:
			{
				returningText += "\t";
				returningText += colorOfSocket(socket[0]);
				if (link[0] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[1]);
				returningText += "\n";
				if (link[1] == true)
				{
					returningText += "\t  |";
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[2]);
				if (link[2] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[3]);
				returningText += "\n";
				if (link[3] == true)
				{
					returningText += "\t|";
				}
				returningText += "\n\t";
				returningText += colorOfSocket(socket[4]);
				if (link[4] == true)
				{
					returningText += '-';
				}
				returningText += colorOfSocket(socket[5]);
				break;
			}
			}

		return returningText;
	}
};


//------------------------------------------------------------------------------------------------------
//
//				JUST MAIN
//
//------------------------------------------------------------------------------------------------------
int main()
{
	//Seeding generator with current time (in seconds)
	mtGen.seed(time(NULL));

	//Creating Item class in memory
	Item przedmiot;

	//Generating item
	przedmiot.generateItem();

   //Generating 1.000.000 items
   std::map<int, Item> drops;
   //Start measure time
   auto start = std::chrono::steady_clock::now();
   for(int x = 0; x < 1000000; x++)
   {
      Item item;
	   item.generateItem();
      drops.insert(std::pair<int, Item>(x, item));
      if(x % 1000 == 0)
         std::cout << x << std::endl << std::flush;
   }
   //End measure time
   auto end = std::chrono::steady_clock::now();
   for(std::pair<int, Item> element : drops)
   {
      //Item item = element.second;
      //std::cout << item.baseClass.modifier << std::endl << std::flush;
   }


   auto time_measured = end - start;
   std::cout << "Time of generation: " 
      << std::chrono::duration<double,std::milli>(time_measured).count() << " ms" << std::endl  << std::endl << std::flush;



	//Displaying created item
	std::cout << przedmiot.toString() << std::endl << std::flush;
}
