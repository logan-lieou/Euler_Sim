struct Options {
	private:
		enum struct COLOR { DEFAULT, HSB, VELOCITY };
		COLOR color;
	public:
		Options(COLOR color = COLOR::DEFAULT);
		~Options();

		COLOR getColor();
		void setColor(COLOR c);
};
