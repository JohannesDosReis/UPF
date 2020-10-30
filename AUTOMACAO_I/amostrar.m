## Copyright (C) 2020 johan
## 
## This program is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see
## <https://www.gnu.org/licenses/>.

## -*- texinfo -*- 
## @deftypefn {} amostrar (@var{F}, @var{Fa})
##
## @seealso{}
## @end deftypefn

## Author: johan <johan@JOHANNES-LAPTOP>
## Created: 2020-09-01

function amostrar(Fi, Fa)
    tol = 0.1; % tolerancia para o grafico de reconstrucao
    No = 2^12; % numero de pontos do sinal original
    F = 100; % frequencia do sinal original
    m = Fi/100; % harmonica do sinal original
    Fs=m*F; % frequencia do sinal considerando a harmonica
    %Fa = 1600; % frequencia de amostragem
    N = Fa/Fs; % numero de pontos contidos na amostra
    Ta = 1/Fa; % periodo de amostragem
    x = linspace(0,m*2*pi,No); % cria vetor do sinal a ser amostrado
    t = linspace(0,1/F,No); % vetor de tempo
    y = sin(x); % gera o sinal
    xa = linspace(0,m*2*pi,(N*m+1)); % auxiliar para o grafico, pontos de amostragem
    ta = linspace(0,1/(F),(N*m+1)); % auxiliar para o grafico, vetor de tempo
    ya = sin(xa); % sinal reconstuido
    figure(); % plotar na figura
    subplot(2,1,1); % plotar na janela superior
    hold off; % replotar
    plot(t,y); % tempo x sinal
    hold on; % manter grafico
    stem(ta,ya); % mostra pontos amostrados
    subplot(2,1,2); % plotar na janela inferiror
    hold off % replotar

    if(max(ya) > tol) % amplitude so sinal acima de tol
        %stairs(ta,ya); % plotar saâˆšâ‰ da do DAC
        plot(ta,ya); % plotar sinal reconstuido
        hold on % manter grafico
        plot(ta,ya,'o'); % plotar pontos amostrados
    else % amplitude so sinal abaixo de tol
        ya = zeros(1,length(ta)) % substitui o sinal por zero
        hold off % replotar
        plot(ta,ya); % plotar sinal
        hold on % manter grafico
        plot(ta,ya,'o'); % plotar pontos amostrados
    end

endfunction