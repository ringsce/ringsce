#!/bin/bash
git config --global alias.up '!git remote update -p; git merge --ff-only @{u}'


for repo in ringsce; do
    (cd "${repo}" && git checkout master && git up)
done
