#pragma once

#include "ofMain.h"

class of_app final : public ofBaseApp{

	public:
		// M�todos 'default'
		void setup() override;
		void update() override;
		void draw() override;

		// M�todos de eventos
		void keyPressed(int key) override;

		// Vari�veis
		float bird_y;					// Posi��o vertical do p�ssaro
		float bird_velocity;			// Velocidade do p�ssaro
		float gravity;					// Gravidade aplicada ao p�ssaro
		float jump_force;				// For�a do salto
		bool is_game_over;				// Verifica se o jogo acabou

		vector<ofRectangle> pipes;		// Tubos do jogo
		float pipe_speed;				// Velocidade dos tubos
		float pipe_spacing;				// Dist�ncia entre os tubos
		int score;						// Pontua��o do jogador

		// M�todos personalizados
		void reset_game();				// Reinicia o jogo
		void create_pipe();				// Cria um novo tubo
};
