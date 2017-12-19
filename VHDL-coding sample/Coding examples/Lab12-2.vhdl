LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use ieee.numeric_std.all; 
use IEEE.std_logic_unsigned.all;

ENTITY Lab12_2 IS
PORT (
Mode: IN STD_LOGIC_VECTOR (1 DOWNTO 0);
CLR: IN STD_LOGIC;
Seven_Segment: OUT STD_LOGIC_VECTOR (6 DOWNTO 0) );
END Lab12_2;

ARCHITECTURE Seven_Segment_Display OF Lab12_2 IS
signal buffere: unsigned (6 DOWNTO 0) := "0000001";
signal tmp: std_logic_vector (3 downto 0) := "0000";
signal Numb_out: std_logic_vector(6 downto 0) := "0000000";
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
signal n : integer := 0; 
BEGIN

sync_proc: process(clk)
BEGIN
	clk <= not clk after PERIOD;
end process sync_proc;

Number_proc: process (tmp)
BEGIN
case tmp is
	when "0000" => Numb_out <= "1000000"; -- '0'
	when "0001" => Numb_out <= "0000110"; -- '1'
	when "0010" => Numb_out <= "1011011"; -- '2'
	when "0011" => Numb_out <= "1001111"; -- '3'
	when "0100" => Numb_out <= "1100110"; -- '4'
	when "0101" => Numb_out <= "1101101"; -- '5'
	when "0110" => Numb_out <= "1111101"; -- '6'
	when "0111" => Numb_out <= "0000111"; -- '7'
	when "1000" => Numb_out <= "1111111"; -- '8'
	when "1001" => Numb_out <= "1101111"; -- '9'
	when others => Numb_out <= "0000000";
end case;
end process Number_proc;


Display_proc: process(MODE,buffere,clk,CLR)
BEGIN


case MODE is 
	when "00" =>							--Leds are ON one at time in order: A-B-C...-A-B-C...

		if(CLR = '1') then		
			Seven_Segment <= "0000001";		--Reset Seven-Segment
		elsif (rising_edge(clk)) then	
			buffere <= buffere rol 1;
			Seven_Segment <= std_logic_vector(buffere);					 
		end if;	

	when "01" =>							--Leds are ON one at time in order: A-B-C...-G-F-E-D...-C-B-A...

		if(CLR = '1') then		
			Seven_Segment <= "0000001";		--Reset Seven-Segment
			n <= 0;			
		elsif (rising_edge(clk)) then
			n <= n+1;			
			if(n < 6) then				
				buffere <= buffere rol 1;
				Seven_Segment <= std_logic_vector(buffere);
			elsif(n >= 6) then
				buffere <= buffere ror 1;				
				Seven_Segment <= std_logic_vector(buffere);
				if(n >= 11) then
					n <= 0;
				end if;
			end if;
		end if;	

	when "10" =>							--Display ODD numbers: 1-3-5-7-9...
		if(CLR = '1') then		
			Seven_Segment <= "0000001";		--Reset Seven-Segment
			tmp <= "0001";
			n <= 0;			
		elsif (rising_edge(clk)) then
			n <= n + 1;			
			if(n < 4) then					--Because of initial state is started from 0 (5 numbers)
				tmp <= tmp + 2;
			elsif(n >= 4) then
				tmp <= "0001";
				n <= 0;
			end if;
			Seven_Segment <= Numb_out; 			 
		end if;

	when "11" =>							--Display ODD numbers: 0-2-4-6-8...
		if(CLR = '1') then		
			Seven_Segment <= "0000000";		--Reset Seven-Segment
			tmp <= "0000";
			n <= 0;					
		elsif (rising_edge(clk)) then
			n <= n + 1;
			if(n < 4) then
				tmp <= tmp + 2;
			elsif(n >= 4) then
				tmp <= "0000";
				n <= 0;
			end if;
			Seven_Segment <= Numb_out;	
		end if;


	when others => Seven_Segment <= "0000000";

end case;
end process Display_proc;
end Seven_Segment_Display;