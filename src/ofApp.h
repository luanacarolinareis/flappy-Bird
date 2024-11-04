#pragma once

#include "ofMain.h"

class of_app final : public ofBaseApp{

	public:
		// Métodos 'default'
		void setup() override;
		void update() override;
		void draw() override;

		// Métodos de eventos
		void keyPressed(int key) override;

		// Variáveis
		float bird_y;					// Posição vertical do pássaro
		float bird_velocity;			// Velocidade do pássaro
		float gravity;					// Gravidade aplicada ao pássaro
		float jump_force;				// Força do salto
		bool is_game_over;				// Verifica se o jogo acabou

		vector<ofRectangle> pipes;		// Tubos do jogo
		float pipe_speed;				// Velocidade dos tubos
		float pipe_spacing;				// Distância entre os tubos
		int score;						// Pontuação do jogador

		// Métodos personalizados
		void reset_game();				// Reinicia o jogo
		void create_pipe();				// Cria um novo tubo
};
