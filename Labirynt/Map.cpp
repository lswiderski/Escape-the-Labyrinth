#include "Map.h"


Map::Map(void)
{
	time_map=0;
	std::vector<std::vector<int>> Npcs;
	std::vector<std::vector<std::string>> txts;
	fp=NULL;
	loadMap("Data/levels/start.lvl");
	
	
	
}


Map::~Map(void)
{
	MapVector.clear();
}
void Map::initialize(){
	

}
void Map::loadMap(const char *filename)
{
	MapVector.clear();
	levers.clear();
	teleports.clear();
	Npcs.clear();
	gates.clear();
	nextMap.clear();
	fp = fopen(filename,"r+b");
	if(fp != NULL)
	{
		fread(tmp,sizeof(int),1,fp);
		for (int i=0;i<tmp[0];i++)
		{

			fread(ctmp,sizeof(char),1,fp);
			stmp+=ctmp[0];
		}
		mapName=stmp;
		stmp="";
		std::cout<<"mapName: "<<mapName<<std::endl;
		fread(loadx, sizeof(int), 1 , fp);
		fread(loady, sizeof(int), 1 , fp);
		fread(loadz, sizeof(int), 1 , fp);
		this->mapSizeX=loadx[0];
		this->mapSizeY=loady[0];
		this->mapSizeZ=loadz[0];
		for(int i=0;i<mapSizeY;i++)
		{
			for(int j=0;j<mapSizeX;j++)
			{
				for(int z=0;z<mapSizeZ;z++)
				{
					fread(tmp, sizeof(int), 1 , fp);
					tmpVector2.push_back(tmp[0]);
				}

				tmpVector.push_back(tmpVector2);
				tmpVector2.clear();	
			}
			MapVector.push_back(tmpVector);
			tmpVector.clear();
		}
	
		fread(coordinates, sizeof(int), 2 , fp);
		fread(&time_map, sizeof(int), 1, fp);
		std::cout<<"time: "<<time_map<<std::endl;
		fread(&vlevers, sizeof(int),1,fp);
		for (int i=0;i<vlevers;i++)
		{
			for (int j=0;j<3;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			levers.push_back(tmpVector2);
			tmpVector2.clear();
		}
		fread(&vgates, sizeof(int),1,fp);
		for (int i=0;i<vgates;i++)
		{
			for (int j=0;j<4;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			gates.push_back(tmpVector2);
			tmpVector2.clear();
		}
		fread(&vboxs, sizeof(int),1,fp);
		for (int i=0;i<vboxs;i++)
		{
			for (int j=0;j<4;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			boxs.push_back(tmpVector2);
			tmpVector2.clear();
		}


		fread(&vteleports, sizeof(int),1,fp);
		for (int i=0;i<vteleports;i++)
		{
			for (int j=0;j<4;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			teleports.push_back(tmpVector2);
			tmpVector2.clear();
		}

		fread(&vnpcs, sizeof(int),1,fp);
		for (int i=0;i<vnpcs;i++)
		{
			for (int j=0;j<3;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			Npcs.push_back(tmpVector2);
			tmpVector2.clear();
		}


		stmp="";
		txts.clear();
		stmpVector.clear();
		fread(tmp, sizeof(int),1,fp);
		for (int i=0;i<tmp[0];i++)
		{
			
			fread(tmp2, sizeof(int),1,fp);
			for (int j=0;j<tmp2[0];j++)
			{
				
				fread(tmp3, sizeof(int),1,fp);
				for (int z=0;z<tmp3[0];z++)
				{
					fread(ctmp, sizeof(char),1,fp);
					stmp+=ctmp[0];
				}
				stmpVector.push_back(stmp);
				stmp="";
			}
			txts.push_back(stmpVector);
			stmpVector.clear();
		}
		
		fread(tmp, sizeof(int),1,fp);
		std::cout<<tmp[0]<<std::endl;
		for (int j=0;j<tmp[0];j++)
		{

			fread(tmp2, sizeof(int),1,fp);
			for (int z=0;z<tmp2[0];z++)
			{
				fread(ctmp, sizeof(char),1,fp);
				stmp+=ctmp[0];
			}
			nextMap.push_back(stmp);
			stmp="";
		}

		fread(&vportals, sizeof(int),1,fp);
		for (int i=0;i<vportals;i++)
		{
			for (int j=0;j<3;j++)
			{
				fread(tmp, sizeof(int), 1 , fp);
				tmpVector2.push_back(tmp[0]);
			}
			portals.push_back(tmpVector2);
			tmpVector2.clear();
		}


		std::cout<<nextMap.size()<<std::endl;
		fclose(fp);
		for (int i=0;i<nextMap.size();i++)
		{
			
			std::cout<<"Next Map: "<<nextMap[i]<<std::endl;
		}
		
	}



}
void Map::pokaz(){

	std::cout<<"Pokazuje"<<std::endl;
	for(int i=0;i<mapSizeY;i++)
	{
		for(int j=0;j<mapSizeX;j++)
		{
			for (int z=0;z<mapSizeZ;z++)
			{
				std::cout<<MapVector[i][j][z]<<" ";
			}
			
		}
		std::cout<<std::endl;
	}
	std::cout<<"Pokazalem"<<std::endl;
}
bool Map::moveBox(int y,int x, int direct)
{
	//0 ^ , 1 > ,2 V , 3 <
	
	if(direct==0)
	{
		if(MapVector[y-1][x][0]%2==0 && MapVector[y-1][x][2]%2==0)
		{
			MapVector[y][x][2]=0;
			MapVector[y-1][x][2]=7;
			

			for (int i=0;i<vboxs;i++)
			{
				if(boxs[i][0]==x && boxs[i][1]==y-1)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=2;

					break;
				}
				else if(boxs[i][0]==x && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=25;
					
				}
			}
			return true;
		}
		
	}
	else if(direct==1)
	{
		if(MapVector[y][x+1][0]%2==0 && MapVector[y][x+1][2]%2==0)
		{
			MapVector[y][x][2]=0;
			MapVector[y][x+1][2]=7;
			for (int i=0;i<vboxs;i++)
			{
				if(boxs[i][0]==x+1 && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=2;

					break;
				}
				else if(boxs[i][0]==x && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=25;
				}
				
					
			}
			return true;
		}
		
	}
	else if(direct==2)
	{
		if(MapVector[y+1][x][0]%2==0 && MapVector[y+1][x][2]%2==0)
		{
			MapVector[y][x][2]=0;
			MapVector[y+1][x][2]=7;

			for (int i=0;i<vboxs;i++)
			{
				if(boxs[i][0]==x && boxs[i][1]==y+1)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=2;

					break;
				}
				else if(boxs[i][0]==x && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=25;
					std::cout<<"kurwa cos poszlo nie tak"<<std::endl;
					break;
				}
			}

			return true;
		}
		
	}
	else if(direct==3)
	{
		if(MapVector[y][x-1][0]%2==0 && MapVector[y][x-1][2]%2==0)
		{
			MapVector[y][x][2]=0;
			MapVector[y][x-1][2]=7;

			for (int i=0;i<vboxs;i++)
			{
				if(boxs[i][0]==x-1 && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=2;

					break;
				}
				else if(boxs[i][0]==x && boxs[i][1]==y)
				{
					MapVector[boxs[i][3]][boxs[i][2]][0]=25;
				}
			}

			return true;
		}
		
	}

}
void Map::checkGate(int id,bool set)
{
	if(set)
		for(int i=0;i<vgates;i++)
		{
			if(gates[i][2]==id)
			{
				if(gates[i][3]==0)
				MapVector[gates[i][1]][gates[i][0]][0]=18;
				else if(gates[i][3]==1)
				MapVector[gates[i][1]][gates[i][0]][0]=25;
			}
			
		}
		
	else
		for(int i=0;i<vgates;i++)
		{
			if(gates[i][2]==id)
			MapVector[gates[i][1]][gates[i][0]][0]=2;
		}
	
	
}

void Map::drawMap(sf::RenderWindow &Window,Player player)
{
	//[(int)(player.getY()/64)][(int)(player.getX()/64)][2]

	renderXmin=player.getX()/64-4;
	if(renderXmin<0) renderXmin=0;

	renderYmin=player.getY()/64-4;
	if(renderYmin<0) renderYmin=0;

	renderXmax=player.getX()/64+5;
	if(renderXmax>mapSizeX)renderXmax=mapSizeX;

	renderYmax=player.getY()/64+5;
	if(renderYmax>mapSizeY)renderYmax=mapSizeY;

	sf::Sprite block;
	block.setTexture(resources::Tiles);
	for(int i = renderXmin; i < renderXmax; i++)
	{
		for(int j = renderYmin; j < renderYmax; j++)
		{
			for (int z=0;z<mapSizeZ;z++)
			{
				if(MapVector[j][i][z] == 1){
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,0,BLOCKSIZE,BLOCKSIZE));


				}
				else if (MapVector[j][i][z] == 0){
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,0,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 2){
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,0,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 3){
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,0,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 4){
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,0,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 5){
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 6){
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 7){
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 8){
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 9){
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 10){
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 11){
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 12){
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));

				}
				else if (MapVector[j][i][z] == 13){ //dzwignia on
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 14){ //teleport
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,2*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}
				else if (MapVector[j][i][z] == 15){ 
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 16){
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 17){ 
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));				
				}
				else if (MapVector[j][i][z] == 18){ 
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));	
				}
				else if (MapVector[j][i][z] == 19){
					
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,3*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));
					
				}


				else if (MapVector[j][i][z] == 20){ 
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 21){ 
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 22){ 
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));				
				}
				else if (MapVector[j][i][z] == 23){ 
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));	
				}
				else if (MapVector[j][i][z] == 24){ 
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,4*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));	
				}


				else if (MapVector[j][i][z] == 25){ 
					block.setTextureRect(sf::IntRect(0*BLOCKSIZE,5*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 26){ 
					block.setTextureRect(sf::IntRect(1*BLOCKSIZE,5*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));			
				}
				else if (MapVector[j][i][z] == 27){ 
					block.setTextureRect(sf::IntRect(2*BLOCKSIZE,5*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));				
				}
				else if (MapVector[j][i][z] == 28){ 
					block.setTextureRect(sf::IntRect(3*BLOCKSIZE,5*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));	
				}
				else if (MapVector[j][i][z] == 29){ 
					block.setTextureRect(sf::IntRect(4*BLOCKSIZE,5*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE));	
				}
				block.setPosition(i * BLOCKSIZE, j * BLOCKSIZE);
				Window.draw(block);
			}
			
		}
	}
}