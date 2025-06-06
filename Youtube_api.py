import os
from fastapi import FastAPI, Request, HTTPException, Query
import requests
from dotenv import load_dotenv

load_dotenv()

YOUTUBE_API_KEY = os.getenv("YOUTUBE_API_KEY")
API_PASSWORD = os.getenv("API_PASSWORD")
SOURCE_URL = 'https://www.googleapis.com/youtube/v3/videos'


@app.get("/video")
async def get_video_info(
    request: Request,
    video_id: str = Query(..., description="ID відео з YouTube")
):
    api_key = request.headers.get("X-API-Key")
    if api_key != API_PASSWORD:
        raise HTTPException(status_code=401, detail="Unauthorized: неправильний ключ")

    params = {
        "part": "snippet,statistics",
        "id": video_id,
        "key": YOUTUBE_API_KEY
    }

    try:
        response = requests.get(YOUTUBE_API_URL, params=params)
        response.raise_for_status()
        data = response.json()

        if not data["items"]:
            raise HTTPException(status_code=404, detail="❌ Відео не знайдено")

        video = data["items"][0]
        snippet = video["snippet"]
        stats = video["statistics"]

        return {
            "videoId": video_id,
            "title": snippet["title"],
            "channel": snippet["channelTitle"],
            "views": stats.get("viewCount", "н/д"),
            "publishedAt": snippet["publishedAt"],
            "description": snippet["description"]
        }

    except requests.exceptions.RequestException as e:
        raise HTTPException(status_code=502, detail=f"Помилка при зверненні до YouTube API: {str(e)}")
