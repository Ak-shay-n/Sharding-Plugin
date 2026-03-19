/*	SingleNode.cc: contains stuff for working with single mysql nodes
	Copyright (C) 2012 Bereznikov Alexey

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.	*/

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include <stdlib.h>
#include <string.h>

#include "SingleNode.h"

SingleNode::SingleNode()
{
	_address = NULL;
}

SingleNode::SingleNode(char *source)
{
	FromString(source);
}

SingleNode::~SingleNode()
{
	
}

MYSQL_RESULT	SingleNode::ProcessCommand(char *command)
{
	return	(MYSQL_RESULT)NULL;	/* TEMPORARY */
}

char	*SingleNode::ToString()
{
	if (_address == NULL)
		return	NULL;
	char	*temp = (char*)calloc(strlen(_address) + 1, 1);
	strncpy(temp, _address, strlen(_address));
	return	temp;
}

int		SingleNode::FromString(char *source)
{
	/*  TODO: add some checks */
	_address = (char*)calloc(strlen(source) + 1, 1);
	strncpy(_address, source, strlen(source));
	return	1;
}
