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
## @deftypefn {} {@var{[r, theta]} =} ret2pol (@var{x}, @var{y})
##
## @seealso{}
## @end deftypefn

## Author: johan <johan@JOHANNES-LAPTOP>
## Created: 2020-08-31

## function [r, theta] = ret2pol (x, y)
##   r = sqrt(x^2 + y^2);
##   theta = atan2(y/x);
##
## endfunction


function [r, theta] = ret2pol (x, y)
  r = sqrt(x^2 + y^2);
  theta = atan(y/x);
  
endfunction
