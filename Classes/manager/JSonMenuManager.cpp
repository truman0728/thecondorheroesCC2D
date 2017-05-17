#include "JSonMenuManager.h"
#include "RefManager.h"

JSonMenuManager* JSonMenuManager::jsonMenuManager;

JSonMenuManager::JSonMenuManager() {
	auto menubuffer = FileUtils::getInstance()->getStringFromFile(String::createWithFormat("json/Menu.json")->getCString());
	this->jsonDoc.Parse(menubuffer.c_str());
}

JSonMenuManager::~JSonMenuManager() {
}

JSonMenuManager * JSonMenuManager::getInstance() {
	if (jsonMenuManager == nullptr)
		jsonMenuManager = new JSonMenuManager();
	return jsonMenuManager;
}

void JSonMenuManager::readFile(int firstIndex) {
	this->m_sIconFilePath = jsonDoc["items"][firstIndex]["iconFilePath"].GetString();
	this->m_nPrice = jsonDoc["items"][firstIndex]["priceItem"].GetInt();
	this->m_sName = jsonDoc["items"][firstIndex]["nameItem"].GetString();
	this->m_sDescription = jsonDoc["items"][firstIndex]["description"].GetString();
}

void JSonMenuManager::readGoldPack(int firstIndex) {
	this->m_sGoldPackName = jsonDoc["gold_packs"][firstIndex]["coinPackName"].GetString();
	this->m_sIconGoldPackPath = jsonDoc["gold_packs"][firstIndex]["iconGoldPackPath"].GetString();
	this->m_nCoinPackNumberGold = jsonDoc["gold_packs"][firstIndex]["goldNumber"].GetInt();
	this->m_nCoinPackDiamondPrice = jsonDoc["gold_packs"][firstIndex]["diamondPrice"].GetInt();
}

void JSonMenuManager::readDiamondPack(int firstIndex) {
	this->m_sDiamondPackName = jsonDoc["diamond_packs"][firstIndex]["diamondPackName"].GetString();
	this->m_sIconDiamondPackPath = jsonDoc["diamond_packs"][firstIndex]["iconDiamondPackPath"].GetString();
	this->m_nDiamondPackNumberDiamond = jsonDoc["diamond_packs"][firstIndex]["diamondNumber"].GetInt();
	this->m_nDiamondPackMoneyPrice = jsonDoc["diamond_packs"][firstIndex]["moneyPrice"].GetInt();
}

void JSonMenuManager::readEnergyPack(int firstIndex) {
	this->m_sEnergyPackName = jsonDoc["energy_packs"][firstIndex]["energyPackName"].GetString();
	this->m_sIconEnergyPackPath = jsonDoc["energy_packs"][firstIndex]["iconEnergyPackPath"].GetString();
	this->m_nEnergyPackNumberEnergy = jsonDoc["energy_packs"][firstIndex]["energyNumber"].GetInt();
	this->m_nEnergyPackDiamondPrice = jsonDoc["energy_packs"][firstIndex]["diamondPrice"].GetInt();
}

