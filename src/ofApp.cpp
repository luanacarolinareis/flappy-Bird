#include "ofApp.h"

//--------------------------------------------------------------
void of_app::setup(){
    bird_y = static_cast<float>(ofGetHeight()) / 2;
    bird_velocity = 0;
    gravity = 0.5;
    jump_force = -10;
    pipe_speed = 3;
    pipe_spacing = 200;
    score = 0;
    is_game_over = false;

    ofSetFrameRate(60);
    create_pipe();
}

//--------------------------------------------------------------
void of_app::update(){
   if (!is_game_over) {

       // Atualiza a posição do pássaro
       bird_velocity += gravity;
       bird_y += bird_velocity;

       // Verifica se o pássaro tocou o chão ou o topo
       if (bird_y > static_cast<float>(ofGetHeight()) || bird_y < 0) {
           is_game_over = true;
       }

       // Atualiza a posição dos tubos
       for (auto& pipe : pipes) {
           pipe.setPosition(pipe.x - pipe_speed, pipe.y);
       }

       // Remove tubos que saíram do ecrã e cria outros novos
       if (!pipes.empty() && pipes.front().x + pipes.front().width < 0) {
           pipes.erase(pipes.begin());
           create_pipe();
           score++;
       }

       // Verifica colisão com os tubos
       for (const auto& pipe : pipes) {
           if (ofRectangle(static_cast<float>(ofGetWidth()) / 4, bird_y, 34, 24).intersects(pipe)) {
               is_game_over = true;
               break;
           }
       }
   }
}

//--------------------------------------------------------------
void of_app::draw(){
    ofBackground(135, 206, 250);

    // Desenha o pássaro
    ofSetColor(255, 255, 0);
    ofDrawRectangle(static_cast<float>(ofGetWidth()) / 4, bird_y, 34, 24);

    // Desenha os tubos
    ofSetColor(34, 139, 34);
    for (const auto& pipe : pipes) {
        ofDrawRectangle(pipe);
    }

    // Desenha a pontuação
    ofSetColor(0);
    ofDrawBitmapString("Score: " + std::to_string(score), 10, 20);

    // Desenha a mensagem de 'game over'
    if (is_game_over) {
        ofDrawBitmapString("Game Over! Press SPACE to restart", static_cast<float>(ofGetWidth()) / 2 - 100, static_cast<float>(ofGetHeight()) / 2);
    }
}

//--------------------------------------------------------------
void of_app::keyPressed(const int key){
    if (key == ' ') {
        if (is_game_over) {
            reset_game();
        }
        else {
            bird_velocity = jump_force;
        }
    }
}

//--------------------------------------------------------------
void of_app::reset_game() {
    bird_y = static_cast<float>(ofGetHeight()) / 2;
    bird_velocity = 0;
    pipes.clear();
    score = 0;
    is_game_over = false;
    create_pipe();
}

//--------------------------------------------------------------
void of_app::create_pipe() {
	constexpr float gap_height = 150; // Altura do espaço entre os tubos (randomizar)
    float top_height = ofRandom(50, static_cast<float>(ofGetHeight()) - gap_height - 50);

    pipes.emplace_back(ofGetWidth(), 0, 50, top_height);
    pipes.emplace_back(ofGetWidth(), top_height + gap_height, 50, static_cast<float>(ofGetHeight()) - top_height - gap_height);

	// gap = ofRandom(100, 300);
    // gap_y = ofRandom(gap/2, gh- gap/2)

	// pipe_1_h = gap_y - gap/2
	// pipe_1_y = pip_1_h / 2

	// pipe_2_h = gh - (gap_y + gap/2)
	// pipe_2_y = gh - pipe_2_h / 2
}
