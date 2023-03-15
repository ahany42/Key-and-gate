#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main() {
	RenderWindow window(VideoMode(1280, 720), "sfml trial");
	window.setFramerateLimit(30);
	int x = 0;
	int keys = 0;
	int counter = 0;
	int done = 0;
	Texture tx;
	tx.loadFromFile("90323072-dba28f00-df21-11ea-841b-22f77ba85ebe-300x128-removebg-preview.png");
	Sprite s;
	s.setOrigin(20, -20);
	s.setTexture(tx);
	s.setTextureRect(IntRect(x * 60, 0, 60, 64));
	s.scale(1,1);

	Texture wt;
	wt.loadFromFile("download-removebg-preview (1).png");
	Sprite wallpaper;
	wallpaper.setTexture(wt);
	wallpaper.setOrigin(0, 0);
	wallpaper.scale(2,2);
	wallpaper.setPosition(300, 200);

	Texture tg;
	tg.loadFromFile("gate.png");
	Sprite gate;
	gate.setTexture(tg);
	gate.setOrigin(1200, 600);
	gate.scale(0.5, 0.5);
	gate.setPosition(1700, 400);

	Texture k;
	k.loadFromFile("dakyghu-e340932d-f85d-4695-b85d-e1276ea20c2b.png");
	Sprite key;
	key.setTexture(k);
	key.setOrigin(700, -200);
	key.scale(0.25, 0.25);
	key.setPosition(700, 500);

	Texture t;
	t.loadFromFile("enemy-removebg-preview.png");
	Sprite q;
	float y =1;
	float z = 1;
	q.setPosition(300, 400);
	q.setTexture(t);
	q.scale(0.08,0.08);

	Texture ts;
	ts.loadFromFile("enemy-removebg-preview.png");
	Sprite d;
	float m = 1;
	float w = 1;
	d.setPosition(m, w);
	d.setTexture(ts);
	d.scale(0.08, 0.08);


	Texture tp;
	tp.loadFromFile("enemy-removebg-preview.png");
	Sprite l;
	l.setPosition(500, 150);
	l.setTexture(tp);
	l.scale(0.08, 0.08);
	float xl = 1; float yl = 2;
	l.move(xl, yl);

	Font foont;
	foont.loadFromFile("Nice Sugar.ttf");
	Text score;
	score.setFont(foont);
	score.setString("Time");
	score.setCharacterSize(20);
	score.setPosition(0, 0);
	score.setFillColor(Color::White);
	score.setStyle(Text::Bold);



	Text Completed;
	Completed.setFont(foont);
	Completed.setString("Level	Completed");
	Completed.setCharacterSize(100);
	Completed.setPosition(200, 360);
	Completed.setFillColor(Color::Green);
	Completed.setStyle(Text::Bold);



	Text Gameover;
	Gameover.setFont(foont);
	Gameover.setString("Game Over");
	Gameover.setCharacterSize(100);
	Gameover.setPosition(200, 360);
	Gameover.setFillColor(Color::Red);
	Gameover.setStyle(Text::Bold);

	Text keyy;
	keyy.setFont(foont);
	keyy.setString("Keys");
	keyy.setCharacterSize(20);
	keyy.setPosition(0, 20);
	keyy.setFillColor(Color::White);
	keyy.setStyle(Text::Bold);

	int keyn = 0;
	Text  numkey;
	numkey.setFont(foont);
	numkey.setCharacterSize(20);
	numkey.setPosition(80, 20);
	numkey.setFillColor(Color::White);
	numkey.setStyle(Text::Bold);
	numkey.setString(to_string(keyn));
	
	int scorec = 0;
	Text  scorecounter;
	scorecounter.setFont(foont);
	scorecounter.setCharacterSize(20);
	scorecounter.setPosition(80, 0);
	scorecounter.setFillColor(Color::White);
	scorecounter.setStyle(Text::Bold);
	scorecounter.setString(to_string(scorec));

	Texture bombs;
	bombs.loadFromFile("download-removebg-preview (2).png");
	Sprite bomb[3];
	for (size_t i = 0; i < 3;i++) {
		bomb[i].setTexture(bombs);
		bomb[i].setPosition((i * 200) + 100, (i * 300) + 100);
		bomb[i].scale(0.1, 0.1);
		
	}
	Music music;
	music.openFromFile("music_zapsplat_action_dark_sci_fi_serious_atmospsheric_deep_tech_014.wav");
	Sound sound;
	music.play();
	while (window.isOpen())
	{
	
		scorec++;
		scorecounter.setString(to_string(scorec));
		window.draw(scorecounter);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		
		l.move(xl, yl);
		xl+=0.2;
		yl+=0.2;
	
		if ((l.getPosition().x < (11000)) || l.getPosition().x > 0) {
			xl *= -1;

		}
		
		if (l.getPosition().y < (0) || l.getPosition().y >(720))
		{
			yl *= -1;
		}
		m += 0.7;
		w +=  0.7;
		d.move(w, m);
		if ((d.getPosition().x < (1100)) || d.getPosition().x > 0) {
			w *= -1;

		}

		if (d.getPosition().y < (0) || q.getPosition().y >(720))
		{
			m *= -1;
		}
		q.move(z, y);
		if ((q.getPosition().x < (1100)) || q.getPosition().y > (720)) {
			z *= -1;

		}


		if (q.getPosition().y < (0) || q.getPosition().y >(720))
		{
			y *= -1;
		}
		z += 0.7;
		y += 0.7;

		if (Keyboard::isKeyPressed(Keyboard::Key::Up) && s.getPosition().y > (0))
		{
			if (s.getGlobalBounds().intersects(q.getGlobalBounds()) || s.getGlobalBounds().intersects(d.getGlobalBounds()) || s.getGlobalBounds().intersects(l.getGlobalBounds()))

			{
				s.move(0, 7);
				counter = 1;
				
			}
			else
				s.move(0, -7);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down) && s.getPosition().y < (630))
		{
			if (s.getGlobalBounds().intersects(q.getGlobalBounds()) || s.getGlobalBounds().intersects(d.getGlobalBounds()) || s.getGlobalBounds().intersects(l.getGlobalBounds()))
			{
				s.move(0, -7);
				counter = 1;
			}

			else
				s.move(0, 7);

		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && s.getPosition().x > (22))
		{
			s.setScale(-1, 1);
			if (s.getGlobalBounds().intersects(q.getGlobalBounds()) || s.getGlobalBounds().intersects(d.getGlobalBounds()) || s.getGlobalBounds().intersects(l.getGlobalBounds()))
			{
				s.move(7, 0);
				counter = 1;
			}
			else
			{
				s.move(-7, 0);

				x++;
				x %= 5;
				s.setTextureRect(IntRect(x * 60, 0, 60, 64));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && s.getPosition().x < (1250))
		{
			s.setScale(1, 1);
			if (s.getGlobalBounds().intersects(q.getGlobalBounds()) || s.getGlobalBounds().intersects(d.getGlobalBounds()) || s.getGlobalBounds().intersects(l.getGlobalBounds()))
			{
				s.move(-7, 0);
				counter = 1;

			}
			else
			{
				s.move(7, 0);
				x++;
				x %= 5;
				s.setTextureRect(IntRect(x * 60, 0, 60, 64));
			}
		}
	
		if (s.getGlobalBounds().intersects(key.getGlobalBounds()))
		{
			keys = 1;
			
		}
		for (size_t i = 0; i < 3; i++) {
			if (s.getGlobalBounds().intersects(bomb[i].getGlobalBounds()))
				counter = 1;
		}
		if (s.getGlobalBounds().intersects(gate.getGlobalBounds()) && keys==1)
			done= 9;
		if (counter == 1) {
			window.draw(Gameover);
			window.display();
			window.close();
		}
		
		
		if (keys == 1)
		{
			keyn = 1;
			if (done == 9) {
				window.draw(Completed);
				window.display();
				window.clear();
				window.close();
			}
		}
		window.clear();
		window.draw(wallpaper);
		window.draw(s);
		window.draw(q);
		window.draw(score);
		window.draw(l);
		for (size_t i = 0; i < 3; i++) {
			window.draw(bomb[i]);
		}
		window.draw(d);
		window.draw(keyy);
		if (keys == 0)
			window.draw(key);
		window.draw(gate);
		window.draw(scorecounter);
		window.draw(numkey);
		numkey.setString(to_string(keyn));
		window.display();
	}
	
	
	return 0;
}