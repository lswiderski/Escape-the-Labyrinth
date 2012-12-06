#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include "Player.h"
#define BLOCKSIZE 64
class Map
{
private:
	
	std::vector<int> tmpVector2;
	std::vector<std::vector<int>> tmpVector;
	std::vector<std::string> stmpVector;
	int tmp[1],tmp2[1],tmp3[1];
	char ctmp[1];
	std::string stmp;
	int loadx[1];
	int loady[1];
	int loadz[1];
	int mapSizeX;
	int mapSizeY;
	int mapSizeZ;
	int renderXmin;
	int renderYmin;
	int renderXmax;
	int renderYmax;

	
	




	sf::Sprite block;
	FILE *fp;
public:
	std::vector<std::string> nextMap;
	int coordinates[2];
	std::vector<std::vector<std::vector<int>>> MapVector;
	void initialize();
	void loadMap(const char *filename);
	void drawMap(sf::RenderWindow &Window, Player player);
	void pokaz();
	void checkGate(int id,bool set);
	bool moveBox(int y,int x, int direct);
	std::vector<std::vector<int>> levers;
	std::vector<std::vector<int>> gates;
	std::vector<std::vector<int>> teleports;
	std::vector<std::vector<int>> boxs;
	std::vector<std::vector<int>> portals;
	int vlevers,vteleports,vnpcs,vgates,vboxs,vportals;
	std::vector<std::vector<int>> Npcs;
	std::vector<std::vector<std::string>> txts;
	int time_map;
	int map_code;
	std::string mapName;
	Map(const char *filename);
	Map(void);
	~Map(void);
};

