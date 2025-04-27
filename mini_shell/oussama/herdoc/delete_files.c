/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:42:44 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/27 21:57:33 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "her_doc.h"

void delete_files()
{
    int i;
    char **files;

    files = g_all.files_to_remove->content;
    i = 0;
    while (files[i])
    {
        unlink(files[i]);
        i++;
    }
}