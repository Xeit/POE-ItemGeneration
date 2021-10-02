#include <iostream>
#include <Windows.h>
#include <thread>
#include <random>
#include <ctime>
#include <string>

#include "baseClass.h"

std::mt19937 mtGen;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 1);


enum itemClass
{
	Sceptre, OneHandedMace, TwoHandedMace, OneHandedAxe, TwoHandedAxe, OneHandedSword, ThrustingOneHandedSword, TwoHandedSword, Bow, Claw, Dagger, RuneDagger, Stave, Wand
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
	Nailed_Fist, Sharktooth_Claw, Awl, Cats_Paw, Blinder, Timeworn_Claw, Sparkling_Claw, Fright_Claw, Double_Claw, Threasher_Claw,
	Gouger, Tigers_Paw, Gut_Ripper, Prehistoric_Claw, Noble_Claw, Eagle_Claw, Twin_Claw, Great_White_Claw, Throat_Stabber, Hellions_Paw,
	Eye_Gouger, Vaal_Claw, Imperial_Claw, Terror_Claw, Gemini_Claw
	//Shadow_Fangs, Malign_Fangs, Void_Fangs
};
enum baseTypeDagger
{
	Glass_Shank, Skinning_Knife, Stiletto, Prong_Dagger, Flaying_Knife, Poignard, Trisula,
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
	Gnarled_Branch, Primitive_Staff, Long_Staff, Royal_Staff, Crescent_Staff, Woodlful_Staff, Quarterstaff, Highborn_Staff, Moon_Staff, 
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


class Item
{
private:
	int ilvl;
	itemClass type;
	int base;
	Bases::BaseClass baseClass;

	void generateBaseType()
	{
		switch (type)
		{
			case itemClass::Sceptre: //DONE
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
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
			case itemClass::OneHandedMace:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeOneHandedMace(distribution(mtGen));
				break;
			}
			case itemClass::TwoHandedMace:
			{
				distribution = std::uniform_int_distribution<int>(0, 21);
				base = baseTypeTwoHandedMace(distribution(mtGen));
				break;
			}
			case itemClass::OneHandedAxe:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeOneHandedAxe(distribution(mtGen));
				break;
			}
			case itemClass::TwoHandedAxe:
			{
				distribution = std::uniform_int_distribution<int>(0, 21);
				base = baseTypeTwoHandedAxe(distribution(mtGen));
				break;
			}
			case itemClass::OneHandedSword:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeOneHandedSword(distribution(mtGen));
				break;
			}
			case itemClass::ThrustingOneHandedSword:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeThrustingOneHandedSword(distribution(mtGen));
				break;
			}
			case itemClass::TwoHandedSword:
			{
				distribution = std::uniform_int_distribution<int>(0, 21);
				base = baseTypeTwoHandedSword(distribution(mtGen));
				break;
			}
			case itemClass::Bow:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeBow(distribution(mtGen));
				break;
			}
			case itemClass::Claw:
			{
				distribution = std::uniform_int_distribution<int>(0, 24);
				base = baseTypeClaw(distribution(mtGen));
				break;
			}
			case itemClass::Dagger:
			{
				distribution = std::uniform_int_distribution<int>(0, 9);
				base = baseTypeDagger(distribution(mtGen));
				break;
			}
			case itemClass::RuneDagger:
			{
				distribution = std::uniform_int_distribution<int>(0, 14);
				base = baseTypeRuneDagger(distribution(mtGen));
				break;
			}
			case itemClass::Stave:
			{
				distribution = std::uniform_int_distribution<int>(0, 12);
				base = baseTypeStave(distribution(mtGen));
				break;
			}
			case itemClass::Wand:
			{
				distribution = std::uniform_int_distribution<int>(0, 19 );
				base = baseTypeWand(distribution(mtGen));
				break;
			}
		}
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE WHAT THIS ITEM IS (Stave, mace, sword etc)
	//
	//------------------------------------------------------------------------------------------------------
	void generateBase()
	{
		distribution = std::uniform_int_distribution<int>(0, 13);
		type = itemClass(distribution(mtGen));
	}


	//------------------------------------------------------------------------------------------------------
	//
	//				GENERATE Ilvl OF THE ITEM (CURRENTLY RANDOM FROM 1 TO 100)
	//
	//------------------------------------------------------------------------------------------------------
	void generateILVL()
	{
		distribution = std::uniform_int_distribution<int>(1, 100);
		ilvl = distribution(mtGen);
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
		generateBase();
		generateBaseType();
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
			case itemClass::Sceptre: returningText += "Sceptre"; break;
			case itemClass::OneHandedMace: returningText += "One Handed Mace"; break;
			case itemClass::TwoHandedMace: returningText += "Two Handed Mace"; break;
			case itemClass::OneHandedAxe: returningText += "One Handed Axe"; break;
			case itemClass::TwoHandedAxe: returningText += "Two Handed Axe"; break;
			case itemClass::OneHandedSword: returningText += "One Handed Sword"; break;
			case itemClass::ThrustingOneHandedSword: returningText += "Thrusting One Handed Sword"; break;
			case itemClass::TwoHandedSword: returningText += "Two Handed Sword"; break;
			case itemClass::Bow: returningText += "Bow"; break;
			case itemClass::Claw: returningText += "Claw"; break;
			case itemClass::Dagger: returningText += "Dagger"; break;
			case itemClass::RuneDagger: returningText += "Rune Dagger"; break;
			case itemClass::Stave: returningText += "Stave"; break;
			case itemClass::Wand: returningText += "Wand"; break;
		}

		returningText += "\nBase: ";

		//TODO: Update this line every time I make new set of base classes. After job done just remove if.
		if (type == itemClass::Sceptre)
		{
			returningText += baseClass.name;
			returningText += "\nPhysical Damage: ";
			returningText += std::to_string(baseClass.minPD);
			returningText += "-";
			returningText += std::to_string(baseClass.maxPD);
			returningText += "\nCritical Strike Chance: ";
			returningText += std::to_string(baseClass.critChance);
			returningText += "\%\nAttacks per Second: ";
			returningText += std::to_string(baseClass.APS);
			returningText += "\nWeapon Range: ";
			returningText += std::to_string(baseClass.range);
			returningText += "\n\nRequires";
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
			returningText += "\n";
		}
		else
		{
			returningText += std::to_string(base); //TODO: After finishing bases delete this
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
	Item item;

	//Generating item
	item.generateItem();

	//Displaying created item
	std::cout << item.toString() << std::endl << std::flush;
}
